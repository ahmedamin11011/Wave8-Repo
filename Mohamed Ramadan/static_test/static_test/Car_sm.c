/*
 ============================================================================
 Name        : Car_sm.c
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */

#include "Car_sm.h"
#include "util/delay.h"

/*************************************************************************************/
ERROR_STATUS Car_SM_Init(void)
{
	uint8_t u8_status;
	u8_status |= Us_Init();
	u8_status |= Steering_Init();
	u8_status |= Steering_SteerCar(CAR_FORWARD,80);
	u8_status |= E_ok;
	return u8_status;
}


/************************************************************************************/

ERROR_STATUS Car_SM_Update(void)
{
	uint16_t Distance;
	uint8_t u8_state;
	Us_Trigger();
	Us_GetDistance(&Distance);

	if(Distance>0 && Distance<=25)
	{
		u8_state=NEAR;
	}
	else if(Distance>25 && Distance<=35)
	{
		u8_state=INTERMEDIATE;
	}
	else if(Distance>35)
	{
		u8_state=FAR;
	}

	switch(u8_state)
	{
		case NEAR:
			Steering_SteerCar(CAR_FORWARD,30);
			break;
		case INTERMEDIATE:
			Steering_SteerCar(CAR_RIGHT,100);
			_delay_ms(500);
			break;
		case FAR:
			Steering_SteerCar(CAR_BACKWARD,30);
			break;
	}

	//softwareDelayMs(100);
	_delay_ms(100);


}



/**************************************************************************************/
