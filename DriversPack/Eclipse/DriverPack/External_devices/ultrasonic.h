/*-------------------------------------------------------------------------------------------------------------
 * File Name:		ultrasonic.h
 *
 * Author: 			Aly maamoun
 *
 * Date: 			13/10/2021
 *
 * Description: 	Header file for ultrasonic module driver
 *
 ------------------------------------------------------------------------------------------------------------*/


#ifndef EXTERNAL_DEVICES_ULTRASONIC_H_
#define EXTERNAL_DEVICES_ULTRASONIC_H_

/*-------------------------------------------------INCLUDES-------------------------------------------------------*/

#include "../std_types.h"


/*-------------------------------------------------DEFINITIONS----------------------------------------------------*/

#define TRIGGER_PIN 	PIN5_ID
#define TRIGGER_PORT	PORTB_ID

/*-----------------------------------------------FUNCTIONS PROTOTYPE----------------------------------------------*/


/*Initializing and Configuring the module*/
void Ultrasonic_init(void);
/*Sending Trigger to the Module*/
void Ultrasonic_Trigger(void);
/*Calculate the distance from the givens from the module*/
uint16 Ultrasonic_readDistance(void);
/*Getting the time of Logic High from the received Echo back*/
void Ultrasonic_edgeProcessing(void);


#endif /* EXTERNAL_DEVICES_ULTRASONIC_H_ */
