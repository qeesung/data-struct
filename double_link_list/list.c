/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  This is a c file about the double link list 
 *
 *        Version:  1.0
 *        Created:  2014年06月20日 23时25分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include"./list.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_List
 *  Description:  create a empty list
 * =====================================================================================
 */
	List
Create_List ()
{
	List new_list;
	Position end_node;

	new_list	= malloc ( sizeof(struct Listnode) );
	if ( new_list==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	end_node	= malloc ( sizeof(struct Listnode) );
	if ( end_node==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	new_list->next=end_node;
	end_node->prior=new_list;
	end_node -> number = -1;
	
	return new_list;

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_List
 *  Description:  insert a element into the list
 * =====================================================================================
 */
	void
Insert_List (List list ,Position index , int number )
{	
	Position temp,temp1;
	List new_node;
	if(index == NULL)
	{
		fprintf(stderr, "\n can not find the element \n ");
		return ;
	}
	list=list->next;
	while(list!=NULL && list!=index)
	{
		list=list->next;
	}
	if(list==NULL)
	{
		fprintf(stderr,"\n can not find the element \n");
		return;
	}
	/*  start to insert the ele */
	
	new_node	= malloc ( sizeof(struct Listnode) );
	if ( new_node==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	new_node->number = number;
	temp1=list->prior;
	new_node->next=list;
	new_node->prior=temp1;
	temp1->next=new_node;
	list->prior=new_node;
	return;

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_List
 *  Description:  delete a element form the list
 * =====================================================================================
 */
	void
Delete_List (List list , int number)
{
	Position temp, temp1;
	Position index = Find_Position(list , number);
	if(index  == NULL)
	{
		fprintf(stderr, "\n can not find the number %d ", number);
		return;
	}
	list=list->next;
	while(list!=NULL && list!=index )
	{
		list=list->next;
	}
	if(list==NULL)
	{
		fprintf(stderr , "\n can not find the element \n");
		return ;
	}
	else
	{
		temp=list->prior;
		temp1=list->next;
		free(list);
		temp->next=temp1;
		temp1->prior=temp;
		return ;

	}

}



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_List
 *  Description:  print all the element in the list
 * =====================================================================================
 */
	void
Print_List ( List list)
{
	if(list->next==NULL)
	{
		fprintf(stderr, "\n the list i empty \n");
		return ;
	}
	list=list->next;
	while(list!=NULL && list->number !=-1)
	{
		printf("%d \t\t", list->number);
		list=list->next;
	}
	printf("\n");
	return;
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Position
 *  Description:  find a element in the list
 * =====================================================================================
 */
	Position
Find_Position ( List list , int number )
{
	
	list=list->next;
	if(list == NULL)
	{
		fprintf(stderr , "\n the list is empty \n");
		return NULL;
	}
	while(list!=NULL && list->number != number && list->number !=-1)
	{
		list=list->next;
	}
	return list;

}		/* -----  end of function Find_Position  ----- */
