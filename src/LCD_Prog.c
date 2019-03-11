/********************************************************************/
/* Author  : Islam A.			                                    */
/* Date    : 10 MAR 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Source code file for LCD driver									*/
/********************************************************************/

#include "STD_Types.h"
#include "Lib_Delay.h"
#include "LIB_Bit_Operations.h"
#include "DIO_Interface.h"

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"


/********************************************************************/
/* Name			: LCD_vInit.			                            */
/* Description  : API to that has the initialization sequence for   */
/*				  character LCD.									*/
/* Inputs		: NONE                                              */
/* Outputs      : NONE												*/
/********************************************************************/
void LCD_vInit (void)
{
	/* Wait for more than 30 ms after Vdd rises to 4.5v 		   */
	Lib_vDelayMs (40);

	/* Check if the configuration was 4 bit mode, these are done   */
	/* Before initialization sequence 							   */
	if(LCD_u8_MODE == LCD_u8_4BIT_MODE)
	{
		private_u8WriteCommand (LCD_u8_4BIT_INIT_SEQUENCE1);
		private_u8WriteCommand (LCD_u8_4BIT_INIT_SEQUENCE2);
	}

	/* Write function set sequence according to configuration      */
	private_u8WriteCommand (LCD_u8_INIT_FUNCTION_SET);

	/* wait for more than 39us                                     */
	Lib_vDelayMs(2);

	/* Write Display control sequence according to configuration   */
	private_u8WriteCommand (LCD_u8_INIT_DISPLAY_CONTROL);

	/* wait for more than 39us                                     */
	Lib_vDelayMs(2);

	/* Write display clear sequence 							   */
	private_u8WriteCommand (LCD_u8_CLEAR);

	/* wait for more than 1.53ms                                   */
	Lib_vDelayMs(2);

}

/********************************************************************/
/* Name			: LCD_u8WriteData			                        */
/* Description  : API to that writes a string on LCD 	            */
/* Inputs		: Data that is going to be written (copy_Pu8Data)   */
/*				  X position on LCD (copy_u8Xpos)					*/
/*				  Y position on LCD (copy_u8Ypos)					*/
/* Outputs      : ErrorState										*/
/********************************************************************/
u8 LCD_u8WriteData(u8 * copy_Pu8Data, u8 copy_u8Xpos, u8 copy_u8Ypos)
{
	u8 local_u8Error = STD_ERROR_OK;
	u8 local_u8Address;

	/* Input validation 											*/
	if((copy_u8Xpos >= LCD_u8_COLUMN_NO) || (copy_u8Ypos >= LCD_u8_ROW_NO)
			|| (copy_Pu8Data == (u8 *)NULL))
	{
		local_u8Error = STD_ERROR_NOK;
	}
	else
	{
		/* Get cursor to specified position							*/
		local_u8Address = copy_u8Xpos + (copy_u8Ypos * LCD_u8_2ND_ROW);
		local_u8Address |= LCD_u8_SET_DDRAM_ADDRESS;
		private_u8WriteCommand(local_u8Address);


		/* Looping on string, while it's not the end of string keep */
		/* writing characters on display							*/
		while(*copy_Pu8Data != '\0')
		{
			/* Write a single character from the array of characters*/
			private_u8WriteData(* copy_Pu8Data++);

			/* Increment the address counter to point to next one   */
			local_u8Address++;

			/* If address counter reached the end of row 1 or not   */
			if(local_u8Address == LCD_u8_LINE1_END)
			{
				/* Display in a new line           					*/
				local_u8Address = LCD_u8_LINE2_START;

				/* Move cursor to this new address 					*/
				private_u8WriteCommand(local_u8Address);
			}

			/* If address counter reached the end of row 2 or not 	*/
			if(local_u8Address == LCD_u8_LINE2_END)
			{
				/* Move the cursor back to the start of row 1 		*/
				local_u8Address = LCD_u8_SET_DDRAM_ADDRESS;
				private_u8WriteCommand(local_u8Address);
			}
		}
	}

	/* Error status return 											*/
	return local_u8Error;
}

/********************************************************************/
/* Name			: LCD_u8SavePattern			                        */
/* Description  : API to that saves a custom pattern in CGRAM       */
/* Inputs		: An array of patterns that needs to be saved		*/
/*				  (Au8_SymbolPattern[][8])							*/
/*				  Word size that needs to be saved (copy_u8WordSize)*/
/* Outputs      : ErrorState										*/
/********************************************************************/
u8 LCD_u8SavePattern(u8 Au8_SymbolPattern[][LCD_u8_CHARACTER_SIZE], u8 copy_u8WordSize)
{
	/* local variable holding the error state 						*/
	u8 local_u8Error = STD_ERROR_OK;
	u8 local_u8Index1, local_u8Index2;

	/* Input validation 											*/
	if (copy_u8WordSize > LCD_u8_MAX_SYMBOL)
	{
		/* Return Error, and writing pattern failed 				*/
		local_u8Error = STD_ERROR_NOK;
	}

	/* Write a command to point address counter to CGRAM			*/
	private_u8WriteCommand(LCD_u8_SET_CGRAM_ADDRESS);

	for (local_u8Index1 = NULL; local_u8Index1 < copy_u8WordSize; local_u8Index1++)
	{
		for (local_u8Index2 = NULL; local_u8Index2 < LCD_u8_CHARACTER_SIZE; local_u8Index2++)
		{
			/* Write character in CGRAM								*/
			private_u8WriteData (Au8_SymbolPattern[local_u8Index1][local_u8Index2]);
		}
	}

	/* return error state of saving pattern in CGRAM				*/
	return local_u8Error;
}


