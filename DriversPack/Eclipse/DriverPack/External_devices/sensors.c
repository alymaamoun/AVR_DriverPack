/****************************************************************************************************
 * File Name:	sensors.c
 *
 * Author: 		Aly Maamoun
 *
 * Date: 		6/10/2021
 *
 * Description:	Source file for different sensors modules drivers
 ******************************************************************************************************/

/*------------------------------------------INCLUDES------------------------------------------------*/

#include "../External_devices/sensors.h"

#include "../Internal_Peripherals/adc.h"

/*---------------------------------------FUNCTION Definitions---------------------------------------*/





uint8 LM35_getTemperature(void){
	uint16 adc=0;
	uint8 temperature=0;
	adc=ADC_readChannel(LM35_channel);
	temperature=(uint8)(((uint32)adc*2.56*LM35_MAX_TEMP)/(LM35_MAX_VOLT*ADC_MAX_VALUE));
	return temperature;
}
