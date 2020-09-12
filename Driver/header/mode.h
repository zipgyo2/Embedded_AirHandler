
#ifndef __MODE_H_
#define __MODE_H_

#include "LPC17xx.h"
#include "fnd.h"
#include "keypad.h"
#include "led.h"

extern uint8_t led_flag1;
extern uint8_t led_flag2;
extern uint8_t led_flag3;
extern uint8_t led_flag4;
extern uint8_t print_flag;

extern void Delay(unsigned long d_t);
void Mode(uint32_t mode);
void MOD_printing(uint8_t mod);

#endif
