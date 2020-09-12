			   
#ifndef __Keypad_H__
#define __Keypad_H__

#include "LPC17XX.h"
#include "lpc_types.h"

void EXT_IO_init(void);
void Keypad_DIR_Output(void);
void Keypad_DIR_Input(void);
void EXT_IO_A_CS(void);
void EXT_IO_B_CS(void);
void EXT_IO_C_CS(void);
void Keypad_Output_Row_1(void);
void Keypad_Output_Row_2(void);
void Keypad_Output_Row_3(void);
void Keypad_Output_Row_4(void);
uint8_t Keypad_Input(uint8_t Low_Num);
uint8_t Keypad(int8_t EXT_IO_DIR);
uint8_t my_Keypad(int8_t EXT_IO_DIR);

#endif  // __Keypad_H__