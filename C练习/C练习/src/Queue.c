#include "common.h"
#include "Queue.h"

/*打印队列元素*/
void sqQueue_Print(sqQueue* q)
{
    if (q == NULL) return;

    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("%d ", q->eledata[i]);
    }
    printf("\n");
}

/*初始化队列*/
void sqQueue_init(sqQueue* q)
{
    if (q == NULL) return;

    q->front = 0;
    q->rear = 0;
    for (int i = 0; i < MAXSIZE; i++)
    {
        q->eledata[i] = 0;
    }
}

/*判断队列是否为空*/
bool sqQueue_is_empty(sqQueue* q)
{
    if (q == NULL) return true;
    return q->front == q->rear;
}

/*获取队列中元素个数*/
int sqQueue_num(sqQueue* q)
{
    if (q == NULL) {
        return -1;
    }
    return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

/*判断队列是否满*/
bool Queue_is_full(sqQueue* q)
{
    if (q == NULL) return false;
    return (q->rear + 1) % MAXSIZE == q->front;
}

 /* 入队*/
void sqQueue_in(sqQueue* q, int e)
{
    if (q == NULL || Queue_is_full(q)) {
        return;  // 队列满或指针无效
    }

    q->eledata[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
}

/* 出队，返回出队的元素值 */
int sqQueue_out(sqQueue* q)
{
    if (q == NULL || sqQueue_is_empty(q)) {
        return -1;  // 返回-1表示错误
    }

    int value = q->eledata[q->front];  // 保存要出队的值
    q->front = (q->front + 1) % MAXSIZE;
    return value;  // 返回出队的值
}


 /* 以下为动态队列操作 */

/*带头结点队列初始化*/
void LinkQueue_Init(LinkQueue* q)
{
    //将头指针和尾指针指向第一个结点
    q->front = q->rear = (LinkNode*)malloc(sizeof(LinkNode));
    q->front->next = NULL;//设置next为空，避免野指针
}

/*判断带头结点队列是否为空*/
bool LinkQueue_IsEmpty(LinkQueue* q)
{
    if (q->front == q->rear)
        return true;
    else
        return false;
}

/*不带头结点队列初始化*/
void  LinkQueue_Init2(LinkQueue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

 /* 函数说明：不带头结点队列是否为空判断
 /* 参数： 返回队列LinkQueue的指针
 /* 返回值： 
 /* 1为true ， 0为false
 */
bool LinkQueue_IsEmpty2(LinkQueue* q)
{
    if (q->front == NULL || q->rear == NULL)
    {
        return true;
    }
    else 
        return false;
}

 /* 带头结点插入*/
void LinkQueue_EnQueue(LinkQueue* Q, int x)//x代表新结点NewNode
{
    /*创建一个新结点s*/
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    /*结点的next指针指向NULL*/
    s->next = NULL;
    /*让原来的队尾节点指向新节点*/
    Q->rear->next = s;
    /*更新队列的rear指针，让它指向新的队尾节点*/
    Q->rear = s;
}
  /*不带头结点插入结点*/
void LinkQueue_EnQueue2(LinkQueue* Q, int x)
{
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    /* 入队的新节点，要让它的next指向NULL */
    s->next = NULL;
    /*如果为空说明是队列中的第一个结点，需要修改让两个指针都指向它*/
    if (Q->front == NULL)
    {
        Q->front = s;
        Q->rear = s;
    }
    else
    {
        Q->rear->next = s;
        Q->rear = s;
    }
}

 /* 带头结点的删除操作，将删除值用x带回，注意边界条件判断*/
bool LinkQueue_DeQueue(LinkQueue* Q, int* x)
{
    /*判断队列是否为空*/
    if (Q->front == Q->rear)
    {
        return false;
    }
    
    LinkNode* p = Q->front->next;
    x = p->data;

    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return true;
}

 /* 遍历队列*/
