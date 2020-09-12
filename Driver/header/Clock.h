#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "LPC17xx.h"
#include "fnd.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_pinsel.h"

extern uint8_t time_10h;
extern uint8_t time_1h ;
extern uint8_t time_10m;
extern uint8_t time_1m;
extern uint8_t time_10s;
extern uint8_t time_1s;

extern uint8_t time_handle;
extern uint8_t time_handle_check;
extern uint8_t time_select;
extern uint8_t time_flag;


void FND_printing(void);
void Time_Handler(uint8_t time_handle);
void Time_plus(uint8_t time_select);
void Time_minus(uint8_t time_select);
void Joystick_Init(void);
uint8_t Joystick_read(void);
void Time_SelectDP(uint8_t time_select);


#endif
