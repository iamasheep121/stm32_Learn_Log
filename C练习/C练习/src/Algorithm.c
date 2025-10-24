//#define _CRT_SECURE_NO_WARNINGS
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


/*
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
*/
/*
#define MOD (10 ^ 9 + 7)
int dp[1001][1001];

#include <stdio.h>
int fun(int i, int j);
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = -1;
        }
    }
    int ret = fun(n, m);
    printf("%d",ret);
    return 0;
}

int fun(int i, int j)
{
    if (i == 1 && j == 1)
    {
        return 1;
    }
    else if (i >= 2 && j == 1) {
        return fun(i - 1, 1);
    }
    else if (j >= 2 && i == 1) {
        return fun(i, j - 1);
    }
    else if (i >= 2 && j >= 2) {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
       dp[i][j] = ( fun(i - 1, j ) + fun( i, j - 1 ) % MOD );

        return (fun(i - 1, j) + fun(i, j - 1));
    }
    return 0;
}


#include <stdio.h>

#define MOD 1000000007

int dp[1001][1001]; // 使用二维数组存储中间结果，避免重复计算

int fun(int i, int j) {
    if (i == 1 && j == 1) {
        return 1;
    }
    else if (i >= 2 && j == 1) {
        return fun(i - 1, 1);
    }
    else if (j >= 2 && i == 1) {
        return fun(i, j - 1);
    }
    else if (i >= 2 && j >= 2) {
        if (dp[i][j] != -1) { // 如果已经计算过，直接返回结果
            return dp[i][j];
        }
        dp[i][j] = (fun(i - 1, j) + fun(i, j - 1)) % MOD; // 计算并存储结果
        return dp[i][j];
    }
    return 0; // 默认返回0，避免编译器警告
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = -1; // 初始化dp数组
        }
    }
    int ret = fun(n, m);
    printf("%d", ret);
    return 0;
}
*/

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 10
//int main() {
//    int n = 0;
//    int i = 0;
//    int put[MAX] = { 0 };
//    while (1) {
//        scanf("%d", &n);
//        if (n == 0)
//        {
//            break;
//        }
//        if (i >= MAX) {
//            printf("数组满了");
//            break;
//        }
//        put[i] = n;
//        i++;
//    }
//    while (1) {
//        printf("%d ", put[i - 1]);
//        if (i == 1) { break; }
//        i--;
//    }
//    return 0;;
//}

//#include <stddef.h>
//#include <stdio.h>
//int max_Min_diff(int arr[], int size);
//int var(int arr[], int size);
//
//int main() {
//    int T = 0;
//    long long int var1 = 0;
//    long int ext = 0;
//    scanf("%d", &T);
//    while (T--)
//    {
//        int n = 0;
//        scanf("%d", &n);
//        int* arr = NULL;
//        arr = molloc(n * sizeof(int));
//        for (int i = 0; i < n; i++)
//        {
//            scanf("%d", &arr[i]);
//        }
//
//        ext = max_Min_diff(arr, n);
//        var1 = var(arr, n);
//        printf("%ld\n %lld\n", ext, var);
//    }
//
//
//    return 0;
//}
//
//int max_Min_diff(int arr[], int size)
//{
//    int max = arr[0];
//    int min = arr[0];
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] < min)
//        {
//            arr[i] = min;
//        }
//    }
//    for (int j = 0; j < size; j++)
//    {
//        if (arr[j] > max)
//        {
//            arr[j] = max;
//        }
//    }
//    return max - min;
//}
//
//int var(int arr[], int size)
//{
//    long int a = 0;
//    int sum = 0;
//    long long int diff = 0;
//    for (int i = 0; i < size; i++)
//    {
//        sum = sum + arr[i];
//    }
//    a = (size / 1) * sum;
//
//    for (int j = 0; j < size; j++)
//    {
//        diff = (arr[j] - a) * (arr[j] - a);
//    }
//    return (size / 1) * diff;
//}

//#include <stdio.h>
//int pro_cnt(int arr[], int size, int k);
//
//int main() {
//    int n, k, T;
//    scanf("%d", &T);
//    int arr[T] ;
//    while (T--)
//    {
//        scanf("%d %d", &n, &k);
//        for (int i = 0; i < n; i++)
//        {
//            scanf("%d", &arr[i]);
//        }
//        int cnt = pro_cnt(arr, n, k);
//        printf("%d\n", cnt);
//    }
//
//    return 0;
//}
//
//int pro_cnt(int arr[], int size, int k)
//{
//    int S = 0, cnt = 0;
//    for (int i = 1; i < size; i++)
//    {
//        if (arr[i] >= k) S = S + arr[i];
//        if (arr[i] == 0 && S >= 1)
//        {
//            S = S - 1;
//            cnt = cnt + 1;
//        }
//        return cnt;
//    }
//}

//#include <stdio.h>
//int x_num(int size, int x);
//
//int main() {
//    int n, x;
//    scanf("%d %d", &n, &x);
//    int sum = 0;
//    sum = x_num(n, x);
//    printf("%d", sum);
//    return 0;
//}
//
//int x_num(int size, int x)
//{
//    int count = 0;
//    for (int num = 1; num < size; num++)
//    {
//        int temp = num;
//        while (temp > 0) {
//
//            int digit = temp % 10;
//            if (digit == x)
//            {
//                count++;
//            }
//            temp /= 10;
//
//        }
//    }
//    return count;
//}

//#include <stdio.h>
//
//int main() {
//    int n = 0, m = 0;
//    scanf("%d %d", 3, 3);
//    int** arr = (int**)malloc (sizeof(int) * n);
//    for (int i = 0; i < n; i++) {
//        arr[i] = (int*)(sizeof(int) * m);
//        }
//        
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//
//    //转置
//    int** dest = (int**)malloc(n * sizeof(int));
//        for (int i = 0; i < n; i++)
//        {
//            dest[i] = (int*)malloc(sizeof(int) * m);
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            dest[i][j] = arr[j][i];
//            printf("%d ", dest[i][j]);
//        }
//    }
//    free(arr);
//    free(dest);
//
//    return 0;
//}
//
//#include <stdio.h>
//#include "string.h"
//int animals(char* animals);
//int main() {
//    char s1[9];
//    char s2[9];
//    scanf("%s,%s", s1, s2);
//
//    //数据处理
//    int a = animals(s1);
//    int b = animals(s2);
//
//    //赢的情况
//    if (a == 0 && b == 1 || a == 1 && b == 2 || a == 2 && b == 3 || a == 3 && b == 0)
//        printf("win");
//    //输的情况
//    else if (b == 0 && a == 1 || b == 1 && a == 2 || b == 2 && a == 3 || b == 3 && a == 0)
//        printf("lose");
//    //平局
//    else
//        printf("tie");
//
//    return 0;
//}
//
//int animals(char* animals)
//{
//    if (strcmp(animals, "elephant") == 0) return 0;
//    if (strcmp(animals, "tiger") == 0) return 1;
//    if (strcmp(animals, "cat") == 0) return 2;
//    if (strcmp(animals, "mouse") == 0) return 3;
//    return -1;
//}

//long long aTimesB(int Number1, int Number2) {
//    return abs(Number1 * Number2);
//    // write code here
//}
//
//int main()
//{
//    int a, b;
//    scanf_s("%d %d", &a, &b);
//    int result = aTimesB(a, b);
//    printg("%d", result);
//}
