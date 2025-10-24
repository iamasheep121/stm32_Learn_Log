#include "common.h"
#include "Queue.h"

int arr1[5] = { 0 };

int main()
{
#if DEBUG
    sqQueue sq;
    LinkQueue Lq;

    // 测试初始化
    sqQueue_init(&sq);
    /*printf("初始化后的队列: ");
    sqQueue_Print(&sq);*/

    // 测试入队
    for (int i = 0; i < 5; i++)
    {
        sqQueue_in(&sq, i * 2);  // 入队 0, 2, 4, 6, 8
        printf("入队 %d 后的队列: ", i * 2);
        sqQueue_Print(&sq);
    }

    // 测试元素个数
    int n = sqQueue_num(&sq);
    printf("队列元素个数: %d\n", n);

    // 测试出队
    int out_value = sqQueue_out(&sq); 
    printf("出队元素: %d\n", out_value);

    n = sqQueue_num(&sq);
    printf("出队后元素个数: %d\n", n);

    
#endif
    return 0;
}