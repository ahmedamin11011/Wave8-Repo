/*
*	File name: DIO.h
*	Author : Tamoo7, Ahmed, Metwally
*	version: 1.3
*
*/

#ifndef	DIO_H
#define DIO_H

#include "../../Infrastructure/std_types.h"
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/common_macros.h"
/************************************************************************/
/*						PINS/BITS defines                               */
/************************************************************************/

#define PIN0	0x01
#define PIN1	0x02
#define PIN2	0x04
#define PIN3	0x08
#define PIN4	0x10
#define PIN5	0x20
#define PIN6	0x40
#define PIN7	0x80

#define BIT0	0x01
#define BIT1	0x02
#define BIT2	0x04
#define BIT3	0x08
#define BIT4	0x10
#define BIT5	0x20
#define BIT6	0x40
#define BIT7	0x80

#define UPPER_NIBBLE	0xF0
#define LOWER_NIBBLE	0x0F
#define FULL_PORT		0xFF

#define GPIOA			0
#define GPIOB			1
#define GPIOC			2
#define GPIOD			3

#define OUTPUT			0xFF
#define INPUT			0x00
/************************************************************************/
/*						Typedefs defines                               	*/
/************************************************************************/
typedef struct 
{
	uint8_t u8_GPIO;
	uint8_t u8_pins;
	uint8_t u8_dir;
}gstr_DIO_Cfg_t;
 

/*				ERROR CODE					*/


#define DIO_MODULE_ERROR_NUMBER        (10)
#define  ERROR_NULL_PTR            (1)
#define  ERROR_UNILTILZED_PORT	   (2)
#define  ERROR_MULTIPLE_INIT       (3)
#define  ERROR_INVALIDE_PORT       (4)
#define  ERROR_INVALIDE_VALUE	   (5)
#define  ERROR_INVALIDE_CFG	   (5)



/*
*Input: DIO_Cfg_s -> to get PORT name, pins to be initiated and the required direction
*Output: No output
*In/Out:
*Description: This function can set the direction of a full port, a nibble
* 			  or even one pin.
*/
extern u8_ERROR_STATUS_t DIO_init (gstr_DIO_Cfg_t *pstr_DIOCfg);


/*
*Input: GPIO -> to get PORT name
*					- GPIOA
*					- GPIOB
*					- GPIOC
*					- GPIOD
*		pins -> pins to be written at.
*					- PIN0
*					- PIN1
*					- PIN2
*					- PIN3
*					- PIN4
*					- PIN5
*					- PIN6
*					- PIN7
*					- UPPER_NIBBLE
*					- LOWER_NIBBLE
*					- FULL_PORT
*		value 	-> The desired value
*					- HIGH
*					- LOW
*Output: No output
*In/Out: No In/Out
*Description: This function can set the value of a full port, a nibble
* 			  or even one pin.
*/
extern u8_ERROR_STATUS_t DIO_Write (uint8_t u8_GPIO, uint8_t u8_pins, uint8_t u8_value);

/*
*Input: GPIO -> to get PORT name
*					- GPIOA
*					- GPIOB
*					- GPIOC
*					- GPIOD
*		pins -> pins to be written at.
*					- PIN0
*					- PIN1
*					- PIN2
*					- PIN3
*					- PIN4
*					- PIN5
*					- PIN6
*					- PIN7
*					- UPPER_NIBBLE
*					- LOWER_NIBBLE
*					- FULL_PORT
*		value 	-> The desired value
*					- HIGH
*					- LOW
*Output: data -> the acquired data wether it was PORT data or pins data
*In/Out:
*Description: This function gets the value of a full port, a nibble
* 			  or even one pin.
*/
extern u8_ERROR_STATUS_t DIO_Read (uint8_t u8_GPIO,uint8_t u8_pins, uint8_t *pu8_data);

/*
*Input: GPIO -> to get PORT name
*					- GPIOA
*					- GPIOB
*					- GPIOC
*					- GPIOD
*		pins -> pins to be written at.
*					- PIN0
*					- PIN1
*					- PIN2
*					- PIN3
*					- PIN4
*					- PIN5
*					- PIN6
*					- PIN7
*					- UPPER_NIBBLE
*					- LOWER_NIBBLE
*					- FULL_PORT
*Output: data -> No output
*In/Out:
*Description: This function toggles the value of a full port, a nibble
* 			  or even one pin.
*/
extern u8_ERROR_STATUS_t DIO_Toggle (uint8_t u8_GPIO, uint8_t u8_pins);



#endif