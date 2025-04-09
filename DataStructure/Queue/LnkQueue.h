//链式队列
// Created by 20358 on 25-4-2.
//

#ifndef LNKQUEUE_H
#define LNKQUEUE_H
typedef int datatype;
typedef struct link_node {
  datatype info;
  struct link_node *next;
}node;
typedef struct {
  node *front,*rear;//定义队首与队尾指针
}queue;
#endif //LNKQUEUE_H
