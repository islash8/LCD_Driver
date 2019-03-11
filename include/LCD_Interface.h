/********************************************************************/
/* Author  : Islam A.			                                    */
/* Date    : 08 MAR 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Header file for using LCD interfaces 							*/
/********************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/********************************************************************/
/* Name			: LCD_vInit.			                            */
/* Description  : API to that has the initialization sequence for   */
/*				  character LCD.									*/
/* Inputs		: NONE                                              */
/* Outputs      : NONE												*/
/********************************************************************/
void LCD_vInit(void);

/********************************************************************/
/* Name			: LCD_u8Clear			                            */
/* Description  : API to that clears character LCD.					*/
/* Inputs		: NONE                                              */
/* Outputs      : Error state										*/
/********************************************************************/
u8 LCD_vClear(void);

/********************************************************************/
/* Name			: LCD_u8ShiftLeft			                        */
/* Description  : API to that shifts cursor to left on character LCD*/
/* Inputs		: NONE                                              */
/* Outputs      : ErrorState										*/
/********************************************************************/
u8 LCD_ShiftLeft(void);

/********************************************************************/
/* Name			: LCD_u8ShiftRight   		                        */
/* Description  : API to that shifts cursor to right on character   */
/*				  LCD												*/
/* Inputs		: NONE                                              */
/* Outputs      : ErrorState										*/
/********************************************************************/
u8 LCD_ShiftRight(void);


/********************************************************************/
/* Name			: LCD_u8WriteData			                        */
/* Description  : API to that writes a string on LCD 	            */
/* Inputs		: Data that is going to be written (copy_Pu8Data)   */
/*				  X position on LCD (copy_u8Xpos)					*/
/*				  Y position on LCD (copy_u8Ypos)					*/
/* Outputs      : ErrorState										*/
/********************************************************************/
u8 LCD_u8WriteData(u8 * copy_Pu8Data, u8 copy_u8Xpos, u8 copy_u8Ypos);

/********************************************************************/
/* Name			: LCD_u8SavePattern			                        */
/* Description  : API to that saves a custom pattern in CGRAM       */
/* Inputs		: An array of patterns that needs to be saved		*/
/*				  (Au8_SymbolPattern[][8])							*/
/*				  Word size that needs to be saved (copy_u8WordSize)*/
/* Outputs      : ErrorState										*/
/********************************************************************/
u8 LCD_u8SavePattern(u8 Au8_SymbolPattern[][8], u8 copy_u8WordSize);

/********************************************************************/
/* Name			: LCD_u8WriteSpecialSymbol	                        */
/* Description  : API to that writes a pattern symbol on LCD 	    */
/* Inputs		: Index of data that is going to be written 		*/
/*                (copy_u8SymbolIndex)   							*/
/*				  X position on LCD (copy_u8Xpos)					*/
/*				  Y position on LCD (copy_u8Ypos)					*/
/* Outputs      : ErrorState										*/
/********************************************************************/
u8 LCD_u8WriteSpecialSymbol (u8 copy_u8SymbolIndex,u8 copy_u8XPos,u8 copy_u8YPos);


#endif /* LCD_INTERFACE_H_ */
