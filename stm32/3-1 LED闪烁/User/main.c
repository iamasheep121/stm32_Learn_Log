#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"




int main()
{
	LED_Init();
	while(1)
	
	{
	RED_LED_ON();
	Delay_ms(500);
	RED_LED_OFF();
	Delay_ms(500);
	}
	
}
