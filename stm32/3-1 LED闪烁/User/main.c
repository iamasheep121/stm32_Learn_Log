//#include "stm32f10x.h"
//#include "delay.h"
//#include "LED.h"
//#include "KEY.h"
//#include "BUZZER.h"
//#include "LightSensor.h"
//#include "OLED.h"
////#include "CountSensor.h"
////#include "Timer.h"
////#include "Encode.h"
////#include "PWM.h"
////#include "Servo.h"
////#include "Motor.h"
////#include "IC.h"
//#include "PWMI.h"
//uint16_t Speed;
////uint16_t j;
//#include "Encode2.h"
//int main(void)
//{
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//    
//    /*模块初始化*/
//    OLED_Init();  
//	//PWMI_Init();
//	Encoder_Init();
////	PWM_Init();
////	IC_Init();
////	
////	
////	PWM_SetPrescaler( 720-1 );
////	PWM_SetCompare1(50);
//	
//	OLED_ShowString(1, 1, "Speed:");
//	
// 	
//	
//	
//	
//	
//	

//	while(1)
//	{
//		OLED_ShowSignedNum(2,1,Encoder_Get(),5);
//	}

//}

//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET)
//	{
//		Speed = Encoder_Get();
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}


