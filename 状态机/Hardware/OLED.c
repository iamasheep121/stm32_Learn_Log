#include "stm32f10x.h"
#include "OLED_Font.h"
#include "Delay.h"

/*引脚配置*/
#define OLED_W_SCL(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_8, (BitAction)(x))
#define OLED_W_SDA(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)(x))

/*引脚初始化*/
void OLED_I2C_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	OLED_W_SCL(1);
	OLED_W_SDA(1);
}

/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void OLED_I2C_Start(void)
{
	OLED_W_SDA(1);
	OLED_W_SCL(1);
	OLED_W_SDA(0);
	OLED_W_SCL(0);
}

/**
  * @brief  I2C停止
  * @param  无
  * @retval 无
  */
void OLED_I2C_Stop(void)
{
	OLED_W_SDA(0);
	OLED_W_SCL(1);
	OLED_W_SDA(1);
}

/**
  * @brief  I2C发送一个字节
  * @param  Byte 要发送的一个字节
  * @retval 无
  */
void OLED_I2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for (i = 0; i < 8; i++)
	{
		OLED_W_SDA(Byte & (0x80 >> i));
		OLED_W_SCL(1);
		OLED_W_SCL(0);
	}
	OLED_W_SCL(1);	//额外的一个时钟，不处理应答信号
	OLED_W_SCL(0);
}

/**
  * @brief  OLED写命令
  * @param  Command 要写入的命令
  * @retval 无
  */
void OLED_WriteCommand(uint8_t Command)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x00);		//写命令
	OLED_I2C_SendByte(Command); 
	OLED_I2C_Stop();
}

/**
  * @brief  OLED写数据
  * @param  Data 要写入的数据
  * @retval 无
  */
void OLED_WriteData(uint8_t Data)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x40);		//写数据
	OLED_I2C_SendByte(Data);
	OLED_I2C_Stop();
}

/**
  * @brief  OLED设置光标位置
  * @param  Y 以左上角为原点，向下方向的坐标，范围：0~7
  * @param  X 以左上角为原点，向右方向的坐标，范围：0~127
  * @retval 无
  */
void OLED_SetCursor(uint8_t Y, uint8_t X)
{
	OLED_WriteCommand(0xB0 | Y);					//设置Y位置
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	OLED_WriteCommand(0x00 | (X & 0x0F));			//设置X位置低4位
}

/**
  * @brief  OLED清屏
  * @param  无
  * @retval 无
  */
void OLED_Clear(void)
{  
	uint8_t i, j;
	for (j = 0; j < 8; j++)
	{
		OLED_SetCursor(j, 0);
		for(i = 0; i < 128; i++)
		{
			OLED_WriteData(0x00);
		}
	}
}

/**
  * @brief  OLED显示一个字符
  * @param  Line 行位置，范围：1~4
  * @param  Column 列位置，范围：1~16
  * @param  Char 要显示的一个字符，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char)
{      	
	uint8_t i;
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
}

/**
  * @brief  OLED显示字符串
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  String 要显示的字符串，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(Line, Column + i, String[i]);
	}
}

/**
  * @brief  OLED次方函数
  * @retval 返回值等于X的Y次方
  */
uint32_t OLED_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}

/**
  * @brief  OLED显示数字（十进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~4294967295
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十进制，带符号数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：-2147483648~2147483647
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length)
{
	uint8_t i;
	uint32_t Number1;
	if (Number >= 0)
	{
		OLED_ShowChar(Line, Column, '+');
		Number1 = Number;
	}
	else
	{
		OLED_ShowChar(Line, Column, '-');
		Number1 = -Number;
	}
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十六进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~0xFFFFFFFF
  * @param  Length 要显示数字的长度，范围：1~8
  * @retval 无
  */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i, SingleNumber;
	for (i = 0; i < Length; i++)							
	{
		SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16;
		if (SingleNumber < 10)
		{
			OLED_ShowChar(Line, Column + i, SingleNumber + '0');
		}
		else
		{
			OLED_ShowChar(Line, Column + i, SingleNumber - 10 + 'A');
		}
	}
}

/**
  * @brief  OLED显示数字（二进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
  * @param  Length 要显示数字的长度，范围：1~16
  * @retval 无
  */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0');
	}
}

/**
  * @brief  OLED初始化
  * @param  无
  * @retval 无
  */
