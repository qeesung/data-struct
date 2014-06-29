/*
 * =====================================================================================
 *
 *       Filename:  test_index_list.c
 *
 *    Description:  test index_list 
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 06时08分07秒
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
#include	"index_list.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{

	Index_list my_list;
	my_list=Init_Index_List();
	Insert_Index_List(my_list, 66);
	Insert_Index_List(my_list, 82);
	Insert_Index_List(my_list, 10);
	Insert_Index_List(my_list, 36);
	Insert_Index_List(my_list, 85);
	Insert_Index_List(my_list, 17);
	Insert_Index_List(my_list, 95);
	Insert_Index_List(my_list, 42);
	Print_Index_List(my_list);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
