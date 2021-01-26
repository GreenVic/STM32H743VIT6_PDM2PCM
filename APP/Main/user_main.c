/**
 *  @file user_main.c
 *
 *  @date 2021-01-11
 *
 *  @author aron566
 *
 *  @copyright ���пƼ��о�Ժ.
 *
 *  @brief ��������
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
#include "user_main.h"
#include "main.h"

/** Private typedef ----------------------------------------------------------*/

/** Private macros -----------------------------------------------------------*/
/*�ж���Ƶ�����Ƿ�С����С���������*/
#define AUDIO_DATA_SIZE_MIN   STEREO_FRAME_SIZE//MONO_FRAME_SIZE
#define AUDIO_DATA_SIZE_IS_LESS_AUDIO_DATA_MIN(size)  ((size < AUDIO_DATA_SIZE_MIN)? \
                                                      1:0)
/*�������������鸴�Ƶ�������������*/
#define INT16_ARRAY2FLOAT32(float_buf, i16_buf, size) do{ \
                                                          for(uint16_t index = 0; index < size; index++) \
                                                          { \
                                                            float_buf[index] = (float)i16_buf[index]; \
                                                          }}while(0)
/*�����ݸ��Ƴ�˫�ݵ�������*/
#define INT16_ARRAY_CROSS_JOIN(cross_buf, source_buf, cross_size) \
                                                      do{ \
                                                          uint16_t cnt = 0; \
                                                          for(uint16_t index = 0; index < cross_size; index +=2) \
                                                          { \
                                                            cross_buf[index+1] = cross_buf[index] = source_buf[cnt++]; \
                                                          }}while(0)
                                                          
/** Private constants --------------------------------------------------------*/
/** Public variables ---------------------------------------------------------*/
/** Private variables --------------------------------------------------------*/
static int16_t audiodatainputbuf[STEREO_FRAME_SIZE] = {0};
static int16_t audiodataoutputbuf[STEREO_FRAME_SIZE] = {0};
static int16_t OneChannel_Data[MONO_FRAME_SIZE] = {0};
/*�㷨����Դ���ݻ�����*/
static float Algorithm_Source_Data[MONO_FRAME_SIZE] = {0};

static int16_t Algorithm_Result_Data[MONO_FRAME_SIZE] = {0};

/** Private function prototypes ----------------------------------------------*/
static void Algorithm_Process_Start(void);/**< �㷨����������*/
static void Algorithm_Function_Select(int16_t *source_data);
/** Private user code --------------------------------------------------------*/

/** Private application code -------------------------------------------------*/
/*******************************************************************************
*
*       Static code
*
********************************************************************************
*/

/**
  ******************************************************************
  * @brief   �㷨����ѡ��
  * @param   [in]source_data ԭʼ�ɼ�����
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2020-01-11
  ******************************************************************
  */
static void Algorithm_Function_Select(int16_t *source_data)
{
//  switch(g_Algorithm_Func_Select)
//  {
//    case RNN_NOISE_FUNC:
//      Algorithm_RNN(source_data, Algorithm_Result_Data);
//      break;
//    case MASK_EMD_FUNC:
//      Algorithm_MASK_EMD(Algorithm_Source_Data, Algorithm_Result_Data);
//      break;
//    case MASK_EMD_WDRC_FUNC:
//      Algorithm_MASK_EMD_WDRC(Algorithm_Source_Data, Algorithm_Result_Data);
//      break;
//    case VOL_FUNC:
//      Algorithm_VOL(source_data, Algorithm_Result_Data);
//      break;
//    case AGC_FUNC:
//      Algorithm_AGC(source_data, Algorithm_Result_Data);
//      break;
//    case FUNCTON_MAX:
//      {
//        Algorithm_RNN(source_data, Algorithm_Result_Data);
//        
//        INT16_ARRAY2FLOAT32(Algorithm_Source_Data, Algorithm_Result_Data, MONO_FRAME_SIZE);
//        
//        Algorithm_MASK_EMD_WDRC(Algorithm_Source_Data, Algorithm_Result_Data);
//        Algorithm_VOL(Algorithm_Result_Data, Algorithm_Result_Data);
//        Algorithm_AGC(Algorithm_Result_Data, Algorithm_Result_Data);
//      }
//      break;
//    default:
//      break;
//  }
//  
//  INT16_ARRAY_CROSS_JOIN(audiodataoutputbuf, Algorithm_Result_Data, STEREO_FRAME_SIZE);

//  Sai_Port_Send_Data((uint8_t *)audiodataoutputbuf, STEREO_FRAME_SIZE);
  
  /*����USB��Ƶ����*/
//  for(int i = 0; i < MONO_FRAME_SIZE; i++)
//  {
//    g_UACRingBuf[g_UACWriteIndex] = source_data[i];
//    g_UACWriteIndex++;
//    if(g_UACWriteIndex >= UAC_BUFFER_SIZE)
//    {
//      g_UACWriteIndex = 0;
//    }
//    
//    g_UACRingBuf[g_UACWriteIndex] = Algorithm_Result_Data[i];
//    g_UACWriteIndex++;

//    if(g_UACWriteIndex >= UAC_BUFFER_SIZE)
//    {
//      g_UACWriteIndex = 0;
//    }
//  }
}

