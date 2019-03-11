/*************************************************************************************/
/*																					 */
/* Author: Islam A.                         			   							 */
/* Date: 06 MAR 2019                                                                 */
/* Version: 01                                                                       */
/* Description: Private file for RCC Driver in STM32F103   							 */
/*																					 */
/*************************************************************************************/

#include "STD_Types.h"
#include "LIB_Bit_Operations.h"
#include "RCC_Interface.h"
#include "RCC_priv.h" 
#include "RCC_config.h" 

/************************************************************************************/
/*																					*/
/* Description: Function to initialize the values for RCC register					*/
/* Inputs: none																		*/
/* Output: void																		*/
/*																					*/
/************************************************************************************/

void RCC_vInit (void)
{
	/*	Checking if HSI is enabled in the configuration file */

	if (RCC_u8_HSI_STATE == RCC_u8_ENABLE)
	{
		/* Enable Internal high-speed clock in RCC_CR register */

		RCC->CR.RegisterAccess = SET_BIT(RCC->CR.RegisterAccess,0);

		/* waiting HSI clock to be ready and stable */

		while (GET_BIT(RCC->CR.RegisterAccess,1) == 0);
	}
	else
	{
		/* Disable Internal high-speed clock in RCC_CR register */

		RCC->CR.RegisterAccess = RESET_BIT(RCC->CR.RegisterAccess,0);
	}

	/* Checking if HSE is enabled in the configuration file */

	if (RCC_u8_HSE_STATE == RCC_u8_ENABLE)
	{
		/* Enable External high-speed clock in RCC_CR register */

		RCC->CR.RegisterAccess = SET_BIT(RCC->CR.RegisterAccess,16);

		/* waiting HSE clock to be ready and stable */

		while (GET_BIT(RCC->CFGR.RegisterAccess,17) == 0);
	}

	else
	{
		/* Disable External high-speed clock in RCC_CR register */
		RCC->CR.RegisterAccess = RESET_BIT(RCC->CR.RegisterAccess,16);
	}

	/*	Checking if PLL is enabled in the configuration file*/

	if (RCC_u8_PLL_STATE == RCC_u8_ENABLE)
	{
		/* Step(1): Enable HSI and select it */
		/* Enable Internal high-speed clock in RCC_CR register */

		RCC->CR.RegisterAccess = SET_BIT(RCC->CR.RegisterAccess,0);

		/* waiting HSI clock to be ready and stable */

		while (GET_BIT(RCC->CR.RegisterAccess,1) == 0);

		/* Select HSI as the system clock in RCC_CFGR register */

		RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,1);
		RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,0);

		/* Disable PLL in RCC_CR_register */

		RCC->CR.RegisterAccess = RESET_BIT(RCC->CR.RegisterAccess,24);

		/* Set the PLL configurations */

		if (RCC_u8_PREDIV1SRC == RCC_u8_HSE)

			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,16);

		else

			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,16);

		if (RCC_u8_PLLXTPRE == RCC_u8_NOT_DIVIDED)

			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,17);

		else

			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,17);

		if (RCC_u8_PLLSRC == RCC_u8_HSI_DIVIDED_BY_2)

			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,16);

		else

			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,16);

		/* Enable the PLL and select it */
		/* Enable PLL clock in RCC_CR register */

		RCC->CR.RegisterAccess = SET_BIT(RCC->CR.RegisterAccess,24);

		/* waiting PLL clock to be ready and stable */

		while (GET_BIT(RCC->CR.RegisterAccess,25) == 0);
	}
	else
	{
		/* Disable PLL clock in RCC_CR register */

		RCC->CR.RegisterAccess = RESET_BIT(RCC->CR.RegisterAccess,24);
	}

	/* Checking the initial configuration of the System Clock */

	switch (RCC_u8_SYS_CLOCK)
	{
		case (RCC_u8_HSI):
		{
			/* Select HSI as the system clock in RCC_CFGR register */

			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,1);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,0);
			break;
		}
		case (RCC_u8_HSE):
		{
			/*Select HSE as the system clock in RCC_CFGR register */
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,1);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,0);
			break;
		}
		case (RCC_u8_PLL):
		{
			/*Select PLL as the system clock in RCC_CFGR register */
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,1);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,0);
			break;
		}
	}

	/* Checking the initial configuration of AHB prescaler */

	switch (RCC_u8_AHB_PRESCALER)
	{
		case (RCC_u8_NOT_DIVIDED):
		{
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,7);
			break;
		}
		case (RCC_u8_DIVIDED_BY_2):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,7);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,6);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,5);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_4):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,7);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,6);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,5);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_8):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,7);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,6);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,5);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_16):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,7);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,6);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,5);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_64):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,7);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,6);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,5);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_128):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,7);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,6);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,5);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_256):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,7);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,6);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,5);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_512):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,7);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,6);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,5);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,4);
			break;
		}
	}

	/* Checking the initial configuration of APB1 prescaler */

	switch (RCC_u8_APB1_PRESCALER)
	{
		case (RCC_u8_NOT_DIVIDED):
		{
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,10);
			break;
		}
		case (RCC_u8_DIVIDED_BY_2):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,10);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,9);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,8);
			break;
		}
		case (RCC_u8_DIVIDED_BY_4):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,10);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,9);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,8);
			break;
		}
		case (RCC_u8_DIVIDED_BY_8):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,10);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,9);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,8);
			break;
		}
		case (RCC_u8_DIVIDED_BY_16):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,10);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,9);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,8);
			break;
		}
	}

	/* Checking the initial configuration of APB2 prescaler */

	switch (RCC_u8_APB2_PRESCALER)
	{
		case (RCC_u8_NOT_DIVIDED):
		{
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,13);
			break;
		}
		case (RCC_u8_DIVIDED_BY_2):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,13);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,12);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,11);
			break;
		}
		case (RCC_u8_DIVIDED_BY_4):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,13);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,12);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,11);
			break;
		}
		case (RCC_u8_DIVIDED_BY_8):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,13);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,12);
			RCC->CFGR.RegisterAccess = RESET_BIT(RCC->CFGR.RegisterAccess,11);
			break;
		}
		case (RCC_u8_DIVIDED_BY_16):
		{
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,13);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,12);
			RCC->CFGR.RegisterAccess = SET_BIT(RCC->CFGR.RegisterAccess,11);
			break;
		}
	}
	return;
}

