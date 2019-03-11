/************************************************************************************/
/* Author  : Islam A.                                                               */
/* Date    : 07 FEB 2019                                                            */
/* Version : V01                                                                    */
/************************************************************************************/
/* Description                                                                      */
/* ------------                                                                     */
/*  This is the application file, where you can write a simple application to test  */
/*  the functionality of DIO														*/
/************************************************************************************/

#include "STD_Types.h"
#include "LIB_Bit_Operations.h"

#include "Lib_Delay.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"


void DIO_vInit(void)
{

	DIO_PORTA -> CRL.RegisterAccess = ((DIO_u8_PIN0_INIT_MODE << 0)  | (DIO_u8_PIN1_INIT_MODE << 4)    |
			(DIO_u8_PIN2_INIT_MODE << 8)  | (DIO_u8_PIN3_INIT_MODE << 12)   |
			(DIO_u8_PIN4_INIT_MODE << 16) | (DIO_u8_PIN5_INIT_MODE << 20)   |
			(DIO_u8_PIN6_INIT_MODE << 24) | (DIO_u8_PIN7_INIT_MODE << 28)   );

	DIO_PORTA -> CRH.RegisterAccess =  ((DIO_u8_PIN8_INIT_MODE << 0)  | (DIO_u8_PIN9_INIT_MODE << 4)   |
			(DIO_u8_PIN10_INIT_MODE << 8)  | (DIO_u8_PIN11_INIT_MODE << 12) |
			(DIO_u8_PIN12_INIT_MODE << 16) | (DIO_u8_PIN13_INIT_MODE << 20) |
			(DIO_u8_PIN14_INIT_MODE << 24) | (DIO_u8_PIN15_INIT_MODE << 28) );

	/* Setting the initialized mode of each pin in Port B */
	DIO_PORTB -> CRL.RegisterAccess = ((DIO_u8_PIN16_INIT_MODE << 0)  | (DIO_u8_PIN17_INIT_MODE << 4)  |
			(DIO_u8_PIN18_INIT_MODE << 8)  | (DIO_u8_PIN19_INIT_MODE << 12) |
			(DIO_u8_PIN20_INIT_MODE << 16) | (DIO_u8_PIN21_INIT_MODE << 20) |
			(DIO_u8_PIN22_INIT_MODE << 24) | (DIO_u8_PIN23_INIT_MODE << 28) );


	DIO_PORTB -> CRH.RegisterAccess = ((DIO_u8_PIN24_INIT_MODE << 0)  | (DIO_u8_PIN25_INIT_MODE << 4)  |
			(DIO_u8_PIN26_INIT_MODE << 8)  | (DIO_u8_PIN27_INIT_MODE << 12) |
			(DIO_u8_PIN28_INIT_MODE << 16) | (DIO_u8_PIN29_INIT_MODE << 20) |
			(DIO_u8_PIN30_INIT_MODE << 24) | (DIO_u8_PIN31_INIT_MODE << 28) );

	/* Setting the initialized mode of pins 13,14,15 in Port C */
	DIO_PORTC->CRH.RegisterAccess   = ((DIO_u8_PIN32_INIT_MODE << 20) | (DIO_u8_PIN33_INIT_MODE << 24) |
			(DIO_u8_PIN34_INIT_MODE << 28));

	/* Setting the initialized mode of pins 0,1 in Port D */
	DIO_PORTD->CRL.RegisterAccess   = ((DIO_u8_PIN35_INIT_MODE << 0) | (DIO_u8_PIN36_INIT_MODE << 4));

	/* Setting the initialized state of each pin in Port A */
	DIO_PORTA->ODR.RegisterAccess = ((DIO_u8_PIN0_INIT_STATE << 0) | (DIO_u8_PIN1_INIT_STATE << 1) | (DIO_u8_PIN2_INIT_STATE << 2)
			| (DIO_u8_PIN3_INIT_STATE << 3) | (DIO_u8_PIN4_INIT_STATE << 4) | (DIO_u8_PIN5_INIT_STATE << 5)
			| (DIO_u8_PIN6_INIT_STATE << 6) | (DIO_u8_PIN7_INIT_STATE << 7) | (DIO_u8_PIN8_INIT_STATE << 8)
			| (DIO_u8_PIN9_INIT_STATE << 9) | (DIO_u8_PIN10_INIT_STATE << 10) | (DIO_u8_PIN11_INIT_STATE << 11)
			| (DIO_u8_PIN12_INIT_STATE << 12) | (DIO_u8_PIN13_INIT_STATE << 13) | (DIO_u8_PIN14_INIT_STATE << 14)
			| (DIO_u8_PIN15_INIT_STATE << 15));

	/* Setting the initialized state of each pin in Port B */
	DIO_PORTB->ODR.RegisterAccess = ((DIO_u8_PIN16_INIT_STATE << 0) | (DIO_u8_PIN17_INIT_STATE << 1) | (DIO_u8_PIN18_INIT_STATE << 2)
			| (DIO_u8_PIN19_INIT_STATE << 3) | (DIO_u8_PIN20_INIT_STATE << 4) | (DIO_u8_PIN21_INIT_STATE << 5)
			| (DIO_u8_PIN22_INIT_STATE << 6) | (DIO_u8_PIN23_INIT_STATE << 7) | (DIO_u8_PIN24_INIT_STATE << 8)
			| (DIO_u8_PIN25_INIT_STATE << 9) | (DIO_u8_PIN26_INIT_STATE << 10) | (DIO_u8_PIN27_INIT_STATE << 11)
			| (DIO_u8_PIN28_INIT_STATE << 12) | (DIO_u8_PIN29_INIT_STATE << 13) | (DIO_u8_PIN30_INIT_STATE << 14)
			| (DIO_u8_PIN31_INIT_STATE << 15));

	/* Setting the initialized state of pins 13,14,15 in Port C */
	DIO_PORTC->ODR.RegisterAccess = ((DIO_u8_PIN32_INIT_STATE << 13) | (DIO_u8_PIN33_INIT_STATE << 14) | (DIO_u8_PIN34_INIT_STATE << 15));

	/* Setting the initialized state of pins 0,1 in Port D */
	DIO_PORTD->ODR.RegisterAccess = (DIO_u8_PIN35_INIT_STATE << 0) | (DIO_u8_PIN36_INIT_STATE << 1);

	return;

}


