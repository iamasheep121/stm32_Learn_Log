#ifndef __LED_H
#define __LED_H

void LED_Init(void);
void heartbeat(void);
void BLUE_LED_ON(void);
void BLUE_LED_OFF(void);
void RED_LED_ON(void);
void RED_LED_OFF(void);
void LED2_Turn(void);
void LED1_Turn(void);


//网上代码
// 二进制计数模式数组 [LED1_PIN状态, LED2_PIN状态]
void binary_counter_effect(void);//二进制初始化
void running_light_effect(void);//跑马灯
void breathe_effect(void);//呼吸灯
void random_blink_effect(void);//随机灯

void rhythm_effect(void);//节奏效果
#endif










