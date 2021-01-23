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
#include <stdint.h> /**< nedd definition of uint8_t */
#include <stddef.h> /**< need definition of NULL    */
#include <stdbool.h>/**< need definition of BOOL    */
#include <stdio.h>  /**< if need printf             */
#include <stdlib.h>
#include <string.h>
#include <limits.h> /**< need variable max value    */
/** Private includes ---------------------------------------------------------*/

/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
//#define DSCP_BUFFER_SIZE             64
//#define DSCP_DATA_BYTE               2
//#define EP1_MAX_PKT_SIZE             ((DSCP_BUFFER_SIZE*2)+30)
//#define UAC_BUFFER_SIZE              DSCP_BUFFER_SIZE*20
//#define UAC_BUFFER_HIGH_THRESHOLD    DSCP_BUFFER_SIZE*15
//#define UAC_BUFFER_LOW_THRESHOLD     DSCP_BUFFER_SIZE*5

///*USB����*/

//#define AUDIO_IN_PACKET              1536

//#define IN_PACKET_NUM                2
//#define TOTAL_IN_BUF_SIZE            ((uint32_t)(AUDIO_IN_PACKET * IN_PACKET_NUM))
//    
//#define AUDIO_TOTAL_BUF_SIZE         TOTAL_IN_BUF_SIZE * 3
/** Exported variables -------------------------------------------------------*/
//extern volatile int16_t g_UACRingBuf[UAC_BUFFER_SIZE];
//extern volatile uint16_t g_UACWriteIndex;
//extern volatile uint16_t g_UACReadIndex;
/** Exported functions prototypes --------------------------------------------*/

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

#ifdef __cplusplus ///<end extern c
}
#endif
#endif
/******************************** End of file *********************************/
