/*
 ============================================================================
 Name        : User_Story3.h
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */

#ifndef APP_USER_STORY3_H_
#define APP_USER_STORY3_H_

/*********************************includes**********************************/
#include "../FreeRtos/FreeRTOS.h"
#include "../FreeRtos/task.h"
#include "../Hall/pushButton.h"
#include "../Hall/led.h"
/***************************************************************************/


/*********************************definitions*******************************/

/***************************************************************************/


/******************************global variables*****************************/

/***************************************************************************/


/***********************************APIs************************************/
void UserStoryThreeInit(void);
void UserStoryThree(void);
void Pushbuttomtask(void);
void ledtask(void);
/***************************************************************************/

#endif /* APP_USER_STORY3_H_ */
