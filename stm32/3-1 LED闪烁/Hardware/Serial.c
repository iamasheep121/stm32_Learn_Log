#include "stm32f10x.h"
#include "stdio.h"
#include "stdarg.h"

uint8_t Serial_RxPacket[4];/*接收数据包*/
uint8_t Serial_TxPacket[4];/*发送数据包*/
uint8_t Serial_RxFlag;

void Serial_Init(void)
{
	/*开启USART1和GPIOA的时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	/*配置PA9接收，PA10发送*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA ,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA ,&GPIO_InitStructure);
	
	/*配置USART1*/
	USART_InitTypeDef  USART_InitStruct;
	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits =  USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);
	
	/*开启USART1*/
	USART_Cmd(USART1,ENABLE);
	
	/*配置串口接收中断*/
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef  NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);

}

uint8_t Serial_GetRxFlag(void)
{
	if(Serial_RxFlag == 1)
	{
		Serial_RxFlag = 0;
		return 1;
	}
	return 0;
}

	/*中断*/
	void USART1_IRQHandler( void )
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE) == SET)
	{
		static uint8_t RxState = 0;
		static uint8_t pRxPacket = 0;
		//Serial_RxFlag = 0;
		uint8_t RxData = USART_ReceiveData(USART1);
		switch( RxState )
		{
			case 0:
			{
				if( RxData == 0xFF)
				{
					RxState = 1;
					pRxPacket = 0;
				break;
				}
			}
			case 1:
			{
				Serial_RxPacket[pRxPacket] = RxData;
				pRxPacket++;
				if(pRxPacket >= 4)
				{
					RxState = 2;
				}
				break;
			}
			case 2:
			{
				if(RxData == 0xFE)
				{
					RxState = 0;
					Serial_RxFlag = 1;
				}
				break;
			}
		}
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}

//void USART1_IRQHandler(void)
//{
//	static uint8_t RxState = 0;		//定义表示当前状态机状态的静态变量
//	static uint8_t pRxPacket = 0;	//定义表示当前接收数据位置的静态变量
//	if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET)		//判断是否是USART1的接收事件触发的中断
//	{
//		uint8_t RxData = USART_ReceiveData(USART1);				//读取数据寄存器，存放在接收的数据变量
//		
//		/*使用状态机的思路，依次处理数据包的不同部分*/
//		
//		/*当前状态为0，接收数据包包头*/
//		if (RxState == 0)
//		{
//			if (RxData == 0xFF)			//如果数据确实是包头
//			{
//				RxState = 1;			//置下一个状态
//				pRxPacket = 0;			//数据包的位置归零
//			}
//		}
//		/*当前状态为1，接收数据包数据*/
//		else if (RxState == 1)
//		{
//			Serial_RxPacket[pRxPacket] = RxData;	//将数据存入数据包数组的指定位置
//			pRxPacket ++;				//数据包的位置自增
//			if (pRxPacket >= 4)			//如果收够4个数据
//			{
//				RxState = 2;			//置下一个状态
//			}
//		}
//		/*当前状态为2，接收数据包包尾*/
//		else if (RxState == 2)
//		{
//			if (RxData == 0xFE)			//如果数据确实是包尾部
//			{
//				RxState = 0;			//状态归0
//				Serial_RxFlag = 1;		//接收数据包标志位置1，成功接收一个数据包
//			}
//		}
//		
//		USART_ClearITPendingBit(USART1, USART_IT_RXNE);		//清除标志位
//	}
//}



//void USART1_IRQHandler( void )
//{
//		if(USART_GetITStatus(USART1,USART_IT_RXNE) == SET)
//	{
//		static uint8_t Serial_Status = 0;
//		
//		static uint8_t Serial_pflag = 0;
//	
//		uint32_t Serial_Data = USART_ReceiveData(USART1);
//		switch(Serial_Status)
//		{
//			case 0:
//				if( Serial_Data == 0xFF )
//				{
//					
//					Serial_Status = 1;
//					Serial_pflag = 0;
//				}
//					break;
//				
//			case 1:
//			{			
//				Serial_RxPacket[Serial_pflag] = Serial_Data;
//				Serial_pflag++;
//				if(Serial_pflag >=4 )
//				{
//					Serial_Status = 2;
//				}
//				break;
//				
//			}
//			case 2:
//			{
//				if( Serial_Data == 0xFE)
//					
//				{
//					Serial_Status = 0;
//					Serial_RxFlag = 1;
//				}
//				break;
//				
//			}
//		}
//		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
//	}
//	
//	
//}


void Serial_SendByte(uint8_t Byte)
{
	
	USART_SendData(USART1,Byte);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) ==RESET);
	
}

	/*发送数组*/
void Serial_SendArray(uint8_t *Array , uint16_t Length)
{
	uint16_t i;
	for(i=0; i<Length ; i++)
	{
		Serial_SendByte(Array[i]);
	}
}

void Serail_SendPacket(void)
{
	/*发送包头文件*/
	Serial_SendByte(0xFF);
	/*发送数据包*/
	Serial_SendArray(Serial_TxPacket,4);
	/*发送包尾*/
	Serial_SendByte(0xFE);
}

void Serial_SendString(char *String)
{
	uint8_t i;
	for(i=0; String[i] != '\0' ;i++)
	{
		Serial_SendByte(String[i]);
	}
}

uint32_t Serial_Pow(uint32_t X , uint32_t Y)
{
	uint32_t Result = 1;
	while(Y--)
	{
		Result *= X;
	}
	return Result;
}

void Serial_SendNumber(uint32_t Number , uint8_t Length)
{
	uint8_t i; 
	for(i = 0; i < Length; i++)
	{
		Serial_SendByte( Number / Serial_Pow(10,Length - i - 1)% 10 + '0');
	}
}

int fputc(int ch, FILE *f)
{
	Serial_SendByte(ch);
	return ch;
}

void Serial_Printf(char *format, ...)
{
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	Serial_SendString(String);
}
