/**
 *  @file UART_Port.h
 *
 *  @date 2021-01-04
 *
 *  @author aron566
 *
 *  @brief ���ڲ����ӿ�
 *  
 *  @version V1.0
 */
#ifndef UART_PORT_H
#define UART_PORT_H
#ifdef __cplusplus //use C compiler
extern "C" {
#endif
/** Includes -----------------------------------------------------------------*/
/*��ӿ�*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
/** Private includes ---------------------------------------------------------*/
/*�ⲿ�ӿ�*/
#include "stm32H7xx_hal.h"
#include "usart.h"
#if USE_FREERTOS
#include "cmsis_os.h"
#endif
/*�ڲ��ӿ�*/
#include "CircularQueue.h"

/** Exported defines ----------------------------------------------------------*/
#define USE_FREERTOS 0
/** Exported typedefines -----------------------------------------------------*/
typedef enum
{
    UART_NUM_0 = 0,
    UART_NUM_1,
    UART_NUM_2,
    UART_NUM_3,
    UART_NUM_4,
    UART_NUM_5,
    UART_NUM_6,
}Uart_num_t;

typedef struct
{
    UART_HandleTypeDef *phuart;     //uart�˿�
    DMA_HandleTypeDef  *phdma_rx;
    CQ_handleTypeDef *cb;           //���ζ���
    uint8_t *RX_Buff_Temp;          //���ջ���
    uint16_t MAX_RX_Temp;           //����������
    int Is_Half_Duplex;             //��˫��ģʽ
#if USE_FREERTOS
    osSemaphoreId *pRX_Sem;         //���ն�ֵ�ź���
#endif
}Uart_Dev_Handle_t;
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/

/*���ڲ�����ʼ��*/
void Uart_Port_Init(void);
/*���ڲ��������ȡ*/
Uart_Dev_Handle_t *Uart_Port_Get_Handle(Uart_num_t uart_num);
/*���ڷ�������*/
bool Uart_Port_Transmit_Data(Uart_Dev_Handle_t *uart_opt_handle, uint8_t *data, uint16_t size);
/*���ڽ����жϴ���*/
void USER_UART_IRQHandler(UART_HandleTypeDef *huart);

#ifdef __cplusplus //end extern c
}
#endif
#endif
