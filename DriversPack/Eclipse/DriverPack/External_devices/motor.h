/*
 * motor.h
 *
 *  Created on: Oct 7, 2021
 *      Author: user
 */

#ifndef EXTERNAL_DEVICES_MOTOR_H_
#define EXTERNAL_DEVICES_MOTOR_H_

#include "../std_types.h"


#define A PIN1_ID
#define B PIN2_ID
#define MOTOR_PORT PORTB_ID

typedef enum{
	 CW,A_CW,stop
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* EXTERNAL_DEVICES_MOTOR_H_ */
