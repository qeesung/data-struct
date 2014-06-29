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