void OLED_Init(void)
{
	uint32_t i, j;
	
	for (i = 0; i < 1000; i++)			//上电延时
	{
		for (j = 0; j < 1000; j++);
	}
	
	OLED_I2C_Init();			//端口初始化
	
	OLED_WriteCommand(0xAE);	//关闭显示
	
	OLED_WriteCommand(0xD5);	//设置显示时钟分频比/振荡器频率
	OLED_WriteCommand(0x80);
	
	OLED_WriteCommand(0xA8);	//设置多路复用率
	OLED_WriteCommand(0x3F);
	
	OLED_WriteCommand(0xD3);	//设置显示偏移
	OLED_WriteCommand(0x00);
	
	OLED_WriteCommand(0x40);	//设置显示开始行
	
	OLED_WriteCommand(0xA1);	//设置左右方向，0xA1正常 0xA0左右反置
	
	OLED_WriteCommand(0xC8);	//设置上下方向，0xC8正常 0xC0上下反置

	OLED_WriteCommand(0xDA);	//设置COM引脚硬件配置
	OLED_WriteCommand(0x12);
	
	OLED_WriteCommand(0x81);	//设置对比度控制
	OLED_WriteCommand(0xCF);

	OLED_WriteCommand(0xD9);	//设置预充电周期
	OLED_WriteCommand(0xF1);

	OLED_WriteCommand(0xDB);	//设置VCOMH取消选择级别
	OLED_WriteCommand(0x30);

	OLED_WriteCommand(0xA4);	//设置整个显示打开/关闭

	OLED_WriteCommand(0xA6);	//设置正常/倒转显示

	OLED_WriteCommand(0x8D);	//设置充电泵
	OLED_WriteCommand(0x14);

	OLED_WriteCommand(0xAF);	//开启显示
		
	OLED_Clear();				//OLED清屏
}


/**
  * @brief  网上找的代码
  * @param  deepseek
  * @retval 无
  */

/**
  * @brief  OLED显示位图
  * @param  X 起始列位置，范围：0~127
  * @param  Y 起始页位置，范围：0~7
  * @param  Width 图像宽度
  * @param  Height 图像高度（必须是8的倍数）
  * @param  Bitmap 图像数据指针
  * @retval 无
  */
void OLED_ShowBitmap(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, const uint8_t *Bitmap)
{
    uint8_t i, j, page;
    
    // 检查参数有效性
    if (X > 127 || Y > 7 || (Height % 8) != 0) return;
    
    // 计算页数
    uint8_t pages = Height / 8;
    
    for (page = 0; page < pages; page++) {
        OLED_SetCursor(Y + page, X);
        for (i = 0; i < Width; i++) {
            OLED_WriteData(Bitmap[page * Width + i]);
        }
    }
}

/**
  * @brief  OLED显示自定义图像（带掩码）
  * @param  X 起始列位置
  * @param  Y 起始页位置
  * @param  Width 图像宽度
  * @param  Height 图像高度
  * @param  Image 图像数据指针
  * @param  Invert 是否反色显示
  * @retval 无
  */
void OLED_ShowImage(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, const uint8_t *Image, uint8_t Invert)
{
    uint8_t i, j, page;
    uint8_t pages = (Height + 7) / 8; // 计算需要的页数
    
    for (page = 0; page < pages; page++) {
        OLED_SetCursor(Y + page, X);
        for (i = 0; i < Width; i++) {
            uint8_t data = Image[page * Width + i];
            if (Invert) {
                data = ~data; // 反色显示
            }
            OLED_WriteData(data);
        }
    }
}

/**
  * @brief  OLED绘制水平线
  * @param  X 起始列位置
  * @param  Y 起始页位置
  * @param  Length 线长度
  * @retval 无
  */
void OLED_DrawHLine(uint8_t X, uint8_t Y, uint8_t Length)
{
    uint8_t i;
    OLED_SetCursor(Y, X);
    for (i = 0; i < Length; i++) {
        OLED_WriteData(0xFF); // 画实线
    }
}

/**
  * @brief  OLED绘制垂直线
  * @param  X 列位置
  * @param  Y 起始页位置
  * @param  Length 线长度（页数）
  * @retval 无
  */
void OLED_DrawVLine(uint8_t X, uint8_t Y, uint8_t Length)
{
    uint8_t i;
    for (i = 0; i < Length; i++) {
        OLED_SetCursor(Y + i, X);
        OLED_WriteData(0xFF);
    }
}

/**
  * @brief  OLED绘制矩形框
  * @param  X1 左上角列位置
  * @param  Y1 左上角页位置
  * @param  X2 右下角列位置
  * @param  Y2 右下角页位置
  * @retval 无
  */
void OLED_DrawRectangle(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2)
{
    OLED_DrawHLine(X1, Y1, X2 - X1 + 1);     // 上边
    OLED_DrawHLine(X1, Y2, X2 - X1 + 1);     // 下边
    OLED_DrawVLine(X1, Y1, Y2 - Y1 + 1);     // 左边
    OLED_DrawVLine(X2, Y1, Y2 - Y1 + 1);     // 右边
}

/**
  * @brief  OLED填充矩形
  * @param  X1 左上角列位置
  * @param  Y1 左上角页位置
  * @param  X2 右下角列位置
  * @param  Y2 右下角页位置
  * @retval 无
  */