/*
 * Description: Function to set the direction of a specific pin in a specified port
 * Inputs: the pin number , the pin direction
 * Output: the STD_ERROR state of the function
 */
u8 DIO_u8SetPinDirection (u8 Copy_u8PinNb,u8 Copy_u8Mode)
{
	/*Local Variable holding the STD_ERROR state*/
	u8 Local_u8STD_ERROR = STD_ERROR_OK;

	/*Local variables holding the actual port number and the pin number */
	u8 Local_u8PortId = Copy_u8PinNb / DIO_u8NUMBER_OF_PINS_IN_PORT;
	u8 Local_u8PinId = Copy_u8PinNb % DIO_u8NUMBER_OF_PINS_IN_PORT;

	/*checking the STD_ERROR possibilities of the inputs*/
	if(
			((Copy_u8Mode != DIO_u8_INPUT_ANALOG) && (Copy_u8Mode != DIO_u8_INPUT_FLOATING)
		      && (Copy_u8Mode != DIO_u8_INPUT_PULL_UP) && (Copy_u8Mode != DIO_u8_INPUT_PULL_DOWN)
			  && (Copy_u8Mode != DIO_u8_OUTPUT_10M_PP)
		      && (Copy_u8Mode != DIO_u8_OUTPUT_10M_OD) && (Copy_u8Mode != DIO_u8_OUTPUT_10M_AFPP)
		      && (Copy_u8Mode != DIO_u8_OUTPUT_10M_AFOD) && (Copy_u8Mode != DIO_u8_OUTPUT_2M_PP)
		      && (Copy_u8Mode != DIO_u8_OUTPUT_2M_OD) && (Copy_u8Mode != DIO_u8_OUTPUT_2M_AFPP)
		      && (Copy_u8Mode != DIO_u8_OUTPUT_2M_AFOD) && (Copy_u8Mode != DIO_u8_OUTPUT_50M_PP)
		      && (Copy_u8Mode != DIO_u8_OUTPUT_50M_OD) && (Copy_u8Mode != DIO_u8_OUTPUT_50M_AFPP)
			  && (Copy_u8Mode != DIO_u8_OUTPUT_50M_AFOD))
      )
	{
		Local_u8STD_ERROR = STD_ERROR_NOK;
	}
	else
	{
		if (Copy_u8Mode == DIO_u8_INPUT_PULL_UP)
		{
			(GPIO_AGPIOPorts[Local_u8PortId])->ODR.RegisterAccess = SET_BIT(((GPIO_AGPIOPorts[Local_u8PortId])->ODR.RegisterAccess),Local_u8PinId);
		}
		else if (Copy_u8Mode == DIO_u8_INPUT_PULL_DOWN)
		{
			(GPIO_AGPIOPorts[Local_u8PortId])->ODR.RegisterAccess = RESET_BIT((GPIO_AGPIOPorts[Local_u8PortId])->ODR.RegisterAccess,Local_u8PinId);
			 Copy_u8Mode = DIO_u8_INPUT_PULL_UP;
		}

		if (Local_u8PinId <= 7)
		{
			ASSIGN_NIBBLE((GPIO_AGPIOPorts[Local_u8PortId])->CRL.RegisterAccess,Local_u8PinId,Copy_u8Mode);
		}
		else
		{
			Local_u8PinId -= 8;
			ASSIGN_NIBBLE((GPIO_AGPIOPorts[Local_u8PortId])->CRH.RegisterAccess,Local_u8PinId,Copy_u8Mode);
		}

	}
	/*Function return*/
	return Local_u8STD_ERROR;
}

