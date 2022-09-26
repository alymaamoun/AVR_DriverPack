/*-------------------------------------------------------------------------------------------------------
 * File Name: 	uart.c
 *
 * Author: 		Aly Maamoun
 *
 * Date: 		14/10/2021
 *
 * Description:	Source file for UART module driver for AVR
 -------------------------------------------------------------------------------------------------------*/

#include "uart.h"

#include <avr/io.h>
#include "../../common_macros.h"


void UART_init(uint32 BaudRate){
	uint16 UBRR_value=0;

	UCSRA=0;
	SET_BIT(UCSRA,U2X);

	UCSRB=0;
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);

	UCSRC=0;
	SET_BIT(UCSRC,URSEL);
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);

	UBRR_value=((F_CPU/(8*BaudRate))-1);
	UBRRH=(UBRR_value>>8);
	UBRRL=UBRR_value;
}

void UART_sendByte(const uint8 data){
	while(BIT_IS_CLEAR(UCSRA,UDRE));
	UDR=data;
}

uint8 UART_recieveByte(void){
	while(BIT_IS_CLEAR(UCSRA,RXC));
	return UDR;
}

void UART_sendString(const uint8 *str){
	for(uint8 i=0;str[i]!='\0';i++){
		UART_sendByte(str[i]);
	}
}

void UART_recieveString(uint8 * str){
	uint8 i=0;
	for(;str[i]!='#';i++){
		str[i]=UART_recieveByte();
	}
	str[i]='\0';
}
