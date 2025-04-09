//带头节点的单链表
// Created by 20358 on 25-3-13.
//

#include<stdio.h>
#include <stdlib.h>
#include "HlnkList.h"

node *init() {
    node *head;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;
    return head;
}


void display(node *head) {
    node *p;
    p=head->next;
    if (!p) printf("带头节点的单链表是空的:\n");
    else {
        printf("带头节点的单链表中各个节点的值为:\n");
        while (p)   {printf("%5d",p->info);p=p->next;}
    }
}


node *find(node *head,int i) {
    int j=0;
    node *p=head;
    if (i<0)    {printf("带头结点的单链表中不存在第%d个节点",i); return NULL;}
    else if (i==0) return p;
    while (p&&i!=j) {
        p=p->next,j++;
    }
    return p;
}


node *insert(node *head,datatype x,int i) {
    node *p,*q;
    q=find(head,i);

    if (!q) {
        printf("带头节点的单链表中不存在第%d个节点,不能插入%d",i,x);
        return head;}
    p=(node *)malloc(sizeof(node));
    p->info=x;
    p->next=q->next;
    q->next=p;
    return head;
}


node *dele(node *head,datatype x) {
    node *pre=head, *q;
    q=head->next;
    while (q&&q->info!=x) {
        pre->next=q->next;
    }
    if (q) {
        pre->next=q->next;
        free(q);
    }
    return head;
}