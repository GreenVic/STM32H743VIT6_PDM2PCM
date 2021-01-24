/**
 *  @file USB_Audio_Port.h
 *
 *  @date 2021-01-01
 *
 *  @author aron566
 *
 *  @brief USB��Ƶ�����ӿ�
 *  
 *  @version V1.0
 */
#ifndef USB_AUDIO_PORT_H
#define USB_AUDIO_PORT_H
#ifdef __cplusplus ///<use C compiler
extern "C" {
#endif
/** Includes -----------------------------------------------------------------*/
#include <stdint.h> /**< need definition of uint8_t */
#include <stddef.h> /**< need definition of NULL    */
#include <stdbool.h>/**< need definition of BOOL    */
#include <stdio.h>  /**< if need printf             */
#include <stdlib.h>
#include <string.h>
#include <limits.h> /**< need variable max value    */
/** Private includes ---------------------------------------------------------*/
#include "main.h"
/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/* Audio status definition */     
#define AUDIO_OK                        0
#define AUDIO_ERROR                     1
#define AUDIO_TIMEOUT                   2


#define AUDIOFREQ_48K                ((uint32_t)48000)
#define AUDIOFREQ_32K                ((uint32_t)32000)
#define AUDIOFREQ_16K                ((uint32_t)16000)
#define AUDIOFREQ_8K                 ((uint32_t)8000)


/* Those defines are used to allocate the right amount of RAM depending on the
   maximum number of microphone and  sampling frequency desired */
#define MAX_AUDIO_IN_FREQ             AUDIOFREQ_16K
#define MAX_AUDIO_IN_CHANNEL_NBR      2 
#define DECIMATION_FACTOR             64    

/*BSP internal buffer size in half words (16 bits)*/
#define PDM_INTERNAL_BUFFER_SIZE      MAX_AUDIO_IN_FREQ / 1000 * DECIMATION_FACTOR * 2 / 8

/** Exported variables -------------------------------------------------------*/

/** Exported functions prototypes --------------------------------------------*/

/*��ƵUSB��ʼ��*/
void USB_Audio_Port_Init(void);
/*��Ƶ����豸��ʼ��*/
int8_t USB_Audio_OutDevice_Init(uint32_t AudioFreq, uint32_t Volume, uint32_t options);
/*��Ƶ����豸����ʼ��*/
int8_t USB_Audio_OutDevice_DeInit(uint32_t options);
/*��Ƶ����豸���ܿ���*/
int8_t USB_Audio_OutDevice_Command(uint8_t* pbuf, uint32_t size, uint8_t cmd);
/*��Ƶ����豸��������*/
int8_t USB_Audio_OutDevice_VolumeCtl(uint8_t vol);
/*��Ƶ����豸��������*/
int8_t USB_Audio_OutDevice_MuteCtl(uint8_t cmd);
/*��Ƶ����豸���ڿ��Ʋ���*/
int8_t USB_Audio_OutDevice_PeriodicTC(uint8_t *pbuf, uint32_t size, uint8_t cmd);
/*��Ƶ����豸״̬��ȡ*/
int8_t USB_Audio_OutDevice_GetState(void);


uint8_t USB_Audio_IN_Init(uint32_t AudioFreq, uint32_t BitRes, uint32_t ChnlNbr);
uint8_t USB_Audio_IN_Record(uint16_t* pbuf, uint32_t size);
uint8_t USB_Audio_IN_Stop(void);
uint8_t USB_Audio_IN_Pause(void);
uint8_t USB_Audio_IN_Resume(void);
uint8_t USB_Audio_IN_SetVolume(uint8_t Volume);
uint8_t USB_Audio_IN_PDMToPCM(uint16_t *PDMBuf, uint16_t *PCMBuf);

/*�жϻص�*/
void USB_Audio_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s);
void USB_Audio_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s);
void USB_Audio_I2S_ErrorCallback(I2S_HandleTypeDef *hi2s);

void USB_Audio_IN_TransferComplete_CallBack(void);
void USB_Audio_IN_HalfTransfer_CallBack(void);
void USB_Audio_IN_Error_Callback(void);

#ifdef __cplusplus ///<end extern c
}
#endif
#endif
/******************************** End of file *********************************/