/********************************************************************/
/* Name			: LCD_u8WriteSpecialSymbol	                        */
/* Description  : API to that writes a pattern symbol on LCD 	    */
/* Inputs		: Index of data that is going to be written 		*/
/*                (copy_u8SymbolIndex)   							*/
/*				  X position on LCD (copy_u8Xpos)					*/
/*				  Y position on LCD (copy_u8Ypos)					*/
/* Outputs      : ErrorState										*/
/********************************************************************/
u8 LCD_u8WriteSpecialSymbol (u8 copy_u8SymbolIndex,u8 copy_u8XPos,u8 copy_u8YPos)
{
	/* local variable holding error state 							*/
	u8 local_u8Error = STD_ERROR_OK;
	u8 local_u8Address;

	/*input validation												*/
	if((copy_u8XPos >= LCD_u8_COLUMN_NO) || (copy_u8YPos >= LCD_u8_ROW_NO))
	{
		local_u8Error = STD_ERROR_NOK;
	}
	else
	{
		/* set coordinates of cursor								*/
		local_u8Address = copy_u8XPos + (copy_u8YPos * LCD_u8_2ND_ROW);

		/* Point to the start of DDRAM which is the beginning of	*/
		/* display													*/
		local_u8Address |= LCD_u8_SET_DDRAM_ADDRESS;

		/* Write command to set address counter to the calculated   */
		/* address from the previous logic							*/
		private_u8WriteCommand(local_u8Address);

		/* Write custom character on display 						*/
		private_u8WriteData(copy_u8SymbolIndex);
	}

	/* return error status											*/
	return local_u8Error;
}


/********************************************************************/
/* Name			: LCD_u8Clear			                            */
/* Description  : API to that clears character LCD.					*/
/* Inputs		: NONE                                              */
/* Outputs      : Error state										*/
/********************************************************************/
u8 LCD_vClear(void)
{
	/* Local variable to store the value of error state 			*/
	u8 local_u8ErrorState = STD_ERROR_OK;

	/* Send command clear to the LCD 								*/
	local_u8ErrorState = private_u8WriteCommand (LCD_u8_CLEAR);

	/* Check the status for the operation whether it's ok or fail   */
	if (local_u8ErrorState == STD_ERROR_OK)
	{
		/* Succeeded												*/
		return STD_ERROR_OK;
	}
	else
	{
		/* Failed													*/
		return STD_ERROR_NOK;
	}

}



/********************************************************************/
/* Name			: LCD_u8ShiftLeft			                        */
/* Description  : API to that shifts cursor to left on character LCD*/
/* Inputs		: NONE                                              */
/* Outputs      : Error state										*/
/********************************************************************/
u8 LCD_ShiftLeft(void)
{
	/* Local variable to store the value of error state 			*/
	u8 local_u8ErrorState = STD_ERROR_OK;

	/* Send command shift left cursor to the LCD 					*/
	local_u8ErrorState = private_u8WriteCommand (LCD_u8_SHIFT_LEFT);

	/* Check the status for the operation whether it's ok or fail   */
	if (local_u8ErrorState == STD_ERROR_OK)
	{
		/* Succeeded												*/
		return STD_ERROR_OK;
	}
	else
	{
		/* Failed													*/
		return STD_ERROR_NOK;
	}
}


/********************************************************************/
/* Name			: LCD_u8ShiftRight   		                        */
/* Description  : API to that shifts cursor to right on character   */
/*				  LCD												*/
/* Inputs		: NONE                                              */
/* Outputs      : Error state										*/
/********************************************************************/
u8 LCD_ShiftRight(void)
{
	/* Local variable to store the value of error state 			*/
	u8 local_u8ErrorState = STD_ERROR_OK;

	/* Send command shift right cursor to the LCD 					*/
	private_u8WriteCommand (LCD_u8_SHIFT_RIGHT);

	/* Check the status for the operation whether it's ok or fail   */
	if (local_u8ErrorState == STD_ERROR_OK)
	{
		/* Succeeded												*/
		return STD_ERROR_OK;
	}
	else
	{
		/* Failed													*/
		return STD_ERROR_NOK;
	}
}

