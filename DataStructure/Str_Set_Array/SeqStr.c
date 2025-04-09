//字符串的顺序存储操作
// Created by 20358 on 25-4-3.
//

#include<stdio.h>
#include<stdlib.h>
#include"SeqStr.h"

//顺序串的插入操作
void StrInsert(seqstring *S,int i,seqstring T){
  int k;

    //特殊情况的处理
    if(i<1||i>S->length+1||S->length+T.length>MAXSIZE-1)
        printf("Error in  StrInsert()\n");
    else{
    //S中从第i个元素开始后移
    for(k=S->length-1;k>i-1;k--)
        S->str[T.length+k]=S->str[k];

    //将T写入S中第i个字符的开始位置
    for(k=0;k<T.length;k++)
        S->str[i+k-1]=T.str[k];

    S->length=S->length+T.length;
    //设置字串S的结束符
    S->str[S->length]='\0';

    }
}


//顺序串的删除操作
void StrDelete(seqstring *S,int i,int len){
  int k;
  //特殊情况的处理
  if(i<1||i>S->length||i+len-1>S->length)
    printf("Error in  Delete()\n");

  else{
    for(k=i+len-1;k<S->length;k++)
      //S中从下标为i+len-1开始的元素前移
      S->str[k-len]=S->str[k];

    S->length=S->length-len;
    //设置字符串S新的结束符
    S->str[S->length]='\0';
  }
}


//顺序串的连接
seqstring *StrConcat(seqstring S1,seqstring S2){
  int i;
  seqstring *r;
  //处理字符数组空间不够使用的情况
  if(S1.length+S2.length>MAXSIZE-1)
    {printf("Error in StrConcat()\n");return NULL;}
  else{
    r=(seqstring *)malloc(sizeof(seqstring));

    //将S1复制到字符数组r的前端
    for(i=0;i<S1.length;i++) r->str[i]=S1.str[i];

    //将S2复制到字符数组r的后端
    for(i=0;i<S2.length;i++) r->str[i+S1.length]=S2.str[i];  //遍历数组给新数组每个元素赋值

    //新数组长度为S1,S2长度之和
    r->length=S1.length+S2.length;
    r->str[S1.length]='\0';
  }
  return r;
}


//求给定顺序串的子串
seqstring *SubString(seqstring S,int i,int len){
  int k;
  seqstring *r;
  //特殊情况的处理
  if(i<1||i>S.length||i+len-1>S.length)
    {printf("Error in SubString()\n");return NULL;}

  else{
    r=(seqstring *)malloc(sizeof(seqstring));
    //复制子串到字符数组r中
    for(k=0;k<len;k++)
      r->str[k]=S.str[i+k-1];

    r->length=len;
    r->str[r->length]='\0';
  }
  return r;

}


//字符串模式匹配：朴素模式匹配算法
int Index(seqstring p,seqstring t)	//寻找模式p在正文t中首次出现的起始位置
{
	int i,j,succ;
	j=0;succ=0;		//用i扫描全文t，succ为匹配成功的标志
	while((i<=t.length-p.length)&&(!succ))
	{
		j=0, succ=0;
		while((j<=p.length-1)&&succ){
			if(p.str[j]==t.str[i+j]) j++;
			else succ=0;
		}
		++i;
	}
	if(succ) return i--;
	else return -1;
}


//字符串模式匹配：快速模式匹配算法
void GetNext(seqstring p,int next[] )
{
	int i, j;
	next[0] = -1;
	i=0, j=-1;
	while(i<p.length){
		if(j==-1||p.str[i]=p.str[j])
		{
			++i,++j;
			next[i] = j;
		}
		else
			j=next[j];
	}
	for(i=0;i<p.length;i++)
	printf("%d",next[i]);
}
