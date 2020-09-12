/******************************************************************************
  * @file  LPC1768_fnd.c
  * @author  ���߱��� 2��
  * @version V1.0.0
  * @date    2020. 09. 11
  * @brief   FND Driver	C File
  ******************************************************************************/


#ifndef _FND_H_
#define _FND_H_

/* Includes ------------------------------------------------------------------- */
#include "LPC17XX.h"
#include "lpc_types.h"

#define	FND_A		(1<<23)	//	FND A
#define	FND_B		(1<<24)	//	FND B
#define	FND_C		(1<<21)	//	FND C
#define	FND_D		(1<<11)	//	FND D
#define	FND_E		(1<<12)	//	FND E
#define	FND_F		(1<<13)	//	FND F
#define	FND_G		(1<<25)	//	FND G
#define	FND_DP	(1<<26)	//	FND DP

void FND_Init (void);
void FND_COM_Init(void);
void FND_Data_Reset(void);
void FND_Data_CS(void);
void FND_COM_CS(void);
void FND_DATA(uint8_t data);
void FND_COM(uint8_t comNum);
void FND_COM_DATA(uint8_t comNum, uint8_t data);

#endif
