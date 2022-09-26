/******************************************************************************************************
 * File Name:	icu.h
 *
 * Author:		Aly Maamoun
 *
 * Date:		12/10/2021
 *
 * Description:	Header file for input capture unit module drivers
 *
 ********************************************************************************************************/


#ifndef INTERNAL_PERIPHERALS_ICU_H_
#define INTERNAL_PERIPHERALS_ICU_H_


/*------------------------------------------ INCLUDES --------------------------------------------------*/

#include 	"../std_types.h"




/*------------------------------------------- ENUMS ---------------------------------------------------*/



/*------------------------------------------------------------------------------------------------------
 * Enum Name:			ICU_Edge
 *
 * Enum Description:	This Enum will be used to select the type of the edge
 *
 ------------------------------------------------------------------------------------------------------*/


typedef enum{
	FALLING,RISING
}ICU_Edge;


/*------------------------------------------------------------------------------------------------------
 * Enum Name:			ICU_clk
 *
 * Enum Description:	This Enum will be used to select the clock prescalar for the ICU
 *
 ------------------------------------------------------------------------------------------------------*/



typedef enum{
	NO_CLK,FCPU_CLK,FCPU_CLK_8,FCPU_CLK_64,FCPU_CLK_256,FCPU_CLK_1024
}ICU_clk;

/*----------------------------------------- Structures --------------------------------------------------*/



/*------------------------------------------------------------------------------------------------------
 * Structure Name:			ICU_Config
 *
 * Structure Description:	This structure will be used to send initializing options and settings for
 * 								ICU_INIT function to initialize the input capture unit
 *
 ------------------------------------------------------------------------------------------------------*/


typedef struct{
	ICU_clk clk;
	ICU_Edge edge;
}ICU_Config;

/*------------------------------------- FUNCTION DECLARATIONS --------------------------------------------*/


/*------------------------------------------------------------------------------------------------------
 * Function Name: 				ICU_init
 *
 * Description:					This function is initialize the ICU
 *
 * ARGS:
 * const ICU_Config * Confing:	pointer to configuration structure
 *
 * Return: 						Nothing
 ------------------------------------------------------------------------------------------------------*/



void ICU_init(const ICU_Config * Config);




/*------------------------------------------------------------------------------------------------------
 * Function Name: 				ICU_SetCallBack
 *
 * Description:					This function is to perform the function needed using the ICU
 *
 * ARGS:
 * void(*ptr)(void):			pointer the function needed to be performed
 *
 * Return: 						Nothing
 ------------------------------------------------------------------------------------------------------*/




void ICU_SetCallBack(void(*ptr)(void));



/*------------------------------------------------------------------------------------------------------
 * Function Name: 				ICU_SetEdge
 *
 * Description:					This function is set the edge needed to be captured
 *
 * ARGS:
 * ICU_Edge edge:				Rising or Falling
 *
 * Return: 						Nothing
 ------------------------------------------------------------------------------------------------------*/



void ICU_SetEdge(const ICU_Edge edge);




/*------------------------------------------------------------------------------------------------------
 * Function Name: 				ICU_getRead
 *
 * Description:					Getting the time taken between edges
 *
 * ARGS:						Nothing
 *
 * Return: 						Time taken
 ------------------------------------------------------------------------------------------------------*/


uint16 ICU_getRead(void);


/*------------------------------------------------------------------------------------------------------
 * Function Name: 				ICU_ClearData
 *
 * Description:					Resetting the counting
 *
 * ARGS:						Nothing
 *
 * Return: 						Noting
 ------------------------------------------------------------------------------------------------------*/



void ICU_ClearData(void);



/*------------------------------------------------------------------------------------------------------
 * Function Name: 				ICU_deinit
 *
 * Description:					Shutting down the ICU
 *
 * ARGS:						Nothing
 *
 * Return: 						Noting
 ------------------------------------------------------------------------------------------------------*/



void ICU_deinit(void);


#endif /* INTERNAL_PERIPHERALS_ICU_H_ */
