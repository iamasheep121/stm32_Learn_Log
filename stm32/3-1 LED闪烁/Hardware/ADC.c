#include "stm32f10x.h"

void AD_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2,ENABLE);
	
	/*设置ADC时钟*/
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN ;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//ADC规则通道配置,在这里可以启用多个通道，最多同时16个通道，不过要注意引脚，要复用一下
	
	
	ADC_InitTypeDef  ADC_InitStruct;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//触发控制的外部触发源选择
	//单ADC还是双ADC
	ADC_InitStruct.ADC_Mode =ADC_Mode_Independent;
	//连续还是单次，disable是单次转换，enable是连续转换
	ADC_InitStruct.ADC_ContinuousConvMode = DISABLE;
	//通道数目 number = nbr
	ADC_InitStruct.ADC_NbrOfChannel = 3;
	//选择扫描还是非扫描模式
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_Init(ADC2,&ADC_InitStruct);
	
	//如果有需要，这里可以添加配置中断和看门狗
	ADC_Cmd(ADC2,ENABLE);
	
	//校准ADC
	ADC_ResetCalibration(ADC2);
	while(ADC_GetResetCalibrationStatus(ADC2) == SET);//等待校准过程
	ADC_StartCalibration(ADC2);
	while(ADC_GetCalibrationStatus(ADC2) == SET);
	
}

//单通道调用
uint16_t AD_GetValue(  )
{
	ADC_RegularChannelConfig(ADC2,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);
	ADC_SoftwareStartConvCmd(ADC2,ENABLE);
	while(ADC_GetFlagStatus(ADC2,ADC_FLAG_EOC) == RESET);//等待完成，reset为0，表示未完成
	return ADC_GetConversionValue(ADC2);
}

//多通道调用
uint16_t AD_GetValue_Nbr( uint8_t ADC_Channe_x )
{
	ADC_RegularChannelConfig(ADC2,ADC_Channe_x,1,ADC_SampleTime_55Cycles5);
	ADC_SoftwareStartConvCmd(ADC2,ENABLE);
	while(ADC_GetFlagStatus(ADC2,ADC_FLAG_EOC) == RESET);//等待完成，reset为0，表示未完成
	return ADC_GetConversionValue(ADC2);
}
