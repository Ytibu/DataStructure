//双链表
// Created by 20358 on 25-3-23.
//
#ifndef DLNKLIST_H
#define DLNKLIST_H

typedef int datatype;
typedef struct dlink_node {
    datatype info;
    struct dlink_node *llink,*rlink;
}dnode;
void main();
#endif //DLNKLIST_H
