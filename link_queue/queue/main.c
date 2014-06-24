/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This is main file to test queue
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 02时41分09秒
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
	Queue my_queue=Init_Queue();
	Enqueue(my_queue,1,"yi");
	Enqueue(my_queue,2,"er");
	Enqueue(my_queue,3,"san");
	Enqueue(my_queue,4,"si");
	Enqueue(my_queue,5,"wu");
	Enqueue(my_queue,6,"liu");
	Enqueue(my_queue,7,"qi");
	Enqueue(my_queue,8,"ba");
	Print_Queue(my_queue);
	printf("\n++++++++++++++++dequeue twice++++++++++++\n");
	Dequeue(my_queue);
	Dequeue(my_queue);
	Print_Queue(my_queue);
	printf("\n++++++++++++++++enqueue twice++++++++++++\n");
	Enqueue(my_queue,9,"jiu");
	Enqueue(my_queue,10,"shi");
	Print_Queue(my_queue);
	printf("\n++++++++++++++++destory the queue++++++++++++\n");
	Destory_Queue(my_queue);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

