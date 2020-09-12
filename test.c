#include "lpc17xx_adc.h"
#include "lpc17xx_exti.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_clkpwr.h"
#include "debug_frmwrk.h"

#include "led.h"
#include "fnd.h"
#include "motor.h"
#include "keypad.h"
#include "Clock.h"
#include "mode.h"

#define _ADC_INT         ADC_ADINTEN2
#define _ADC_CHANNEL      ADC_CHANNEL_2

__IO uint32_t adc_value;
uint32_t adc_flag = 0;
uint8_t int_flag = 0;
uint8_t time_flag = 0;

uint8_t time_10h =1 ;
uint8_t time_1h =3 ;
uint8_t time_10m = 3;
uint8_t time_1m = 2;
uint8_t time_10s =5;
uint8_t time_1s =0;

uint8_t time_handle = 0;
uint8_t time_handle_check = 0;
uint8_t time_select = 5;

uint8_t led_flag1 = 0;
uint8_t led_flag2 = 0;
uint8_t led_flag3 = 0;
uint8_t led_flag4 = 0;

void Delay(unsigned long d_t);
void PinConfig(void);
void ADCConfig(void);
void EXTIConfig(void);
void TIMER0Config(void);

/* Private struct ---------------------------------------------------------*/
TIM_TIMERCFG_Type TIM_ConfigStruct;
TIM_MATCHCFG_Type TIM_MatchConfigStruct ;

int main(){
	SystemInit();
	Motor_Init();
	Led_Init();
	Led_All_Off();
	Joystick_Init();
	
	EXTIConfig();
	ADCConfig();
	TIMER0Config();
	
	NVIC_SetPriority(ADC_IRQn, ((0x01<<4)|0x01));
	NVIC_SetPriority(EINT0_IRQn, ((0x01<<3)|0x01));
	NVIC_SetPriority(TIMER0_IRQn, ((0x01<<2)|0x01));
	
	NVIC_EnableIRQ(TIMER0_IRQn);   //   TIMER0 Interrupt 활성화
	NVIC_EnableIRQ(EINT0_IRQn); // EXTI0 ???	
	
	TIM_Cmd(LPC_TIM0, ENABLE);   //   Timer Start

	while(1){
		if (int_flag == 1){
			ADC_StartCmd(LPC_ADC,ADC_START_NOW);
			NVIC_EnableIRQ(ADC_IRQn);
			Delay(10000);
		}
		else{
			uint32_t input = 0;
			uint32_t input_tmp = Keypad('C');
			input = input_tmp;
			Delay(5000);
			if(input != 0) Mode(input);
			
			time_handle = Joystick_read(); //JoyStick 읽기
			Delay(5000);
			if(time_handle_check == 0){
				FND_printing(); //FND 출력
			}
			else{
				while(time_handle == 0){
					time_handle = Joystick_read();
					Time_Handler(time_handle);
					Delay(5000);
					FND_printing();
					Time_SelectDP(time_select);
					if(time_handle_check == 0) break;
				}
				FND_printing();
				Time_SelectDP(time_select);
			}   
		}		
	}
}

void TIMER0_IRQHandler(void){   // 1초에 한번 씩 진입
   TIM_ClearIntPending(LPC_TIM0, TIM_MR0_INT); //TIM0 interrupt clear
   
   // 초 : 1의 자리 , 10의 자리 / 분 : 1의 자리, 10의 자리
   time_flag++;
   if(time_flag == 10) time_flag =0;
   
   time_1s++;
   if(time_1s == 10)
   {
      time_10s++;
      time_1s=0;
   }
   if(time_10s == 6)
   {
      time_1m++;
      time_10s = 0;
   }
   if(time_1m == 10)
   {
      time_10m++;
      time_1m = 0;
   }   
   if(time_10m == 6)
   {
      time_1h ++;
      time_10m =0 ;
      
   }   
   if(time_1h ==10){
      time_10h ++;
      time_1h=0;
   }
   if(time_10h ==2 && time_1h ==4){
      time_10h=0;
      time_1h=0;
      time_1m =0 ;
      time_10s = 0;
      time_1s = 0;
   }
}

