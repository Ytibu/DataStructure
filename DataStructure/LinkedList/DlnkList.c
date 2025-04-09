//双链表的操作
// Created by 20358 on 25-3-20.
//

#include <stdio.h>
#include <stdlib.h>
#include "DlnkList.h"

//建立一个空链表
dnode *init() {
    return NULL;
}

//输出双链表中各个节点的值
void display(dnode *head) {
    dnode *p;
    printf("\n");
    p=head;
    if (!p) printf("双链表为空\n");
    else {
        printf("双链表中各个结点的值为\n");
        while (p) {printf("%5d",p->info);p=p->rlink;}
    }
}


//在双链表中查找第i个结点的值
dnode *find(dnode *head,int i) {
    int j=1;
    dnode *p=head;
    if (i<1) {printf("第%d个结点不存在\n",i); return NULL;}
    while  (p&&i!=j) {
        p=p->rlink;j++;
    }
    if (!p) {printf("第%d个节点不存在\n");return NULL;}
    return p;
}


//在双链表中第i个节点后插入一个值为x的新节点
dnode *insert(dnode *head,datatype x,int i) {
    dnode *p,*q;
    p=(dnode *)malloc(sizeof(dnode));   //分配空间
    p->info=x;  //设置新结点的值
    if (i==0) { //在最前面插入一个值为x的新节点
        p->rlink=NULL;    //新插入节点无前驱节点
        p->llink=head;    //新插入节点的后继节点为双链表中第一个节点
        if (!head) {      //原表为空
            head=p;
        }
        else {
            head->llink=p;
            head=p;
        }
        return head;
    }
    q=find(head,i);
    if (!q)
        {printf("第%d个节点不存在,无法进行插入操作\n",i); free(p); return head;}
    if (q->rlink==NULL) {
        p->rlink=q->rlink;
        p->rlink=q;
        q->rlink=p;
    }
    else {
        p->rlink=q->rlink;
        p->rlink=q;
        q->rlink->llink=p;
        q->rlink=p;
    }
    return head;
}


//在双链表中删除一个值为x的节点
dnode *dele(dnode *head,datatype x) {
    dnode *q;
    if (!head) {printf("双链表为空无法进行删除操作\n"); return head;}    //链表为空无法删除
    q=head;
    while (q&&q->info!=x) q=q->rlink;   //循环结束后q指向的是值为x的节点
    if (!q) {
        printf("没有找到值为%d的节点,不做删除操作",x);
    }
    if (q==head&&head->rlink) {    //被删除节点是第一个节点并且表中不止一个节点
        head=head->rlink;
        head->rlink=NULL;
        free(q);return head;
    }
    if (q==head&&head->rlink) {    //被删除的节点是第一个节点并且表中只有只一个节点
        free(q);
        return NULL;    //双链表置空
    }
    else
    {
        if (q->rlink) {    //被删除的节点是双链表的最后一个节点
            q->rlink->rlink=NULL;
            free(q);
            return head;
        }
        else {    // q是由两个以上节点的双链表中的一个非开始`非终端节点
            q->llink->rlink=q->rlink;
            q->rlink->llink=q->llink;
            free(q);
            return head;
        }
    }
}