/*
 * Description: Function to set a specific pin in a specified port with a specified value (INPUT = 0,OUTPUT = 1)
 * Inputs: the pin number , the pin value
 * Output: the STD_ERROR state of the function
 */
u8 DIO_u8SetPinValue (u8 Copy_u8PinNb, u8 Copy_u8Value)
{
	/*Local Variable holding the STD_ERROR state*/
	u8 Local_u8STD_ERROR = STD_ERROR_OK;
	u8 Local_u8PortId = Copy_u8PinNb / DIO_u8NUMBER_OF_PINS_IN_PORT;
	u8 Local_u8PinId = Copy_u8PinNb % DIO_u8NUMBER_OF_PINS_IN_PORT;

	/*checking the STD_ERROR possibilities of the inputs*/
	if (((Copy_u8Value != DIO_u8_PIN_HIGH) && (Copy_u8Value != DIO_u8_PIN_LOW)))
	{
		Local_u8STD_ERROR = STD_ERROR_NOK;
	}
	else
	{
		if (Copy_u8Value == DIO_u8_PIN_HIGH)
		{
			(GPIO_AGPIOPorts[Local_u8PortId])->BSRR.RegisterAccess = SET_BIT(((GPIO_AGPIOPorts[Local_u8PortId])->BSRR.RegisterAccess),Local_u8PinId);
		}
		else
		{
			(GPIO_AGPIOPorts[Local_u8PortId])->BSRR.RegisterAccess = SET_BIT(((GPIO_AGPIOPorts[Local_u8PortId])->BSRR.RegisterAccess),Local_u8PinId+16);
		}
	}
	/*Function return*/
	return Local_u8STD_ERROR;
}

/*
 * Description: Function to get the value of a certain input pin in a specified port
 * Inputs: the pin number , the container variable which will hold the value on this pin
 * output: the STD_ERROR state of the function
 */
