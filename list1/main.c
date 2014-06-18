/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This is main file
 *
 *        Version:  1.0
 *        Created:  2014年06月19日 05时52分05秒
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
#include	"./list.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	List my_list;
	my_list=Create_List();
//	Print_List(my_list);
	Insert_List(my_list,(Position)my_list->next,90,"qeesung");
	Insert_List(my_list,my_list->next,56,"weepinside");
	Insert_List(my_list,my_list->next,100,"steve jobs");
	Insert_List(my_list,my_list->next,89,"Q-season-Q");
	Insert_List(my_list,my_list->next,71,"qeesung");
	Insert_List(my_list,my_list->next,90,"qinshicheng");
	Print_List(my_list);

	printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	Insert_List(my_list,Find_Position(my_list,71 ,"qeesung"),99,"xinxinjiang");
	Print_List(my_list);
	printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	Delete_List(my_list,Find_Position(my_list,56,"weepinside"));
	Print_List(my_list);
	Find_Position(my_list,78,"xixihaha");
//	printf("%d %s",my_list->next->number ,my_list->next->name);
	Delete_All_List(my_list);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
