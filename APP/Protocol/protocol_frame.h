/**
 *  @file protocol_frame.h
 *
 *  @date 2021-01-01
 *
 *  @author zgl
 *
 *  @brief ͨѶЭ�鱨�Ľ���
 *  
 *  @version V1.0
 */
#ifndef __PROTOCOL_FRAME_H
#define __PROTOCOL_FRAME_H
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
#include "agc.h"
#include "wdrc_emd.h"
/** Private defines ----------------------------------------------------------*/
/** Exported typedefines -----------------------------------------------------*/
/*�㷨����*/
typedef struct
{
    int* vol;
    int* eq;
    WDRC_PAR_Typedef_t* wdr;
    AGC_PAR_Typedef_t* agc;
    int* level;
}ALGORITHM_PAR_Typedef_t;

/*�㷨���ܷ���*/
typedef enum
{
  RNN_NOISE_FUNC     = 0x01,
  MASK_EMD_FUNC      = 0x02,
  MASK_EMD_WDRC_FUNC = 0x03,
  VOL_FUNC           = 0x04,
  AGC_FUNC           = 0x05,
  FUNCTON_MAX        = 0x06,
}ALGORIYHM_FUNCTION_Typdef_t;

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
extern ALGORITHM_PAR_Typedef_t g_Algorithm_Par;/**< �㷨����*/
extern ALGORIYHM_FUNCTION_Typdef_t g_Algorithm_Func_Select;/**< �㷨ѡ��*/
/** Exported functions prototypes --------------------------------------------*/

/*Э��ջ��ʼ��*/
void Protocol_Stack_Init(void);
/*����Э��ջ*/
void Protocol_Stack_Start(void);

#ifdef __cplusplus ///<end extern c
}
#endif
#endif
/******************************** End of file *********************************/
