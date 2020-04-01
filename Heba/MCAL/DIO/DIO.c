﻿/*
 * DIO.c
 *
 * Created: 17/02/2020 11:33:51 ص
 *  Author: TOSHIBA
 */ 
#include "DIO.h"
#define DEBBUGE 1
#ifdef  DEBBUGE
#define STATIC 
#else
#define STATIC static 
#endif
#define INIT_MODULE			1
#define UNINIT_MODULE		0
#define PORTA_INIT_MASK		0x01	
#define PORTB_INIT_MASK		0x02	
#define PORTC_INIT_MASK		0x04	
#define PORTD_INIT_MASK		0x08	

STATIC uint8_t u8_DIO_PortInitFLag = UNINIT_MODULE;

extern u8_ERROR_STATUS_t DIO_init (gstr_DIO_Cfg_t *pstr_DIOCfg)
{
	u8_ERROR_STATUS_t u8_DIO_ErrorStatus= E_OK;
	if (pstr_DIOCfg!=NULL){
	switch (pstr_DIOCfg->u8_GPIO)
	{	
		case GPIOA :
		if((u8_DIO_PortInitFLag & PORTA_INIT_MASK)==UNINIT_MODULE)
		{
			switch (pstr_DIOCfg->u8_dir){
				
				case INPUT:
				
					PORTA_DIR&=~(pstr_DIOCfg->u8_pins);
					u8_DIO_PortInitFLag |= PORTA_INIT_MASK;
					
				break;
				
				case OUTPUT:
				
					PORTA_DIR|=	pstr_DIOCfg->u8_pins;
					
					u8_DIO_PortInitFLag |= PORTA_INIT_MASK;
					
				break;
				
				default:
					u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_INVALIDE_VALUE;
				break;
			}
			
		}
		else
	    {
			u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_MULTIPLE_INIT;
		}
		
		
		break;
		
		case GPIOB :
		if((u8_DIO_PortInitFLag & PORTB_INIT_MASK)==UNINIT_MODULE)
		{
			switch (pstr_DIOCfg->u8_dir){
				case INPUT:
				
					PORTB_DIR&=~(pstr_DIOCfg->u8_pins);
					
					u8_DIO_PortInitFLag |= PORTB_INIT_MASK;

				break;
				case OUTPUT:
				
					PORTB_DIR|=	(pstr_DIOCfg->u8_pins);
					
					u8_DIO_PortInitFLag |= PORTB_INIT_MASK;

				break;
				
				default:
					u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_INVALIDE_VALUE;
				break;
			}
		}
		else
		{
			u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_MULTIPLE_INIT;
		}
		
		break;
		
		case GPIOC :
		if((u8_DIO_PortInitFLag & PORTC_INIT_MASK)==UNINIT_MODULE)
		{
			switch (pstr_DIOCfg->u8_dir)
			{
				case INPUT:
					PORTC_DIR&=~(pstr_DIOCfg->u8_pins);
					u8_DIO_PortInitFLag |= PORTC_INIT_MASK;
				break;
				
				case OUTPUT:
				
					PORTC_DIR|=	(pstr_DIOCfg->u8_pins);
					u8_DIO_PortInitFLag |= PORTC_INIT_MASK;
					
				break;
				
				default:
					u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_INVALIDE_VALUE;
				break;
			}
			
		}
		else
		{
			u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_MULTIPLE_INIT;
		}
		
		break;
		
		case GPIOD :
		if((u8_DIO_PortInitFLag & PORTD_INIT_MASK)==UNINIT_MODULE)
		{
			switch (pstr_DIOCfg->u8_dir){
				case INPUT:
					PORTD_DIR&=~(pstr_DIOCfg->u8_pins);
					u8_DIO_PortInitFLag |= PORTD_INIT_MASK;
				break;
				
				case OUTPUT:
					PORTD_DIR|=(pstr_DIOCfg->u8_pins);
					u8_DIO_PortInitFLag |= PORTD_INIT_MASK;
				break;
				
				default:
					u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_INVALIDE_VALUE;
				break;
			}
			
		}
		else
		{
			u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_MULTIPLE_INIT;
		}
		
		break;
		
		
		default:
			u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_INVALIDE_PORT;
		break;
		}
	}
	else
	{
		u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_NULL_PTR;
	}
return  u8_DIO_ErrorStatus;

}
extern u8_ERROR_STATUS_t DIO_Write (uint8_t u8_GPIO, uint8_t u8_pins, uint8_t u8_value){
	u8_ERROR_STATUS_t u8_DIO_ErrorStatus = E_OK;
	switch (u8_GPIO)
	{
		
		case GPIOA :
		if((u8_DIO_PortInitFLag & PORTA_INIT_MASK) == PORTA_INIT_MASK)
		{
			if((PORTA_DIR&u8_pins)==u8_pins)
			{
				switch(u8_value){
					
					case HIGH:
						PORTA_DATA|=u8_pins;
					break;
					
					case LOW :
						PORTA_DATA&=(~u8_pins);
					break;
					
					default:
						u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_INVALIDE_VALUE;
					break;
				}
			}
			else 
			{
				u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
			}
			
		}
		else
		{
			u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
		}
		
		break;
		
		case GPIOB :
		
		if((u8_DIO_PortInitFLag & PORTB_INIT_MASK) == PORTB_INIT_MASK)
		{
			if((PORTB_DIR&u8_pins)==u8_pins)
			{
				switch(u8_value){
					
					case HIGH:
						PORTB_DATA |=u8_pins;
					break;
					case LOW :
						PORTB_DATA &=(~u8_pins);
					break;
					
					default:
						u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_INVALIDE_VALUE;
					break;
				}
			}
			
			else
			{
				u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
			}
		}
		else
		{
			u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
		}
		
		break;
		
		case GPIOC :
		if((u8_DIO_PortInitFLag & PORTC_INIT_MASK )== PORTC_INIT_MASK)
		{
			if((PORTC_DIR&u8_pins)==u8_pins)
			{
				switch(u8_value){
					
					case HIGH:
						PORTC_DATA|=u8_pins;
					break;
					case LOW :
						PORTC_DATA&=(~u8_pins);
					break;
					
					default:
						u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_INVALIDE_VALUE;
					break;
				}
			}
			
			else
			{
				u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
			}
		}
		else 
		{
			u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
		}
		
		break;
		
		case GPIOD :
		if((u8_DIO_PortInitFLag & PORTD_INIT_MASK )== PORTD_INIT_MASK)
		{
			if((PORTD_DIR&u8_pins)==u8_pins)
			{
				switch(u8_value){
					
					case HIGH:
						PORTD_DATA|=u8_pins;
					break;
					case LOW :
						PORTD_DATA&=(~u8_pins);
					break;
					default:
						u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_INVALIDE_VALUE;
					break;
				}
			}
			
			else
			{
				u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
			}
		}
		else
		{
			u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
		}
		
		break;
		
		default:
			u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_PORT;
		break;
	}
	return u8_DIO_ErrorStatus ;
}

