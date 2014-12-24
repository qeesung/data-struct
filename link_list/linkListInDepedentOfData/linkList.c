#include "linkList.h"

LinkList createLinkList()
{
	//创建一个表头
	LinkListNode header = (LinkListNode)malloc(sizeof(struct linkList));
	if(header==NULL)
	{
		perror("Create a linkList failed");
		exit(EXIT_FAILURE);
	}
	return header;
}

void insertLinkListNode(LinkList list , LinkListNode insertNode)
{
	if(list==NULL)
	{
		fprintf(stderr, "%s\n","you should class createLinkList to create a new LinkList first" );
		return;
	}
	if(insertNode == NULL)
	{
		fprintf(stderr, "%s\n","can not insert a null node" );
		return;
	}
	LinkListNode temp = list->next;
	list->next=insertNode;
	list->next->next=temp;//插入成功
}

LinkListNode deleteLinkListNode(LinkList list , LinkListNode deleteNode)
{
	if(list==NULL)
	{
		fprintf(stderr, "%s\n","you should class createLinkList to create a new LinkList first" );
		return NULL;
	}
	if(deleteNode ==NULL)
		return NULL;
	LinkListNode retNode;
	//在链表里面寻找当前的节点指针
	while(list->next != NULL && list->next!=deleteNode)
	{
		list=list->next;
	}
	if(list->next!=NULL)
	{
		LinkListNode temp=list->next->next;
		retNode = list->next;
		list->next=temp;
		return retNode;
	}
	return NULL;
	
}

LinkListNode getNextNode(LinkList list , LinkListNode curNode)
{
	if(list==NULL)
	{
		fprintf(stderr, "%s\n","you should class createLinkList to create a new LinkList first" );
		return NULL;
	}
	if(curNode ==NULL)
		return NULL;
	return curNode->next;
}