u8 DIO_u8GetPinValue (u8 Copy_u8PinNb,u8 *Copy_u8PinValue)
{
	/*Local Variable holding the STD_ERROR state*/
	u8 Local_u8STD_ERROR = STD_ERROR_OK;
	u8 Local_u8PortId = Copy_u8PinNb / DIO_u8NUMBER_OF_PINS_IN_PORT;
	u8 Local_u8PinId = Copy_u8PinNb % DIO_u8NUMBER_OF_PINS_IN_PORT;

	/*checking the STD_ERROR possibilities of the inputs*/
	if (Copy_u8PinValue == NULL)
	{
		Local_u8STD_ERROR = STD_ERROR_NOK;
	}
	else
	{
		switch (Local_u8PortId)
		{
			case DIO_u8_PORTA: *Copy_u8PinValue = GET_BIT(DIO_PORTA -> IDR.RegisterAccess,Local_u8PinId); break;

			case DIO_u8_PORTB: *Copy_u8PinValue = GET_BIT(DIO_PORTB -> IDR.RegisterAccess,Local_u8PinId); break;

			case DIO_u8_PORTC: *Copy_u8PinValue = GET_BIT(DIO_PORTC -> IDR.RegisterAccess,Local_u8PinId); break;

			case DIO_u8_PORTD: *Copy_u8PinValue = GET_BIT(DIO_PORTD -> IDR.RegisterAccess,Local_u8PinId); break;
			default:  Local_u8STD_ERROR = STD_ERROR_NOK;
		}
	}
	/*Function return*/
	return Local_u8STD_ERROR;
}

/*
 * Description: Function to set pins of a specified port with a specified value
 * Inputs: the port number , the port value
 * Output: the STD_ERROR state of the function
 */
u8 DIO_u8SetPortValue (u8 Copy_u8PortNb, u8 Copy_u8Value)
{
	/*Local Variable holding the STD_ERROR state*/
	u8 Local_u8STD_ERROR;

	/*checking the STD_ERROR possibilities of the inputs*/
	if (Copy_u8PortNb >= DIO_u8MAXPortNB)
		Local_u8STD_ERROR = STD_ERROR_NOK;
	else
	{
		switch (Copy_u8PortNb)
		{
			case DIO_u8_PORTA: DIO_PORTA -> ODR.RegisterAccess = Copy_u8Value; break;

			case DIO_u8_PORTB: DIO_PORTB -> ODR.RegisterAccess = Copy_u8Value; break;

			case DIO_u8_PORTC: DIO_PORTC -> ODR.RegisterAccess = Copy_u8Value; break;

			case DIO_u8_PORTD: DIO_PORTD -> ODR.RegisterAccess = Copy_u8Value; break;
			default:  Local_u8STD_ERROR = STD_ERROR_NOK;
		}
	}

	/*Function return*/
	return Local_u8STD_ERROR;
}

/*
 * Description: Function to get the value of a specified port
 * Inputs: the port number , the container variable which will hold the value on this port
 * output: the STD_ERROR state of the function
 */
u8 DIO_u8GetPortValue (u8 Copy_u8PortNb, u8 *Copy_u8PortValue)
{
	/*Local Variable holding the STD_ERROR state*/
	u8 Local_u8STD_ERROR;

	/*checking the STD_ERROR possibilities of the inputs*/
	if (Copy_u8PortNb >= DIO_u8MAXPortNB || Copy_u8PortValue == NULL)
		Local_u8STD_ERROR = STD_ERROR_NOK;
	else
	{
		switch (Copy_u8PortNb)
		{
			case DIO_u8_PORTA: *Copy_u8PortValue = DIO_PORTA -> IDR.RegisterAccess; break;

			case DIO_u8_PORTB: *Copy_u8PortValue = DIO_PORTB -> IDR.RegisterAccess; break;

			case DIO_u8_PORTC: *Copy_u8PortValue = DIO_PORTC -> IDR.RegisterAccess; break;

			case DIO_u8_PORTD: *Copy_u8PortValue = DIO_PORTD -> IDR.RegisterAccess; break;
			default:  Local_u8STD_ERROR = STD_ERROR_NOK;
		}
	}

	/*Function return*/
	return Local_u8STD_ERROR;
}