extern u8_ERROR_STATUS_t DIO_Read (uint8_t u8_GPIO,uint8_t u8_pins, uint8_t *pu8_data){
	u8_ERROR_STATUS_t u8_DIO_ErrorStatus = E_OK ;
	
	if (pu8_data != NULL)
	{
		switch (u8_GPIO){
			
			case GPIOA :
				if((u8_DIO_PortInitFLag & PORTA_INIT_MASK )== PORTA_INIT_MASK)
				{
					if(((PORTA_DIR&u8_pins)^u8_pins)== u8_pins)// check if the port direction is input 
					{
						*pu8_data=u8_pins & PORTA_PIN;						
					}
					
				else
				{
					u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
				}
				}
				else
				{
					u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
				}
			
			break;
			
			case GPIOB :
				if((u8_DIO_PortInitFLag & PORTB_INIT_MASK) == PORTB_INIT_MASK)
				{
					if(((PORTB_DIR&u8_pins)^u8_pins)==u8_pins)// check if the port direction is input
					{
						*pu8_data=u8_pins & PORTB_PIN;
					}
					
					else
					{
						u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
					}
				}
				else
				{
					u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
				}
			break;
			
			case GPIOC :
				if((u8_DIO_PortInitFLag & PORTC_INIT_MASK) == PORTC_INIT_MASK)
				{
					if(((PORTC_DIR&u8_pins)^u8_pins)==u8_pins)// check if the port direction is input
					{
						*pu8_data=u8_pins & PORTC_PIN;
					}
					
					else
					{
						u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
					}
				}
				else
				{
					u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
				}
			break;
			
			case GPIOD :
			
				if((u8_DIO_PortInitFLag & PORTD_INIT_MASK )== PORTD_INIT_MASK)
				{
					if(((PORTD_DIR&u8_pins)^u8_pins)==u8_pins)// check if the port direction is input
					{
						*pu8_data=u8_pins & PORTD_PIN;
					}
					
					else
					{
						u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
					}
				}
				else
				{
					u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
				}
			break;
			
			default:
				u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_PORT;
			break;
		}
		
	}
	else 
	{
		u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER+ERROR_NULL_PTR;
	}
	
	return u8_DIO_ErrorStatus ;

}

extern u8_ERROR_STATUS_t DIO_Toggle (uint8_t u8_GPIO, uint8_t u8_pins){
	u8_ERROR_STATUS_t u8_DIO_ErrorStatus = E_OK ;

	switch (u8_GPIO){
		
		case GPIOA :
			if((u8_DIO_PortInitFLag & PORTA_INIT_MASK) == PORTA_INIT_MASK)
			{
				if((PORTA_DIR&u8_pins)==u8_pins)
				{
					PORTA_DATA^=u8_pins;
				}
				
				else
				{
					u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
				}
			}
			else
			{
				u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
			}
		break;
		
		case GPIOB :
			if((u8_DIO_PortInitFLag & PORTB_INIT_MASK) == PORTB_INIT_MASK)
			{
				if((PORTB_DIR&u8_pins)==u8_pins)
				{
					PORTB_DATA^=u8_pins;
				}
				
				else
				{
					u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
				}
			}
			else
			{
				u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
			}
		break;
		case GPIOC :
			if((u8_DIO_PortInitFLag & PORTC_INIT_MASK) == PORTC_INIT_MASK)
			{
				if((PORTC_DIR&u8_pins)==u8_pins)
				{
					PORTC_DATA ^=u8_pins;
				}
				
				else
				{
					u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
				}
			}
			else
			{
				u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
			}
		break;
		
		case GPIOD :
		
		if((u8_DIO_PortInitFLag & PORTD_INIT_MASK) == PORTD_INIT_MASK)
		{
			if((PORTD_DIR&u8_pins)==u8_pins)
			{
				PORTD_DATA ^=u8_pins;
			}
			
			else
			{
				u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_CFG;
			}
		}
		else
		{
			u8_DIO_ErrorStatus = DIO_MODULE_ERROR_NUMBER + ERROR_UNILTILZED_PORT;
		}

		break;
		
	  default:
	  
	  		u8_DIO_ErrorStatus= DIO_MODULE_ERROR_NUMBER + ERROR_INVALIDE_PORT;
			  
       break;
	}
	return u8_DIO_ErrorStatus ; 
}
	


