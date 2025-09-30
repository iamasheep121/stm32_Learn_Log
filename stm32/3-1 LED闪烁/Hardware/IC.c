#include "stm32f10x.h"


/**
  * 函    数：IC初始化
  * 参    数：无
  * 返 回 值：无
  */
  
  
void IC_Init(void)
{
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM3, ENABLE );
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
    // PA0 - TIM2_CH1 (PWM输出)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
 
	TIM_InternalClockConfig(TIM3);
	
	//时基单元配置
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 65536-1;		//ARR
	TIM_TimeBaseInitStruct.TIM_Prescaler = 72-1;	//PSC
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
	
	
	
	
//	//输出比较
//	TIM_OCInitTypeDef  TIM_OCInitStruct;
//	//给结构体赋默认值
//	TIM_OCStructInit(&TIM_OCInitStruct);
//	
//	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
//	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
//	TIM_OCInitStruct.TIM_Pulse = 0;
//	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OC1Init(TIM3,&TIM_OCInitStruct);
//	
	
	

	//设置TIM3通道1输入捕获
	TIM_ICInitTypeDef  TIM_ICInitStruct;
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICFilter = 0xF;
	TIM_PWMIConfig(TIM3,&TIM_ICInitStruct);//双通道，自动将相反的通道初始化，只能在通道1和通道2使用
	
	
	//选择听谁的（老板）触发源
	TIM_SelectInputTrigger( TIM3,TIM_TS_TI1FP1 );
	
//	//选择TRGO触发时机（老板什么时候喊开始）
 	TIM_SelectOutputTrigger( TIM3,TIM_TRGOSource_Reset );
	
	//从机工作模式
	TIM_SelectSlaveMode( TIM3 , TIM_SlaveMode_Reset );
	
	//使能TIM3时钟，让他工作
	TIM_Cmd(TIM3,ENABLE);
	 
}
//设定CCR的值，占空比=CCR/(ARR+1)
uint16_t  IC_Get_Duty(void)
{
	return (TIM_GetCapture2(TIM3) *100) / (TIM_GetCapture1(TIM3));
}


uint32_t IC_GetFreq(void)
{
	return 1000000/TIM_GetCapture1(TIM3);
}


