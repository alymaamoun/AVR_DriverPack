/*********************************************************************************************************
 * File Name: 	adc.h
 *
 * Author: 		Aly Maamoun
 *
 * Date:		10/6/2021
 *
 * Description: Header file for analog to digital converter module driver
 *
 ********************************************************************************************************/

#ifndef INTERNAL_PERIPHERALS_ADC_H_
#define INTERNAL_PERIPHERALS_ADC_H_

/*-----------------------------------------INCLUDES-----------------------------------------------------*/

#include "../std_types.h"


/*----------------------------------------CONFIGURATION------------------------------------------------*/

#define ADC_MAX_VALUE 1023

#define POLLING
//#define INTERRUPT				//NEVER EARSE


/*----------------------------------------EXTERN MODULE------------------------------------------------*/

extern volatile uint16 ADC_INT;
extern volatile uint8 ADC_REF_VOLT;

/*-------------------------------------------ENUMS-----------------------------------------------------*/

typedef enum{
	AREF_INTERNAL_VREF_TURNED_OFF,AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN,xxxx,INTERNAL_2_56V_VOLTAGE_REFERENCE_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN
}ADC_ReferenceVolatge;

typedef enum{
	CLK_2_1_ADC,CLK_2_2_ADC,CLK_4_ADC,CLK_8_ADC,CLK_16_ADC,CLK_32_ADC,CLK_64_ADC,CLK_128_ADC
}ADC_Prescaler;

typedef enum{
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}ANALOG_CHANNEL;


/*-----------------------------------------Structures------------------------------------------------*/


typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;


/*-------------------------------------------Functions Declaration-----------------------------------*/



void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(ANALOG_CHANNEL channel);




#endif /* INTERNAL_PERIPHERALS_ADC_H_ */
