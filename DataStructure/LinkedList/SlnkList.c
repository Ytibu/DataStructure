//单链表
// Created by 20358 on 25-3-20.
//

#include <stdio.h>
#include <stdlib.h>
#include"SlnkList.h"

//建立空链表
node *init() {
    return NULL;
}

//输出单链表中各个节点的值
void display(node *head) {
    node *p;
    p=head;
    if (!p)printf("单链表为空\n");
    else {
        printf("单链表各个节点的值为:\n");
        while (p) {printf("%5d", p->info); p=p->next;}
    }
}

//在单链表中查找第i个节点
node *find(node *head,int i) {
    int j=1;
    node *p=head;
    if (i<1)    return NULL;
    while (p&&i!=j) {
        p=p->next;j++;
    }
    return p;
}

//单链表的插入操作
node *insert(node *head,datatype x,int i) {
    node *p,*q;
    q=find(head,i);     //查找第i个节点
    if (!q&&i!=0)   printf("找不到第%d个节点，不能插入%d",i,x);
    else {
        p=(node *)malloc(sizeof(node)); //分配空间
        p->info=x;              //设置新节点
        if(i==0){               //插入的节点作为单链表的第一个节点
            p->next=head;       //插入操作1
            head=p;             //插入操作2
        }
        else {
            p->next=q->next;       //插入操作1
            q->next=p;             //插入操作2
        }
    }
    return head;
}


node *dele(node *head,datatype x) {
    node *pre=NULL,*p;
    if (!head)  {printf("单链表为空");return head;}
    p=head;
    while (p&&p->info!=x) {     //没有找到并且没有找完
        pre=p;p=p->next;        //pre指向P的前驱节点
    }
    if (p) {                    //找到被删除的节点
        if (!pre) head=head->next;      //要删除的第一个节点
        else pre->next=p->next;
        free(p);
    }
    return head;
}



