#include<stdio.h>
#include<stdlib.h>
#include"./list_yan.h"

struct Listnode
{
	int number;
	char * name;
	List next;
};
List Create_List(int numebr)
{
	List new_list;
	List temp;
	int i;
	// create the header 
	new_list=malloc(sizeof(struct Listnode));
	if(new_list == NULL)
	{
		printf("out of space create the haeder failed\n");
		return NULL;
	}
	// and now create the body
	temp=new_list;
	for(i=0;i<number;i++)
	{
		temp->next=malloc(sizeof(struct Listnode));
		if(temp->next==NULL)
		{
			printf("create the Listnode failed\n");
			Delete_List(new_list);// delete has been malloc
			return NULL;
		}
		printf("enter #%d number:",i);
		scanf("%d",&(temp->next->number));
		printf("\n");
		printf("enter #%d name:",i);
		scanf("%s",temp->next->name);
		temp=temp->next;// insert done
		
	}
	return new_list;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Position Get_Node(List my_list , int i,int list_size)
{
	Position temp;
	int i;
	if(my_list->next==NULL)
	{
		printf("the List is empty\n");
		return NULL;
	}
	if(i>list_size)
	{
		printf("can not find the element\n");
		return NULL;
	}
	temp=my_list;
	for(i=0;i<i;i++)
	{	
		temp=temp->next;
		
	}
	return temp;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif


