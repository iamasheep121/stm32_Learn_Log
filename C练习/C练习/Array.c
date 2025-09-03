#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
/*
* @file    demo.c
* @beief   这是一个c语言练习文件，用来记录一些C语言练习题以及解决办法
* @author  小宇
* @date    2025-8-29
* @vision  1.0
* @Statementhttps:学习资料来自于主要来自于菜鸟教程以及github.com/wuxiaolie

/*	sizeof(arr) / sizeof(arr[0])	计算数组元素个数 */

/*
C语言字符串拷贝代码
断言是一个布尔值表达式，判断括号内真假
*/

void my_strcopy(char* dest, const char* src)
{
	while (*dest++ = *src++);
}

/*
while (1) {            // 开始一个无限循环
	char temp = *src;  // 1. 取源指针当前指向的字符
	*dest = temp;      // 2. 将该字符赋给目标指针指向的位置
	if (temp == '\0')  // 3. 判断刚赋值的字符是否是字符串结束符 '\0'
		break;         // 4. 如果是，则跳出循环
	src++;             // 5. 源指针向后移动一个字符的位置
	dest++;            // 6. 目标指针向后移动一个字符的位置
}
*/


 /*复制字符串
int main()
{
	char str [] = "i love you";
	char dest[100] = {0};
	assert(strlen(str) +1 <= sizeof(dest));
	my_strcopy(dest, str);
	printf("%d",Arrat_num(str) );
}*/



/* 1.求数组最大值和最小值
	for 循环从 1 开始而不是 0 的原因可能是因为您已经将 min 和 max 指针初始化为指向数组的第一个元素（arr[0]）
	。因此，不需要再次检查第一个元素，而是从第二个元素（即数组索引 1）开始遍历数组，以找到最大值和最小值。


int main()
{
	int arr[] = { 1,2,3,5,8,54,8,99,30 }; 
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	//求最大
    int min = arr[0];
    int max = arr[0];

	for (int i = 1; i < sz; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (arr[i] > max)
		{
			max = arr[i];
		}
		
	}
	printf("%d %d %d",sz,min,max);
}
*/

/* 2.计算数组元素平均值
double Array_Average(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
		
	}
	return sum/size;
}

int main()
{
	int arr[] = { 1,2,3,5,8,54,8,99,30 };
	double ret = Array_Average(&arr, 9);
	printf("%f" ,ret );

}*/

/* 3.反转数组
*/
void reverve_Array(char array[],int size)
{
	char* start = array;
	char* end = array + size - 1;
	for (int i = 0; i < size / 2; i++)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

//int main()
//{
//	char arr1[] = {"evol"};
//	int len = 4;
//	char arr2[100];
//
//	reverve_Array(arr1, len);
//	int arr[] = { 1,2,3,5,8,54,8,99,30 };
//	/*double ret = Array_Average(&arr, 9);*/
//	printf("%s", arr1);
//	//
//}


void reverse_Array(char array[], int size) {
	char* start = array;
	char* end = array + size - 1;
	for (int i = 0; i < size / 2; i++) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
//
//double Array_Average(int* arr, int size) {
//	double sum = 0;
//	for (int i = 0; i < size; i++) {
//		sum += arr[i];
//	}
//	return sum / size;
//}
//
//int main() {
//	char arr1[] = "evol";
//	int len = strlen(arr1);
//	reverse_Array(arr1, len);
//	printf("Reversed string: %s\n", arr1);
//
//	int arr[] = { 1, 2, 3, 5, 8, 54, 8, 99, 30 };
//	double ret = Array_Average(arr, 9);
//	printf("Average: %f\n", ret);
//
//	return 0;
//}