void OLED_FillRectangle(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2)
{
    uint8_t i, j;
    for (i = Y1; i <= Y2; i++) {
        OLED_SetCursor(i, X1);
        for (j = X1; j <= X2; j++) {
            OLED_WriteData(0xFF);
        }
    }
}

/**
  * @brief  简单动画 - 进度条
  * @param  Line 行位置，1~4
  * @param  Progress 进度，0~100
  * @retval 无
  */
void OLED_ProgressBar(uint8_t Line, uint8_t Progress)
{
    uint8_t i;
    uint8_t startX = 10;
    uint8_t endX = 118;
    uint8_t length = endX - startX;
    uint8_t fillLength = (length * Progress) / 100;
    
    // 清空进度条区域
    OLED_SetCursor((Line-1)*2, startX);
    for (i = 0; i < length; i++) {
        OLED_WriteData(0x00);
    }
    OLED_SetCursor((Line-1)*2+1, startX);
    for (i = 0; i < length; i++) {
        OLED_WriteData(0x00);
    }
    
    // 绘制边框
    OLED_DrawRectangle(startX-1, (Line-1)*2, endX+1, (Line-1)*2+1);
    
    // 填充进度
    if (fillLength > 0) {
        OLED_SetCursor((Line-1)*2, startX);
        for (i = 0; i < fillLength; i++) {
            OLED_WriteData(0xFF);
        }
        OLED_SetCursor((Line-1)*2+1, startX);
        for (i = 0; i < fillLength; i++) {
            OLED_WriteData(0xFF);
        }
    }
}

/**
  * @brief  动画 - 滚动文本
  * @param  Line 行位置，1~4
  * @param  String 要显示的字符串
  * @param  Speed 滚动速度（延时毫秒数）
  * @retval 无
  */
void OLED_ScrollText(uint8_t Line, char *String, uint16_t Speed)
{
    uint8_t i, j;
    uint8_t len = 0;
    char buffer[50];
    
    // 计算字符串长度
    while (String[len] != '\0') len++;
    
    // 如果字符串长度小于16，不需要滚动
    if (len <= 16) {
        OLED_ShowString(Line, 1, String);
        return;
    }
    
    // 创建滚动缓冲区
    for (i = 0; i < len + 16; i++) {
        OLED_Clear();
        
        // 构建当前帧的显示内容
        for (j = 0; j < 16; j++) {
            if (i + j < len) {
                buffer[j] = String[i + j];
            } else if (i + j < len + 16) {
                buffer[j] = ' ';
            } else {
                buffer[j] = '\0';
                break;
            }
        }
        buffer[16] = '\0';
        
        OLED_ShowString(Line, 1, buffer);
        Delay_ms(Speed);
        
        // 如果滚动完成，退出
        if (i >= len) break;
    }
}


/**
  * @brief  动画 - 移动的小球
  * @param  StartX 起始列位置
  * @param  EndX 结束列位置
  * @param  Y 页位置
  * @param  Speed 移动速度
  * @retval 无
  */
void OLED_BallAnimation(uint8_t StartX, uint8_t EndX, uint8_t Y, uint16_t Speed)
{
    uint8_t i;
    uint8_t ball[] = {0x3C, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C}; // 小球图案
    
    for (i = StartX; i <= EndX; i++) {
        OLED_Clear();
        OLED_ShowImage(i, Y, 8, 8, ball, 0);
        Delay_ms(Speed);
    }
    
    for (i = EndX; i >= StartX; i--) {
        OLED_Clear();
        OLED_ShowImage(i, Y, 8, 8, ball, 0);
        Delay_ms(Speed);
    }
}

//搬上去就能用
//	  while (1) {
//        // 示例1: 进度条动画
//        OLED_Clear();
//        OLED_ShowString(1, 1, "Progress:");
//        for (uint8_t i = 0; i <= 100; i += 5) {
//            OLED_ProgressBar(2, i);
//            Delay_ms(100);
//        }
//        Delay_ms(1000);
//        
//        // 示例2: 滚动文本
//        OLED_Clear();
//        OLED_ScrollText(3, "Hello! This is a scrolling text demo!", 150);
//        Delay_ms(1000);
//        
//        // 示例3: 移动的小球
//        OLED_Clear();
//        OLED_ShowString(1, 1, "Ball Animation");
//        OLED_BallAnimation(10, 110, 2, 50);
//        Delay_ms(1000);
//        
//        // 示例4: 图形显示
//        OLED_Clear();
//        OLED_ShowString(1, 1, "Graphics Demo");
//        OLED_DrawRectangle(10, 2, 117, 5);    // 绘制矩形框
//        OLED_FillRectangle(15, 3, 30, 4);     // 填充矩形
//        Delay_ms(2000);
//    }
