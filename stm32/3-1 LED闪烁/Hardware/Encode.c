#include "stm32f10x.h"

/*这是定时中断版本
*
*
*/
#define ENCODE_PORT GPIOB
#define ENCODE_PIN GPIO_Pin_1 | GPIO_Pin_0
int16_t Encode_Count;
void Encode_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Initstructure.GPIO_Pin = ENCODE_PIN;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
	
	//将两个端口设置为中断线
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
	
	//中断设置
	EXTI_InitTypeDef  EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line = EXTI_Line0 | EXTI_Line1;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
	//NVIC
	//PB0
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	//PB1
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
	
	
}
//A相PB0
void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0)== SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 0)
		{
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)		//PB0的下降沿触发中断，此时检测另一相PB1的电平，目的是判断旋转方向
			{
				Encode_Count ++;					//此方向定义为反转，计数变量自减
			}
		}
		EXTI_ClearFlag(EXTI_Line0);
	}
		
}
//B向PB1
void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1)== SET)
	{
		
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0)
		{
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)		//PB0的下降沿触发中断，此时检测另一相PB1的电平，目的是判断旋转方向
			{
				Encode_Count --;					//此方向定义为反转，计数变量自减
			}
		}
		EXTI_ClearFlag(EXTI_Line1);
	}
		
}

uint16_t Encode_Get(void)
{
	int16_t Temp;
	Temp = Encode_Count;
	Encode_Count = 0;
	return Temp;

}
