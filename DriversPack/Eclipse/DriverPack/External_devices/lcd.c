/***************************************************************************************************
 * File Name: lcd.c
 * Author: Aly maamoun
 * Date: 1/10/2021
 * Description: LCD driver
 ************************************************************************************************/


/*********************************************************************************************************
*******************************************INCLUDES****************************************************
***********************************************************************************************************/
#include "../External_devices/lcd.h"

/*********************************************************************************************************
******************************************* FUNCTIONS  ****************************************************
***********************************************************************************************************/

/*This function is to initialize the LCD*/

void LCD_init(void){
	GPIO_setupPinDirection(LCD_CONTROL_PORT_ID, RW_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_CONTROL_PORT_ID, RS_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_CONTROL_PORT_ID, ENABLE_ID, PIN_OUTPUT);
	GPIO_setupPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT);
	LCD_sendCommand(_2_LINES_AND_5X8_MATRIX);
	LCD_sendCommand(DISPLAY_ON_CURSOR_OFF);
	LCD_sendCommand(CLEAR_DISPLAY_SCREEN);
}

/*This function is to send command to the LCD*/

void LCD_sendCommand(uint8 command){
	GPIO_writePin(LCD_CONTROL_PORT_ID, RS_ID, LOGIC_LOW);
	GPIO_writePin(LCD_CONTROL_PORT_ID, RW_ID, LOGIC_LOW);
	_delay_ms(FIGURE_DELAY);
	GPIO_writePin(LCD_CONTROL_PORT_ID, ENABLE_ID, LOGIC_HIGH);
	_delay_ms(FIGURE_DELAY);
	GPIO_writePort(LCD_DATA_PORT_ID, command);
	_delay_ms(FIGURE_DELAY);
	GPIO_writePin(LCD_CONTROL_PORT_ID, ENABLE_ID, LOGIC_LOW);
	_delay_ms(FIGURE_DELAY);
}

/*This function is to display character through the LCD*/

void LCD_displayCharacter(uint8 character){
	GPIO_writePin(LCD_CONTROL_PORT_ID, RS_ID, LOGIC_HIGH);
	GPIO_writePin(LCD_CONTROL_PORT_ID, RW_ID, LOGIC_LOW);
	_delay_ms(FIGURE_DELAY);
	GPIO_writePin(LCD_CONTROL_PORT_ID, ENABLE_ID, LOGIC_HIGH);
	_delay_ms(FIGURE_DELAY);
	GPIO_writePort(LCD_DATA_PORT_ID, character);
	_delay_ms(FIGURE_DELAY);
	GPIO_writePin(LCD_CONTROL_PORT_ID, ENABLE_ID, LOGIC_LOW);
	_delay_ms(FIGURE_DELAY);
}

/*This function is to display string through the LCD*/

void LCD_displayString(const uint8* str){
	for(int i=0;str[i]!='\0';i++){
		if(i==15){
			LCD_sendCommand(FORCE_CURSOR_TO_BEGINNING_OF_2ST_LINE);
		}
		LCD_displayCharacter(str[i]);
	}
}

/*This function is to clear the LCD*/

void LCD_clearScreen(){
	LCD_sendCommand(CLEAR_DISPLAY_SCREEN);
}

/*This function is to transfer number to string then display through the LCD*/

void LCD_intgerToString(uint16 data){
	char buffer[256];
	itoa(data,buffer,10);
	LCD_displayString(buffer);
}

/*This function is to move the cursor through the LCD*/

void LCD_moveCursor(uint8 row,uint8 column){
	uint8 lcd_memory_address;
	switch(row){
	case 0:
		lcd_memory_address=column;
		break;
	case 1:
		lcd_memory_address=column+0x40;
		break;
	case 2:
		lcd_memory_address=column+0x10;
		break;
	case 3:
		lcd_memory_address=column+0x50;
		break;
	}
	LCD_sendCommand((FORCE_CURSOR_TO_BEGINNING_OF_1ST_LINE|lcd_memory_address));

}

/*This function is to display string by shifted row and column through the LCD*/

void LCD_displayStringRowColumn(uint8 row,uint8 column,const uint8* str){
	LCD_moveCursor(row, column);
	LCD_displayString(str);
}


