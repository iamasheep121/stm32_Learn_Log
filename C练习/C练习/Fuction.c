#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
int main()
{
	char a[] = "sd";
	putchar(a[0]);
	printf("\n%s",a);
	return 0;
}

     1.putchar 函数用于输出单个字符
*/

/*   2.位域，位域是一种在结构体中定义成员的方式，它允许你指定成员占用的位数，而不是默认的字节数。这可以帮助你节省内存。
节省内存。
与硬件交互时，可以直接操作特定的位
这么说的话，我可以把我项目里面的模式改成位域，节省空间
typedef enum {
    MODE_OFF,
    MODE_LOW,
    MODE_MEDIUM,
    MODE_HIGH
} DeviceMode;

struct DeviceStatus {
    unsigned int power : 1;   // 电源状态，1位
    unsigned int mode : 2;    // 模式，2位
    unsigned int volume : 5;  // 音量，5位
};
*/

/*  3.typedef
C 语言提供了 typedef 关键字，您可以使用它来为类型取一个新的名字。下面的实例为单字节数字定义了一个术语 BYTE：

typedef unsigned char BYTE;
在这个类型定义之后，标识符 BYTE 可作为类型 unsigned char 的缩写，例如：

BYTE  b1, b2;
*/

/*
    getchar()
    char c;
    c = getchar();
    putchar()
    char c = 'a';
    putchar(c);
    puts()
    与printf()的区别

    自动加入换行符
    printf()支持多种花样输出，而puts()就是输出字符串
    puts("请输入一个字符：");
    gets()
    char str[100];
    gets(str);

*/

/*输入 / 输出函数
    printf：
    用于格式化输出。可以将数据以指定格式输出到控制台。
    语法：printf(format, arg1, arg2, ...);
    例如：printf("Hello, %s\n", name);
    scanf：
    用于从标准输入（键盘）读取格式化输入。
    语法：scanf(format, &var1, &var2, ...);
    例如：scanf("%d", &number);
    getchar：
    从标准输入读取一个字符。
    语法：int getchar(void);
    例如：char c = getchar();
    putchar：
    将一个字符输出到标准输出。
    语法：int putchar(int c);
    例如：putchar('A');
    fgets：
    从文件或标准输入读取一行文本。
    语法：char* fgets(char* str, int n, FILE* stream);
    例如：fgets(line, 100, stdin);
    字符串处理函数
    strlen：
    计算字符串的长度（不包括终止的空字符）。
    语法：size_t strlen(const char* str);
    例如：int len = strlen(str);
    strcpy：
    复制字符串。
    语法：char* strcpy(char* dest, const char* src);
    例如：strcpy(dest, src);
    strcat：
    连接两个字符串。
    语法：char* strcat(char* dest, const char* src);
    例如：strcat(str, src);
    strcmp：
    比较两个字符串。
    语法：int strcmp(const char* str1, const char* str2);
    例如：if(strcmp(str1, str2) == 0) { ... }
    strstr：
    在一个字符串中查找子串。
    语法：char* strstr(const char* haystack, const char* needle);
    例如：char* found = strstr(haystack, needle);
    数学函数
    sqrt：
    计算平方根。
    语法：double sqrt(double x);
    例如：double root = sqrt(16.0);
    pow：
    计算幂。
    语法：double pow(double base, double exponent);
    例如：double result = pow(2.0, 3.0);
    fabs：
    计算绝对值。
    语法：double fabs(double x);
    例如：double absValue = fabs(-5.0);
    round：
    四舍五入到最接近的整数。
    语法：double round(double x);
    例如：double rounded = round(3.6);

int main() {
    char c;
    printf("Enter a character: ");
    c = getchar(); // 读取一个字符
    putchar(c); // 输出该字符
    putchar('\n');
    return 0;
}


int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char result[100];

    printf("Length of str1: %zu\n", strlen(str1));
    strcpy(result, str1);
    strcat(result, " ");
    strcat(result, str2);
    printf("Concatenated string: %s\n", result);
    printf("str1 == str2? %d\n", strcmp(str1, str2) == 0);
    printf(" strstr(str1, \"ell\") = %s\n", strstr(str1, "ell"));
    return 0;
}


int main() {
    double x = 16.0;
    double root = sqrt(x);
    double power = pow(2.0, 3.0);
    double absValue = fabs(-5.0);
    double roundedValue = round(3.6);

    printf("Square root of %f is %f\n", x, root);
    printf("2 raised to the power of 3 is %f\n", power);
    printf("Absolute value of -5.0 is %f\n", absValue);
    printf("Rounded value of 3.6 is %f\n", roundedValue);
    return 0;
}

*/

/*define语法 只是单纯替换，如果是运算记得加括号
* enum语法
enum用于变量的枚举。

定义枚举类型的变量，变量的取值将被限制
struct语法


    名场面：1.指针函数
            2.函数指针，回调函数
            类比的话我又想起来一个数组指针和指针数组的

 **         在 C 语言中，void (*callback)(int) 是一个声明，它定义了一个指向函数的指针。这个指针指向的函数接受一个 int 类型的参数，并且不返回任何值（void 类型）。让我们详细分解这个声明：
    callback：这是指针变量的名称，它将被用来存储函数的地址。
    *：这个星号表示 callback 是一个指针。
    (void：这表示函数的返回类型是 void，意味着函数不返回任何值。
    (：这是函数参数列表的开始。
    int：这指定了函数接受的参数类型，这里是 int 类型。
    )：这是函数参数列表的结束。
    将这些部分组合起来，void (*callback)(int) 表示 callback 是一个指针，它指向一个接受一个 int 类型参数并返回 void 的函数。
*/


/*
// 回调函数原型声明
void callback(int x, int y);

// 回调函数定义
void callback(int x, int y) {
    if (x) {
        printf("这个函数大\n");
    }
    else {
        printf("这个函数小\n");
    }
}

// 接受回调函数的函数
void my_fun(void (*callback)(int, int), int x) {
    callback(4, 5 * x);
}

int main() {
    my_fun(callback, 2);
    printf("运算值为：");
    return 0;
}

*/


/*二维数组初始化
int main()
{
    int array[2][2] = { 0,0,0,0 };
    for (int i = 0; i < 2; i++)
    {
            for (int j = 0; j < 2; j++)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");

    }
    return 0;
}
*/

//防止头文件被重复包含
//#ifndef
//#define
//
//#endif

