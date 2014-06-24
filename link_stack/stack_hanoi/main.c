/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  hanoi 
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 01时23分31秒
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Mov
 *  Description:  move a element from this to another 
 * =====================================================================================
 */
	void
Mov ( char start , int number , char end ) /*  move number form start to end */
{
	printf("%d ::::  %c -> %c \n ", number , start, end);
	return;
}		/* -----  end of function Mov  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Hanoi
 *  Description:  
 * =====================================================================================
 */
	void
Hanoi ( int size, char start, char aid , char end )/*  hanoi size from start to end with aid */
{
	if(size==1)
	{
		Mov(start,1,end);
	}
	else
	{
		Hanoi(size-1,start, end, aid);
		Mov(start, size,end);
		Hanoi(size-1,aid,start,end);
	}
	return;
}		/* -----  end of function Hanoi  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{

	int number ;
	if(argc!=2)
	{
		fprintf(stderr,"\n the number of the main is error\n ");
		return -1;
	}
	number =atoi(argv[1]);
	Hanoi(number ,'x', 'y' , 'z');
	printf("\n");
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