/******************* Private functions ******************************/

/********************************************************************/
/* Name  : private_u8WriteData										*/
/* Description: Function needed to send Data to the LCD				*/
/* Inputs: The data needed to be sent Data as a string				*/
/* Output: error state												*/
/********************************************************************/
static u8 private_u8WriteData(u8 copy_u8Data)
{
	/* Local variable to hold error state of the function 			*/
	u8 local_u8Error = STD_ERROR_OK;

	/* Setting RS pin to write data 								*/
	DIO_u8SetPinValue(LCD_u8_RS_PIN, DIO_u8_PIN_HIGH);
	local_u8Error = private_u8Write (copy_u8Data);

	return local_u8Error;
}

/********************************************************************/
/* Name  : private_u8WriteCommand									*/
/* Description: Function needed to send Command to the LCD			*/
/* Inputs: The command needed to be sent							*/
/* Output: error state												*/
/********************************************************************/
static u8 private_u8WriteCommand (u8 copy_u8Command)
{
	/* Local variable to hold error state of the function 			*/
	u8 local_u8Error = STD_ERROR_OK;

	/* Setting RS pin to write a command							*/
	local_u8Error = DIO_u8SetPinValue (LCD_u8_RS_PIN, DIO_u8_PIN_LOW);
	local_u8Error = private_u8Write (copy_u8Command);

	return local_u8Error;

}


/********************************************************************/
/* Name	 :	private_u8Write											*/
/* Description: Private function needed to send Data/Command to		*/
/* 				the LCD												*/
/* Inputs: The data or the command needed to be sent				*/
/* Output: Error state												*/
/********************************************************************/
static u8 private_u8Write (u8 copy_u8Data)
{
	/* Local variable to hold error state of the function 			*/
	u8 local_u8Error = STD_ERROR_OK;

	/* Setting enable pin to low, and activate write mode			*/
	local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN, DIO_u8_PIN_LOW);
	local_u8Error = DIO_u8SetPinValue (LCD_u8_RW_PIN, DIO_u8_PIN_LOW);

	/* check if we are in 8 bit mode, 								*/
	if (LCD_u8_MODE == LCD_u8_8BIT_MODE)
	{
		/* Writing values of first 4 bits							*/
		local_u8Error = DIO_u8SetPinValue (LCD_u8_D0_PIN,GET_BIT(copy_u8Data,0));
		local_u8Error = DIO_u8SetPinValue (LCD_u8_D1_PIN,GET_BIT(copy_u8Data,1));
		local_u8Error = DIO_u8SetPinValue (LCD_u8_D2_PIN,GET_BIT(copy_u8Data,2));
		local_u8Error = DIO_u8SetPinValue (LCD_u8_D3_PIN,GET_BIT(copy_u8Data,3));
	}

	/* Writing values of second 4 bits								*/
	local_u8Error = DIO_u8SetPinValue (LCD_u8_D0_PIN,GET_BIT(copy_u8Data,4));
	local_u8Error = DIO_u8SetPinValue (LCD_u8_D1_PIN,GET_BIT(copy_u8Data,5));
	local_u8Error = DIO_u8SetPinValue (LCD_u8_D2_PIN,GET_BIT(copy_u8Data,6));
	local_u8Error = DIO_u8SetPinValue (LCD_u8_D3_PIN,GET_BIT(copy_u8Data,7));

	/* Setting enable to high to read write these values 			*/
	local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN, DIO_u8_PIN_HIGH);
	Lib_vDelayMs(2);

	/* Reseting enable pin to low in order to write second part of  */
	/* 4 bit mode, cause it is supposed to be written on 2 parts. 	*/
	local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN, DIO_u8_PIN_LOW);
	Lib_vDelayMs(5);

	/* Writing second part of data/command							*/
	if (LCD_u8_MODE == LCD_u8_4BIT_MODE)
	{
		/* Setting enable pin to low, and activate write mode		*/
		local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN, DIO_u8_PIN_LOW);
		local_u8Error = DIO_u8SetPinValue (LCD_u8_RW_PIN, DIO_u8_PIN_LOW);

		/* Writing second part on 4 pins of LCD						*/
		local_u8Error = DIO_u8SetPinValue (LCD_u8_D4_PIN,GET_BIT(copy_u8Data,0));
		local_u8Error = DIO_u8SetPinValue (LCD_u8_D5_PIN,GET_BIT(copy_u8Data,1));
		local_u8Error = DIO_u8SetPinValue (LCD_u8_D6_PIN,GET_BIT(copy_u8Data,2));
		local_u8Error = DIO_u8SetPinValue (LCD_u8_D7_PIN,GET_BIT(copy_u8Data,3));

		/* Setting enable pin, and wait on it then resetting it		*/
		local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_HIGH);
		Lib_vDelayMs (2);
		local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_LOW);
	}

	/* return error state	*/
	return local_u8Error;
}

