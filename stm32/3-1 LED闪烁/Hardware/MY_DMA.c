#include "stm32f10x.h"

void MyDMA_Init(uint32_t src, uint32_t dest,uint8_t size)
{
	//DMA Config three steps that the first to enable DMA_Clock,the second to config DMA_REF and the end 
	//of DMA_Cmd to ENABLE;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);

	DMA_InitTypeDef  DMA_InitStruct;
	
	DMA_InitStruct.DMA_MemoryInc = DMA_PeripheralInc_Enable ;
	DMA_InitStruct.DMA_MemoryBaseAddr = src ;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	DMA_InitStruct.DMA_PeripheralBaseAddr = dest;
	DMA_InitStruct.DMA_PeripheralDataSize =DMA_PeripheralDataSize_Byte;
	
	DMA_InitStruct.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStruct.DMA_BufferSize = size;
	DMA_InitStruct.DMA_Priority = DMA_Priority_Medium;
	DMA_InitStruct.DMA_M2M = DMA_M2M_Enable;
	DMA_Init(DMA1_Channel1,&DMA_InitStruct);
	
	DMA_Cmd(DMA1_Channel1,ENABLE);
}