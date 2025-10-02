#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
#include "KEY.h"
#include "BUZZER.h"
#include "LightSensor.h"
#include "OLED.h"
//#include "CountSensor.h"
//#include "Timer.h"
//#include "Encode.h"
//#include "PWM.h"
//#include "Servo.h"
//#include "Motor.h"
//#include "IC.h"
#include "PWMI.h"
#include "Encode2.h"
#include "ADC.h"
//uint16_t ADValue;
//uint16_t ADValue1;
//uint16_t ADValue2;
#include "MY_DMA.h"

const uint8_t a = 0x35;
int main(void)
{
	DMA_Cmd(DMA1_Channel1,DISABLE);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
	uint8_t src[] = {0x01,0x02,0x03,0x04};
	uint8_t dest[] = {0,0,0,0};
	
    /*模块初始化*/
    OLED_Init();  
	
	OLED_ShowHexNum(1,1,src[0],2);
	OLED_ShowHexNum(1,4,src[1],2);
	OLED_ShowHexNum(1,7,src[2],2);
	OLED_ShowHexNum(1,10,src[3],2);
	
	OLED_ShowHexNum(2,1,dest[0],2);
	OLED_ShowHexNum(2,4,dest[1],2);
	OLED_ShowHexNum(2,7,dest[2],2);
	OLED_ShowHexNum(2,10,dest[3],2);
	Delay_ms(1000);
	
	
	MyDMA_Init((uint32_t)src,(uint32_t)dest,4);
	//PWMI_Init();
	
	OLED_ShowHexNum(3,1,src[0],2);
	OLED_ShowHexNum(3,4,src[1],2);
	OLED_ShowHexNum(3,7,src[2],2);
	OLED_ShowHexNum(3,10,src[3],2);
	
	
	OLED_ShowHexNum(4,1,dest[0],2);
	OLED_ShowHexNum(4,4,dest[1],2);
	OLED_ShowHexNum(4,7,dest[2],2);
	OLED_ShowHexNum(4,10,dest[3],2);
	while (1)
	{
		
	}

}



