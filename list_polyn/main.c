/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This is a main file for testing polyn list
 *
 *        Version:  1.0
 *        Created:  2014年06月21日 03时48分42秒
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
#include	"./polyn.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Polyn polyn,polyn1;
	polyn=Create_Polyn();
	polyn1=Create_Polyn();
	Insert_Polyn(polyn,1,2);
	Insert_Polyn(polyn,3,4);
	Insert_Polyn(polyn,56,90);
	Insert_Polyn(polyn,71,34);
	Insert_Polyn(polyn,289,6789);
	Insert_Polyn(polyn,4657,9000);
	Insert_Polyn(polyn,45,2);
	printf("\n +++++++++++++++   polyn1   +++++++++++++++++++++ \n ");
	Print_Polyn(polyn);
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
	Insert_Polyn(polyn1,3,4);
	Insert_Polyn(polyn1,39,47);
	Insert_Polyn(polyn1,89,36);
	Insert_Polyn(polyn1,2892,6789);
	Insert_Polyn(polyn1,4657,9001);
	Insert_Polyn(polyn1,45,2);
	printf("\n +++++++++++++++   polyn2   +++++++++++++++++++++ \n ");
	Print_Polyn(polyn1);
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	printf("\n ------------------------------------------------- \n ");
	Add_Polyn(polyn,polyn1);
	printf("\n +++++++++++++++  after add polyn1  +++++++++++++++++++++ \n ");
	Print_Polyn(polyn);


	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


