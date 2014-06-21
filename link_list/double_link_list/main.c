/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This is main.c file
 *
 *        Version:  1.0
 *        Created:  2014年06月20日 23时56分15秒
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
 *  Description: this is the main file to test the double link list 
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	List list;
	list=Create_List();
	Insert_List(list , Find_Position(list,-1), 10);
	Insert_List(list , Find_Position(list,-1),78);
	Insert_List(list , Find_Position(list,-1), 34);
	Insert_List(list , Find_Position(list,-1), 30);
	Insert_List(list , Find_Position(list,-1), 31);
	Insert_List(list , Find_Position(list,-1), 56);
	Insert_List(list , Find_Position(list,-1), 28);
	printf("\n +++++++++++++++++++++++++++++++++ \n ");
	Print_List(list);
	printf("\n +++++++++++++++++++++++++++++++++ \n ");
	Delete_List(list,34);
	Delete_List(list,28);
	Delete_List(list,0);
	Print_List(list);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

