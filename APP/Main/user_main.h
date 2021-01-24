/**
 *  @file user_mian.h
 *
 *  @date 2021-01-11
 *
 *  @author aron566
 *
 *  @brief ��������
 *  
 *  @version V1.0
 */
#ifndef USER_MAIN_H
#define USER_MAIN_H
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
#include "SAI_Port.h"
#include "PDM_Datacov.h"
#include "UART_Port.h"
#include "I2S_Port.h"
#include "Timer_Port.h"
#include "DFSDM_Port.h"
#include "utilities.h"
#include "USB_Audio_Port.h"
/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/

/*�ж�����������D������*/
void User_InterruptVectorTable_Move(void);
/*��ʼ����ģ�鹦��*/
void User_Main_Task_Init(void);
/*������ѭ��*/
void User_Main_Task_Process_Loop(void);
/*������Ƶ������*/
void User_Main_PlayTask_Process_Loop(void);
/*�洢������Ƶ�豸����*/
void User_Audio_Channel_Data_Save(uint16_t *data, uint32_t len);

#ifdef __cplusplus ///<end extern c
}
#endif
#endif
/******************************** End of file *********************************/
