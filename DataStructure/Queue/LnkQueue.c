//链式队列的操作
// Created by 20358 on 25-4-2.
//

#include<stdio.h>
#include<stdlib.h>
#include"LnkQueue.h"

//建立空列表
queue *Init(){
    queue *qu;
    qu = (queue *)malloc(sizeof(queue));  //分配空间
    qu->front = NULL;    //对手指针设置为NULL
    qu->rear = NULL;    //队尾指针设置为NULL
    return qu;
}

//判断链式队列是否为空
int Empty(queue *qu){
return (qu->front?1:0);
}

//输出链式队列各个结点的值
void Display(queue *qu){
  node *p;
  p = qu->front;
  if(!p) printf("The Link Queue is empty\n");
  while(p){
    printf("%d ",p->info);
    p = p->next;
  }
}

//取得链式队列的队首节点值
datatype Reaad(queue *qu){
  if(!qu->front){
    printf("链式队列为空\n");
    exit(1);}
  return (qu->front->info);
}

//链式队列的插入操作
queue *Insert(queue *qu,datatype x){
  //向链式队列插入一个值为x的节点
  node *p;
  p = (node *)malloc(sizeof(node));  //分配空间
  p->info = x;    //设置新节点的值
  p->next = NULL;
  if(qu->front==NULL){    //当前队列为空，新插入的节点为队列中唯一的节点
    qu->front = qu->rear = p;
  }else{
    qu->rear->next = p;    //队首插入
    qu->rear = p;
  }
  return qu;
}

//链式队列的删除操作
queue *Delete(queue *qu){//删除队首节点值
  node *q;
  if(!qu->front){
    printf("队列为空，无法删除");
    return qu;
  }
  q = qu->front;    //q指向队首节点值，删除操作1
  qu->front = q->next;    //对手指针指向下一节点，删除操作2
  free(q);    //释放原队首节点空间
  if(qu->front==NULL) qu->rear=NULL;   //队列唯一节点被删除后队列变空，删除操作3
  return qu;
}