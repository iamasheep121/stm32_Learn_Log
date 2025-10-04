#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#define KEY_PORT GPIOB
#define KEY_PIN GPIO_Pin_11 | GPIO_Pin_1
void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//开启PB11作为按键中断源
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource11);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = KEY_PIN ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB ,&GPIO_InitStructure);
	
//	EXTI_InitTypeDef EXTI_InitStruct;
//	EXTI_InitStruct.EXTI_Line = EXTI_Line11;
//	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
//	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
//	EXTI_Init(&EXTI_InitStruct);
//	
//	NVIC_InitTypeDef  NVIC_InitStruct;
//	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
//	NVIC_Init(&NVIC_InitStruct);
//	
}

//void EXTI15_10_IRQHandler(void)
//{
//    if (EXTI_GetITStatus(EXTI_Line11) == SET)
//    {
//        Delay_ms(20); // 消抖
//        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
//        {
//            static uint8_t led_state = 0;
//            if (led_state == 0)
//            {
//                BLUE_LED_ON(); // 打开LED
//                led_state = 1;
//            }
//            else
//            {
//                BLUE_LED_OFF(); // 关闭LED
//                led_state = 0;
//            }
//        }
//        EXTI_ClearITPendingBit(EXTI_Line11); // 清除中断挂起位
//    }
//}


uint8_t Key_GetNumber(void)
{
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0);
		Delay_ms(20);
		KeyNum = 1;
		
	}
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0);
		Delay_ms(20);
		KeyNum = 2;
		
	}
	
	return KeyNum;
}


