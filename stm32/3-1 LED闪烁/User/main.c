#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
#include "KEY.h"
#include "BUZZER.h"
#include "LightSensor.h"
#include "OLED.h"
//#include "Timer.h"
//#include "Encode.h"
//#include "PWM.h"
//#include "ADC.h"
//#include "MY_DMA.h"
#include "Serial.h"
#include "ADC2.h"
uint8_t data;
int main(void)
{
	char Arr[10] = {'I',' ','l','o','v','e',' ','y','o','u'};
	uint8_t NumArr[] = {0x00,0x08,0x02,0x03};
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	OLED_Init();
	Serial_Init();
	//Serial_SendByte(0x43);
	while(1)
	{
		if(Serial_GetRxFlag() == 1)
		{
				data = Serial_GetRxData();
				Serial_SendByte(data);
				OLED_ShowHexNum(1,1,data,4);
		}
	}
	
}




