#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
/*
	@beilf 简易计算器，主要功能有加减乘除
*/
//int main()
//{
//	double input1, input2, result;
//	char operator[2];
//
//	printf("请输入第一位数字：");
//	scanf("%lf", &input1);
//
//	printf("请输入运算符：(+ - * /^)");
//	scanf("%s", &operator);
//
//	printf("请输入第二位数字：");
//	scanf("%lf", &input2);
//
//	switch (tolower(operator[0]))
//	{
//	case'+':
//		result = input1 + input2;
//		break;
//	case'-':
//		result = input1 - input2;
//		break;
//	case'*':
//		result = input1 * input2;
//		break;
//	case'/':
//		if (input2 != 0) {
//			result = input1 / input2;
//		}
//		else {
//			printf("分母不能为0\n");
//			return 1;
//		}
//	case '^':
//		result = pow(input1, input2);
//		break;
//	default:
//		printf("Error! 无效的操作符\n");
//		return 1;
//	}
//	printf("计算结果为:%lf",result);
//	return 0;
//}

/*测试用例
	1.分母不为0
	2.被减数>减数时情况提示计算错误，问题是把%s换成%lf，导致不能正确读取字符串
	3.其他情况
	4.代码健壮性
	缺点：代码不够健壮，操作符多输入两个就死机了，考虑检查操作符是否唯一。还有读取输入时，特别是两个输入变量，如果我在其中加入操作符或者字符也会死机
	如果我想一直计算，不退出考虑加个循环
*/

/*计算器2.0
* int isdigit(int ch);检查字符是否为数字
* 刚刚试了一下，这个函数是大坑，会一直循环输入第一个数字，所以不用了
*/

//int main() {
//    double input1, input2, result;
//    char operator;
//    char answer;
//    int validInput;
//
//    do {
//        // 读取第一个数字
//        printf("请输入第一位数字：");
//        while (scanf("%lf", &input1) != 1) {
//            printf("无效输入，请输入数字：");
//            while (getchar() != '\n'); // 清除缓冲区
//        }
//        while (getchar() != '\n'); // 清除缓冲区剩余字符
//
//        // 读取运算符
//        printf("请输入运算符（+、-、*、/、^）：");
//        validInput = scanf(" %c", &operator);
//        while (getchar() != '\n'); 
//        if (validInput != 1) {
//            printf("无效运算符，请重新开始。\n");
//            continue;
//        }
//
//        // 读取第二个数字
//        printf("请输入第二位数字：");
//        while (scanf("%lf", &input2) != 1) {
//            printf("无效输入，请输入数字：");
//            while (getchar() != '\n'); 
//        }
//        while (getchar() != '\n');
//       
//        switch (operator) {
//        case '+':
//            result = input1 + input2;
//            break;
//        case '-':
//            result = input1 - input2;
//            break;
//        case '*':
//            result = input1 * input2;
//            break;
//        case '/':
//            if (input2 == 0) {
//                printf("错误：除数不能为0。\n");
//                continue; 
//            }
//            result = input1 / input2;
//            break;
//        case '^':
//            result = pow(input1, input2);
//            break;
//        default:
//            printf("错误！无效的操作符。\n");
//            continue;
//        }
//
//        printf("结果为：%.2lf\n", result);
//   
//        printf("是否继续计算？(y/n): ");
//        scanf(" %c", &answer);
//        while (getchar() != '\n'); 
//    } while (tolower(answer) == 'y');
//
//    return 0;
//}


	//@beilf 斐波那契数列实现
	//编写一个程序，生成斐波那契数列的前 n 项
	//波那契数列的特点是从第三项开始，每一项都是前两项之和。数列的前几项通常是这样的
	//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 8, 13, 21, 34, ...
	//我记得好像要用递归来实现

/* 
unsigned long long fibonacci(int n);
int main()
{
	printf("请输入想得到的第n项");
	int n = 0;
	scanf("%d",&n);
	unsigned long long result =fibonacci(n);
	printf("结果为%llu\n", result);
	return 0;
}

unsigned long long fibonacci(int n)
{
	if (n == 0); return 0;
	if (n == 1); return 1 ;
	return fibonacci(n - 1) + fibonacci(n - 2);
}*/
//可以用动态规划，但是我不会，这个程序刚开始还好好的，后面会崩


//	@素数检查
//	编写一个程序，检查一个给定的数是否为素数
//	最笨的方法


//int isPrime(int n) {
//	if (n <= 1) return 0; // 0和1不是素数
//	for (int i = 2; i < n; i++) {
//		if (n % i == 0) return 0; 
//	}
//	return 1; 
//}
//
//int main() {
//	int n;
//	printf("请输入一个整数: ");
//	scanf("%d", &n);
//	if (isPrime(n)) {
//		printf("%d 是素数\n", n);
//	}
//	else {
//		printf("%d 不是素数\n", n);
//	}
//	return 0;
//}
//
//#include <stdio.h>
//
//int main() {
//	int hour = 0;
//	int min = 0;
//	int s = 0;
//	scanf("%d", &s);
//	if (s == 0)
//	{
//		printf("%d %d %d", 0, 0, 0);
//	}
//	else if (s > 0)
//	{
//		hour = s / 3600;
//		s = s % 3600;
//		min = s / 60;
//		s = s % 60;
//	}
//	printf("%d %d %d", hour, min, s);
//	return 0;
//}


//#include <stdio.h>
//int fun(int n);
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fun(n);
//	printf("%d", ret);
//	return 0;
//}
//int fun(int n) {
//	if (n <= 1) {
//		return 1;
//	}
//
//	int prev = 1;
//	int current = 1;
//	for (int i = 2; i <= n; i++) {
//		current = prev + i;
//		prev = current - i;
//	}
//	return current;
//}

//#include <stdio.h>
//int main() {
//	int T = 0;
//	int n = 0;
//	scanf("%d", &T);
//	for (int i = 0; i < T; i++) {
//		scanf("%d", &n);
//		if (n <= 1) {
//			printf("No\n");
//		}
//		else if (n > 1) {
//			for (int i = 2; i < n; i++)
//				if (n % i == 0) {
//					printf("No\n");
//				}
//		}
//		else {
//			printf("Yes\n");
//		}
//	}
//	return 0;
//}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int Max_Min(int arr[], int size);

int main() {
    int n1 = 0;
    scanf("%d", &n1);
    int* arr1 = (int*)malloc(n1 * sizeof(int));
    if (arr1 == NULL)
    {
        return false;
    }

    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    int result = Max_Min(arr1, n1);
    printf("%d", result);
    return 0;
}

int Max_Min(int arr[], int size)
{
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return max - min;

}