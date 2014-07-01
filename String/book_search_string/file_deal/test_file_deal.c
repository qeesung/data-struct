/*
 * =====================================================================================
 *
 *       Filename:  test_file_deal.c
 *
 *    Description:  test for my file deal function
 *
 *        Version:  1.0
 *        Created:  2014年07月01日 01时37分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */
#include	"file_deal.h"
#include	<stdlib.h>
#include	<stdio.h>
#include	"../link_list/string_list/string_list.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	String_list list ;
	list=Init_String_List();

	Deal_File("../source_file/bookname_file",list);

	Print_String_List(list);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

