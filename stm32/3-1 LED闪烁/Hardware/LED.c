#include "stm32f10x.h"
#include "Delay.h"
#define LED_PORT 	GPIOA
#define LED_PIN 	GPIO_Pin_0
#define LED_PIN_BLUE	GPIO_Pin_2
#define LED_PIN_RED 	GPIO_Pin_1
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = LED_PIN_BLUE | LED_PIN_RED ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA ,&GPIO_InitStructure);
	
	GPIO_SetBits(LED_PORT, LED_PIN_BLUE | LED_PIN_RED);
}

void BLUE_LED_ON(void)
{
	GPIO_ResetBits(LED_PORT, LED_PIN_BLUE );
}

void BLUE_LED_OFF(void)
{
	GPIO_SetBits(LED_PORT, LED_PIN_BLUE );
}

void RED_LED_ON(void)
{
	GPIO_ResetBits(LED_PORT, LED_PIN_RED );
}

void RED_LED_OFF(void)
{
	GPIO_SetBits(LED_PORT, LED_PIN_RED );
}



void heartbeat(void) {
    // 像心跳一样：快闪两次 + 停顿
    GPIO_ResetBits(LED_PORT, LED_PIN); Delay_ms(100);
    GPIO_SetBits(LED_PORT, LED_PIN);   Delay_ms(100);
    GPIO_ResetBits(LED_PORT, LED_PIN); Delay_ms(100);
    GPIO_SetBits(LED_PORT, LED_PIN);   Delay_ms(300);
}
