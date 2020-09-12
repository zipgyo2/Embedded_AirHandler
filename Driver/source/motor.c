/******************************************************************************
  * @file  motor.c
  * @author  집중교육 2조
  * @version V1.0.0
  * @date    2020. 09. 11
  * @brief   MOTOR Driver	C File
  ******************************************************************************/

#include "motor.h"


#define SEC_1 	SystemCoreClock/4  
#define SEC_2 	SystemCoreClock/2
#define SEC_4 	SystemCoreClock

extern __IO uint32_t adc_value;
extern uint32_t adc_flag;
extern uint8_t int_flag;
extern void Delay(unsigned long d_t);

void Motor_Init(void)
{
	LPC_GPIO0->FIODIR |= (1<<4)|(1<<5)|(1<<10)|(1<<11)|(1<<19)|(1<<20)|(1<<21)|(1<<23) |(1<<24);
	LPC_GPIO1->FIODIR |= (1<<21);
	LPC_GPIO2->FIODIR |= (1<<11)|(1<<12)|(1<<13);
	LPC_GPIO3->FIODIR |= (1<<25)|(1<<26);
}

void Cycle_Init(uint32_t adc_value)
{
	uint32_t count = 0;
	if(adc_value == 0) adc_value = 10;
	adc_flag = 0;
	
	for(count = 0; count < 1; count++)
	{
		LPC_GPIO0->FIOSET = (1<<5);
		LPC_GPIO0->FIOCLR = (1<<10);
		LPC_GPIO0->FIOSET = (1<<23);
		LPC_GPIO0->FIOCLR = (1<<24);
		Delay(SEC_1/(adc_value/50));

		LPC_GPIO0->FIOCLR = (1<<5);
		LPC_GPIO0->FIOSET = (1<<10);
		LPC_GPIO0->FIOSET = (1<<23);
		LPC_GPIO0->FIOCLR = (1<<24);
		Delay(SEC_1/(adc_value/50));

		LPC_GPIO0->FIOCLR = (1<<5);
		LPC_GPIO0->FIOSET = (1<<10);
		LPC_GPIO0->FIOCLR = (1<<23);
		LPC_GPIO0->FIOSET = (1<<24);
		Delay(SEC_1/(adc_value/50));

		LPC_GPIO0->FIOSET = (1<<5);
		LPC_GPIO0->FIOCLR = (1<<10);
		LPC_GPIO0->FIOCLR = (1<<23);
		LPC_GPIO0->FIOSET = (1<<24);
		Delay(SEC_1/(adc_value/50));
		
		LPC_GPIO0->FIOSET = (1<<5);
		LPC_GPIO0->FIOCLR = (1<<10);
		LPC_GPIO0->FIOCLR = (1<<23);
		LPC_GPIO0->FIOSET = (1<<24);
		Delay(SEC_1/(adc_value/50));
		
		LPC_GPIO0->FIOCLR = (1<<5);
		LPC_GPIO0->FIOSET = (1<<10);
		LPC_GPIO0->FIOCLR = (1<<23);
		LPC_GPIO0->FIOSET = (1<<24);
		Delay(SEC_1/(adc_value/50));
		
		LPC_GPIO0->FIOCLR = (1<<5);
		LPC_GPIO0->FIOSET = (1<<10);
		LPC_GPIO0->FIOSET = (1<<23);
		LPC_GPIO0->FIOCLR = (1<<24);
		Delay(SEC_1/(adc_value/50));
		
		LPC_GPIO0->FIOSET = (1<<5);
		LPC_GPIO0->FIOCLR = (1<<10);
		LPC_GPIO0->FIOSET = (1<<23);
		LPC_GPIO0->FIOCLR = (1<<24);
		Delay(SEC_1/(adc_value/50));
		
		if(int_flag==0) break;	
		if(adc_flag==1) break;	
	}
}

void Cycle(uint32_t adc_value)
{
	uint32_t count = 0;
	if(adc_value == 0) adc_value = 10;
	adc_flag = 0;

	for(count = 0; count < 1; count++)
	{
		LPC_GPIO0->FIOSET = (1<<5);
		LPC_GPIO0->FIOCLR = (1<<10);
		LPC_GPIO0->FIOSET = (1<<23);
		LPC_GPIO0->FIOCLR = (1<<24);
		Delay(SEC_1/(adc_value/50));

		LPC_GPIO0->FIOCLR = (1<<5);
		LPC_GPIO0->FIOSET = (1<<10);
		LPC_GPIO0->FIOSET = (1<<23);
		LPC_GPIO0->FIOCLR = (1<<24);
		Delay(SEC_1/(adc_value/50));

		LPC_GPIO0->FIOCLR = (1<<5);
		LPC_GPIO0->FIOSET = (1<<10);
		LPC_GPIO0->FIOCLR = (1<<23);
		LPC_GPIO0->FIOSET = (1<<24);
		Delay(SEC_1/(adc_value/50));

		LPC_GPIO0->FIOSET = (1<<5);
		LPC_GPIO0->FIOCLR = (1<<10);
		LPC_GPIO0->FIOCLR = (1<<23);
		LPC_GPIO0->FIOSET = (1<<24);
		Delay(SEC_1/(adc_value/50));

		if(int_flag==0) break;
		if(adc_flag==1) break;	
	}
}
void Cycle_Reverse(uint32_t adc_value)
{
	uint32_t count = 0;
	if(adc_value == 0) adc_value = 10;
	adc_flag = 0;

	for(count = 0; count < 1; count++)
	{
		LPC_GPIO0->FIOSET = (1<<5);
		LPC_GPIO0->FIOCLR = (1<<10);
		LPC_GPIO0->FIOCLR = (1<<23);
		LPC_GPIO0->FIOSET = (1<<24);
		Delay(SEC_1/(adc_value/50));
		
		LPC_GPIO0->FIOCLR = (1<<5);
		LPC_GPIO0->FIOSET = (1<<10);
		LPC_GPIO0->FIOCLR = (1<<23);
		LPC_GPIO0->FIOSET = (1<<24);
		Delay(SEC_1/(adc_value/50));
		
		LPC_GPIO0->FIOCLR = (1<<5);
		LPC_GPIO0->FIOSET = (1<<10);
		LPC_GPIO0->FIOSET = (1<<23);
		LPC_GPIO0->FIOCLR = (1<<24);
		Delay(SEC_1/(adc_value/50));
		
		LPC_GPIO0->FIOSET = (1<<5);
		LPC_GPIO0->FIOCLR = (1<<10);
		LPC_GPIO0->FIOSET = (1<<23);
		LPC_GPIO0->FIOCLR = (1<<24);
		Delay(SEC_1/(adc_value/50));

		if(int_flag==0) break;
		if(adc_flag==1) break;
	}
}