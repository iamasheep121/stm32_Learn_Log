#ifndef __OLED_H
#define __OLED_H

void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);


/**
  * @brief  网上找的代码
  * @param  deepseek
  * @retval 无
  */
  
void OLED_ShowBitmap(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, const uint8_t *Bitmap);
void OLED_ShowImage(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, const uint8_t *Image, uint8_t Invert);
void OLED_DrawHLine(uint8_t X, uint8_t Y, uint8_t Length);
void OLED_DrawVLine(uint8_t X, uint8_t Y, uint8_t Length);
void OLED_DrawRectangle(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2);
void OLED_FillRectangle(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2);
void OLED_ProgressBar(uint8_t Line, uint8_t Progress);
void OLED_ScrollText(uint8_t Line, char *String, uint16_t Speed);
void OLED_BallAnimation(uint8_t StartX, uint8_t EndX, uint8_t Y, uint16_t Speed);
	
#endif
