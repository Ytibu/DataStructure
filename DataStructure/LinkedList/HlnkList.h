//带头结点的单链表
// Created by 20358 on 25-3-20.
//

#ifndef HLNKLIST_H
#define HLNKLIST_H

typedef int datatype;
typedef struct link_node {
    datatype info;               // 节点数据
    struct link_node *next;      // 指向下一个节点的指针
}node;
#endif // HLNKLIST_H
