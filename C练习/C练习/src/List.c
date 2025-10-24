#include "common.h"
#include "Queue.h"

/*
* @file    data_structure.c
* @beief   这是一个c语言编写的包含各种数据结构常用操作，主要实现数据结构的创建，销毁，增删改查
* @author  小宇
* @date    2025 - 9 - 22
* @vision  1.0
* @Statementhttps:学习资料来自于主要来自于菜鸟教程以及哔哩哔哩王道《数据结构》
* 
*/

/*	1.顺序表
静态顺序表
#define Max_Size 10

typedef struct {
	int element[Max_Size];
	int lenth;
}SqList;

//初始化静态顺序表,应该是因为这是C文件，不支持&L这种操作将值改变，只能用指针.我知道了，VS不支持，服了，怎么什么都不支持
void InitList(SqList* L)//
{
	for (int i = 0; i < Max_Size; i++)
	{
		L->element[i] = 0;
		L->lenth = 0;
	}

}

静态顺序表按位查找，只需要返回（i-1)位即可
void GetElem(SqList L, int i)
{
	if( i >=1 && i <= L->length )
	return L->element[i - 1];
}


#define InitSize 100

动态顺序表
typedef struct {
	int* data;
	int MaxSize, lenth;
}SeqList;


初始化顺序表
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
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	for (int i = 0; i < L->lenth; i++)
	{
		L->data[i] = p[i];
	}
	L->MaxSize = L->MaxSize + len;
	free(p);

}

按值查找
int LocateElem( SeqList *L, const int e)
{
	for (int i = 0; i < L->lenth; i++)
	{
		if (L->data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

在顺序表的第i个位置插入数据e
void ListInsert(SeqList* L, int i, int e)
{
	i <= L->lenth;
	for (int j = L->lenth; j <= i; j--)
	{
		L->data[j] = L->data[j-1];
	}
	L->data[i - 1] = e;
	L->lenth++
}

插入2.0版本
bool ListInsert(SeqList* L, int i, int e)
{
	if (i<1 || i>L->lenth + 1)
		return false;
	if (L->lenth >= InitSize)
		return false;
		i <= L->lenth;
	for (int j = L->lenth; j <= i; j--)
	{
		L->data[j] = L->data[j-1];
	}
	L->data[i - 1] = e;
	L->lenth--;
}

//在顺序表L里面删除第i个元素，并且将其赋值给e带回来
bool  ListDelete(SeqList* L, int i, int* e)
{
	if (i<1 || i>L->lenth )
		return false;
	*e = L->data[i-1];
	for (int j = i; j < L->lenth ; j++)
	{
		L->data[j - 1] = L->data[j];
	}
	L->lenth--;
	return true;
}

//两个结构体不能比较，只能比较其中的元素



int main()
{
	SeqList L;
	Init_list(&L);
	IncreaseSize(&L, 10);
	ListInsert(&L, 3, 4);
	int e = -1;
	ListDelete(&L, 3, e);
	LocateElem(&L, 4);


	printf("%d\n", L.MaxSize);
	int i = 9;
	while (i--)
	{
		printf("%d\n", L.data[i]);
	}


	return 0;
}

*/

	/* 2.单链表
	* 
	*/
	//typedef struct Lnode {
	//int data;
	//struct Lnode* next;
	//}Lnode,*LinkList;//这是一个指向struct Lnode的指针

	
	/*
	
	/* 
	 typedef struct Lnode{
	 int data;
	 struct Lnode* next;
	 }*LinkList;
	 
	 我一直以为typedef把这个名字命名为"*LinkList",没想到是把指向他的指针命名为"LinkList"
	 typedef struct Lnode{
	 int data;
	 struct Lnode* next;
	 }Lnode;
	
	typedef struct Lnode = Lnode
	typedef struct Lnode* = LinkList(单链表)	
	 */

	//要表示一个链表时，只需要声明一个头指针L，指向单链表的第一个节点
	//Lnode* L 等价于LInkList 声明一个指向单链表第一个节点的指针

	//不带头结点的单链表初始化
	//bool InitList(LinkList* L)
	//{
	//	L = NULL;
	//	return true;
	//}

	
	//带头结点的单链表初始化
//	bool InitList(LinkList* L)
//	{
//		*L = (Lnode*)malloc(sizeof(Lnode));
//		if (*L == NULL)
//			return false;
//		(*L)->next = NULL;
//		return false;
//		free(L);
//	}
//
//	//判断数据是否为空
//	bool empty(LinkList* L)
//	{
//		if((*L)->data == NULL)
//			return true;
//		else
//			return false;
//	}
//
//	int main()
//	{
//		LinkList L;
//		InitList( & L);
//}


