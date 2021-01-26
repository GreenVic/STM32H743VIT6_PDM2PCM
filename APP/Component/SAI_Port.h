/**
 *  @file SAI_Port.h
 *
 *  @date 2021-01-01
 *
 *  @author aron566
 *
 *  @brief sai�����ӿ�-MIC
 *  
 *  @version V1.0
 */
#ifndef SAI_PORT_H
#define SAI_PORT_H
#ifdef __cplusplus ///<use C compiler
extern "C" {
#endif
/** Includes -----------------------------------------------------------------*/
#include <stdint.h> /**< nedd definition of uint8_t */
#include <stddef.h> /**< need definition of NULL    */
#include <stdbool.h>/**< need definition of BOOL    */
#include <stdio.h>  /**< if need printf             */
#include <stdlib.h>
#include <string.h>
#include <limits.h> /**< need variable max value    */
/** Private includes ---------------------------------------------------------*/
#include "main.h"
/** Private defines ----------------------------------------------------------*/
#define MIC_CHANNEL_NUM     (8/2U)                /**< ͨ������*/
#define MONO_FRAME_SIZE     (160)                 /**< ������֡��С*/
#define STEREO_FRAME_SIZE   (MONO_FRAME_SIZE*2)   /**< ������֡��С*/
#define PCM_ONE_SAMPLE_NUM  STEREO_FRAME_SIZE     /**< ����PCMת��֡��С*/
#define PCM_TWO_SAMPLE_NUM  (PCM_ONE_SAMPLE_NUM*2)/**< ����PCMת��֡��С*/
#define PDM_ONE_SAMPLE_NUM  (PCM_ONE_SAMPLE_NUM*4)/**< ����PDM����֡��С*/
#define PDM_TWO_SAMPLE_NUM  (PDM_ONE_SAMPLE_NUM*2)/**< ����PDM����֡��С*/

/** Exported typedefines -----------------------------------------------------*/
/*PDMתPCM���ݽṹ*/
typedef struct
{
  uint16_t PDM_RX_Buf[PDM_TWO_SAMPLE_NUM*2];/**< ˫������*/
  uint16_t PDM_One_Sample_Buf[PDM_ONE_SAMPLE_NUM];/**< ����ͨ������*/
  int16_t  PCM_Buf[PCM_TWO_SAMPLE_NUM];
  int16_t  PCM_One_Sample_Buf[PCM_ONE_SAMPLE_NUM];
}PDM2PCM_BUF_Typedef_t;
/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/* Flag���� */
extern volatile uint8_t SAI_Transmit_Complete_Flag;
extern volatile uint8_t SAI_Receive_Complete_Flag;
extern volatile uint8_t SAI_Can_Send_Data_Flag;
/** Exported functions prototypes --------------------------------------------*/

/*SAI������ʼ��*/
void Sai_Port_Init(void);
/*SAI���ݷ���*/
void Sai_Port_Send_Data(uint8_t *data, uint16_t size);
/*SAI˫���巢��*/
HAL_StatusTypeDef HAL_SAI_MultiMemTransmit_DMA(SAI_HandleTypeDef *hsai, uint8_t *pData, uint8_t *SecondMemAddress, uint16_t Size);
/*SAI˫�������*/
HAL_StatusTypeDef HAL_SAI_MultiMemReceive_DMA(SAI_HandleTypeDef *hsai, uint8_t *pData, uint8_t *SecondMemAddress, uint16_t Size);

void Sai_ADC_Data_LoopBack(void);

#ifdef __cplusplus ///<end extern c
}
#endif
#endif
/******************************** End of file *********************************/
