/**
 *  @file I2S_Port.c
 *
 *  @date 2021-01-15
 *
 *  @author aron566
 *
 *  @copyright None.
 *
 *  @brief 
 *
 *  @details 1��
 *
 *  @version V1.0
 */
#ifdef __cplusplus ///<use C compiler
extern "C" {
#endif
/** Includes -----------------------------------------------------------------*/
/* Private includes ----------------------------------------------------------*/
#include "I2S_Port.h"
#include "main.h"
#include "usbd_audio.h"
/** Private typedef ----------------------------------------------------------*/

/** Private macros -----------------------------------------------------------*/
#define ENABLE_I2S_PERIPHERAL   0/**< ѡ���Ƿ�����I2Sģ��*/

/*���ý��ջ����С*/
#if ENABLE_I2S_PERIPHERAL
  #ifdef PCM_ONE_SAMPLE_NUM
    #undef PCM_ONE_SAMPLE_NUM
    #define PCM_ONE_SAMPLE_NUM    MONO_FRAME_SIZE/**< ����PCMת��֡��С*/
    #undef PCM_TWO_SAMPLE_NUM
    #define PCM_TWO_SAMPLE_NUM    (PCM_ONE_SAMPLE_NUM*2)/**< ����PCMת��֡��С*/
  #endif
  #ifdef PDM_ONE_SAMPLE_NUM
  #undef PDM_ONE_SAMPLE_NUM
  #define PDM_ONE_SAMPLE_NUM      (PCM_ONE_SAMPLE_NUM*4)/**< ����PDM����֡��С*/
  #undef PDM_TWO_SAMPLE_NUM
  #define PDM_TWO_SAMPLE_NUM      (PDM_ONE_SAMPLE_NUM*2)/**< ����PDM����֡��С*/
  #endif
#endif
/** Private constants --------------------------------------------------------*/
/** Public variables ---------------------------------------------------------*/
#if ENABLE_I2S_PERIPHERAL
extern I2S_HandleTypeDef hi2s1;
#endif
extern volatile PDM2PCM_BUF_Typedef_t Pdm2Pcm_ChannelBuf[MIC_CHANNEL_NUM];

extern volatile int16_t g_UACRingBuf[UAC_BUFFER_SIZE];
extern volatile uint16_t g_UACWriteIndex;
extern volatile uint16_t g_UACReadIndex;
/** Private variables --------------------------------------------------------*/
/*I2S���ݽ��ձ�־*/
static int16_t *PCM_Data_Ptr[MIC_CHANNEL_NUM]   = {NULL};
static volatile uint32_t I2S_DmaCanRead_Flag  = 0;

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
#if ENABLE_I2S_PERIPHERAL
/**
  ******************************************************************
  * @brief   I2S�뷢������ж�
  * @param   [in]hi2s ���
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2021-01-26
  ******************************************************************
  */
void HAL_I2S_TxHalfCpltCallback(I2S_HandleTypeDef *hi2s) 
{
  UNUSED(hi2s);
}

/**
  ******************************************************************
  * @brief   I2S��������ж�
  * @param   [in]hi2s ���
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2021-01-26
  ******************************************************************
  */
void HAL_I2S_TxCpltCallback(I2S_HandleTypeDef *hi2s) 
{
  UNUSED(hi2s);
}

/**
  ******************************************************************
  * @brief   I2S���������ж�
  * @param   [in]hi2s ���
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2021-01-26
  ******************************************************************
  */
void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s) 
{

}

/**
  ******************************************************************
  * @brief   I2S��������ж�
  * @param   [in]hi2s ���
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2021-01-26
  ******************************************************************
  */
void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s) 
{

}
#endif
/**
  ******************************************************************
  * @brief   I2S�ӿ�����
  * @param   [in]None
  * @return  None
  * @author  aron566
  * @version V1.0
  * @date    2021-01-24
  ******************************************************************
  */
void I2S_Port_Start(void)
{
  if(I2S_DmaCanRead_Flag == 0)
  {
    return;
  }
  
  
  
  I2S_DmaCanRead_Flag = 0;
}

/**
  ******************************************************************
  * @brief   I2S�ӿڳ�ʼ��
  * @param   [in]None
  * @return  None
  * @author  aron566
  * @version V1.0
  * @date    2021-01-24
  ******************************************************************
  */
void I2S_Port_Init(void)
{
#if ENABLE_I2S_PERIPHERAL
  HAL_I2S_Receive_DMA(&hi2s1, (uint16_t *)Pdm2Pcm_ChannelBuf[0].PDM_RX_Buf, PDM_TWO_SAMPLE_NUM);
#endif
}

#ifdef __cplusplus ///<end extern c
}
#endif
/******************************** End of file *********************************/
