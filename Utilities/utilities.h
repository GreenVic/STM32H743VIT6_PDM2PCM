/**
 *  @file utilities.h
 *
 *  @date 2021-01-01
 *
 *  @author aron566
 *
 *  @brief ����
 *  
 *  @version V1.0
 */
#ifndef UTILITIES_H
#define UTILITIES_H
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
#include <time.h>
/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/
typedef enum
{
    CURRENT_TIME = 0,   /**< ��ǰʱ�伴��UTC1970-1-1 0:0:0��ʼ*/
    CURRENT_TIME_MS,    /**< ��ǰʱ�伴��UTC1970-1-1 0:0:0��ʼus/ms/s����*/
    RUN_TIME,           /**< ϵͳ��������ʱ��*/
    PROCESS_CPUTIME,    /**< �����̵���ǰ����ϵͳCPU���ѵ�ʱ��*/
    THREAD_CPUTIME,     /**< ���̵߳���ǰ����ϵͳCPU���ѵ�ʱ��*/
}UTILITIES_TIME_MODE_Typedef_t;

/*��ֵ����*/
typedef enum
{
    INT8 = 0,       
    INT16,
    INT32,
    INT64,
    UINT8,
    UINT16,
    UINT32,
    UINT64,
    FLOAT32,
    DOUBLE,
    STRING,
    VALUE_TYPE_MAX,
}VALUE_Type_t; 
/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/**                                                                             
 * @name ���ù���                                                           
 * @{                                                                           
 */ 
//#define UNUSED(x) (void)(x)/**< ����δʹ�ò�������*/
#define OFFSETOF(struct_type, member)  ((size_t)(&(((struct_type*)0)->member)))/**< ���Աƫ���ֽ�*/
#define GET_ARRAY_SIZE(array)   (sizeof(array)/array[0])/**< ������Ԫ�ظ���*/
#define BYTES_TO_U8ARRAY_INNDEX(at_bytes) (at_bytes-1)/**< �ֽ�תΪ�����е�λ��*/
#define GET_U16_HI_BYTE(data)   ((uint8_t)((data>>8)&0x00FF))/**< ���u16���ݸ��ֽ�*/
#define GET_U16_LOW_BYTE(data)  ((uint8_t)(data&0x00FF))/**< ���u16���ݵ��ֽ�*/
#define GET_U32_HI_HALF_WORD(data)  ((uint16_t)((data>>16)&0xFFFF))/**< ���u32���ݸ߰���*/
#define GET_U32_LOW_HALF_WORD(data)  ((uint16_t)(data&0xFFFF))/**< ���u32���ݵͰ���*/
#define DEBUG_PRINT(str)  printf("%s%s%s%s\n", __FILE__, __FUNCTION__, __LINE__, str)/**< ��ϵ��Դ�ӡ*/
#define SaturaLH(N, L, H) (((N)<(L))?(L):(((N)>(H))?(H):(N)))
#define HTONS(A)  ((((uint16_t)(A) & 0xff00) >> 8) | \
                   (((uint16_t)(A) & 0x00ff) << 8))
/** @}*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/
/*���Դ�ӡ*/
void debug_print(uint8_t *msg, uint32_t msg_len);

/*us����ʱ*/
void delay_xus(uint32_t nTime);

/*��ȫ�ַ�������*/
char *strncopy(char *dest_str, const char *src_str, size_t size);

/*��ȡ��ֵ��Ӧ���ַ���*/
char *get_value_str(char *dest_str, void *data, size_t size, VALUE_Type_t value_type);

/*��ȡʱ��*/
uint64_t get_current_time_s(UTILITIES_TIME_MODE_Typedef_t mode);

/*��תΪʱ���ַ���*/
const char *get_time_str(time_t sec);

/*16�����ַ�תΪ��ֵ*/
uint8_t hex_char_to_value(uint8_t ch);

/*16��������ת�ַ���*/
void hex_to_str(char *strbuf, uint8_t *hex_data, uint32_t len);

/*����д��ĸת����Сд��ĸ*/
uint8_t ch_tolower(uint8_t ch);

/*16���Ƶ��ַ���ת��������*/
int hextoi(char s[]);

/*����ָ���ַ�*/
int common_filter_special_char(char ch, const char *str, char *out_str, int size);

/*����32λ����-��λ��ǰ*/
uint32_t common_get_u32_data(uint8_t *data, int start_index);

/*����16λ����-��λ��ǰ*/
uint16_t common_get_u16_data(uint8_t *data, int start_index);

/*��������������-��λ��ǰ*/
float common_get_float_data(uint8_t *data, int start_index);

/*����32λ����-��λ��ǰ*/
uint32_t common_get_modbus_u32_data(uint8_t *data, int start_index);

/*����16λ����-��λ��ǰ*/
uint16_t common_get_modbus_u16_data(uint8_t *data, int start_index);

/*��������������-��λ��ǰ*/
float common_get_modbus_float_data(uint8_t *data, int start_index);

#ifdef __cplusplus ///<end extern c
}
#endif
#endif
/******************************** End of file *********************************/
