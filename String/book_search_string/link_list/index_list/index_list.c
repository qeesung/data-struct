/*
 * =====================================================================================
 *
 *       Filename:  index_list.c
 *
 *    Description:  index link list c file 
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 05时31分30秒
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
#include"index_list.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Index_List
 *  Description:  init a index list 
 * =====================================================================================
 */
	Index_list
Init_Index_List ( )
{
	Index_list new_index_list;
	
	new_index_list	= malloc ( sizeof(struct index_node) );
	if ( new_index_list==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	return new_index_list;
	
	return ;
}		/* -----  end of function Init_Index_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Index_List
 *  Description:  insert a index to the index list
 * =====================================================================================
 */
	void
Insert_Index_List ( Index_list list, int index )
{
	Index_position temp;
	Index_position new_index_node;
	if(list==NULL)
	{
		fprintf(stderr,"\n the list is not init\n ");
		return ;
	}

	new_index_node	= malloc ( sizeof(index_node) );
	if ( new_index_node==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	new_index_node->index_number = index;
	while(list->next!=NULL && list->next->index_number < index)
	{
		list=list->next;
	}
	temp=list->next;
	list->next=new_index_node;
	list->next->next=temp;// insert done
	
	return;
}		/* -----  end of function Insert_Index_List  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Index_List
 *  Description:  delete a index from the index list
 * =====================================================================================
 */
	void
Delete_Index_List ( Index_list list , int index )
{
	Index_position temp;
	if(list==NULL)
	{
		fprintf(stderr,"\n the list is not init \n  ");
		return ;
	}
	while(list->next!=NULL && list->next->index_number !=index)
	{
		list-list->next;
	}
	if(list->next==NULL)
	{
		fprintf(stderr,"\n can not find the index : %d \n ", index);
		return ;
	}
	if(list->next->index_number == index)
	{
		temp=list->next->next;
		free(list->next);
		list->next=temp;
	}
	return ;
}		/* -----  end of function Delete_Index_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Index_Position
 *  Description:  find a index position 
 * =====================================================================================
 */
	Index_position
Find_Index_Position ( Index_list list , int index  )
{
	if(list==NULL)
	{
		fprintf(stderr,"\n the list is not init \n ");
		return NULL;
	}
	while(list->next!=NULL && list->next->index_number !=index)
	{
		list=list->next;
	}
	return list->next;
}		/* -----  end of function Find_Index_Position  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Index_List
 *  Description:  print the index list all the index number 
 * =====================================================================================
 */
	void
Print_Index_List (Index_list list )
{
	while(list->next!=NULL )
	{
		printf("%d\t\t",list->next->index_number);
		list=list->next;
	}
	printf("\n ");
	return ;
}		/* -----  end of function Print_Index_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Write_Index_List
 *  Description:  write the data into index_file
 * =====================================================================================
 */
	void
Write_Index_List (Index_list list )
{
	FILE * file ;
	file=fopen("./source_file/index_file", "a+");
	if(file==NULL)
	{
		fprintf(stderr, "\n open the Index_file failed\n ");
		return ;
	}
	while(list->next!=NULL)
	{
		fputs((char*)list->next->inex_number, file);
		fputs("\t\t", file);
		list=list->next;
	}
	fputs("\n ", file);
	return ;
}		/* -----  end of function Write_Index_List  ----- */
