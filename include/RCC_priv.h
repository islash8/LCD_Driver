/*************************************************************************************/
/*																					 */
/* Author: Islam A.                         			   							 */
/* Date: 06 MAR 2019                                                                 */
/* Version: 01                                                                       */
/* Description: Private file for RCC Driver in STM32F103   							 */
/*																					 */
/*************************************************************************************/

/***************************** Preprocessor Guard ************************************/

#ifndef RCC_PRIV_H 
#define RCC_PRIV_H 

/*************************** STM32F103 RCC registers *********************************/

typedef struct
{
	Register_32Bit CR;
	Register_32Bit CFGR;
	Register_32Bit CIR;
	Register_32Bit APB2RSTR;
	Register_32Bit APB1RSTR;
	Register_32Bit AHBENR;
	Register_32Bit APB2ENR;
	Register_32Bit APB1ENR;
	Register_32Bit BDCR;
	Register_32Bit CSR;
	Register_32Bit AHBRSTR;
	Register_32Bit CFGR2;
}RCC_REG;

/* RCC base address	*/

#define  RCC    	  					((RCC_REG*)0x40021000)

/* Macros for system clock definition */

#define RCC_u8_HSI   					(u8)0
#define RCC_u8_HSE   					(u8)1
#define RCC_u8_PLL   					(u8)2
#define RCC_u8_PLL2  					(u8)3

/* Macros to determine the PLL entry source */

#define RCC_u8_HSI_DIVIDED_BY_2        (u8)0
#define RCC_u8_PREDIV1_CLK_SOURCE      (u8)1

/* Macros for PLL multiplication factor */

#define  RCC_u8_PLL_MULTIPLED_BY_4     0b0010
#define	 RCC_u8_PLL_MULTIPLED_BY_5     	0b0011
#define  RCC_u8_PLL_MULTIPLED_BY_6     0b0100
#define  RCC_u8_PLL_MULTIPLED_BY_7     0b0101
#define  RCC_u8_PLL_MULTIPLED_BY_8     0b0110
#define  RCC_u8_PLL_MULTIPLED_BY_9     0b0111
#define  RCC_u8_PLL_MULTIPLED_BY_6_5   0b1101

/* Macros for prescaler probable states */

#define RCC_u8_NOT_DIVIDED            	(u8)0
#define RCC_u8_DIVIDED_BY_2           	(u8)1
#define RCC_u8_DIVIDED_BY_4           	(u8)2
#define RCC_u8_DIVIDED_BY_8           	(u8)3
#define RCC_u8_DIVIDED_BY_16          	(u8)4
#define RCC_u8_DIVIDED_BY_64          	(u8)5
#define RCC_u8_DIVIDED_BY_128        	(u8)6
#define RCC_u8_DIVIDED_BY_256        	(u8)7
#define RCC_u8_DIVIDED_BY_512        	(u8)8

#define RCC_u8_ENABLE      				(u8)0
#define RCC_u8_DISABLE     				(u8)1

#endif /* RCC_PRIV_H */ 
