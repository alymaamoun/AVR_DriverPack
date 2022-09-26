/*-------------------------------------------------------------------------------------------------------
 * File Name: 	uart.h
 *
 * Author: 		Aly Maamoun
 *
 * Date: 		14/10/2021
 *
 * Description:	Header file for UART module driver for AVR
 -------------------------------------------------------------------------------------------------------*/

#ifndef INTERNAL_PERIPHERALS_SERIAL_COMMUNICATIONS_UART_H_
#define INTERNAL_PERIPHERALS_SERIAL_COMMUNICATIONS_UART_H_

#include "../../std_types.h"

void UART_init(uint32 BaudRate);

void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *str);

void UART_recieveString(uint8 * str);

#endif /* INTERNAL_PERIPHERALS_SERIAL_COMMUNICATIONS_UART_H_ */
