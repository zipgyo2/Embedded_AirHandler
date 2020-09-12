#include "Clock.h"
#define SEC_1 	SystemCoreClock/4  
#define SEC_2 	SystemCoreClock/2
#define SEC_4 	SystemCoreClock

extern void Delay(unsigned long d_t);

void FND_printing(void){ //FND에 시계, 설정 출력	
   FND_COM_DATA(8,time_1m);   // 8번째(오른쪽 맨 끝) 세그먼트에 time_1m 값 표시
   Delay(8000);
   FND_COM_DATA(7,time_10m);   
   Delay(8000);
   FND_COM_DATA(6,time_1h);   
   Delay(8000);
   FND_COM_DATA(5,time_10h);   
   Delay(8000);
}

void Joystick_Init(void){
   //output (port 4)
   LPC_GPIO4->FIODIR |= (1<<28);
   //input (port 1)
   LPC_GPIO1->FIODIR &= ~(1<<20); //press
   LPC_GPIO1->FIODIR &= ~(1<<23); //left
   LPC_GPIO1->FIODIR &= ~(1<<24); //up
   LPC_GPIO1->FIODIR &= ~(1<<25); //right
   LPC_GPIO1->FIODIR &= ~(1<<26); //down
}

uint8_t Joystick_read(){
   uint8_t js_val = 0;
   LPC_GPIO4->FIOPIN &= ~(1<<28);
   
   if((LPC_GPIO1->FIOPIN >> 20) & 0x01);
   else {
      if(time_handle_check ==0) {
         time_select =6;
         time_handle_check =1;
      }
      else time_handle_check =0;
      Delay(SEC_1/3);
   }
   if((LPC_GPIO1->FIOPIN >> 23) & 0x01);
   else js_val=2;
   if((LPC_GPIO1->FIOPIN >> 24) & 0x01);
   else js_val=3;
   if((LPC_GPIO1->FIOPIN >> 25) & 0x01);
   else js_val=4;
   if((LPC_GPIO1->FIOPIN >> 26) & 0x01);
   else js_val=5;
   
   LPC_GPIO4->FIOPIN |= ~(1<<28);
   
   return js_val;
}

void Time_SelectDP(uint8_t time_select){
   if(time_flag %2 == 0){
      FND_COM_DATA(time_select, 'D');
   }
}
void Time_Handler(uint8_t time_handle){
   switch(time_handle){
      case 2: 
         time_select--;
         if(time_select == 5) time_select =8;
         break;
      case 3: 
         Time_plus(time_select);
         break;
      case 4: 
         time_select++;
         if(time_select == 9) time_select =6;
         break;
      case 5: 
         Time_minus(time_select);
         break;
   }   
}

void Time_plus(uint8_t time_select){
   
   switch(time_select){
      case 8: 
         if(time_1m == 9) 
            time_1m =0;  
         else
            time_1m ++; 
         break;
         
      case 7: 
         if(time_10m == 5) 
            time_10m =0;
         else
            time_10m ++;
         break;
         
      case 6: 
         if((time_1h == 9 && time_10h == 0) || (time_1h == 9 && time_10h == 1)){
            time_1h =0;
            time_10h ++;
         }
         else if(time_10h == 2 && time_1h ==3){
            time_10h =0;
            time_1h = 0;
         }
         else time_1h ++;
         break;
   }
}

void Time_minus(uint8_t time_select){
   switch(time_select){
      case 8: 
         if(time_1m == 0) 
            time_1m =9;  
         else
            time_1m --; 
         break;
         
      case 7: 
         if(time_10m == 0) 
            time_10m =5;
         else
            time_10m --;
         break;
         
      case 6: 
         if((time_1h == 0 && time_10h == 2) || (time_1h == 0 && time_10h == 1)){
            time_1h =9;
            time_10h --;
         }
         else if(time_10h == 0 && time_1h ==0){
            time_10h =2;
            time_1h = 3;
         }
         else time_1h --;
         break;
   }
}
