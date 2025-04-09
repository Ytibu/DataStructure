//顺序栈的操作
// Created by 20358 on 25-3-26.
//

#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"

//顺序栈的初始化
void Init(sequence_stack *st) {
    st->top=0;
}

//判断顺序栈是否为空
int Empty(sequence_stack st) {
    return(st.top?0:1);
}

//读取顺序栈的栈顶节点值
datatype Read(sequence_stack st) {
    if (Empty(st))
    {printf("栈为空");exit(1);}
    else
        return st.a[st.top];
}


//进栈操作Push即插入操作(插入元素x为新的栈顶元素)
void Push(sequence_stack *st,datatype x) {
    if (st->top == MAXSIZE -1)       //栈满
    {
        printf("栈已满");exit(1);
    }
    st->a[st->top]=x;
    st->top++;
}


//出栈操作Pop即删除操作(若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR)
void Pop(sequence_stack *st) {
    if (st->top == 0)
        {printf("栈为空无法删除");exit(1);}
    st->top--;                   //栈顶指针域-1
}