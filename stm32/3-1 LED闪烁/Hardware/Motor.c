#include "stm32f10x.h"
#include "PWM.h"
#define GPIO_IN1_PIN GPIO_Pin_4
#define GPIO_IN2_PIN GPIO_Pin_5

void Motor_Init(void)
{
	PWM_Init();
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_IN1_PIN | GPIO_IN2_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOA, &GPIO_InitStructure );
	
}

void Motor_Speed(int8_t Speed)
{
	if( Speed >= 0 )
	{
		//正转
		GPIO_SetBits( GPIOA, GPIO_IN1_PIN );
		GPIO_ResetBits( GPIOA, GPIO_IN2_PIN );
		PWM_SetCompare2( Speed );
		
		
	}
	else
	{
		//反转
		GPIO_ResetBits( GPIOA, GPIO_IN1_PIN );
		GPIO_SetBits( GPIOA, GPIO_IN2_PIN);
		PWM_SetCompare2( -Speed );
		
	}
}
