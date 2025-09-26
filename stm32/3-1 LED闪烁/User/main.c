#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
#include "KEY.h"
#include "BUZZER.h"
#include "LightSensor.h"
#include "OLED.h"

int main()
{
	LED_Init();
	Key_Init();
	OLED_Init();
	OLED_ShowChar(1,1,'A');
	while (1) {
        // 示例1: 进度条动画
        OLED_Clear();
        OLED_ShowString(1, 1, "Progress:");
        for (uint8_t i = 0; i <= 100; i += 5) {
            OLED_ProgressBar(2, i);
            Delay_ms(100);
        }
        Delay_ms(1000);
        
        // 示例2: 滚动文本
        OLED_Clear();
        OLED_ScrollText(3, "Hello! This is a scrolling text demo!", 150);
        Delay_ms(1000);
        
        // 示例3: 移动的小球
        OLED_Clear();
        OLED_ShowString(1, 1, "Ball Animation");
        OLED_BallAnimation(10, 110, 2, 50);
        Delay_ms(1000);
        
        // 示例4: 图形显示
        OLED_Clear();
        OLED_ShowString(1, 1, "Graphics Demo");
        OLED_DrawRectangle(10, 2, 117, 5);    // 绘制矩形框
        OLED_FillRectangle(15, 3, 30, 4);     // 填充矩形
        Delay_ms(2000);
    }
}
