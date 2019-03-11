/********************************************************************/
/* Author  : Islam A.			                                    */
/* Date    : 10 MAR 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Header file for using LCD private values used inside driver		*/
/********************************************************************/

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


/*Private macros for the probable LCD mode							*/
#define  LCD_u8_4BIT_MODE    (u8)0
#define  LCD_u8_8BIT_MODE    (u8)1

/*Macro for the number of rows and column of the LCD 				*/
#define LCD_u8_ROW_NO       (u8)2
#define LCD_u8_COLUMN_NO    (u8)16

/*Macros for whole needed commands for the LCD 						*/
#define LCD_u8_FUNCTION_SET_8BIT_1LINE        (u8)0x30
#define LCD_u8_FUNCTION_SET_8BIT_2LINES       (u8)0x38
#define LCD_u8_FUNCTION_SET_4BIT_1LINE	 	  (u8)0x20
#define LCD_u8_FUNCTION_SET_4BIT_2LINES	  	  (u8)0x28
#define LCD_u8_4BIT_INIT_SEQUENCE1		  (u8)0x33
#define LCD_u8_4BIT_INIT_SEQUENCE2		  (u8)0x32
#define LCD_u8_ENTRY_MODE				  (u8)0x06
#define LCD_u8_CLEAR                     (u8)0x01
#define LCD_u8_DISPLAY_OFF_CURSOR_OFF	  (u8)0x08
#define LCD_u8_DISPLAY_ON_CURSOR_ON 	  (u8)0x0E
#define LCD_u8_DISPLAY_ON_CURSOR_OFF	  (u8)0x0C
#define LCD_u8_SHIFT_RIGHT				  (u8)0x1C
#define LCD_u8_SHIFT_LEFT				  (u8)0x18
#define LCD_u8_RETURN_HOME               (u8)0x02
#define LCD_u8_SET_CGRAM_ADDRESS         (u8)0x40
#define LCD_u8_SET_DDRAM_ADDRESS         (u8)0x80

/*Macro to set the size of the single character in the LCD 			*/
#define LCD_u8_CHARACTER_SIZE    (u8)8
#define LCD_u8_MAX_SYMBOL        (u8)8

/*Macro of the address of the 1st character in the second row		*/
#define LCD_u8_2ND_ROW            (u8)0x40
#define LCD_u8_LINE1_END          (u8)0x90
#define LCD_u8_LINE2_START        (u8)0xC0
#define LCD_u8_LINE2_END          (u8)0xD0


/********************************************************************/
/* Name	 :	private_u8Write											*/
/* Description: Private function needed to send Data/Command to		*/
/* 				the LCD												*/
/* Inputs: The data or the command needed to be sent				*/
/* Output: Error state												*/
/********************************************************************/
static u8 private_u8Write (u8 copy_u8Data);


/********************************************************************/
/* Name  : private_u8WriteCommand									*/
/* Description: Function needed to send Command to the LCD			*/
/* Inputs: The command needed to be sent							*/
/* Output: Error state												*/
/********************************************************************/
static u8 private_u8WriteCommand (u8 copy_u8Command);


/********************************************************************/
/* Name  : private_u8WriteData										*/
/* Description: Function needed to send Data to the LCD				*/
/* Inputs: The data needed to be sent Data as a string				*/
/* Output: Error state												*/
/********************************************************************/
static u8 private_u8WriteData (u8 copy_u8Data);


#endif /* LCD_PRIVATE_H_ */
