//

/*-------------------------------------------------------------------------------------------------------------
 * File Name:		main.h
 *
 * Author: 			Aly maamoun
 *
 * Date: 			13/10/2021
 *
 * Description: 	Source file for Application layer of Ultrasonic reading distance and display it on LCD
 *
 ------------------------------------------------------------------------------------------------------------*/



#define F_CPU	8000000UL							/*Making the uc work in 8MHZ mode*/


/*----------------------------------------------INCLUDES-----------------------------------------------------*/
#include "External_devices/ultrasonic.h"
#include "External_devices/lcd.h"
#include "Internal_Peripherals/gpio.h"
#include <avr/io.h>
#include "common_macros.h"


/*------------------------------------------MAIN FUNCTION---------------------------------------------------*/

int main(void){
	SET_BIT(SREG,7);											/*Enabling the Global Interrupt*/
	Ultrasonic_init();											/*Initializing the Ultrasonic Module*/
	LCD_init();													/*Initializing the LCD Module*/
	LCD_displayString("Distance:    cm");
	while(1){

		LCD_moveCursor(0, 9);
		LCD_intgerToString(Ultrasonic_readDistance());			/*Displaying the distance calculated*/
		LCD_displayCharacter(' ');

	}
}


