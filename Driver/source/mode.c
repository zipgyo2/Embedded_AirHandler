
#include "mode.h"

void MOD_printing(uint8_t mod){
	if(print_flag >0){
		switch(mod){
			case 4:
					FND_COM_DATA(1,'C');
					Delay(5000);

					FND_COM_DATA(2, 'O'); 
					Delay(5000);

					FND_COM_DATA(3, 'O');
					Delay(5000);

					FND_COM_DATA(4, 'L');
					Delay(5000);
			break;
			case 5:
					FND_COM_DATA(1, 'H');
					Delay(5000);

					FND_COM_DATA(2, 'E');		
					Delay(5000);
					
					FND_COM_DATA(3, 'A');
					Delay(5000);

					FND_COM_DATA(4, 'T');
					Delay(5000);
			break;
			case 6:
				FND_COM_DATA(1, '_');
					Delay(5000);
					
					FND_COM_DATA(2, 'I');   
					Delay(5000);
					
					FND_COM_DATA(3, 'N');
					Delay(5000);
					
					FND_COM_DATA(4, '_');
					Delay(5000);
			break;
			case 11:
					FND_COM_DATA(1, '_');
					Delay(5000);
					
					FND_COM_DATA(2, 'O');
					Delay(5000);
					
					FND_COM_DATA(3, 'U');
					Delay(5000);
					
					FND_COM_DATA(4, 'T');
					Delay(5000);
			break;
		}
	}
}

void Mode(uint32_t input){
	uint8_t tmp = 0;
	print_flag =2;
	switch(input){
		case 4:
			if(led_flag2 == 1){
				Led_Off(3);
				Led_Off(4);
				led_flag2 = 0;
			}
			led_flag1 = 1;
			Led_On(1);
			Led_On(2);
			Delay(5000);
		break;
			
		case 5:
			if(led_flag1 == 1){
				Led_Off(1);
				Led_Off(2);
				led_flag1 = 0;
			}
			led_flag2 = 1;
			Led_On(3);
			Led_On(4);
			Delay(5000);
		break;
			
		case 6:
			if(led_flag4 == 1){
				Led_Off(7);
				Led_Off(8);
				led_flag4 = 0;
			}
			led_flag3 = 1;
			Led_On(5);
			Led_On(6);
			Delay(5000);
		break;
			
		case 11:
			if(led_flag3 == 1){
				Led_Off(5);
				Led_Off(6);
				led_flag3 = 0;
			}
			led_flag4 = 1;
			Led_On(7);
			Led_On(8);
			Delay(5000);
		break;
			
		case 15:
			Led_All_Off();
			led_flag1=0;
			led_flag2=0;
			led_flag3=0;
			led_flag4=0;
			Delay(5000);
		break;
	}
}