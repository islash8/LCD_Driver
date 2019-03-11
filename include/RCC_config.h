/***********************************************************************************/
/*																				   */
/* Author: Islam A.				                            	  				   */
/* Date: 07 MAR 2019                                                               */
/* Version: 01                                                                     */
/* Description: Configuration file for RCC Driver  in STM32F103                    */
/*																				   */
/***********************************************************************************/

/***************************** Preprocessor Guard **********************************/

#ifndef RCC_CONFIG_H 
#define RCC_CONFIG_H 

/***********************************************************************************/

/***********************************************************************************/
/* 																				   */
/*  Initial configuration of the System Clock register							   */
/*  Expected inputs : RCC_u8_HSI --> for High speed internal clock				   */
/* 		  			  RCC_u8_HSE --> for High speed external clock				   */
/* 		  			  RCC_u8_PLL --> for Phase locked loop						   */
/*																				   */
/***********************************************************************************/

#define RCC_u8_SYS_CLOCK      RCC_u8_HSI

/**********************************************************************************/
/*																				  */
/* Initial states of the different clocks, what clock is operating by default     */
/* Expected input: RCC_u8_ENABLE  --> To enable corresponding clock				  */
/* 	    	 	   RCC_u8_DISABLE --> To disable corresponding clock              */
/*																				  */
/**********************************************************************************/

#define RCC_u8_HSI_STATE 	 RCC_u8_ENABLE
#define RCC_u8_HSE_STATE    RCC_u8_DISABLE
#define RCC_u8_PLL_STATE    RCC_u8_DISABLE


/********** Macros configured in case of using PLL as the system clock ***********/
/* 																				 */
/* 1- first you have to configure what will be the input clock for PREDIV1       */
/* --> (either it will be HSE or PLL2)											 */
/* 2- Select PREDIV1 division factor for the PREDIV1 input clock			     */
/* -->(whether it HSE or PLL2) -> /2 or as not divided							 */
/* 3- configure what will be the input clock for PLLSRC							 */
/* --> (either it will be HSI/2 or the PREDIV1 clock)							 */
/* 4- Define the PLL multiplication factor										 */
/*																				 */
/*********************************************************************************/

/*********************************************************************************/
/*																				 */
/* Macro to determine the PREDIV1 entry clock source							 */
/* Expected inputs: --> RCC_u8_HSE												 */
/*        			--> RCC_u8_PLL2												 */
/*																				 */
/*********************************************************************************/

#define RCC_u8_PREDIV1SRC     RCC_u8_HSE

/*********************************************************************************/
/*																				 */
/* Macro for LSB of division factor PREDIV1 to determine if the PLL input clock  */
/* will be divided by 2 or not													 */
/* (in case your choosing the PLL2 as the input clock for PREDIV1)				 */
/* Expected inputs: -> RCC_u8_DIVIDED_BY_2										 */
/*        			-> RCC_u8_NOT_DIVIDED										 */
/*																				 */
/*********************************************************************************/

#define RCC_u8_PLLXTPRE        RCC_u8_NOT_DIVIDED

/*********************************************************************************/
/*																				 */
/*  Macro to determine the PLL entry source 									 */
/*  Range: -> RCC_u8_HSI_DIVIDED_BY_2											 */
/* 		   -> RCC_u8_PREDIV1_CLK_SOURCE											 */
/*																				 */
/*********************************************************************************/

#define RCC_u8_PLLSRC           RCC_u8_HSI_DIVIDED_BY_2

/********************************************************************************/
/*																				*/
/* Macro to determine the PLL multiplication factor								*/
/* Expected inputs: -> RCC_u8_PLL_MULTIPLED_BY_4							    */
/* 		  			-> RCC_u8_PLL_MULTIPLED_BY_5						        */
/* 		  			-> RCC_u8_PLL_MULTIPLED_BY_6								*/
/* 		  			-> RCC_u8_PLL_MULTIPLED_BY_7								*/
/* 		  			-> RCC_u8_PLL_MULTIPLED_BY_8								*/
/* 		  			-> RCC_u8_PLL_MULTIPLED_BY_9								*/
/* 		  			-> RCC_u8_PLL_MULTIPLED_BY_6.5								*/
/*																				*/
/********************************************************************************/

#define RCC_u8_PLLMUL        RCC_u8_PLL_MULTIPLED_BY_4

/********************************************************************************/
/*																				*/
/*  Initial configuration of AHB prescaler										*/
/*  Expected inputs: -> RCC_u8_NOT_DIVIDED										*/
/* 		  			 -> RCC_u8_DIVIDED_BY_2										*/
/* 		  			 -> RCC_u8_DIVIDED_BY_4										*/
/* 		  			 -> RCC_u8_DIVIDED_BY_8										*/
/* 		  			 -> RCC_u8_DIVIDED_BY_16									*/
/* 		  			 -> RCC_u8_DIVIDED_BY_64									*/
/* 		  			 -> RCC_u8_DIVIDED_BY_128									*/
/* 		  			 -> RCC_u8_DIVIDED_BY_256									*/
/* 		  			 -> RCC_u8_DIVIDED_BY_512									*/
/*																				*/
/********************************************************************************/

#define RCC_u8_AHB_PRESCALER  RCC_u8_NOT_DIVIDED

/*******************************************************************************/
/*																			   */
/*  Initial configuration of APB1 prescaler									   */
/*  Expected inputs: -> RCC_u8_NOT_DIVIDED									   */
/* 		  			 -> RCC_u8_DIVIDED_BY_2									   */
/* 		  			 -> RCC_u8_DIVIDED_BY_4									   */
/* 		  			 -> RCC_u8_DIVIDED_BY_8									   */
/* 		  			 -> RCC_u8_DIVIDED_BY_16								   */
/*																			   */
/*******************************************************************************/

#define RCC_u8_APB1_PRESCALER  RCC_u8_NOT_DIVIDED

/******************************************************************************/
/*																			  */
/*  Initial configuration of APB2 prescaler									  */
/*  Expected inputs: -> RCC_u8_NOT_DIVIDED									  */
/* 		  			 -> RCC_u8_DIVIDED_BY_2									  */
/* 		  			 -> RCC_u8_DIVIDED_BY_4									  */
/* 		  			 -> RCC_u8_DIVIDED_BY_8									  */
/* 		  			 -> RCC_u8_DIVIDED_BY_16								  */
/*																			  */
/******************************************************************************/

#define RCC_u8_APB2_PRESCALER  RCC_u8_NOT_DIVIDED

#endif /* RCC_CONFIG_H */ 

