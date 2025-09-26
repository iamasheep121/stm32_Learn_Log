#include "stm32f10x.h"
#include "Delay.h"
#define LED_PORT 	GPIOA
#define LED_PIN 	GPIO_Pin_1 | GPIO_Pin_2
#define LED1_PIN	GPIO_Pin_2
#define LED2_PIN 	GPIO_Pin_1
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = LED1_PIN | LED2_PIN ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA ,&GPIO_InitStructure);
	
	GPIO_SetBits(LED_PORT, LED1_PIN | LED2_PIN);
}

void BLUE_LED_ON(void)
{
	GPIO_ResetBits(LED_PORT, LED1_PIN );
}

void BLUE_LED_OFF(void)
{
	GPIO_SetBits(LED_PORT, LED1_PIN );
}

void RED_LED_ON(void)
{
	GPIO_ResetBits(LED_PORT, LED2_PIN );
}

void RED_LED_OFF(void)
{
	GPIO_SetBits(LED_PORT, LED2_PIN );
}



void heartbeat(void) {
    // 像心跳一样：快闪两次 + 停顿
    GPIO_ResetBits(LED_PORT, LED_PIN); Delay_ms(100);
    GPIO_SetBits(LED_PORT, LED_PIN);   Delay_ms(100);
    GPIO_ResetBits(LED_PORT, LED_PIN); Delay_ms(100);
    GPIO_SetBits(LED_PORT, LED_PIN);   Delay_ms(300);
}

void LED1_PIN_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	}
	
}


void LED2_PIN_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	}
}


/**
  * @brief  网上找的代码
  * @param  deepseek
  * @retval 无
  */

// 二进制计数模式数组 [LED1_PIN状态, LED2_PIN状态]
const uint8_t binary_patterns[4][2] = {
    {0, 0},  // 00 - 全灭
    {0, 1},  // 01 - LED2_PIN亮
    {1, 0},  // 10 - LED1_PIN亮  
    {1, 1}   // 11 - 全亮
};

void binary_counter_effect(void) {
    for(int i = 0; i < 4; i++) {
        // 根据数组设置LED状态
        if(binary_patterns[i][0]) {
            GPIO_ResetBits(LED_PORT, LED1_PIN);  // LED1_PIN亮
        } else {
            GPIO_SetBits(LED_PORT, LED1_PIN);    // LED1_PIN灭
        }
        
        if(binary_patterns[i][1]) {
            GPIO_ResetBits(LED_PORT, LED2_PIN);  // LED2_PIN亮
        } else {
            GPIO_SetBits(LED_PORT, LED2_PIN);    // LED2_PIN灭
        }
        
        Delay_ms(500);  // 延时500ms
    }
}

// 跑马灯模式数组
const uint8_t running_light_patterns[4][2] = {
    {1, 0},  // LED1亮, LED2灭
    {0, 1},  // LED1灭, LED2亮  
    {1, 1},  // 全亮
    {0, 0}   // 全灭
};

void running_light_effect(void) {
    for(int i = 0; i < 4; i++) {
        // 设置LED1
        running_light_patterns[i][0] ? 
            GPIO_ResetBits(LED_PORT, LED1_PIN) : 
            GPIO_SetBits(LED_PORT, LED1_PIN);
        
        // 设置LED2
        running_light_patterns[i][1] ? 
            GPIO_ResetBits(LED_PORT, LED2_PIN) : 
            GPIO_SetBits(LED_PORT, LED2_PIN);
            
        Delay_ms(300);
    }
}

// 亮度等级数组（模拟PWM占空比）呼吸灯
const uint8_t breathe_patterns[8][2] = {
    {100, 0},   // LED1全亮, LED2全灭
    {80, 20},   // LED1 80%, LED2 20%
    {60, 40},   // LED1 60%, LED2 40%
    {40, 60},   // LED1 40%, LED2 60%
    {20, 80},   // LED1 20%, LED2 80%
    {0, 100},   // LED1全灭, LED2全亮
    {50, 50},   // 各50%
    {0, 0}      // 全灭
};

void breathe_effect(void) {
    for(int pattern = 0; pattern < 8; pattern++) {
        // 每个亮度等级持续一段时间，通过快速开关模拟PWM
        for(int cycle = 0; cycle < 100; cycle++) {
            // LED1 PWM
            if(cycle < breathe_patterns[pattern][0]) {
                GPIO_ResetBits(LED_PORT, LED1_PIN);
            } else {
                GPIO_SetBits(LED_PORT, LED1_PIN);
            }
            
            // LED2 PWM
            if(cycle < breathe_patterns[pattern][1]) {
                GPIO_ResetBits(LED_PORT, LED2_PIN);
            } else {
                GPIO_SetBits(LED_PORT, LED2_PIN);
            }
            
            Delay_ms(1);  // 1ms周期，总共100ms一个完整PWM周期
        }
    }
}

//随机闪烁效果
// 伪随机序列数组
const uint8_t random_patterns[16][2] = {
    {1, 0}, {0, 1}, {1, 1}, {0, 0},
    {1, 1}, {0, 0}, {1, 0}, {0, 1},
    {0, 1}, {1, 0}, {0, 0}, {1, 1},
    {1, 0}, {1, 1}, {0, 1}, {0, 0}
};

void random_blink_effect(void) {
    for(int i = 0; i < 16; i++) {
        // 使用位操作一次性设置两个LED
        if(random_patterns[i][0]) {
            GPIO_ResetBits(LED_PORT, LED1_PIN);
        } else {
            GPIO_SetBits(LED_PORT, LED1_PIN);
        }
        
        if(random_patterns[i][1]) {
            GPIO_ResetBits(LED_PORT, LED2_PIN);
        } else {
            GPIO_SetBits(LED_PORT, LED2_PIN);
        }
        
        Delay_ms(200);  // 快速闪烁
    }
}

//音乐节奏效果
// 节奏模式数组（类似心跳节奏）
const uint8_t rhythm_patterns[8][2] = {
    {1, 0}, {1, 0}, {0, 0},  // 哒 哒 空
    {0, 1}, {0, 1}, {0, 0},  // 哒 哒 空  
    {1, 1}, {0, 0}           // 哒 空
};

// 对应的延时时间（毫秒）
const uint16_t rhythm_delays[8] = {
    100, 100, 200,  // 短 短 长
    100, 100, 200,  // 短 短 长
    150, 250        // 中 长
};

void rhythm_effect(void) {
    for(int i = 0; i < 8; i++) {
        // 设置LED状态
        rhythm_patterns[i][0] ? 
            GPIO_ResetBits(LED_PORT, LED1_PIN) : 
            GPIO_SetBits(LED_PORT, LED1_PIN);
        
        rhythm_patterns[i][1] ? 
            GPIO_ResetBits(LED_PORT, LED2_PIN) : 
            GPIO_SetBits(LED_PORT, LED2_PIN);
            
        Delay_ms(rhythm_delays[i]);
    }
}