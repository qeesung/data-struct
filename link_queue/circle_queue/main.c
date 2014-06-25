/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This is the main file about the circle queue
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 05时19分21秒
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
#include	"queue.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Circle_queue my_queue ;
	my_queue=Init_Circle_Queue();
	Enqueue(my_queue,0);
	Enqueue(my_queue,1);
	Enqueue(my_queue,2);
/*  	Enqueue(my_queue,3);
	Enqueue(my_queue,4);
	Enqueue(my_queue,5);
	Enqueue(my_queue,6);
	Enqueue(my_queue,7);
	Enqueue(my_queue,8);
	Enqueue(my_queue,9);
	Enqueue(my_queue,10);
	Enqueue(my_queue,11);
	Enqueue(my_queue,12);
	Enqueue(my_queue,13);
	Enqueue(my_queue,14);*/
	printf("\n ++++++++++++++++++after enqueue+++++++++++++\n ");
	Print_Queue(my_queue);
	Dequeue(my_queue);
	Dequeue(my_queue);
	Dequeue(my_queue);
	Dequeue(my_queue);
	printf("\n ++++++++++++++++++after dequeue+++++++++++++\n ");
	Print_Queue(my_queue);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

