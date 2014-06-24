/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  this is mian file to test my stack conversion
 *
 *        Version:  1.0
 *        Created:  2014年06月22日 06时35分35秒
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
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Stack stack;
	int shan;
	int yushu;
	int number ;
	int shuzhi;
	stack = Init_Stack();
	if(argc!=3)
	{
		fprintf(stderr, "\n usge for the main function is only two\n");
		return -1;
	}
	number = atoi(argv[1]);
	shuzhi = atoi(argv[2]);
	while(shan !=0)
	{
		shan=number/shuzhi;
		yushu=number%shuzhi;
		Push(stack,yushu);
		number=shan;
	}
	Print_Stack(stack);// print the result
	printf("\n");
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
