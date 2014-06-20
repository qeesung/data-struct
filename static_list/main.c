/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月20日 07时26分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<stdio.h>
#include 	"list_static.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	List list;

	list	= malloc ( sizeof(struct list_ele) );
	if ( list==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	Init_List(list);
	Insert_List(list,0,"ling");
	Insert_List(list,1,"yi");
	Insert_List(list,2,"er");
	Insert_List(list,3,"san");
	Insert_List(list,4,"si");
	Insert_List(list,5,"wu");
	Insert_List(list,6,"liu");
	printf("\n +++++++++++++++++++++++++++++++ \n ");
	Print_List(list);
	printf("%d %s ", list->data[2].number , list->data[2].name);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
