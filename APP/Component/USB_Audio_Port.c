/**
 *  @file USB_Audio_Port.c
 *
 *  @date 2021-01-08
 *
 *  @author aron566
 *
 *  @copyright ���пƼ��о�Ժ.
 *
 *  @brief USB��Ƶ�����ӿ�
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
#include "USB_Audio_Port.h"
#include "usbd_audio_if.h"
/** Private typedef ----------------------------------------------------------*/

/** Private macros -----------------------------------------------------------*/

/** Private constants --------------------------------------------------------*/
/** Public variables ---------------------------------------------------------*/

/** Private variables --------------------------------------------------------*/

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

/**
  ******************************************************************
  * @brief   ��Ƶ����豸��ʼ��
  * @param   [in]AudioFreq Ƶ��
  * @param   [in]Volume ���� 
  * @param   [in]options ����
  * @return  USBD_OK ���� USBD_FAILʧ��
  * @author  aron566
  * @version V1.0
  * @date    2020-01-08
  ******************************************************************
  */
int8_t USB_Audio_OutDevice_Init(uint32_t AudioFreq, uint32_t Volume, uint32_t options)
{
  UNUSED(AudioFreq);
  UNUSED(Volume);
  UNUSED(options);
  return USBD_OK;
}

/**
  ******************************************************************
  * @brief   ��Ƶ����豸����ʼ��
  * @param   [in]options ����
  * @return  USBD_OK ���� USBD_FAILʧ��
  * @author  aron566
  * @version V1.0
  * @date    2020-01-08
  ******************************************************************
  */
int8_t USB_Audio_OutDevice_DeInit(uint32_t options)
{
  UNUSED(options);
  return USBD_OK;
}

/**
  ******************************************************************
  * @brief   ��Ƶ����豸���ܿ���
  * @param   [in]pbuf ��������
  * @param   [in]size �������ݴ�С 
  * @param   [in]cmd ����
  * @return  USBD_OK ���� USBD_FAILʧ��
  * @author  aron566
  * @version V1.0
  * @date    2020-01-08
  ******************************************************************
  */
int8_t USB_Audio_OutDevice_Command(uint8_t* pbuf, uint32_t size, uint8_t cmd)
{
//  AUDIO_CMD_START = 1,
//  AUDIO_CMD_PLAY,
//  AUDIO_CMD_STOP,

  UNUSED(pbuf);
  UNUSED(size);
  UNUSED(cmd);
  return USBD_OK;
}

/**
  ******************************************************************
  * @brief   ��Ƶ����豸��������
  * @param   [in]vol 0-100�����ȼ�
  * @return  USBD_OK ���� USBD_FAILʧ��
  * @author  aron566
  * @version V1.0
  * @date    2020-01-08
  ******************************************************************
  */
int8_t USB_Audio_OutDevice_VolumeCtl(uint8_t vol)
{
  UNUSED(vol);
  return USBD_OK;
}

/**
  ******************************************************************
  * @brief   ��Ƶ����豸��������
  * @param   [in]cmd ����
  * @return  USBD_OK ���� USBD_FAILʧ��
  * @author  aron566
  * @version V1.0
  * @date    2020-01-08
  ******************************************************************
  */
int8_t USB_Audio_OutDevice_MuteCtl(uint8_t cmd)
{
  UNUSED(cmd);
  return USBD_OK;
}

/**
  ******************************************************************
  * @brief   ��Ƶ����豸���ڿ��Ʋ���
  * @param   [in]cmd ����
  * @return  USBD_OK ���� USBD_FAILʧ��
  * @author  aron566
  * @version V1.0
  * @date    2020-01-08
  ******************************************************************
  */
int8_t USB_Audio_OutDevice_PeriodicTC(uint8_t *pbuf, uint32_t size, uint8_t cmd)
{
  UNUSED(pbuf);
  UNUSED(size);
  UNUSED(cmd);
  return USBD_OK;
}

/**
  ******************************************************************
  * @brief   ��Ƶ����豸״̬��ȡ
  * @param   [in]cmd ����
  * @return  USBD_OK ���� USBD_FAILʧ��
  * @author  aron566
  * @version V1.0
  * @date    2020-01-08
  ******************************************************************
  */
int8_t USB_Audio_OutDevice_GetState(void)
{
  return USBD_OK;
}

#ifdef __cplusplus ///<end extern c
}
#endif
/******************************** End of file *********************************/
