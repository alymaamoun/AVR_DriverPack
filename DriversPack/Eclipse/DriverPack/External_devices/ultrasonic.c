/*-------------------------------------------------------------------------------------------------------------
 * File Name:		ultrasonic.c
 *
 * Author: 			Aly maamoun
 *
 * Date: 			13/10/2021
 *
 * Description: 	Source file for ultrasonic module driver
 *
 ------------------------------------------------------------------------------------------------------------*/





/*------------------------------------------------INCLUDES----------------------------------------------------------*/


#include "../External_devices/ultrasonic.h"

#include <avr/io.h>
#include "../common_macros.h"
#include "util/delay.h"

#include "../Internal_Peripherals/gpio.h"
#include "../Internal_Peripherals/icu.h"


/*-------------------------------------------------Global Variables--------------------------------------------------*/

volatile char g_tick=0;
volatile uint32 time_high=0;
volatile uint32 distance=0;
volatile char working=0;




/*-----------------------------------------------Functions Definitions------------------------------------------------*/


void Ultrasonic_init(void){
	ICU_Config ICU_CONFIG={FCPU_CLK_8,RISING};					/*Making the Structure configuration for the ICU*/
	ICU_init(&ICU_CONFIG);										/*Passing the Configuration Structure to the ICU*/
	ICU_SetCallBack(Ultrasonic_edgeProcessing);					/*Selecting the call back function*/
	GPIO_setupPinDirection(TRIGGER_PORT, TRIGGER_PIN, PIN_OUTPUT);		/*Configuring specific pin to send trigger to the Ultrasonic*/
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW);
	Ultrasonic_Trigger();										/*Initializing Signal*/


}
void Ultrasonic_Trigger(void){									/*This function will send trigger signal for 10 us*/
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW);
}

void Ultrasonic_edgeProcessing(void){
	g_tick++;
	if(BIT_IS_CLEAR(PORTD,PIN6_ID))								/*This line till if(working) is to stabilize the synchronizing with ultrasonic*/
		working=1;
	if(working){
	if(g_tick==1){
		ICU_ClearData();									/*Clear value of timer counter*/
		ICU_SetEdge(FALLING);						/*Search for Falling edge to calculate the period of Logic High */
	}
	else if(g_tick==2){
		time_high=ICU_getRead();					/*get the period of Logic High*/
		ICU_ClearData();									/*Clear value of timer counter*/
		ICU_SetEdge(RISING);						/*Search for Rising again for next signal*/
	}
}
}


uint16 Ultrasonic_readDistance(void){
	Ultrasonic_Trigger();											/*Starting the Signal to receive it back to calculate the time*/
	if(g_tick==2){													/*Then we get the period of the rising edge*/
		distance=((time_high*5)/294)+((sint32)(distance-57)/73)+1;	/*converting from sound speed and Micro second to distance and seconds + error handling*/
		if(distance>57){											/*Error handling*/
			distance++;
		}
		g_tick=0;}
	return distance;
}

