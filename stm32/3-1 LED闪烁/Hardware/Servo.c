#include "stm32f10x.h"
#include "PWM.h"
#include "Encode.h"
#include "IC.h"

void Servo_Init(void)
{
	PWM_Init();
	
}

void Servo_Angle(float Angle)
{
	TIM_SetCompare2(TIM2,( Angle / 180 * 2000 + 500));
}

