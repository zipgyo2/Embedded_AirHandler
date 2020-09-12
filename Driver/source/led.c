#include "led.h"

void Led_Init(){
	LPC_GPIO2->FIODIR |= (1<<6); // LED 1 OUT
	LPC_GPIO2->FIODIR |= (1<<5); // LED 2 OUT
	LPC_GPIO2->FIODIR |= (1<<4); // LED 3 OUT
	LPC_GPIO2->FIODIR |= (1<<3); // LED 4 OUT
	LPC_GPIO2->FIODIR |= (1<<2); // LED 5 OUT
	LPC_GPIO1->FIODIR |= (1UL<<31); // LED 6 OUT
	LPC_GPIO1->FIODIR |= (1<<29); // LED 7 OUT
	LPC_GPIO1->FIODIR |= (1<<28); // LED 8 OUT
}

void Led_On(uint8_t Led)
{
	switch(Led)
	{
		case LED1 :
			LPC_GPIO1->FIOSET = (1<<28);
			break;
		
		case LED2 :
			LPC_GPIO1->FIOSET = (1<<29);
			break;
		
		case LED3 :
			LPC_GPIO1->FIOSET = (1<<31);
			break;
		
		case LED4  :
			LPC_GPIO2->FIOSET = (1<<2);	
			break;
		
		case LED5 :
			LPC_GPIO2->FIOSET = (1<<3);		
			break;
		
		case LED6 :
			LPC_GPIO2->FIOSET = (1<<4);	
			break;
		
		case LED7 :
			LPC_GPIO2->FIOSET = (1<<5);
			break;
		
		case LED8 :
			LPC_GPIO2->FIOSET = (1<<6);
			break;			
	}
}

void Led_Off(uint8_t Led)
{
	switch(Led)
	{
		case 1 :
			LPC_GPIO1->FIOCLR = (1<<28);
			break;
		
		case 2 :
			LPC_GPIO1->FIOCLR = (1<<29);
			break;
		
		case 3 :
			LPC_GPIO1->FIOCLR = (1<<31);
			break;
		
		case 4 :
			LPC_GPIO2->FIOCLR = (1<<2);
			break;
		
		case 5 :
			LPC_GPIO2->FIOCLR = (1<<3);
			break;
		
		case 6 :
			LPC_GPIO2->FIOCLR = (1<<4);	
			break;
		
		case 7 :
			LPC_GPIO2->FIOCLR = (1<<5);
			break;
		
		case 8 :
			LPC_GPIO2->FIOCLR = (1<<6);		
			break;		
	}
}

void Led_All_On(void)
{
	LPC_GPIO1->FIOSET = (1<<28);
	LPC_GPIO1->FIOSET = (1<<29);
	LPC_GPIO1->FIOSET = (1<<31);
	LPC_GPIO2->FIOSET = (1<<2);
	LPC_GPIO2->FIOSET = (1<<3);
	LPC_GPIO2->FIOSET = (1<<4);
	LPC_GPIO2->FIOSET = (1<<5);
	LPC_GPIO2->FIOSET = (1<<6);	
}

void Led_All_Off(void)
{
	LPC_GPIO1->FIOCLR = (1<<28);
	LPC_GPIO1->FIOCLR = (1<<29);
	LPC_GPIO1->FIOCLR = (1<<31);
	LPC_GPIO2->FIOCLR = (1<<2);
	LPC_GPIO2->FIOCLR = (1<<3);
	LPC_GPIO2->FIOCLR = (1<<4);
	LPC_GPIO2->FIOCLR = (1<<5);
	LPC_GPIO2->FIOCLR = (1<<6);				
}
