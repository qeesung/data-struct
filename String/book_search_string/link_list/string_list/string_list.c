/*
 * =====================================================================================
 *
 *       Filename:  string_list.c
 *
 *    Description:  this is string_list C file
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 21时45分08秒
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
#include"./index_list/index_list.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_String_List
 *  Description:  init a string list to store the source
 * =====================================================================================
 */
	String_list
Init_String_List ( )
{
	String_list new_string_list;

	new_string_list	= malloc ( sizeof(struct string_node) );
	if ( new_string_list==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	new_string_list->book_index=Init_Index_list();// init the index_list in the string_list
	new_string_list->next==NULL;
	return new_string_list;
}		/* -----  end of function Init_String_List  ----- */

