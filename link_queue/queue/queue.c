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




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Enqueue
 *  Description:  
 * =====================================================================================
 */
	void
Enqueue ( Queue queue , int number , char * name)
{
	Position new_list_node;
	new_List_node	= malloc ( sizeof(struct list_node) );
	if ( new_List_node==NULL ) 
	{
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	new_list_node->number = number;
	new_list_node->name = name;
	new_list_node->next=NULL;
	if(queue->queue_list->next==NULL)
	{
		queue->queue_list->next=new_list_node;
		queue->front=new_list_node;
		queue->rear=new_list_node;
		
	}
	else
	{
		queue->rear->next=new_list_node;
		queue->rear=new_list_node;
	}
	return ;
}		/* -----  end of function Enqueue  ----- */
