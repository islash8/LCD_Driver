/************************************************************************************/
/* Author  : Islam A.                                                               */
/* Date    : 08 FEB 2019                                                            */
/* Version : V01                                                                    */
/************************************************************************************/
/* Description                                                                      */
/* ------------                                                                     */
/*  This is the application file, where you can write a simple application to test  */
/*  the functionality of DIO														*/
/************************************************************************************/
#include "STD_Types.h"
#include "Lib_Delay.h"
#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"

void main(void)
{
   RCC_vInit();
   RCC_vEnablePeripheralClock (RCC_u8_IOPA);
   RCC_vEnablePeripheralClock (RCC_u8_IOPC);
   DIO_u8SetPinDirection (DIO_u8_PIN0,DIO_u8_OUTPUT_2M_PP);
   DIO_u8SetPinDirection (DIO_u8_PIN32,DIO_u8_OUTPUT_2M_PP);
   LCD_vInit();
  while (1)
  {
	LCD_u8WriteData("islam", 0, 0);
  }

}