static void Algorithm_Old_Process_Start(void)
{
//  extern volatile uint8_t SAI_Transmit_Complete_Flag;
//  extern volatile uint8_t SAI_Receive_Complete_Flag;
//  extern volatile uint8_t SAI_Can_Send_Data_Flag;
//  extern volatile uint16_t SAI_RX_Buf_0[STEREO_FRAME_SIZE];
//  extern volatile uint16_t SAI_RX_Buf_1[STEREO_FRAME_SIZE];
//  if(SAI_Can_Send_Data_Flag == 1)
//  {
//    SAI_Can_Send_Data_Flag = 0;
//    
//    /*����RXx*/
//    if(SAI_Receive_Complete_Flag == 0)
//    {
//      memcpy((void *)audiodatainputbuf, (void *)SAI_RX_Buf_0, sizeof(int16_t)*STEREO_FRAME_SIZE);
//    }
//    if(SAI_Receive_Complete_Flag == 1)
//    {
//      memcpy((void *)audiodatainputbuf, (void *)SAI_RX_Buf_1, sizeof(int16_t)*STEREO_FRAME_SIZE);
//    }
//    
//    /*����ͨ�����ݣ�L-R-L-R-L-R......*/
//    for(int i = 0; i < MONO_FRAME_SIZE; i++)
//    {
//      OneChannel_Data[i] = audiodatainputbuf[i*2];
//      Algorithm_Source_Data[i] = (float)audiodatainputbuf[i*2];
//  //    temp_data_right[i] = temp_buf[i*2+1];
//    }    
 
//    switch(g_Algorithm_Func_Select)
//    {
//      case RNN_NOISE_FUNC:
//        Algorithm_RNN(OneChannel_Data, Algorithm_Result_Data);
//        break;
//      case MASK_EMD_FUNC:
//        Algorithm_MASK_EMD(Algorithm_Source_Data, Algorithm_Result_Data);
//        break;
//      case MASK_EMD_WDRC_FUNC:
//        Algorithm_MASK_EMD_WDRC(Algorithm_Source_Data, Algorithm_Result_Data);
//        break;
//      case VOL_FUNC:
//        Algorithm_VOL(OneChannel_Data, Algorithm_Result_Data);
//        break;
//      case AGC_FUNC:
//        Algorithm_AGC(OneChannel_Data, Algorithm_Result_Data);
//        break;
//      case FUNCTON_MAX:
//        {
//          Algorithm_RNN(OneChannel_Data, Algorithm_Result_Data);
//          
//          INT16_ARRAY2FLOAT32(Algorithm_Source_Data, Algorithm_Result_Data, MONO_FRAME_SIZE);
//          
//          Algorithm_MASK_EMD_WDRC(Algorithm_Source_Data, Algorithm_Result_Data);
//          Algorithm_VOL(Algorithm_Result_Data, Algorithm_Result_Data);
//          Algorithm_AGC(Algorithm_Result_Data, Algorithm_Result_Data);
//        }
//        break;
//      default:
//        break;
//    }

//    INT16_ARRAY_CROSS_JOIN(audiodataoutputbuf, Algorithm_Result_Data, STEREO_FRAME_SIZE);

//    if(SAI_Transmit_Complete_Flag == 0)
//    {
//      memcpy((void *)SAI_TX_Buf_0, (void *)audiodataoutputbuf, sizeof(int16_t)*STEREO_FRAME_SIZE);
//    }
//    else if(SAI_Transmit_Complete_Flag == 1)
//    {
//      memcpy((void *)SAI_TX_Buf_1, (void *)audiodataoutputbuf, sizeof(int16_t)*STEREO_FRAME_SIZE);
//    }	
//  }
}

/** Public application code --------------------------------------------------*/
/*******************************************************************************
*
*       Public code
*
********************************************************************************
*/

/**
  ******************************************************************
  * @brief   ������Ƶ������
  * @param   [in]None
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2020-01-14
  ******************************************************************
  */
