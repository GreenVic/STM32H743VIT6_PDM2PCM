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
/** Private typedef ----------------------------------------------------------*/

/** Private macros -----------------------------------------------------------*/

/** Private constants --------------------------------------------------------*/
/** Public variables ---------------------------------------------------------*/
extern DFSDM_Filter_HandleTypeDef hdfsdm1_filter0;
extern DFSDM_Filter_HandleTypeDef hdfsdm1_filter1;
extern DFSDM_Filter_HandleTypeDef hdfsdm1_filter2;
extern DFSDM_Filter_HandleTypeDef hdfsdm1_filter3;
extern DFSDM_Channel_HandleTypeDef hdfsdm1_channel0;
extern DFSDM_Channel_HandleTypeDef hdfsdm1_channel1;
extern DFSDM_Channel_HandleTypeDef hdfsdm1_channel2;
extern DFSDM_Channel_HandleTypeDef hdfsdm1_channel3;
extern DFSDM_Channel_HandleTypeDef hdfsdm1_channel4;
extern DFSDM_Channel_HandleTypeDef hdfsdm1_channel5;
extern DFSDM_Channel_HandleTypeDef hdfsdm1_channel6;
extern DFSDM_Channel_HandleTypeDef hdfsdm1_channel7;


extern volatile PDM2PCM_BUF_Typedef_t Pdm2Pcm_ChannelBuf[MIC_CHANNEL_NUM];
/** Private variables --------------------------------------------------------*/
/*microphone 1*/
static uint8_t DmaRecHalfBuffCplt_1  = 0;
static uint8_t DmaRecBuffCplt_1      = 0;

/*microphone 2*/
static uint8_t DmaRecHalfBuffCplt_2  = 0;
static uint8_t DmaRecBuffCplt_2      = 0;

/*microphone 3*/
static uint8_t DmaRecHalfBuffCplt_3  = 0;
static uint8_t DmaRecBuffCplt_3      = 0;

/*microphone 4*/
static uint8_t DmaRecHalfBuffCplt_4  = 0;
static uint8_t DmaRecBuffCplt_4      = 0;

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
  if(hdfsdm_filter == &hdfsdm1_filter0)
  {
    DmaRecHalfBuffCplt_1 = 1;
    /* Invalidate Data Cache to get the updated content of the SRAM*/
    SCB_InvalidateDCache_by_Addr((uint32_t*)&Pdm2Pcm_ChannelBuf[0].PCM_Buf[0], PCM_TWO_SAMPLE_NUM);
  }
  else if(hdfsdm_filter == &hdfsdm1_filter1)
  {
    DmaRecHalfBuffCplt_2 = 1;
    /* Invalidate Data Cache to get the updated content of the SRAM*/
    SCB_InvalidateDCache_by_Addr((uint32_t*)&Pdm2Pcm_ChannelBuf[0].PCM_Buf[0], PCM_TWO_SAMPLE_NUM);
  }
  else if(hdfsdm_filter == &hdfsdm1_filter2)
  {
    DmaRecHalfBuffCplt_3 = 1;
    /* Invalidate Data Cache to get the updated content of the SRAM*/
    SCB_InvalidateDCache_by_Addr((uint32_t*)&Pdm2Pcm_ChannelBuf[0].PCM_Buf[0], PCM_TWO_SAMPLE_NUM);
  }
  else if(hdfsdm_filter == &hdfsdm1_filter3)
  {
    DmaRecHalfBuffCplt_4 = 1;
    /* Invalidate Data Cache to get the updated content of the SRAM*/
    SCB_InvalidateDCache_by_Addr((uint32_t*)&Pdm2Pcm_ChannelBuf[0].PCM_Buf[0], PCM_TWO_SAMPLE_NUM);
  }
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
  if(hdfsdm_filter == &hdfsdm1_filter0)
  {
    DmaRecBuffCplt_1 = 1;
    /* Invalidate Data Cache to get the updated content of the SRAM*/
//    SCB_InvalidateDCache_by_Addr((uint32_t*)&Pdm2Pcm_ChannelBuf[0].PCM_Buf[PCM_ONE_SAMPLE_NUM], PCM_TWO_SAMPLE_NUM);
  }
  else if(hdfsdm_filter == &hdfsdm1_filter1)
  {
    DmaRecBuffCplt_2 = 1;
    /* Invalidate Data Cache to get the updated content of the SRAM*/
    SCB_InvalidateDCache_by_Addr((uint32_t*)&Pdm2Pcm_ChannelBuf[0].PCM_Buf[PCM_ONE_SAMPLE_NUM], PCM_TWO_SAMPLE_NUM);
  }
  else if(hdfsdm_filter == &hdfsdm1_filter2)
  {
    DmaRecBuffCplt_3 = 1;
    /* Invalidate Data Cache to get the updated content of the SRAM*/
    SCB_InvalidateDCache_by_Addr((uint32_t*)&Pdm2Pcm_ChannelBuf[0].PCM_Buf[PCM_ONE_SAMPLE_NUM], PCM_TWO_SAMPLE_NUM);
  }
  else if(hdfsdm_filter == &hdfsdm1_filter3)
  {
    DmaRecBuffCplt_4 = 1;
    /* Invalidate Data Cache to get the updated content of the SRAM*/
    SCB_InvalidateDCache_by_Addr((uint32_t*)&Pdm2Pcm_ChannelBuf[0].PCM_Buf[PCM_ONE_SAMPLE_NUM], PCM_TWO_SAMPLE_NUM);
  }
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
  if((DmaRecHalfBuffCplt_1 == 0) && (DmaRecBuffCplt_1 == 0))
  {
    return;
  }
  
