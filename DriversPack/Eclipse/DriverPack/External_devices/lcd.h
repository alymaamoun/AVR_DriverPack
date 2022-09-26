/***************************************************************************************************
 * File Name: lcd.c
 * Author: Aly maamoun
 * Date: 1/10/2021
 * Description: LCD driver
 ************************************************************************************************/




#ifndef EXTERNAL_DEVICES_LCD_H_
#define EXTERNAL_DEVICES_LCD_H_


/*********************************************************************************************************
*******************************************INCLUDES****************************************************
***********************************************************************************************************/
#include <avr/io.h>
#include "util/delay.h"

#include "../Internal_Peripherals/gpio.h"
#include "../std_types.h"
#include "../common_macros.h"


/*********************************************************************************************************
*******************************************DEFINITIONS****************************************************
***********************************************************************************************************/

#define LCD_CONTROL_PORT_ID 						PORTB_ID
#define LCD_DATA_PORT_ID							PORTA_ID
#define ENABLE_ID									PIN2_ID
#define RW_ID										PIN1_ID
#define RS_ID										PIN0_ID


#define FIGURE_DELAY 								1


#define CLEAR_DISPLAY_SCREEN 						0x01
#define RETURN_HOME 								0x02
#define SHIFT_CURSOR_TO_LEFT						0x04
#define SHIFT_DISPLAY_RIGHT							0x05
#define SHIFT_CURSOR_TO_RIGHT						0x06
#define SHIFT_DISPLAY_LEFT							0x07
#define DISPLAY_OFF_CURSOR_OFF						0x08
#define DISPLAY_OFF_CURSOR_ON						0x0A
#define DISPLAY_ON_CURSOR_OFF 						0x0C
#define DISPLAY_ON_CURSOR_ON						0x0E
#define DISPLAY_ON_CURSOR_BLINKING					0x0F
#define SHIFT_CURSOR_POSITION_TO_LEFT				0x10
#define SHIFT_CURSOR_POSITION_TO_RIGHT				0x14
#define SHIFT_THE_ENTIRE_DISPLAY_TO_THE_LEFT		0x18
#define SHIFT_THE_ENTIRE_DISPLAY_TO_THE_RIGHT		0x1C
#define FORCE_CURSOR_TO_BEGINNING_OF_1ST_LINE		0x80
#define FORCE_CURSOR_TO_BEGINNING_OF_2ST_LINE		0xC0
#define _2_LINES_AND_5X8_MATRIX						0x38

/*********************************************************************************************************
*******************************************FUNCTIONS PROTOTYPE*********************************************
***********************************************************************************************************/

void LCD_init();															//DONE

void LCD_sendCommand(uint8 command);										//DONE

void LCD_displayCharacter(uint8 character);									//DONE

void LCD_displayString(const uint8* str);									//DONE

void LCD_moveCursor(uint8 row,uint8 column);								//DONE

void LCD_displayStringRowColumn(uint8 row,uint8 column,const uint8* str);	//DONE

void LCD_clearScreen();														//DONE

void LCD_intgerToString(uint16 data);										//DONE


#endif  /* EXTERNAL_DEVICES_LCD_H_*/
