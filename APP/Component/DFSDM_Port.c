/**
 *  @file DFSDM_Port.c
 *
 *  @date 2021-01-22
 *
 *  @author aron566
 *
 *  @copyright ���пƼ��о�Ժ.
 *
 *  @brief DFSDM�����ӿڣ�PDMתPCM
 *
 *  @details 1��ͨ��0��ͨ��1ָ���ݽ��룬��������-->����ͨ��1��-->���뵽�����˲���ת��PCM���ݣ��˲���0��ͨ��0���˲���1��ͨ��1��
 *           2��ͨ��2��ͨ��3ָ���ݽ��룬��������-->����ͨ��3��-->���뵽�����˲���ת��PCM���ݣ��˲���2��ͨ��2���˲���3��ͨ��3��
 *           3��ͨ��4��ͨ��5ָ���ݽ��룬��������-->����ͨ��5��-->���뵽�����˲���ת��PCM���ݣ����˲������ã�
 *           4��ͨ��6��ͨ��7ָ���ݽ��룬��������-->����ͨ��7��-->���뵽�����˲���ת��PCM���ݣ����˲������ã�
 *           5�������� = ʱ��Դ/��Ƶֵ/(Fosr*Iosr) == 16khz = 2048000hz/2/(64*1)
 *           6��ż��ͨ���ţ��ɼ����������ݼ�SEL��GND��MIC�豸
 *
 *  @version V1.0
 */
