#include<stdio.h>
#include"list.h"
struct listnode
{
	int ele;
	position next;
};

LIST makeempty(void)//create a empty list
{
	LIST head;
	head=(struct listnode *)malloc(sizeof(struct listnode));
	if(head == NULL)
	{
		printf("out of space\n");
		return NULL;
	}
	return head;
}

int insertele(LIST list , int ele ,position p)
{
	// insert a element into the position
	position temp;
	position new;
	position temp1;
	new=(struct listnode *)(malloc(sizeof(struct listnode)));
	if(new==NULL)
	{
		printf("out of space\n");
		return -1;
	}
	if(list->next==NULL)
	{
		printf("the list is NULL\n");
		return -1;
	}
	if(list->next==p)
	{
		temp=list->next;
		list->next=new;
		list->next->next=temp;//insert down;
		
	}
	else
	{
		temp=list;
		while(temp->next!=p)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=p;
		temp->next->next=temp1;
		// insert down ;
	}
	return 0;
	
}
