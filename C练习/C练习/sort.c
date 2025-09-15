/* #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void bubble_sort(int arr[], int size);

int main() {
    int n = 0;
    int num = 0;
    scanf("%d", &n);
    int arr1[] = { 0 };
    //输入处理
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        arr1[i] = num;
    }

    //处理数据
    bubble_sort(arr1, n);

    //输出数据
    if (n == 1)(printf("%d ", 0));
    for (int i = 1; i < n; i++)
    {
        printf("%d ", arr1[i - 1]);
    }
    return 0;
}

void bubble_sort(int arr[], int size)
{
    int i, j, t;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
*/

