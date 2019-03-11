/********************************************************************/
/* Author  : Islam A.			                                    */
/* Date    : 04 MAR 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Header file for using DIO Private peripheral in STM32F103        */
/********************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

typedef struct
{
	Register_32Bit CRL;
	Register_32Bit CRH;
	Register_32Bit IDR;
	Register_32Bit ODR;
	Register_32Bit BSRR;
	Register_32Bit BRR;
	Register_32Bit LCKR;
}GPIO;

/* Macros for pins initialized states in case the pin is output */
#define DIO_u8_INIT_HIGH 1
#define DIO_u8_INIT_LOW  0

/* Macros for pins initialized states in case the pin is output */
#define DIO_u8_INIT_HIGH 1
#define DIO_u8_INIT_LOW  0

#define DIO_u8_INPUT_PULL_UP_DOWN	 	0b1000

/* Macro for number of pins in a single port */
#define DIO_u8NUMBER_OF_PINS_IN_PORT (u8)16

#define DIO_u8MAXPortNB (u8)4


#define DIO_PORTA ((GPIO*)0x40010800)
#define DIO_PORTB ((GPIO*)0x40010C00)
#define DIO_PORTC ((GPIO*)0x40011000)
#define DIO_PORTD ((GPIO*)0x40011400)

GPIO * GPIO_AGPIOPorts[DIO_u8MAXPortNB] = {DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD};


#endif /* DIO_PRIVATE_H_ */
