//顺序栈的操作
// Created by 20358 on 25-3-26.
//
#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"

//队列的初始化
void Init(sequence_queue *sq) {
    sq->front = sq->rear = 0;
    //front为队首节点在数组中的索引，rear为队尾节点在数组中的索引
}

//判断队列是否为空
int Empty(sequence_queue sq) {
    return sq.front == sq.rear?1:0; //队首节点=队尾节点?即判断数组是否为空
}

//输出队列的各个节点值
void Display(sequence_queue sq) {
    int i;
    if (Empty(sq)) {    //调用函数Empty从而确定队列是否为空
        printf("顺序栈为空\n");
    }else {
        for (i = sq.front; i < sq.rear; i++) {
            printf("%5d",sq.a[i]);
        }
    }
}

//取得队列的队首节点值
datatype Get(sequence_queue sq) {
    if (Empty(sq)) {
        printf("顺序队列为空,无法获得队首节点值");exit(1);
    }   //队列为空强制结束函数并返回提示
    return sq.a[sq.front];
}

//队列的插入操作
void Insert(sequence_queue *sq, datatype x) {
    int i;
    if (sq->rear == MAXSIZE) {
        printf("队列已满");exit(1);
    }
    sq->a[sq->rear] = x;
    sq->rear = sq->rear + 1;
}

//队列的删除操作
void Delete(sequence_queue *sq) {
    if (sq->front == sq->rear) {
        printf("队列为空，无法进行删除操作");exit(1);
    }
    sq->front++;    //队首节点+1
}

//循环队列的插入操作
void Insert_sequence_cqueue(sequence_queue *sq, datatype x) {
    if ((sq->rear) % MAXSIZE == sq->front)
        {printf("循环队列已满，无法进行插入操作");exit(1);}
    sq->a[sq->rear] = x;
    sq->rear = (sq->rear + 1) % MAXSIZE;
}

//循环队列的删除操作
void Delete_sequence_cqueue(sequence_queue *sq) {
    if (sq->front == sq->rear)
        {printf("循环队列为空");exit(1);}
    sq->front = (sq->front + 1) % MAXSIZE;
}
