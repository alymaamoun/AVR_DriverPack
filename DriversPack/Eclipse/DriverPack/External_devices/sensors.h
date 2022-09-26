/****************************************************************************************************
 * File Name:	sensors.h
 *
 * Author: 		Aly Maamoun
 *
 * Date: 		6/10/2021
 *
 * Description:	header file for different sensors modules drivers
 ******************************************************************************************************/

#ifndef EXTERNAL_DEVICES_SENSORS_H_
#define EXTERNAL_DEVICES_SENSORS_H_

/*-----------------------------------------INCLUDES-----------------------------------------------------*/

#include "../std_types.h"

/*----------------------------------------CONFIGURATION------------------------------------------------*/

#define LM35_MAX_TEMP 150
#define LM35_MAX_VOLT 1.5
#define LM35_channel ADC2

/*-------------------------------------------Functions Declaration-----------------------------------*/

uint8 LM35_getTemperature(void);

#endif /* EXTERNAL_DEVICES_SENSORS_H_ */