#ifdef __cplusplus ///<use C compiler
extern "C" {
#endif
/** Includes -----------------------------------------------------------------*/
/* Private includes ----------------------------------------------------------*/
#include "DFSDM_Port.h"
#include "main.h"
#include "usbd_audio.h"
/** Private typedef ----------------------------------------------------------*/

/** Private macros -----------------------------------------------------------*/
#define ENABLE_DFSDM_PERIPHERAL   1/**< ѡ���Ƿ�����DFSDMģ��*/

/*���ý��ջ����С*/
#if ENABLE_DFSDM_PERIPHERAL
  #ifdef PCM_ONE_SAMPLE_NUM
    #undef PCM_ONE_SAMPLE_NUM
    #define PCM_ONE_SAMPLE_NUM    MONO_FRAME_SIZE
    #undef PCM_TWO_SAMPLE_NUM
    #define PCM_TWO_SAMPLE_NUM    (PCM_ONE_SAMPLE_NUM*2)
  #endif
#endif
/** Private constants --------------------------------------------------------*/

/** Public variables ---------------------------------------------------------*/
extern DFSDM_Filter_HandleTypeDef hdfsdm1_filter0;
extern DFSDM_Filter_HandleTypeDef hdfsdm1_filter1;
extern DFSDM_Filter_HandleTypeDef hdfsdm1_filter2;
extern DFSDM_Filter_HandleTypeDef hdfsdm1_filter3;
extern PDM2PCM_BUF_Typedef_t Pdm2Pcm_ChannelBuf[MIC_CHANNEL_NUM];

extern volatile int16_t g_UACRingBuf[UAC_BUFFER_SIZE];
extern volatile uint16_t g_UACWriteIndex;
extern volatile uint16_t g_UACReadIndex;
/** Private variables --------------------------------------------------------*/

static int16_t *PCM_Data_Ptr[MIC_CHANNEL_NUM]   = {NULL};
static volatile uint32_t DFSDM_DmaCanRead_Flag  = 0;
static volatile uint32_t DmaRecHalfBuffCplt_Num = 0;
static volatile uint32_t DmaRecBuffCplt_Num     = 0;

static int16_t MIC1_Aidio_Buf[PCM_ONE_SAMPLE_NUM]= {0};
static int16_t MIC2_Aidio_Buf[PCM_ONE_SAMPLE_NUM]= {0};
static int16_t MIC3_Aidio_Buf[PCM_ONE_SAMPLE_NUM]= {0};
static int16_t MIC4_Aidio_Buf[PCM_ONE_SAMPLE_NUM]= {0};

/** Private function prototypes ----------------------------------------------*/

/** Private user code --------------------------------------------------------*/

/** Private application code -------------------------------------------------*/
/*******************************************************************************
*
*       Static code
*
********************************************************************************
*/

/** Public application code --------------------------------------------------*/
/*******************************************************************************
*
*       Public code
*
********************************************************************************
*/
/**
  * @brief  Half regular conversion complete callback. 
  * @param  hdfsdm_filter : DFSDM filter handle.
  * @retval None
  */
void HAL_DFSDM_FilterRegConvHalfCpltCallback(DFSDM_Filter_HandleTypeDef *hdfsdm_filter)
{
  DFSDM_DmaCanRead_Flag = 1;
  PCM_Data_Ptr[0] = (int16_t*)Pdm2Pcm_ChannelBuf[0].PCM_Buf;
  PCM_Data_Ptr[1] = (int16_t*)Pdm2Pcm_ChannelBuf[1].PCM_Buf;
  PCM_Data_Ptr[2] = (int16_t*)Pdm2Pcm_ChannelBuf[2].PCM_Buf;
  PCM_Data_Ptr[3] = (int16_t*)Pdm2Pcm_ChannelBuf[3].PCM_Buf;
}

/**
  * @brief  Regular conversion complete callback. 
  * @note   In interrupt mode, user has to read conversion value in this function
            using HAL_DFSDM_FilterGetRegularValue.
  * @param  hdfsdm_filter : DFSDM filter handle.
  * @retval None
  */
void HAL_DFSDM_FilterRegConvCpltCallback(DFSDM_Filter_HandleTypeDef *hdfsdm_filter)
{
  DFSDM_DmaCanRead_Flag = 1;
  PCM_Data_Ptr[0] = (int16_t*)&Pdm2Pcm_ChannelBuf[0].PCM_Buf[PCM_ONE_SAMPLE_NUM];
  PCM_Data_Ptr[1] = (int16_t*)&Pdm2Pcm_ChannelBuf[1].PCM_Buf[PCM_ONE_SAMPLE_NUM];
  PCM_Data_Ptr[2] = (int16_t*)&Pdm2Pcm_ChannelBuf[2].PCM_Buf[PCM_ONE_SAMPLE_NUM];
  PCM_Data_Ptr[3] = (int16_t*)&Pdm2Pcm_ChannelBuf[3].PCM_Buf[PCM_ONE_SAMPLE_NUM];
}

/**
  ******************************************************************
  * @brief   DFSDM����PDMת��
  * @param   [in]None.
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2021-01-22
  ******************************************************************
  */
void DFSDM_Port_Start(void)
{ 
  if(DFSDM_DmaCanRead_Flag == 0)
  {
    return;
  }
  
  memcpy((void *)MIC1_Aidio_Buf, (void *)PCM_Data_Ptr[0], sizeof(int16_t)*PCM_ONE_SAMPLE_NUM);	
  memcpy((void *)MIC2_Aidio_Buf, (void *)PCM_Data_Ptr[1], sizeof(int16_t)*PCM_ONE_SAMPLE_NUM);	
  memcpy((void *)MIC3_Aidio_Buf, (void *)PCM_Data_Ptr[2], sizeof(int16_t)*PCM_ONE_SAMPLE_NUM);	
  memcpy((void *)MIC4_Aidio_Buf, (void *)PCM_Data_Ptr[3], sizeof(int16_t)*PCM_ONE_SAMPLE_NUM);	
  
  /*����*/
  /*����USB��Ƶ����*/
  for(int i = 0; i < PCM_ONE_SAMPLE_NUM; i++)
  {
    g_UACRingBuf[g_UACWriteIndex] = MIC1_Aidio_Buf[i];
    g_UACWriteIndex++;
    g_UACWriteIndex = (g_UACWriteIndex >= UAC_BUFFER_SIZE)?0:g_UACWriteIndex;

    g_UACRingBuf[g_UACWriteIndex] = MIC2_Aidio_Buf[i];
    g_UACWriteIndex++;

    g_UACWriteIndex = (g_UACWriteIndex >= UAC_BUFFER_SIZE)?0:g_UACWriteIndex;
  }
  DFSDM_DmaCanRead_Flag = 0;
}

/**
  ******************************************************************
  * @brief   DFSDM��ʼ��
  * @param   [in]None.
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2021-01-22
  ******************************************************************
  */
void DFSDM_Port_Init(void)
{
#if ENABLE_DFSDM_PERIPHERAL
	/*����ͨ��0����*/	
  if(HAL_DFSDM_FilterRegularMsbStart_DMA(&hdfsdm1_filter0, (int16_t *)(Pdm2Pcm_ChannelBuf[0].PCM_Buf), PCM_TWO_SAMPLE_NUM) == HAL_ERROR)
  {
    Error_Handler();
  }

  /*����ͨ��1����*/		
  if(HAL_DFSDM_FilterRegularMsbStart_DMA(&hdfsdm1_filter1, (int16_t *)(Pdm2Pcm_ChannelBuf[1].PCM_Buf), PCM_TWO_SAMPLE_NUM) == HAL_ERROR)
  {
    Error_Handler();
  }
  
  /*����ͨ��2����*/	
  if(HAL_DFSDM_FilterRegularMsbStart_DMA(&hdfsdm1_filter2, (int16_t *)(Pdm2Pcm_ChannelBuf[2].PCM_Buf), PCM_TWO_SAMPLE_NUM) == HAL_ERROR)
  {
    Error_Handler();
  }
  
  /*����ͨ��3����*/	
  if(HAL_DFSDM_FilterRegularMsbStart_DMA(&hdfsdm1_filter3, (int16_t *)(Pdm2Pcm_ChannelBuf[3].PCM_Buf), PCM_TWO_SAMPLE_NUM) == HAL_ERROR)
  {
    Error_Handler();
  }
#endif
}

#ifdef __cplusplus ///<end extern c
}
#endif
/******************************** End of file *********************************/
