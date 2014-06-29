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
