#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <stdio.h>
#include <stdlib.h>

//这个链表时独立于数据而存在的，这样用户就可以存取任何类型的数据

struct linkList
{
	struct linkList * next;
};

typedef struct linkList * LinkList;
typedef LinkList LinkListNode;

//创建一个链表
LinkList createLinkList();
//在链表末尾插入一个元素
void insertLinkListNode(LinkList  list , LinkListNode insertNode);
//在链表里面删除一个元素，并将对应的指针返回
LinkListNode deleteLinkListNode(LinkList list , LinkListNode deleteNode);
//得到链表里面的当前节点的下一个节点
LinkListNode getNextNode(LinkList list , LinkListNode curNode);

#endif