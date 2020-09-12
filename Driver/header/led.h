
#ifndef _LED_H_
#define _LED_H_

#include "LPC17xx.h"

#define LED1					1
#define LED2					2
#define LED3					3
#define LED4					4
#define LED5					5
#define LED6					6
#define LED7					7
#define LED8					8

void Led_Init(void);
void Led_On(uint8_t Led);
void Led_Off(uint8_t Led);
void Led_All_On(void);
void Led_All_Off(void);

#endif
