#include "../Internal_Peripherals/icu.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../common_macros.h"
#include "gpio.h"


static volatile void (*g_callBack)(void)=NULL_PTR;

ISR(TIMER1_CAPT_vect){
	if(g_callBack!=NULL_PTR){
		g_callBack();
	}
}

void ICU_init(const ICU_Config * Config){
	GPIO_setupPinDirection(PORTD_ID, PIN6_ID, PIN_INPUT);
	TCCR1A=(1<<FOC1A)|(1<<FOC1B);
	TCCR1B=(TCCR1B & 0xF8) | (Config->clk);
	TCCR1B=(TCCR1B&0xBF)|((Config->edge)<<ICES1);
	TCNT1=0;
	ICR1=0;
	SET_BIT(TIMSK,TICIE1);
}


void ICU_SetCallBack(void(*ptr)(void)){
	g_callBack=ptr;
}



void ICU_SetEdge(const ICU_Edge edge){
	TCCR1B=(TCCR1B&0xBF)|(edge<<ICES1);
}

uint16 ICU_getRead(void){
	return ICR1;
}

void ICU_ClearData(void){
	TCNT1=0;
}

void ICU_deinit(void){
	TCCR1A=0;
	TCCR1B=0;
	TCNT1=0;
	ICR1=0;
	CLEAR_BIT(TIMSK,TICIE1);
}
