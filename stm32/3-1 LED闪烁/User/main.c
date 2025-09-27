#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
#include "KEY.h"
#include "BUZZER.h"
#include "LightSensor.h"
#include "OLED.h"
#include "CountSensor.h"
#include "Timer.h"


uint16_t count ;


int main(void)
{
	
	
	/*模块初始化*/
	OLED_Init();			

	Timer_Init();
	OLED_ShowString(1, 1, "Num:");
	while(1)
	{
		OLED_ShowNum(1,5,count,5);
	}
	

}

void TIM2_IRQHandler(void)
{
	if((TIM_GetITStatus(TIM2,TIM_IT_Update)==SET))
	{
		
		count++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
