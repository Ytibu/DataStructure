//顺序表的操作
// Created by 20358 on 25-3-26.
//
#include <stdio.h>
#include <stdlib.h>
#include "SequList.h"

//顺序表的初始化——置空表
void Init(sequence_list *slt) {
    slt->size = 0;
}

//顺序表的插入操作
void Append(sequence_list *slt, datatype x) {
    if (slt->size == MAXSIZE) {
        printf("顺序表已满");exit(1);
    }
    slt->a[slt->size] = x;
    slt->size++;
}

//输出顺序表各个节点的值
void Display(sequence_list slt) {
    int i;
    if (!slt.size) {printf("顺序表为空");}
    else {
        for (i = 0; i < slt.size; i++) {printf("%5d",slt.a[i]);}
    }
}

//判断顺序表是否为空
int Empty(sequence_list slt) {
    return slt.size == 0?1:0;
}

//查找是顺序表中值为x的节点位置
int Find(sequence_list slt, datatype x) {
    int i=0;
    while (i < slt.size && slt.a[i] != x) {i++;}
    return i<slt.size?i:-1;
}

//取得顺序表中第i个节点的值
datatype Get(sequence_list slt,int i) {
    if (i < 0 || i >= slt.size) {
        printf("指定位置节点不存在！");exit(1);
    }else {
        return slt.a[i];
    }
}

//顺序表的position位置插入值为x的节点
void Insert(sequence_list *slt,datatype x,int position) {
    int i;
    if (slt->size == MAXSIZE) {
        printf("顺序表已满无法插入");exit(1);
    }
    if (position<0 || position > slt->size) {
        printf("指定位置不存在");exit(1);
    }
    for (i = slt->size; i > position; i--) {slt->a[i] = slt->a[i-1];}
    slt->a[position] = x;
    slt->size++;
}

//删除顺序表中第position位置的节点
void Delete(sequence_list *slt,int position) {
    int i;
    if (slt->size == 0) {printf("顺序表为空");exit(1);}
    if (position < 0 || position > slt->size) {printf("指定的删除位置不存在");exit(1);}
    for (i = position; i < slt->size; i++) {slt->a[i] = slt->a[i+1];}
    slt->size--;
}