/**
 *  @file utilities_crc.h
 *
 *  @date 2021-01-06
 *
 *  @author aron566
 *
 *  @brief crc����
 *  
 *  @version V1.0
 */
#ifndef UTILITIES_H
#define UTILITIES_H
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
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/

/*������CRC16*/
uint16_t get_crc(uint8_t *puchMsg, uint16_t usDataLen);
/*������CRC16���Ա����ݰ��е�CRC�����ؽ�������ݰ���crc��������+crc������������ָ��Խ�����*/                                                                              
bool get_crc_result(uint8_t *puchMsg, uint16_t usDataLen);

/*����CRC*/
uint16_t modbus_crc_return(uint8_t *data, uint16_t data_len);
/*�������modbus CRC16*/
uint16_t modbus_crc_return_with_table(uint8_t *data, uint16_t data_len);
/*����CRC16���Ա����ݰ��е�CRC�����ؽ�������ݰ���crc��������+crc������������ָ��Խ�����*/ 
bool modbus_get_crc_result(uint8_t *msg, uint16_t len);

#ifdef __cplusplus ///<end extern c
}
#endif
#endif
/******************************** End of file *********************************/
