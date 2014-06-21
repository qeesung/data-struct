/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  This file is define somefunction;
 *
 *        Version:  1.0
 *        Created:  2014年06月19日 05时10分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */
#include"./list.h"
#include<stdlib.h>
#include<stdio.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_List
 *  Description:  create a empty List with header
 * =====================================================================================
 */
List Create_List(void)
{
	List list;
		
	list	= malloc ( sizeof(struct Listnode) );
	if ( list==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	list->next	= malloc ( sizeof(struct Listnode) );
	if ( list->next==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	} /*  this one is the list back */
	list->next->name="end";
	list->next->number=-1;

	free ( list->next );
	list->next	= NULL;

	list->number=0;
	list->name="Header";
	list->next=NULL;
	return list;
	
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_List
 *  Description:  insert a element into the List
 * =====================================================================================
 */
void Insert_List(List list,Position pos,int number,char * name)
{
	struct Listnode * new_node;
	Position temp;
	new_node	= malloc ( sizeof(struct Listnode) );
	if ( new_node==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	new_node->number=number;
	new_node->name=name;
	if(list->next==NULL)
	{
		list->next=new_node;
	}
	else
	{
	
		temp=list;
		while(list->next!=NULL && list->next!=pos)
		{
			list=list->next;
		}
		if(list->next==NULL)
		{
			printf("\n can not find the position \n");
			return;
		}
		else
		{
			
			temp->number++;// the list element number add one 
			temp=list->next;
			list->next=new_node;
			list->next->next=temp;
			// insert done
		}
	}


}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_List
 *  Description:  delete a element from the list
 * =====================================================================================
 */
void Delete_List(List list,Position pos)
{
	Position temp;
	if(list->next==NULL)
	{
		printf("\nthe List is empty\n");
		return;
	}
	temp=list;
	while(list->next!=NULL && list->next !=pos)
	{
		list=list->next;
	}
	if(list->next==NULL)
	{
		printf("\n can not find the possition \n");
		return;
	}
	else
	{
		temp->number--;	//delete the number of the list
		temp=list->next->next;
		free(list->next);
		list->next=temp;//delete done;
	}
	return;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Position
 *  Description:  Find a position with given number and name
 * =====================================================================================
 */
Position Find_Position(List list , int number ,char * name)
{
	if(list->next==NULL)
	{
		fprintf(stderr,"\n the list is empty\n");
		return NULL;
	}
	while(list->next!=NULL && list->next->number !=number && list->next->name != name)
	{
		list=list->next;
	}
	if(list->next==NULL)
	{
		fprintf(stderr,"\n can not find the element \n ");
		return NULL;
	}
	else
	{
		return list->next;
	}
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_List
 *  Description:  print all the element in the list
 * =====================================================================================
 */

void Print_List ( List list )
{
	int i=0;
	if(list->next==NULL)
	{
		fprintf(stderr , "\n the list is empty \n ");
		return ;
	}
	while(list->next!=NULL)
	{
		i++;
		printf("The #%d number is %d and the name is %s \n  ", i , list->next->number ,list->next->name);
		list=list->next;
	}
	return;
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_All_List
 *  Description:delele all the element in the list include the header;  
 * =====================================================================================
 */

void Delete_All_List (List list  )
{
	Position temp;
	while(list!=NULL)
	{
		temp=list->next;
		free(list);
		list=temp;
	}
	return;

	return ;
}		/* -----  end of function Delete_All_List  ----- */


