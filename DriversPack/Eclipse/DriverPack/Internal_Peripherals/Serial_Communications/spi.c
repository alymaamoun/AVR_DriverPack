/*-------------------------------------------------------------------------------------------------------
 * File Name: 	spi.c
 *
 * Author: 		Aly Maamoun
 *
 * Date: 		14/10/2021
 *
 * Description:	Source file for SPI module driver for AVR
 -------------------------------------------------------------------------------------------------------*/


#include "spi.h"

#include <avr/io.h>

#include "../gpio.h"
#include "../../common_macros.h"

volatile uint8 SPI_DEFAULT_VALUE=0xff;

void SPI_initMaster(void){

	GPIO_setupPinDirection(SPI_PORT, MISO, PIN_INPUT);
	GPIO_setupPinDirection(SPI_PORT, MOSI, PIN_OUTPUT);
	GPIO_setupPinDirection(SPI_PORT, SCK, PIN_OUTPUT);
	GPIO_setupPinDirection(SPI_PORT, SS, PIN_OUTPUT);

	SPCR=0;
	SET_BIT(SPCR,SPE);
	SET_BIT(SPCR,MSTR);

	CLEAR_BIT(SPSR,SPI2X);
}

void SPI_Slave(void){
	GPIO_setupPinDirection(SPI_PORT, MISO, PIN_OUTPUT);
	GPIO_setupPinDirection(SPI_PORT, MOSI, PIN_INPUT);
	GPIO_setupPinDirection(SPI_PORT, SCK, PIN_INPUT);
	GPIO_setupPinDirection(SPI_PORT, SS, PIN_INPUT);

	SPCR=0;
	SET_BIT(SPCR,SPE);

	CLEAR_BIT(SPSR,SPI2X);
}

uint8 SPI_SendReceiveByte(uint8 data)
{
	SPDR=data;
	while(BIT_IS_CLEAR(SPSR,SPIF));
	return SPDR;
}

void SPI_sendString(const uint8 * str)
{
	for(uint8 i=0;str[i]!='\0';i++){
		SPI_SendReceiveByte(str[i]);
	}
}

void SPI_receiveString( uint8 * str)
{
	uint8 i=0;
	str[i]=SPI_SendReceiveByte(SPI_DEFAULT_VALUE);
	while(str[i]!='#'){
		i++;
		str[i]=SPI_SendReceiveByte(SPI_DEFAULT_VALUE);
	}
	str[i]='\0';
}
