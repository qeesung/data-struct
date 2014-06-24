/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  This is the c file about the queue
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 02时07分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Queue
 *  Description:  init a empty queue
 * =====================================================================================
 */
	Queue
Init_Queue (  )
{	
	Queue new_queue;

	new_queue	= malloc ( sizeof(struct queue_node) );
	if ( new_queue==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	
	new_queue->queue_list	= malloc ( sizeof(struct list_node ) );
	if ( new_queue->queue_list==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	new_queue->front = NULL;
	new_queue->rear = NULL;

	return new_queue;
}		/* -----  end of function Init_Queue  ----- */