void User_Main_PlayTask_Process_Loop(void)
{
//  extern volatile uint8_t SAI_Can_Read_Data_Flag;
//  if(SAI_Can_Read_Data_Flag == 0)
//  {
//    return;
//  }
//  
//  SAI_Can_Read_Data_Flag = 0;

//  /*ת��PDM����*/
//  extern PDM2PCM_BUF_Typedef_t Pdm2Pcm_ChannelBuf[MIC_CHANNEL_NUM];
//  
//  uint16_t *p_PDM_Data = (SAI_Receive_Complete_Flag == 0)?Pdm2Pcm_ChannelBuf[0].PDM_RX_Buf:Pdm2Pcm_ChannelBuf[0].PDM_RX_Buf+64;
//  
//  /*����*/
//  /*����USB��Ƶ����*/
//  #include "usbd_audio.h"
//  extern volatile int16_t g_UACRingBuf[UAC_BUFFER_SIZE];
//  extern volatile uint16_t g_UACWriteIndex;
//  extern volatile uint16_t g_UACReadIndex;
//  
//  /*ǰ�÷���ͨ�����ݣ�L8bit-R8bit-L8bit-R8bit-L8-R8......MSB��ʽȡ��λ�ֽ�ͨ��*/
//  for(int i = 0; i < 64; i++)
//  {
//    Pdm2Pcm_ChannelBuf[0].PDM_One_Sample_Buf[i] = p_PDM_Data[i*2] & 0xFF;
//    Pdm2Pcm_ChannelBuf[0].PDM_One_Sample_Buf[i] |= (uint16_t)((p_PDM_Data[i*2+1] & 0xFF)<<8);
//    
////    Pdm2Pcm_ChannelBuf[0].PDM_One_Sample_Buf[i] |= p_PDM_Data[i*2] & 0xFF;
////    Pdm2Pcm_ChannelBuf[0].PDM_One_Sample_Buf[i] <<= 8;
////    Pdm2Pcm_ChannelBuf[0].PDM_One_Sample_Buf[i] += (uint16_t)(p_PDM_Data[i*2+1] & 0xFF);/*MSB*/
//  }
//  PDM_To_PCM_Stream(Pdm2Pcm_ChannelBuf[0].PDM_One_Sample_Buf, (uint16_t *)Pdm2Pcm_ChannelBuf[0].PCM_One_Sample_Buf);
//  
//  /*���÷���ͨ������*/
////  PDM_To_PCM_Stream(p_PDM_Data, (uint16_t *)Pdm2Pcm_ChannelBuf[0].PCM_Buf);
//    /*˫ͨ��PCM���ݷ���*/
////  for(int i = 0; i < PCM_ONE_SAMPLE_NUM; i++)
////  {
////    Pdm2Pcm_ChannelBuf[0].PCM_One_Sample_Buf[i] = Pdm2Pcm_ChannelBuf[0].PCM_Buf[i*2];
////  }
//  
//  for(int i = 0; i < PCM_ONE_SAMPLE_NUM; i++)
//  {
//    g_UACRingBuf[g_UACWriteIndex] = Pdm2Pcm_ChannelBuf[0].PCM_One_Sample_Buf[i];
//    g_UACWriteIndex++;
//    if(g_UACWriteIndex >= UAC_BUFFER_SIZE)
//    {
//      g_UACWriteIndex = 0;
//    }

//    g_UACRingBuf[g_UACWriteIndex] = Pdm2Pcm_ChannelBuf[0].PCM_One_Sample_Buf[i];
//    g_UACWriteIndex++;

//    if(g_UACWriteIndex >= UAC_BUFFER_SIZE)
//    {
//      g_UACWriteIndex = 0;
//    }
//  }
  /*never return*/
}

/**
  ******************************************************************
  * @brief   ������
  * @param   [in]None
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2020-01-11
  ******************************************************************
  */
void User_Main_Task_Process_Loop(void)
{
  for(;;)
  {
//    Algorithm_Old_Process_Start();
    
//    User_Main_PlayTask_Process_Loop();
    DFSDM_Port_Start();
  }
  /*never return*/
}

/**
  ******************************************************************
  * @brief   ��ʼ����ģ�鹦��
  * @param   [in]None
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2020-01-11
  ******************************************************************
  */
void User_Main_Task_Init(void)
{
  /*���ڲ�����ʼ��*/
  Uart_Port_Init();

  /*��ʱ����ʼ��*/
//  Timer_Port_Init();
  
  /*Sai������ʼ��*/
//  Sai_Port_Init();
  
  /*DFSDM��ʼ��*/
  DFSDM_Port_Init();
  
  /*USB��ʼ��*/
  UAC_Init();
  
  /*I2S��ʼ��*/
//  I2S_Port_Init();
  /*other initialization task code*/
}

/**
  ******************************************************************
  * @brief   �ж�����������D������
  * @param   [in]None
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2020-01-18
  ******************************************************************
  */
void User_InterruptVectorTable_Move(void)
{
  uint32_t *SouceAddr = (uint32_t *)FLASH_BANK1_BASE;
  uint32_t *DestAddr = (uint32_t *)D1_DTCMRAM_BASE;
  memcpy(DestAddr, SouceAddr, 0x400);
  /* �����ж������� DTCM ����*/
  SCB->VTOR = D1_DTCMRAM_BASE;
}

#ifdef __cplusplus ///<end extern c
}
#endif
/******************************** End of file *********************************/
