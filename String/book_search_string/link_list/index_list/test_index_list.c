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
	Insert_Index_List(my_list, "066");
	Insert_Index_List(my_list, "082");
	Insert_Index_List(my_list, "010");
	Insert_Index_List(my_list, "036");
	Insert_Index_List(my_list, "085");
	Insert_Index_List(my_list, "017");
	Insert_Index_List(my_list, "095");
	Insert_Index_List(my_list, "042");
	Print_Index_List(my_list);
	Write_Index_List("/root/suanfa/String/book_search_string/source_file/index_file",my_list);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
