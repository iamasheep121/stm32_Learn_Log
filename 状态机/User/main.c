#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
#include "KEY.h"
#include "BUZZER.h"
#include "LightSensor.h"
#include "OLED.h"
#include "CountSensor.h"

int main(void)
{
	//按键状态
	typedef enum{
		STATE_PRESS,
		STATE_RELEASE,
		STATE_IDLE
	}State_Typedef;
	
	volatile State_Typedef current_stase = STATE_IDLE;
	
	
	
	LED_Init();
	Key_Init();
	
	switch (current_stase)
		case STATE_IDLE:
			break;
		
		case STATE_RELEASE:
			break;
		
		case STATE_PRESS:
	

}
