#pragma once
#include "common.h"
#define DEBUG 1  // 1=开启调试, 0=关闭调试
#define MAXSIZE 8

typedef struct {
    int eledata[MAXSIZE];
    int front;
    int rear;
}sqQueue;

/* 链表方式实现队列 */
typedef struct {
    int data;
    struct LinkNode* next;
}LinkNode;
typedef struct {
    LinkNode* rear, * front;
}LinkQueue;


// 函数声明
void sqQueue_Print(sqQueue* q);//遍历静态队列
void sqQueue_init(sqQueue* q);
bool sqQueue_is_empty(sqQueue* q);
int sqQueue_num(sqQueue* q);
void sqQueue_in(sqQueue* q, int e);
bool Queue_is_full(sqQueue* q);
int sqQueue_out(sqQueue* q);

// 链式队列函数声明
void LinkQueue_Init(LinkQueue* q);                    // 带头节点初始化
void LinkQueue_Init2(LinkQueue* q);                   // 不带头节点初始化
bool LinkQueue_IsEmpty(LinkQueue* q);                 // 带头节点判空
bool LinkQueue_IsEmpty2(LinkQueue* q);                // 不带头节点判空
void LinkQueue_EnQueue(LinkQueue* q, int x);          // 带头节点入队
void LinkQueue_EnQueue2(LinkQueue* q, int x);         // 不带头节点入队
bool LinkQueue_DeQueue(LinkQueue* q, int* x);         // 带头节点出队