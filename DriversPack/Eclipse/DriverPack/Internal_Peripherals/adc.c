/*********************************************************************************************
 * File Name:	adc.c
 *
 * Author: 		Aly Maamoun
 *
 * Date: 		6/10/2021
 *
 * Description: Source file for ADC Module Driver
 *********************************************************************************************/


/*---------------------------------------INCLUDES--------------------------------------------*/

#include "../Internal_Peripherals/adc.h"

#include <avr/io.h>
#include "../common_macros.h"
#include "util/delay.h"
#include <avr/interrupt.h>
#include "gpio.h"

/*---------------------------------------Global Variables-------------------------------------*/

volatile uint16 ADC_INT =0;
volatile uint8 ADC_REF_VOLT;

/*---------------------------------------FUNCTION Definitions---------------------------------*/

void ADC_init(const ADC_ConfigType * Config_Ptr){
	ADMUX=0; 									//clearing ADMUX to clear ADLAR and Channel bits
	ADCSRA=0;									//clearing ADCSRA
	ADMUX=((Config_Ptr->ref_volt)<<REFS0);		//Setting the selected reference voltage
	ADCSRA=(Config_Ptr->prescaler);				//Setting the prescalar
#ifdef INTERRUPT								//if Interrupt was selected
	SET_BET(ADCSRA,ADIE);						//Enable ADC Interrupt
#endif
#ifdef POLLING									//if Polling was selected
	CLEAR_BIT(ADCSRA,ADIE);						//disable ADC Interrupt
#endif
	SET_BIT(ADCSRA,ADEN);						//Enabling ADC Module
	if(Config_Ptr->ref_volt==AREF_INTERNAL_VREF_TURNED_OFF){
		ADC_REF_VOLT=5;
	}
	else if(Config_Ptr->ref_volt==INTERNAL_2_56V_VOLTAGE_REFERENCE_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN){
		ADC_REF_VOLT=2;
	}
}




uint16 ADC_readChannel(ANALOG_CHANNEL channel){
	ADMUX=(ADMUX&0xE0)|channel;					//Setting the selected channel
	SET_BIT(ADCSRA,ADSC);						//Starting Conversion
#ifdef POLLING									//If Polling was Selected
	while(BIT_IS_CLEAR(ADCSRA,ADIF));			//busy loop till ADC finish conversion
	SET_BIT(ADCSRA,ADIF);						//Clearing the flag
	return ADC;									//Reading the Value
#endif
#ifdef INTERRUPT
return 0;										//return dummy variable
#endif


}


#ifdef INTERRUPT								//if interrupt was selected
ISR(ADC_vect){									//ISR Function of ADC
	ADC_INT=ADC;								//Putting the value in global variable which is externed
}

#endif
