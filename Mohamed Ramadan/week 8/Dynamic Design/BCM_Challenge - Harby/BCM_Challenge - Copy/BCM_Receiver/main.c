/*
 * main.c
 *
 *  Created on: Mar 2, 2020
 *      Author: Youssef Harby & Mohamed Ramadan
 */


/*- INCLUDES -----------------------------------------------*/

#include "BCM.h"


/*- DEFINITIONS --------------------------------------------*/

#define OVERHEAD 		4
#define ELEMENTS(X)		(X + OVERHEAD)

#define BCM_DONE		1
#define BCM_NOT_DONE	0


volatile sint8_t SendingString[ELEMENTS(20)];

volatile uint8_t uart_counter = 0;

uint8_t uart_flag = 1;

uint8_t bcm_flag = BCM_NOT_DONE;

void Uart_SendingApp(void)
{
	uart_flag = 1;
}

void Bcm_CallBack(void)
{
	bcm_flag = BCM_DONE;
}

int main(void)
{
	uint8_t UART_status = BCM_NOT_DONE;
	UART_ConfigType UART_cfg = {
			UART_ASYNCHRONOUS_MODE,
			UART_SENDER_MODE,
			UART_INTERRUPT_ENABLED,
			UART_EIGHT_BITS,
			UART_PARITY_DISABLED,
			UART_ONE_STOP_BIT
	};

	strBcmConfig_t BCM_cfg = {
			BCM_SPI_ID,
			BCM_RECEIVE
	};

	BCM_SetCallBack(&Bcm_CallBack);

	BCM_Init(&BCM_cfg);

	UART_TXC_setCallBack(&Uart_SendingApp);

	UART_init(&UART_cfg);

	sei();

	BCM_SetupRxBuffer(BCM_SPI_ID, (uint8_t*)SendingString, ELEMENTS(20));

	while(1)
	{
		if(UART_status == BCM_DONE && uart_flag == 1)
		{
			UART_Send_String((char*)SendingString);
			uart_flag = 0;
		}

		if(UART_status == BCM_NOT_DONE)
		{
			BCM_RxDispatch();
		}
	}
}



//uint8_t Buffer[ELEMENTS(21)];
//strBcmConfig_t cfg = {
//		BCM_SPI_ID,
//		BCM_RECEIVE
//};
//
//BCM_Init(&cfg);
//
//sei();
//
//BCM_SetupRxBuffer(BCM_SPI_ID, (uint8_t*)Buffer, sizeof(Buffer));
//
//while(1)
//{
//	BCM_RxDispatch();
//}
