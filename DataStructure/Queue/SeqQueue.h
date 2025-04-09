//顺序队列（队列的顺序存储）
// Created by 20358 on 25-3-26.
//
#ifndef SEQQUEUE_H
#define SEQQUEUE_H
#define MAXSIZE 100
typedef int datatype;
typedef struct {
    datatype a[MAXSIZE];
    int front, rear;
}sequence_queue;
#endif //SEQQUEUE_H
