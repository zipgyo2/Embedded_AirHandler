/******************************************************************************
  * @file  motor.h
  * @author  집중교육 2조
  * @version V1.0.0
  * @date    2020. 09. 11
  * @brief   MOTOR Driver	Header File
  ******************************************************************************/

#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "LPC17XX.h"
	
void Motor_Init (void);
void Cycle(uint32_t adc_value);
void Cycle_Reverse(uint32_t adc_value);
void Cycle_Init(uint32_t adc_value);

#endif
