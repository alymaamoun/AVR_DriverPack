#include "../Internal_Peripherals/timer.h"

#include <avr/io.h>
#include "../common_macros.h"
#include "gpio.h"

void TIMER0_normal(PRESCALAR prescalar,uint8 initial){
	TCNT0=initial;
	TCCR0=prescalar;
	SET_BIT(TCCR0,FOC0);
	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_ctc(PRESCALAR prescalar,uint8 compare,uint8 initial,COMPRARE_OUTPUT_MODE_NON_PWM_MODE_TIMER0 mode){
	TCNT0=initial;
	OCR0=compare;
	TCCR0=prescalar;
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,FOC0);
	TCCR0=(TCCR0&0xcf)|(mode<<COM00);
	SET_BIT(TIMSK,OCIE0);
}

void TIMER0_pwm_init(PRESCALAR prescalar,COMPRARE_OUTPUT_MODE_FAST_PWM_MODE_TIMER0 mode){
	TCNT0=0;
	OCR0=0;
	TCCR0=prescalar;
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	TCCR0=(TCCR0&0xcf)|(mode<<COM00);
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

}
void TIMER0_pwm(uint8 duty_cycle){
	OCR0=duty_cycle;
}
