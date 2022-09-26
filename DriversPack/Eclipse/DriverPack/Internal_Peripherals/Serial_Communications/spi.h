/*-------------------------------------------------------------------------------------------------------
 * File Name: 	spi.c
 *
 * Author: 		Aly Maamoun
 *
 * Date: 		14/10/2021
 *
 * Description:	Header file for SPI module driver for AVR
 -------------------------------------------------------------------------------------------------------*/




#ifndef INTERNAL_PERIPHERALS_SERIAL_COMMUNICATIONS_SPI_H_
#define INTERNAL_PERIPHERALS_SERIAL_COMMUNICATIONS_SPI_H_


#include "../../std_types.h"

#define SS			PIN4_ID
#define MOSI		PIN5_ID
#define MISO		PIN6_ID
#define SCK			PIN7_ID
#define SPI_PORT	PORTB_ID


void SPI_initMaster			(void);

void SPI_Slave				(void);

uint8 SPI_SendReceiveByte	(uint8 data);

void SPI_sendString			(const uint8 * str);

void SPI_receiveString		( uint8 * str);


#endif /* INTERNAL_PERIPHERALS_SERIAL_COMMUNICATIONS_SPI_H_ */
