#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
#include "KEY.h"
#include "BUZZER.h"
#include "LightSensor.h"
#include "OLED.h"
#include "CountSensor.h"
#include "Timer.h"
#include "Encode.h"
#include "PWM.h"
#include "Servo.h"

void Earthquake(void);
void Binary_Counter(void);
void Snake_Move(void);
void Nod_Head(void);

uint8_t i;
uint8_t n;
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /*模块初始化*/
    OLED_Init();      
	Servo_Init();
	Encode_Init();
while(1)
{
	//Earthquake();
//	Binary_Counter();
	//Snake_Move();
	Nod_Head();
}

// 模拟地震震动
}

void Earthquake(void)
{
    while(1)
    {
        Servo_Angle(90);  // 中心位置
        
        // 随机震动
        for(int i = 0; i < 20; i++)
        {
            Servo_Angle(90 + (rand() % 30) - 15);  // 随机偏移
            Delay_ms(50 + rand() % 100);
        }
        
        Delay_ms(2000);  // 平静期
    }
}

// 用舵机位置表示二进制数
void Binary_Counter(void)
{
    uint8_t count = 0;
    
    while(1)
    {
        // 0-7用三个"比特位"表示
        uint8_t bit0 = (count & 0x01) ? 150 : 30;  // 最低位
        uint8_t bit1 = (count & 0x02) ? 150 : 30;  // 中间位  
        uint8_t bit2 = (count & 0x04) ? 150 : 30;  // 最高位
        
        // 快速在三个位置间切换（假装有多个舵机）
        Servo_Angle(bit0);
        Delay_ms(200);
        Servo_Angle(bit1);
        Delay_ms(200); 
        Servo_Angle(bit2);
        Delay_ms(500);
        
        count = (count + 1) & 0x07;  // 0-7循环
    }
}

// 像蛇一样扭动
void Snake_Move(void)
{
    uint8_t snake_wave[] = {0, 30, 60, 90, 120, 150, 180, 150, 120, 90, 60, 30};
    
    while(1)
    {
        for(int i = 0; i < 12; i++)
        {
            Servo_Angle(snake_wave[i]);
            OLED_ShowNum(1, 1, snake_wave[i], 4);
            Delay_ms(100);
        }
    }
}

// 快速点头
void Nod_Head(void)
{
    while(1)
    {
        Servo_Angle(90);   // 抬头
        Delay_ms(500);
        Servo_Angle(120);  // 点头
        Delay_ms(200);
        Servo_Angle(90);   // 抬头
        Delay_ms(500);
    }
}
