/********************************************************************/
/* Author  : Islam A.			                                    */
/* Date    : 10 MAR 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Header file for using LCD configuration 							*/
/********************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/********************************************************************/
/* Macro for setting the LCD mode									*/
/* Range:															*/
/*      LCD_u8_4BIT_MODE											*/
/*      LCD_u8_8BIT_MODE											*/
/********************************************************************/
#define LCD_u8_MODE					LCD_u8_8BIT_MODE

/********************************************************************/
/* Macro for setting the Initialized function set of LCD			*/
/* Range:															*/
/*      LCD_u8_FUNCTION_SET_8BIT_1LINE								*/
/*      LCD_u8_FUNCTION_SET_8BIT_2LINE								*/
/*      LCD_u8_FUNCTION_SET_4BIT_1LINE								*/
/*      LCD_u8_FUNCTION_SET_4BIT_2LINE								*/
/********************************************************************/
#define LCD_u8_INIT_FUNCTION_SET	LCD_u8_FUNCTION_SET_8BIT_2LINES

/********************************************************************/
/* Macro for setting LCD Display ON/OFF and Cursor mode				*/
/* Range:															*/
/*      LCD_u8_DISPLAY_OFF_CURSOR_OFF								*/
/*      LCD_u8_DISPLAY_ON_CURSOR_ON									*/
/* 		LCD_u8_DISPLAY_ON_CURSOR_OFF								*/
/********************************************************************/
#define LCD_u8_INIT_DISPLAY_CONTROL          LCD_u8_DISPLAY_ON_CURSOR_ON


/*Defining the pins of the LCD control pins							*/
#define LCD_u8_RS_PIN			DIO_u8_PIN8
#define LCD_u8_RW_PIN			DIO_u8_PIN9
#define LCD_u8_E_PIN			DIO_u8_PIN10

/*Defining the pins of the LCD data pins							*/
#define LCD_u8_D0_PIN			DIO_u8_PIN0
#define LCD_u8_D1_PIN			DIO_u8_PIN1
#define LCD_u8_D2_PIN			DIO_u8_PIN2
#define LCD_u8_D3_PIN			DIO_u8_PIN3
#define LCD_u8_D4_PIN			DIO_u8_PIN4
#define LCD_u8_D5_PIN			DIO_u8_PIN5
#define LCD_u8_D6_PIN			DIO_u8_PIN6
#define LCD_u8_D7_PIN			DIO_u8_PIN7

#endif /* LCD_CONFIG_H_ */