void ADC_IRQHandler(void)
{
	adc_value = 0;
	if (ADC_ChannelGetStatus(LPC_ADC,_ADC_CHANNEL,ADC_DATA_DONE))
	{
		adc_value =  ADC_ChannelGetData(LPC_ADC,_ADC_CHANNEL);
		NVIC_DisableIRQ(ADC_IRQn);
	}
	adc_flag = 1;
	if (int_flag == 1){
		if(led_flag1 == 1) {
			led_flag2 = 0;
			Cycle(adc_value);
		}
		if(led_flag2 == 1) {
			led_flag1 =0;
			Cycle_Reverse(adc_value);
		}
	}
	else adc_flag = 0;
}

void EINT0_IRQHandler(void)
{
	EXTI_ClearEXTIFlag(EXTI_EINT0);   // Interrupt ??? ??? ?? ?? ?? ??? ???.
	int_flag = int_flag^0x1;
	if (int_flag == 1){
		if(led_flag1 == 1) {
			led_flag2 = 0;
			Cycle(adc_value);
		}
		if(led_flag2 == 1) {
			led_flag1 =0;
			Cycle_Reverse(adc_value);
		}
	}
}

void Delay(unsigned long d_t)
{
	long k;
	for(k=0; k<d_t; k++); //sytem clock speed = 12MHz, 1 loop delay = 1/12,000,000 sec
}

void PinConfig(void){
	PINSEL_CFG_Type PinCfg;
	/*
	* Init ADC pin connect
	* AD0.2 on P0.25
	*/
	PinCfg.Funcnum = 1;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Pinnum = 25;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);
}

void ADCConfig(void){
	PinConfig();
		/* Configuration for ADC:
	*  select: ADC channel 2 (if using MCB1700 board)
	*        ADC channel 5 (if using IAR-LPC1768 board)
	*  ADC conversion rate = 200KHz
	*/
	ADC_Init(LPC_ADC, 200000);
	ADC_IntConfig(LPC_ADC,_ADC_INT,ENABLE);
	ADC_ChannelCmd(LPC_ADC,_ADC_CHANNEL,ENABLE);
}

void EXTIConfig(void){
	EXTI_Init();   // EXTI ???
	AF_ConfigPin(2, PINSEL_PIN_10, PINSEL_FUNC_1);   // ?? GPIO ??? ?? Alternate Function? ???? ?? ??
	EXTI_ConfigPin(EXTI_EINT0); // EXTI0 ??
}

void TIMER0Config(void){
   TIM_ConfigStruct.PrescaleOption = TIM_PRESCALE_USVAL;   //   us(microsecond) 기준으로 Prescale 설정
   TIM_ConfigStruct.PrescaleValue   = 100;   //   100us
   TIM_MatchConfigStruct.MatchChannel = 0;   //   0번 채널 사용
   TIM_MatchConfigStruct.IntOnMatch = ENABLE;   //   Timer가 일치할 때  Interrupt 발생 Enable
   TIM_MatchConfigStruct.ResetOnMatch = ENABLE;   //   Timer가 일치할 때  Reset Enable
   TIM_MatchConfigStruct.StopOnMatch = DISABLE;   //   Timer가 일치할 때 Timer Stop Disable
   TIM_MatchConfigStruct.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;   //   Timer 일치할때 아무런 외부 출력 하지 않음 (외부로 출력하지 않기 때문에 GPIO를 설정하지 않아도 됨.)
   TIM_MatchConfigStruct.MatchValue = 10000;   // Timer 일치 값 설정 100us * 10000번 = 1초
	
	 TIM_Init(LPC_TIM0, TIM_TIMER_MODE,&TIM_ConfigStruct);   //  TIM_ConfigStruct 설정 적용
   TIM_ConfigMatch(LPC_TIM0,&TIM_MatchConfigStruct);      // TIM_MatchConfigStruct 설정 적용
}
