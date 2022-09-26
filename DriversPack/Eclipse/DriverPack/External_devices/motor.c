/********************************************************************************************************************************
 * File Name: 	motor.c
 *
 * Author: 		Aly Maamoun
 *
 * Data: 		6/10/2021
 *
 * Description:	Source file for motor driver
 *
 ***********************************************************************************************************************************/





/***********************************************INCLUDES**************************************************************************/



#include "../External_devices/motor.h"

#include <avr/io.h>

#include "../Internal_Peripherals/gpio.h"
#include "../Internal_Peripherals/timer.h"
#include "../common_macros.h"

/**********************************************Global variables*************************************************************************/

volatile uint8 duty_cycle=0;

/*********************************************Functions ************************************************************************/

void DcMotor_Init(void){
	GPIO_setupPinDirection(MOTOR_PORT, A, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT, B, PIN_OUTPUT);
	TIMER0_pwm_init(CLK_8_TIMER, CLEAR_OC0_ON_COMPARE_MATCH);
	DcMotor_Rotate(stop, 0);
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	duty_cycle=((uint32)speed*255)/100;
	switch(state){
	case CW:
		GPIO_writePin(MOTOR_PORT, A, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT, B, LOGIC_HIGH);
		TIMER0_pwm(duty_cycle);
		break;
	case A_CW:
		GPIO_writePin(MOTOR_PORT, A, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT, B, LOGIC_LOW);
		TIMER0_pwm(duty_cycle);
		break;

	case stop:
		GPIO_writePin(MOTOR_PORT, A, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT, B, LOGIC_LOW);
		TIMER0_pwm(0);
		break;

}
}
