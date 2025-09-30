#include "stm32f10x.h"

void PWMI_Init(void)
{
	//开启GPIOA的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	//P6，TIM3通道1输出测波形
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_6 ;
	GPIO_Initstructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	
	//P7，TIM3通道2输入读取数据
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_7 ;
	GPIO_Initstructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	
	//配置TIM3的时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 720-1;	//PSC
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 100-1;	//ARR
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
	
	//配置输出比较
	TIM_OCInitTypeDef  TIM_OCInitStruct;
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 50;//CCR的值
	TIM_OC1Init(TIM3,&TIM_OCInitStruct);
	
	
	//配置TIM3的通道2作为输入捕获
	TIM_ICInitTypeDef  TIM_ICInitStruct;
	TIM_ICStructInit(&TIM_ICInitStruct);
	
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICFilter = 0x0F;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM3,&TIM_ICInitStruct);
	
	//TIM_PWMIConfig(TIM3,&TIM_ICInitStruct);//双通道，自动将相反的通道初始化，只能在通道1和通道2使用
	
	
	//配置主模式，从模式，触发源
//	TIM_SelectOutputTrigger(TIM2,TIM_TRGOSource_Reset);//配置定时器2为主模式
//	TIM_SelectInputTrigger();
//	TIM_SelectSlaveMode();
	//开启TIM3定时器
	TIM_Cmd(TIM3,ENABLE);
}

void PWMI_Set_Prescaler(uint16_t Prescaler)
{
	TIM_PrescalerConfig(TIM2,Prescaler,TIM_PSCReloadMode_Update);

}
uint16_t GetFrequence( void )
{
	return 72000000 / TIM_GetCapture1(TIM3)/100;
}

uint16_t PWM_GetCapture( uint16_t CCR)
{
	return TIM_GetCapture1(TIM3);
}


uint16_t PWM_Get_CCR( void )
{
	return TIM3->CCR3;
}

uint16_t PWM_Get_duty(void)
{
	return TIM_GetCapture2(TIM3) / TIM_GetCapture1(TIM3);
}
