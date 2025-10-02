#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
#include "KEY.h"
#include "BUZZER.h"
#include "LightSensor.h"
#include "OLED.h"
//#include "CountSensor.h"
//#include "Timer.h"
//#include "Encode.h"
//#include "PWM.h"
//#include "Servo.h"
//#include "Motor.h"
//#include "IC.h"
//#include "PWMI.h"
//#include "Encode2.h"
//#include "ADC.h"
//uint16_t ADValue;
//uint16_t ADValue1;
//uint16_t ADValue2;
//#include "MY_DMA.h"
#include "ADC2.h"
int main(void)
{
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	OLED_Init();
	AD2_Init();
	while(1)
	{
		Get_ADValue();
		// 在你的主循环中：
		OLED_ShowNum(1, 1, dest[0], 4);  // PA0的ADC值
		OLED_ShowNum(2, 1, dest[1], 4);  // PA1的ADC值  
		OLED_ShowNum(3, 1, dest[2], 4);  // PA2的ADC值
		OLED_ShowNum(4, 1, dest[3], 4);  // PA3的ADC值
//		OLED_ShowChar(1,1,'a');
		Delay_ms(100);
	}
	
}

//#include "stm32f10x.h"                  // Device header
//#include "Delay.h"
//#include "OLED.h"
//#include "AD.h"

//int main(void)
//{
//	/*模块初始化*/
//	OLED_Init();				//OLED初始化
//	AD_Init();					//AD初始化
//	
//	/*显示静态字符串*/
//	OLED_ShowString(1, 1, "AD0:");
//	OLED_ShowString(2, 1, "AD1:");
//	OLED_ShowString(3, 1, "AD2:");
//	OLED_ShowString(4, 1, "AD3:");
//	
//	while (1)
//	{
//		OLED_ShowNum(1, 5, AD_Value[0], 4);		//显示转换结果第0个数据
//		OLED_ShowNum(2, 5, AD_Value[1], 4);		//显示转换结果第1个数据
//		OLED_ShowNum(3, 5, AD_Value[2], 4);		//显示转换结果第2个数据
//		OLED_ShowNum(4, 5, AD_Value[3], 4);		//显示转换结果第3个数据
//		
//		Delay_ms(100);							//延时100ms，手动增加一些转换的间隔时间
//	}
//}



