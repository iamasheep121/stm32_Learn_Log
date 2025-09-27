#include "stm32f10x.h"

#define LightSersor_PORT GPIOB
#define LightSersor_PIN GPIO_Pin_14


void LightSereor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin =  LightSersor_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB ,&GPIO_InitStructure);
}



uint8_t GetNum_LightSerSon(void)
{
	return GPIO_ReadInputDataBit(LightSersor_PORT,LightSersor_PIN);
}

