//链式栈
// Created by 20358 on 25-3-23.
//
#include <stdio.h>
#include <stdlib.h>
#include "LnkStack.h"

//建立一个空的链式栈
node *init() {
    return NULL;
}

//判断链式栈是否为空
int empty(node *top) {
    return top?0:1;
}

//取得链式栈的栈顶结点值
datatype read(node *top) {
    if (!top){printf("链式栈为空！\n"); exit(1);}
    return (top->info);
}   //本函数可以调用empty()函数

//输出链式栈中各个结点的值
void display(node *top) {
    node *p;
    p = top;
    printf("\n");
    if (!p) printf("链式栈为空\n");
    while (p){printf("%5d",p->info);p=p->next;}
}

//向链式栈中插入一个值为x的节点（进栈）
node *push(node *top,datatype x) {
    node *p;
    p = (node *)malloc(sizeof(node));   //分配空间
    p->info = x;    //设置新结点的值
    p->next = top;  //插入操作1
    top = p;        //插入操作2
    return top;
}

//删除链式栈的栈顶节点（出栈）
node *pop(node *top) {
    node *q;
    if (!top) {printf("链式栈为空！");return NULL;}
    q = top;        //指向被删除的节点。删除操作1
    top = top->next;    //删除栈顶节点。删除操作2
    free(q);
    return top;
}