/********************************************************************************/
/*																				*/
/* Description: Function to set the state of any peripheral (Enable/disable)	*/
/* Inputs: the peripheral name													*/
/* Output: Error state															*/
/*																				*/
/********************************************************************************/

u8 RCC_vEnablePeripheralClock (u8 Copy_u8PeriName)
{
	/* Local Variable holding the error state */

	u32 Local_u8Error = STD_ERROR_OK;

	switch (Copy_u8PeriName)
	{
		/* For APB2 peripherals */

		case RCC_u8_USART1:
					RCC->APB2ENR.RegisterAccess |= (1<<14); break;
		case RCC_u8_SPI1:
					RCC->APB2ENR.RegisterAccess |= (1<<12); break;
		case RCC_u8_TIM1:
					RCC->APB2ENR.RegisterAccess |= (1<<11); break;
		case RCC_u8_ADC2:
					RCC->APB2ENR.RegisterAccess |= (1<<10); break;
		case RCC_u8_ADC1:
					RCC->APB2ENR.RegisterAccess |= (1<<9); break;
		case RCC_u8_IOPD:
					RCC->APB2ENR.RegisterAccess |= (1<<5); break;
		case RCC_u8_IOPC:
					RCC->APB2ENR.RegisterAccess |= (1<<4); break;
		case RCC_u8_IOPB:
					RCC->APB2ENR.RegisterAccess |= (1<<3); break;
		case RCC_u8_IOPA:
					RCC->APB2ENR.RegisterAccess |= (1<<2); break;
		case RCC_u8_AFIO:
					RCC->APB2ENR.RegisterAccess |= (1<<0); break;

		/* For APB1 peripherals */

		case RCC_u8_DAC:
					RCC->APB1ENR.RegisterAccess |= (1<<29); break;
		case RCC_u8_PWR:
					RCC->APB1ENR.RegisterAccess |= (1<<28); break;
		case RCC_u8_BKP:
					RCC->APB1ENR.RegisterAccess |= (1<<27); break;
		case RCC_u8_CAN2:
					RCC->APB1ENR.RegisterAccess |= (1<<26); break;
		case RCC_u8_CAN1:
					RCC->APB1ENR.RegisterAccess |= (1<<25); break;
		case RCC_u8_I2C2:
					RCC->APB1ENR.RegisterAccess |= (1<<22); break;
		case RCC_u8_I2C1:
					RCC->APB1ENR.RegisterAccess |= (1<<21); break;
		case RCC_u8_USART5:
					RCC->APB1ENR.RegisterAccess |= (1<<20); break;
		case RCC_u8_USART4:
					RCC->APB1ENR.RegisterAccess |= (1<<19); break;
		case RCC_u8_USART3:
					RCC->APB1ENR.RegisterAccess |= (1<<18); break;
		case RCC_u8_USART2:
					RCC->APB1ENR.RegisterAccess |= (1<<17); break;
		case RCC_u8_SPI3:
					RCC->APB1ENR.RegisterAccess |= (1<<15); break;
		case RCC_u8_SPI2:
					RCC->APB1ENR.RegisterAccess |= (1<<14); break;
		case RCC_u8_WWDG:
					RCC->APB1ENR.RegisterAccess |= (1<<11); break;
		case RCC_u8_TIM7:
					RCC->APB1ENR.RegisterAccess |= (1<<5); break;
		case RCC_u8_TIM6:
					RCC->APB1ENR.RegisterAccess |= (1<<4); break;
		case RCC_u8_TIM5:
					RCC->APB1ENR.RegisterAccess |= (1<<3); break;
		case RCC_u8_TIM4:
					RCC->APB1ENR.RegisterAccess |= (1<<2); break;
		case RCC_u8_TIM3:
					RCC->APB1ENR.RegisterAccess |= (1<<1); break;
		case RCC_u8_TIM2:
					RCC->APB1ENR.RegisterAccess |= (1<<0); break;

		/* For AHB peripherals */

		case RCC_u8_OTGFS:
					RCC->AHBENR.RegisterAccess |= (1<<12); break;
		case RCC_u8_CRC:
					RCC->AHBENR.RegisterAccess |= (1<<6); break;
		case RCC_u8_SRAM:
					RCC->AHBENR.RegisterAccess |= (1<<2); break;
		case RCC_u8_DMA2:
					RCC->AHBENR.RegisterAccess |= (1<<1); break;
		case RCC_u8_DMA1:
					RCC->AHBENR.RegisterAccess |= (1<<0); break;
		default:
			Local_u8Error = STD_ERROR_NOK;
	}

	/* Function return */
	return Local_u8Error;
}

