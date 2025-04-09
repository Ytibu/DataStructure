//字符串的链式操作
// Created by 20358 on 25-4-3.
//

#include<stdio.h>
#include<stdlib.h>
#include"LinkStr.h"

//链式串的创建
void StrCreate(linkstring *S){
	char ch;
	linkstrnode *p,*r;
	*S=NULL; r=NULL;    //r始终指向当前链式串的最后一个字符对应的节点
    while((ch=getchar())!='\n'){
        p=(linkstrnode *)malloc(sizeof(linkstrnode));  //产生新节点
        p->data=ch;
        if(*S==NULL)  *S=p;
        else r->next=p;
        r=p;  //
    }
    if(r!=NULL){r->next=NULL;}    //处理表尾结点指针域
}

//链式串的插入
void StrInsert(linkstring *S,int i,linkstring T){
	int k;
	linkstring p,q;
	p=*S,k=1;
	while(p&&k<i){
		p=p->next;
		k++;
	}
	if(!p) printf("error");
	else{
		q=T;
		while(q&&q->next) q=q->next;
		q->next=p->next;
		p->next=T;
	}

}

//链式串的删除
void StrDlete(linkstring *S,int i,int len){
	int k;
	linkstring p,q,r;
	p=*S,q=NULL;k=1;
	while(p&&k<i){
		q=p;
		p=p->next;	//用p查找S的第i个元素，q始终跟踪p的前驱节点
		k++;
	}
	if(!p) {printf("error1");}	//S查找的第i个元素不存在报错
	else{
		k=1;
		while(k<len&&p)		//p从第i个元素开始查找长度为len的子串的最后一个元素
			{p=p->next;k++;}
		if(!p) printf("error2\n");
		else{
			if(!q) {r=*S; *S=p->next;}	//被删除的子串位于S的最前面
			else{
				r=q->next; q->next=p->next;	//被删除的子串位于S的中间或最后的情形
			}
			p->next=NULL;
			while(r!=NULL){		//回收被删除的子串所占用的空间
				p=r;
				r=r->next;
				free(p);
			}
		}
	
	}
}


//链式串的链接
linkstring Substring(linkstring S,int i,int len){
	int k;
	linkstring p,q,r,t;
	p=S,k=1;
	while(p&&k<i){
		p=p->next;k++;		//用P查找S中的第i个字符
	}
	if(!p) {printf("error1");return NULL;}	//处理S中第i个字符不存在的情形
	else{
		r=(linkstring *)malloc(sizeof(linkstrnode));
		r->data=p->data; r->next=NULL;
		k=1,q=r;		//用q始终指向子串的最后一个字符的位置
		while(p->next&&k<len){	//取长度为len的子串
			p=p->next;k++;
			t=(linkstring *)malloc(sizeof(linkstrnode));
			t->data=p->data;
			q->next=t; q=t;
		}
		if(k<len) {printf("error2"); return NULL;}
		else{
			q->next=NULL;
			return r;		//处理子串的尾部
		}
	}
}


