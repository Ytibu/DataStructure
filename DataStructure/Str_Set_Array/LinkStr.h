//字符串的链式存储
// Created by 20358 on 25-4-3.
//

#ifndef LINKSTR_H
#define LINKSTR_H
typedef struct{
  char data;    //用于存放字符串个每个字符
  struct node *next;    //用于只想本字符的下一个字符对应的节点指针
}linkstrnode;
typedef linkstrnode *linkstring;
#endif //LINKSTR_H
