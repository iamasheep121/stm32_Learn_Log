#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
* @file    data_structure.c
* @beief   这是一个c语言编写的包含各种数据结构常用操作，主要实现数据结构的创建，销毁，增删改查
* @author  小宇
* @date    2025 - 9 - 22
* @vision  1.0
* @Statementhttps:学习资料来自于主要来自于菜鸟教程以及哔哩哔哩王道《数据结构》
* 
*/
//	1.顺序表
//静态顺序表
//#define Max_Size 10

//typedef struct {
//	int element[Max_Size];
//	int lenth;
//}SqList;
//
////初始化静态顺序表,应该是因为这是C文件，不支持&L这种操作将值改变，只能用指针.我知道了，VS不支持，服了，怎么什么都不支持
//void InitList(SqList* L)//
//{
//	for (int i = 0; i < Max_Size; i++)
//	{
//		L->element[i] = 0;
//		L->lenth = 0;
//	}
//
//}

#define InitSize 100

//动态顺序表
typedef struct {
	int* data;
	int MaxSize, lenth;
}SeqList;

//初始化顺序表
void Init_list(SeqList* L)
{
	L->data = (int*)malloc(sizeof(int) * InitSize);
	L->MaxSize = InitSize;
	L->lenth = 0;
}

//增加动态数组长度
void IncreaseSize(SeqList* L, int len)
{
	int* p = L->data;
	L->data = (int*)malloc( (L->MaxSize + len) * sizeof(int));
	for (int i = 0; i < L->lenth; i++)
	{
		L->data[i] = p[i];
	}
	L->MaxSize = len + L->MaxSize;
	free(p);
}

//在顺序表的第i个位置插入数据e
void ListInsert(SeqList* L, int i, int e)
{
		
}



int main()
{
	SeqList L;
	Init_list(&L);
	IncreaseSize(&L, 10);
	printf("%d", L.MaxSize);


	return 0;
}