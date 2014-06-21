/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This is  mian file
 *
 *        Version:  1.0
 *        Created:  2014年06月22日 05时24分32秒
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
#include	"stack.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  entry  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Stack stack;
	struct Person_node * temp;
	stack=Init_Stack();
	printf("\n +++++++++++++++push++++++++++++++\n ");
	Push(stack,1,"yi");
	Push(stack,2,"er");
	Push(stack,3,"san");
	Push(stack,4,"si");
	Push(stack,5,"wu");
	Push(stack,6,"liu");
	Push(stack,7,"qi");
	Push(stack,8,"ba");
	Push(stack,9,"jiu");
	Print_Stack(stack);
	printf("\n ++++++++++++++pop+++++++++++++++++\n ");
	Pop(stack);
	Pop(stack);
	Pop(stack);
	Pop(stack);
	Pop(stack);
	Print_Stack(stack);
	printf("\n ++++++++++++++get top+++++++++++++++++\n ");
	temp=Get_Top(stack);
	printf("the number is %d | the name is : %s \n", temp->number , temp->name);
	temp=Get_Top(stack);
	printf("the number is %d | the name is : %s \n", temp->number , temp->name);
	temp=Get_Top(stack);
	printf("the number is %d | the name is : %s \n", temp->number , temp->name);
	temp=Get_Top(stack);
	printf("the number is %d | the name is : %s \n", temp->number , temp->name);
	printf("\n ++++++++++++++more pop+++++++++++++++++\n ");
	Pop(stack);
	Pop(stack);
	Pop(stack);
	Pop(stack);
	Pop(stack);
	Pop(stack);
	Pop(stack);
	free(stack->base);
	stack->base = NULL;
	free(stack);
	stack=NULL;
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