u8 RCC_vDisablePeripheralClock (u8 Copy_u8PeriName)
{
	/* Local Variable holding the error state */

	u32 Local_u8Error = STD_ERROR_OK;

	switch (Copy_u8PeriName)
	{
		/* For APB2 peripherals */

		case RCC_u8_USART1:
					RCC->APB2RSTR.RegisterAccess |= (1<<14); break;
		case RCC_u8_SPI1:
					RCC->APB2RSTR.RegisterAccess |= (1<<12); break;
		case RCC_u8_TIM1:
					RCC->APB2RSTR.RegisterAccess |= (1<<11); break;
		case RCC_u8_ADC2:
					RCC->APB2RSTR.RegisterAccess |= (1<<10); break;
		case RCC_u8_ADC1:
					RCC->APB2RSTR.RegisterAccess |= (1<<9); break;
		case RCC_u8_IOPD:
					RCC->APB2RSTR.RegisterAccess |= (1<<5); break;
		case RCC_u8_IOPC:
					RCC->APB2RSTR.RegisterAccess |= (1<<4); break;
		case RCC_u8_IOPB:
					RCC->APB2RSTR.RegisterAccess |= (1<<3); break;
		case RCC_u8_IOPA:
					RCC->APB2RSTR.RegisterAccess |= (1<<2); break;
		case RCC_u8_AFIO:
					RCC->APB2RSTR.RegisterAccess |= (1<<0); break;

		/* For APB1 peripherals */

		case RCC_u8_DAC:
					RCC->APB1RSTR.RegisterAccess |= (1<<29); break;
		case RCC_u8_PWR:
					RCC->APB1RSTR.RegisterAccess |= (1<<28); break;
		case RCC_u8_BKP:
					RCC->APB1RSTR.RegisterAccess |= (1<<27); break;
		case RCC_u8_CAN2:
					RCC->APB1RSTR.RegisterAccess |= (1<<26); break;
		case RCC_u8_CAN1:
					RCC->APB1RSTR.RegisterAccess |= (1<<25); break;
		case RCC_u8_I2C2:
					RCC->APB1RSTR.RegisterAccess |= (1<<22); break;
		case RCC_u8_I2C1:
					RCC->APB1RSTR.RegisterAccess |= (1<<21); break;
		case RCC_u8_USART5:
					RCC->APB1RSTR.RegisterAccess |= (1<<20); break;
		case RCC_u8_USART4:
					RCC->APB1RSTR.RegisterAccess |= (1<<19); break;
		case RCC_u8_USART3:
					RCC->APB1RSTR.RegisterAccess |= (1<<18); break;
		case RCC_u8_USART2:
					RCC->APB1RSTR.RegisterAccess |= (1<<17); break;
		case RCC_u8_SPI3:
					RCC->APB1RSTR.RegisterAccess |= (1<<15); break;
		case RCC_u8_SPI2:
					RCC->APB1RSTR.RegisterAccess |= (1<<14); break;
		case RCC_u8_WWDG:
					RCC->APB1RSTR.RegisterAccess |= (1<<11); break;
		case RCC_u8_TIM7:
					RCC->APB1RSTR.RegisterAccess |= (1<<5); break;
		case RCC_u8_TIM6:
					RCC->APB1RSTR.RegisterAccess |= (1<<4); break;
		case RCC_u8_TIM5:
					RCC->APB1RSTR.RegisterAccess |= (1<<3); break;
		case RCC_u8_TIM4:
					RCC->APB1RSTR.RegisterAccess |= (1<<2); break;
		case RCC_u8_TIM3:
					RCC->APB1RSTR.RegisterAccess |= (1<<1); break;
		case RCC_u8_TIM2:
					RCC->APB1RSTR.RegisterAccess |= (1<<0); break;

		/* For AHB peripherals */

		case RCC_u8_OTGFS:
					RCC->AHBRSTR.RegisterAccess |= (1<<12); break;
		case RCC_u8_CRC:
					RCC->AHBRSTR.RegisterAccess |= (1<<6); break;
		case RCC_u8_SRAM:
					RCC->AHBRSTR.RegisterAccess |= (1<<2); break;
		case RCC_u8_DMA2:
					RCC->AHBRSTR.RegisterAccess |= (1<<1); break;
		case RCC_u8_DMA1:
					RCC->AHBRSTR.RegisterAccess |= (1<<0); break;
		default:
			Local_u8Error = STD_ERROR_NOK;
	}
	/* Function return */
	return Local_u8Error;
}
