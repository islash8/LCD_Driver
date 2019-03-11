/********************************************************************/
/* Author  : Islam A.			                                    */
/* Date    : 04 MAR 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Header file for using DIO interfaces peripheral in STM32F103     */
/********************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/* DIO Pins Macros */
typedef enum
{
	  DIO_u8_PIN0,	/* -> PINA0  */
	  DIO_u8_PIN1,	/* -> PINA1  */
	  DIO_u8_PIN2,	/* -> PINA2  */
	  DIO_u8_PIN3,	/* -> PINA3  */
	  DIO_u8_PIN4,	/* -> PINA4  */
	  DIO_u8_PIN5,	/* -> PINA5  */
	  DIO_u8_PIN6,	/* -> PINA6  */
	  DIO_u8_PIN7,	/* -> PINA7  */
	  DIO_u8_PIN8,	/* -> PINA8  */
	  DIO_u8_PIN9,	/* -> PINA9  */
	  DIO_u8_PIN10,	/* -> PINA10 */
	  DIO_u8_PIN11,	/* -> PINA11 */
	  DIO_u8_PIN12,	/* -> PINA12 */
	  DIO_u8_PIN13,	/* -> PINA13 */
	  DIO_u8_PIN14,	/* -> PINA14 */
	  DIO_u8_PIN15,	/* -> PINA15 */
	  DIO_u8_PIN16,	/* -> PINB0  */
	  DIO_u8_PIN17,	/* -> PINB1  */
	  DIO_u8_PIN18, /* -> PINB2  */
	  DIO_u8_PIN19,	/* -> PINB3  */
	  DIO_u8_PIN20,	/* -> PINB4  */
	  DIO_u8_PIN21,	/* -> PINB5  */
	  DIO_u8_PIN22,	/* -> PINB6  */
	  DIO_u8_PIN23,	/* -> PINB7  */
	  DIO_u8_PIN24,	/* -> PINB8  */
	  DIO_u8_PIN25,	/* -> PINB9  */
	  DIO_u8_PIN26,	/* -> PINB10 */
	  DIO_u8_PIN27,	/* -> PINB11 */
	  DIO_u8_PIN28,	/* -> PINB12 */
	  DIO_u8_PIN29,	/* -> PINB13 */
	  DIO_u8_PIN30,	/* -> PINB14 */
	  DIO_u8_PIN31,	/* -> PINB15 */
	  DIO_u8_PIN32,	/* -> PINC0  */
	  DIO_u8_PIN33,	/* -> PINC1  */
	  DIO_u8_PIN34,	/* -> PINC2  */
	  DIO_u8_PIN35,	/* -> PIND0  */
	  DIO_u8_PIN36	/* -> PIND1  */
}DIO_enu_PINS;

/* Assignment Macros for pins */
#define DIO_u8_PIN_HIGH            (u8)1
#define DIO_u8_PIN_LOW             (u8)0

#define DIO_u8_PORT_HIGH            (u8)1
#define DIO_u8_PORT_LOW             (u8)0

/* Macros for ports mapping */
#define DIO_u8_PORTA           (u8)0
#define DIO_u8_PORTB           (u8)1
#define DIO_u8_PORTC           (u8)2
#define DIO_u8_PORTD           (u8)3

/* Macros used for the CNF register, CNF bits, inputs */
#define DIO_u8_INPUT_ANALOG          0b0000
#define DIO_u8_INPUT_FLOATING        0b0100
#define DIO_u8_INPUT_PULL_UP         0b1000
#define DIO_u8_INPUT_PULL_DOWN       0b1100

/* Macros used for the CNF register, CNF bits, outputs */
#define DIO_u8_OUTPUT_2M_PP          0b0010
#define DIO_u8_OUTPUT_2M_OD          0b0110
#define DIO_u8_OUTPUT_2M_AFPP        0b1010
#define DIO_u8_OUTPUT_2M_AFOD        0b1110

/* Macros used for the CNF register, CNF bits, outputs */
#define DIO_u8_OUTPUT_10M_PP         0b0001
#define DIO_u8_OUTPUT_10M_OD         0b0101
#define DIO_u8_OUTPUT_10M_AFPP       0b1001
#define DIO_u8_OUTPUT_10M_AFOD       0b1101

/* Macros used for the CNF register, CNF bits, outputs */
#define DIO_u8_OUTPUT_50M_PP         0b0011
#define DIO_u8_OUTPUT_50M_OD         0b0111
#define DIO_u8_OUTPUT_50M_AFPP       0b1011
#define DIO_u8_OUTPUT_50M_AFOD       0b1111

void DIO_vInit(void);

/*
 * Description: Function to set the initialized direction and value of each pin in all ports
 * Inputs: none
 * Output: void
 */
void DIO_vInit (void);

/*
 * Description: Function to set the direction of a specific pin in a specified port
 * Inputs: the pin number , the pin direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinDirection (u8 Copy_u8PinNb,u8 Copy_u8Mode);

/*
 * Description: Function to set a specific pin in a specified port with a specified value (INPUT = 0,OUTPUT = 1)
 * Inputs: the pin number , the pin value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinValue (u8 Copy_u8PinNb, u8 Copy_u8Value);

/*
 * Description: Function to get the value of a certain input pin in a specified port
 * Inputs: the pin number , the container variable which will hold the value on this pin
 * output: the Error state of the function
 */
u8 DIO_u8GetPinValue (u8 Copy_u8PinNb,u8 *Copy_Pu8PinValue);

/*
 * Description: Function to set pins of a specified port with a specified value
 * Inputs: the port number , the port value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPortValue (u8 Copy_u8PortNb,u8 Copy_u8Value);

/*
 * Description: Function to get the value of a specified port
 * Inputs: the port number , the container variable which will hold the value on this port
 * output: the Error state of the function
 */
u8 DIO_u8GetPortValue (u8 Copy_u8PortNb, u8 *Copy_Pu8PortValue);

#endif /* DIO_INTERFACE_H_ */