//  if(DmaLeftRecHalfBuffCplt == 1)
//  {
//    memmove((void *)Pdm2Pcm_ChannelBuf[0].PCM_One_Sample_Buf, (void *)Pdm2Pcm_ChannelBuf[0].PCM_Buf, PCM_ONE_SAMPLE_NUM);
//  }
//  if(DmaLeftRecBuffCplt == 1)
//  {
//    memmove((void *)Pdm2Pcm_ChannelBuf[0].PCM_One_Sample_Buf, (void *)(Pdm2Pcm_ChannelBuf[0].PCM_Buf+PCM_ONE_SAMPLE_NUM), PCM_ONE_SAMPLE_NUM);
//  }
  int16_t *PCM_Data_Ptr = (DmaRecHalfBuffCplt_1 == 1)?(int16_t *)Pdm2Pcm_ChannelBuf[0].PCM_Buf:(int16_t *)Pdm2Pcm_ChannelBuf[0].PCM_Buf+PCM_ONE_SAMPLE_NUM;
  
  /*����*/
  /*����USB��Ƶ����*/
  #include "usbd_audio.h"
  extern volatile int16_t g_UACRingBuf[UAC_BUFFER_SIZE];
  extern volatile uint16_t g_UACWriteIndex;
  extern volatile uint16_t g_UACReadIndex;
  
  for(int i = 0; i < PCM_ONE_SAMPLE_NUM; i++)
  {
    g_UACRingBuf[g_UACWriteIndex] = PCM_Data_Ptr[i];//Pdm2Pcm_ChannelBuf[0].PCM_One_Sample_Buf[i];
    g_UACWriteIndex++;
    g_UACWriteIndex = (g_UACWriteIndex >= UAC_BUFFER_SIZE)?0:g_UACWriteIndex;

    g_UACRingBuf[g_UACWriteIndex] = PCM_Data_Ptr[i];//Pdm2Pcm_ChannelBuf[0].PCM_One_Sample_Buf[i];
    g_UACWriteIndex++;

    g_UACWriteIndex = (g_UACWriteIndex >= UAC_BUFFER_SIZE)?0:g_UACWriteIndex;
  }
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
	/*����ͨ��0����*/	
  if(HAL_DFSDM_FilterRegularMsbStart_DMA(&hdfsdm1_filter0, (int16_t *)Pdm2Pcm_ChannelBuf[0].PCM_Buf, PCM_TWO_SAMPLE_NUM) == HAL_ERROR)
  {
    Error_Handler();
  }
  
  /*����ͨ��1����*/		
//  if(HAL_DFSDM_FilterRegularMsbStart_DMA(&hdfsdm1_filter1, (int16_t *)(Pdm2Pcm_ChannelBuf[1].PCM_Buf+PCM_ONE_SAMPLE_NUM), PCM_ONE_SAMPLE_NUM) == HAL_ERROR)
//  {
//    Error_Handler();
//  }
  
  /*����ͨ��2����*/	
//  if(HAL_DFSDM_FilterRegularMsbStart_DMA(&hdfsdm1_filter2, (int16_t *)(Pdm2Pcm_ChannelBuf[2].PCM_Buf+PCM_ONE_SAMPLE_NUM), PCM_ONE_SAMPLE_NUM) == HAL_ERROR)
//  {
//    Error_Handler();
//  }
  
  /*����ͨ��3����*/	
//  if(HAL_DFSDM_FilterRegularMsbStart_DMA(&hdfsdm1_filter3, (int16_t *)(Pdm2Pcm_ChannelBuf[3].PCM_Buf+PCM_ONE_SAMPLE_NUM), PCM_ONE_SAMPLE_NUM) == HAL_ERROR)
//  {
//    Error_Handler();
//  }
}

#ifdef __cplusplus ///<end extern c
}
#endif
/******************************** End of file *********************************/
