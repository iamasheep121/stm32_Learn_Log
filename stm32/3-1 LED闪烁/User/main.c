#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
#include "KEY.h"
#include "OLED.h"
#include "Serial.h"
#include "MyI2C.h"


int main()
{
	OLED_Init();
	MyI2C_Init();
	MyI2C_Start();
	MyI2C_SendByte( 0xD0 );
	uint8_t Ack = MyI2C_ReceiveAck();
	MyI2C_Stop();
	OLED_ShowNum(1,1,Ack,3);
	
}




