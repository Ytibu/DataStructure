//循环单链表
// Created by 20358 on 25-3-23.
//

#include<stdio.h>
#include<stdlib.h>
#include "ClnkList.h"

//建立空的循环单链表
node *init(){
    return NULL;
}

//获得循环单链表的最后一个结点的存储地址
node *rear(node *head) {
    node *p;
    if (!head) p=NULL;      //循环链表为空
    else {
        p=head;     //从第一个节点开始
        while(p->next!=head)        //没有到达最后一个节点
            p=p->next;      //继续向后
    }
    return p;
}

//输出循环单链表中各个结点的值
void display(node *head) {
    node *p;
    if (!head) printf("循环单链表为空！");
    else {
        printf("%5d",head->info);   //输出非空表中第一个节点的值
        p=head->next;                     //p指向第一个节点的下一个节点值
        while (p!=head) {                   //没有回到第一个节点
            printf("%5d",p->info);
            p=p->next;
        }
    }
}

//在循环单链表中查找值为x的节点
node *find(node *head,datatype x) {
    node *q;        //查找一个值为x的节点
    if (!head) {
        printf("循环单链表为空，无法找到指定节点");
        return NULL;
    }
    q=head;         //q指向循环单链表的第一个节点,准备查找
    while (q->next!=head&&q->info!=x)       //没有查找到并且没有查找完整个表
        q=q->next;      //继续查找
    if (q->info==x) return q;
    else return NULL;
}

//循环单链表的插入操作
//在循环单链表中第i个节点后插入值为x的新节点
node *insert(node *head,datatype x,int i) {
    //i为0时表示将值为x的节点插入并作为循环单链表的第一个节点
    node *p,*q,*myrear;
    int j;
    p = (node *)malloc(sizeof(node));   //分配空间
    p->info = x;        //设置新结点的值
    if (i<0){           //如果i小于0，则输出出错信息
        printf("无法找到指定的插入位置！");
        free(p);return head;
    }
    if (i==0 && !head)     //插入前如果循环单链表是空的，则新节点的指针域应该指向他自己
    {p->next=p; head=p;return head;}
    if (i==0 && head){      //在非空循环单链最前面插入
        myrear = rear(head);    //找到循环单链表的最后一个节点
        p->next=head;           //插入操作1
        head=p;                 //插入操作2
        myrear->next=p;         //插入操作3，最后一个节点的指针域指向新插入的表中第个节点
        return head;
    }
    if (i>0 && !head) {printf("无法找到指定的插入位置!");
        free(p);
        return head;
    }
    if (i>0 && head) {
        //在非空循环单链表中插入值为x的节点，并且插入的节点不是第一个节点
        q=head;     //准备从表中第一个节点开始查找
        j=1;        //计数开始
        while (i!=j && q->next!=head) {     //没有找到并且没有找遍整个表
            q=q->next;j++;      //继续查找，计数器+1
        }
        if (i!=j) {     //找不到指定插入位置，即i的值超过表中节点的个数，则不进行插入
            printf("表中不存在第%d个节点，无法进行插入操作",i);
            free(p);return head;
        }
        else {      //找到第i个节点，插入x
            p->next=q->next;    //插入，修改指针操作1
            q->next=p;          //插入，修改指针操作2
            return head;
        }
    }
}

//循环单链表的删除操作
//在循环单链表中删除一个值为x的节点
node *dele(node *head,datatype x) {
    node *pre=NULL,*q;      //q用于查找值为x的节点，pre指向q的前驱节点
    if (!head) {    //表为空则无法做删除操作
        printf("循环单链表为空，无法做删除操作!");
        return head;
    }
    q=head;     //从第一个节点开始查找
    while (q->next!=head && q->info!=x) {   //没有找遍整个表并且没有找到
        pre=q;
        q=q->next;      //pre为q的前驱节点继续查找
    }       //循环结束后pre为q的前驱节点
    if (q->info != x) {
        printf("没有找到值为%d的节点！",x);
    }
    else {  //找到，进行删除
        if (q!=head) {pre->next=q->next;free(q);}
        else
            if (head->next==head)   {free(q);head=NULL;}
            else {
                pre=head->next;
                while (pre->next!=q) pre=pre->next;     //找q的前驱位置
                head = head->next;
                pre->next=head;
                free(q);
            }
        }
    return head;
}