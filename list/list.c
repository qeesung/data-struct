#include"list.h"
#include<stdlib.h>
#include<stdio.h>



/* in the c file we wiil define the list functions */

//define struct list node 
struct listnode
{
	int number;
	Position next;
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
List init_list()
{
	List my_list;
	my_list=malloc(sizeof(struct listnode));// create a header
	if(my_list==NULL)
	{
		printf("out of space\n");
		return NULL;
	}
	my_list->number=0;
	my_list->next=NULL;
	return my_list;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++
int insert_number(List my_list,int number,Position my_position)
{
	List new_node;
	Position temp;
	Position temp1;
	new_node=malloc(sizeof(struct listnode));
	if(new_node==NULL)
	{
		printf("out of space\n");
		return -1;
	}
	new_node->number==number;
	new_node->next==NULL;

	if(my_list==NULL)
	{
		printf("the table is empty\n");
		return -1;
	}
	else
	{
		temp=my_list;
		while(temp->next!=NULL && temp->next!=my_position)
		{
			temp=temp->next;
		}
		if(temp->next==NULL)
		{
			printf("can not find the position \n");
			return -1;
		}
		else
		{
			temp1=temp->next;
			temp->next=new_node;
			temp->next->next=temp1;
			// insert done!
		}
		return 1;

		
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int delete_number(List my_list,int number)
{
	Position temp;
	Position temp1;
	if(my_list==NULL)
	{
		printf("The list is empty\n");
		return -1;
	}
	temp=my_list;
	while(temp->next!=NULL && temp->next->number!=number)
	{
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		printf("can not find the number\n");
		return -1;
	}
	else
	{
		temp1=temp->next->next;// record the number that deleted 
		free(temp->next);// free the memory
		temp->next=temp1;
		//delete done	
	}


}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int delete_List(List my_list)
{
	Position temp;
	while(temp!=NULL)
	{
		temp=my_list->next;
		free(my_list);
		my_list=temp;
	}// release all the number
	return 1;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Position position_find(List my_list,int number)
{
	Position temp;
	if(my_list->next==NULL)
	{
		printf("the List is empty\n");
		return NULL;
	
	}
	temp=my_list;
	while(temp->next!=NULL && temp->number != number)
	{
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		printf("can not find the nmber \n");
		return NULL;
	}
	else
	{
		return temp->next;
	}
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Print_lits(List my_list)
{
	if(my_list->next==NULL)
	{
		printf("the list is NULL\n");
		return;
	}
	while(my_list->next!=NULL)
	{
		printf("%d\t\t",my_list->next->number);
	}
	return;
}
