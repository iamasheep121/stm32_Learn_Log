#include "stm32f10x.h"
#include "PWM.h"
#include "Encode.h"
static uint8_t angle = 90;

void Servo_Init(void)
{
	PWM_Init();
	
}

void Servo_Angle(float Angle)
{
	PWM_SetCompare2( Angle / 180 * 2000 + 500);
}

