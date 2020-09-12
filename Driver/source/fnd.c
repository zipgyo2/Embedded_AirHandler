/******************************************************************************
  * @file  LPC1768_fnd.c
  * @author  ���߱��� 2��
  * @version V1.0.0
  * @date    2020. 09. 11
  * @brief   FND Driver	C File
  ******************************************************************************/

/* Includes ------------------------------------------------------------------- */
#include "fnd.h"

void FND_Init (void)
{
	LPC_GPIO0->FIODIR |= (1<<4)|(1<<5)|(1<<10)|(1<<11)|(1<<19)|(1<<20)|(1<<21)|(1<<23)|(1<<24);
	LPC_GPIO1->FIODIR |= (1<<21);
	LPC_GPIO2->FIODIR |= (1<<11)|(1<<12)|(1<<13);
	LPC_GPIO3->FIODIR |= (1<<25)|(1<<26);
}

void FND_COM_Init()
{
	LPC_GPIO0->FIOCLR = (1<<23); //	1
	LPC_GPIO0->FIOCLR = (1<<24); //	2
	LPC_GPIO1->FIOCLR = (1<<21); //	3
	LPC_GPIO2->FIOCLR = (1<<11); //	4
	LPC_GPIO2->FIOCLR = (1<<12); //	5
	LPC_GPIO2->FIOCLR = (1<<13); //	6
	LPC_GPIO3->FIOCLR = (1<<25); //	7
	LPC_GPIO3->FIOCLR = (1<<26); //	8
}

void FND_Data_CS()
{
	LPC_GPIO0->FIOSET |= (1<<5);
	LPC_GPIO0->FIOCLR = (1<<5);	
}

void FND_COM_CS()
{
	LPC_GPIO0->FIOPIN |= (1<<10);
	LPC_GPIO0->FIOPIN &= ~(1<<10);
}

void FND_Data_Reset()
{
	/* FND Data setting */
	LPC_GPIO0->FIOSET |= (1<<23)|(1<<24);
	LPC_GPIO1->FIOSET |= (1<<21);
	LPC_GPIO2->FIOSET |= (1<<11)|(1<<12)|(1<<13);
	LPC_GPIO3->FIOSET |= (1<<25)|(1<<26);

	FND_Data_CS();	//	Clock 
}

void FND_DATA(uint8_t dataNum)
{
	FND_Data_Reset();
	switch(dataNum)
	{
		case 0:
			LPC_GPIO0->FIOCLR = FND_A | FND_B;
			LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_D | FND_E | FND_F;
			break;
		
		case 1:
			LPC_GPIO0->FIOCLR = FND_B;
			LPC_GPIO1->FIOCLR = FND_C;
			break;
	
		case 2:
			LPC_GPIO0->FIOCLR = FND_A | FND_B;
			LPC_GPIO2->FIOCLR = FND_D | FND_E;
			LPC_GPIO3->FIOCLR = FND_G;
			break;

		case 3:
			LPC_GPIO0->FIOCLR = FND_A | FND_B;
			LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_D;
			LPC_GPIO3->FIOCLR = FND_G;
			break;

		case 4:
			LPC_GPIO0->FIOCLR = FND_B;
			LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_F;
			LPC_GPIO3->FIOCLR = FND_G;
			break;

		case 5:
			LPC_GPIO0->FIOCLR = FND_A;
			LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_D | FND_F;
			LPC_GPIO3->FIOCLR = FND_G;
			break;

		case 6:
			LPC_GPIO0->FIOCLR = FND_A;
			LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_D | FND_E | FND_F;
			LPC_GPIO3->FIOCLR = FND_G;
			break;

		case 7:
			LPC_GPIO0->FIOCLR = FND_A | FND_B;
		  LPC_GPIO1->FIOCLR = FND_C;
			break;

		case 8:
			LPC_GPIO0->FIOCLR = FND_A | FND_B;
		  LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_D | FND_E | FND_F;
			LPC_GPIO3->FIOCLR = FND_G;
			break;

		case 9:
			LPC_GPIO0->FIOCLR = FND_A | FND_B;
		  LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_F;
			LPC_GPIO3->FIOCLR = FND_G;
			break;
		
		case 'A':
			LPC_GPIO0->FIOCLR = FND_A | FND_B;
		  LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_E | FND_F;
			LPC_GPIO3->FIOCLR = FND_G;
			break;
		
		case 'C':
			LPC_GPIO0->FIOCLR = FND_A;
			LPC_GPIO2->FIOCLR = FND_D | FND_E | FND_F;
			break;
		
		case 'E':
			LPC_GPIO0->FIOCLR = FND_A;
			LPC_GPIO2->FIOCLR = FND_D | FND_E| FND_F;   
			LPC_GPIO3->FIOCLR = FND_G;
			break;
		
		case 'H':
			LPC_GPIO0->FIOCLR = FND_B;
			LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_E | FND_F;   
			LPC_GPIO3->FIOCLR = FND_G;
			break;
		
		case 'L':
			LPC_GPIO2->FIOCLR = FND_D | FND_E | FND_F;  
			break;
		
		case 'N':
			LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_E;
			LPC_GPIO3->FIOCLR = FND_G; 
			break;   
		
		case 'O':
			LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_D | FND_E;
			LPC_GPIO3->FIOCLR = FND_G;
			break;    
		
		case 'T':
			LPC_GPIO2->FIOCLR = FND_D | FND_E | FND_F;    
			LPC_GPIO3->FIOCLR = FND_G;
			break;     
		
		case 'V':
			LPC_GPIO1->FIOCLR = FND_C;
			LPC_GPIO2->FIOCLR = FND_D | FND_E;
			break;
		
		case 'D':
			LPC_GPIO3->FIOCLR = FND_DP;
	}
	FND_Data_CS();	//	Clock 
}

void FND_COM(uint8_t comNum)
{
	FND_COM_Init();
	switch(comNum)
	{
		case 1:
			LPC_GPIO0->FIOSET = (1<<23); //	COM 1
			break;
		
		case 2:
			LPC_GPIO0->FIOSET = (1<<24); //	COM 2
			break;
		
		case 3:
			LPC_GPIO1->FIOSET = (1<<21); //	COM 3
			break;
		
		case 4:
			LPC_GPIO2->FIOSET = (1<<11); //	COM 4
			break;
		
		case 5:
			LPC_GPIO2->FIOSET = (1<<12); //	COM 5
			break;
		
		case 6:
			LPC_GPIO2->FIOSET = (1<<13); //	COM 6
			break;
		
		case 7:
			LPC_GPIO3->FIOSET = (1<<25); //	COM 7
			break;
		
		case 8:
			LPC_GPIO3->FIOSET = (1<<26); //	COM 8
			break;		
	}
	FND_COM_CS();	
}

void FND_COM_DATA(uint8_t comNum, uint8_t data)
{
	FND_COM(comNum);	
	FND_DATA(data);
}

