/*
 * =====================================================================================
 *
 *       Filename:  test_string_list.c
 *
 *    Description:  test for my string_list 
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 22时43分05秒
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
#include	"./string_list.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{

	String_list my_list;
	my_list=Init_String_List();
	Insert_String_List(my_list, "qeesung" , 12);
	Insert_String_List(my_list, "qeesung" , 3);
	Insert_String_List(my_list, "qeesung" , 520);
	Insert_String_List(my_list, "qinshicheng" , 38);
	Insert_String_List(my_list, "zhouwenxin" , 67);
	Insert_String_List(my_list, "weepinside" , 46);
	printf("\n ++++++++++++++after insert+++++++++++\n ");
	Print_String_List(my_list);
	Delete_String_List(my_list,"weepinside",-1);
	Delete_String_List(my_list,"qeesung",3);
	printf("\n ++++++++++++++after delete+++++++++++\n ");
	Print_String_List(my_list);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
