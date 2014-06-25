/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  This is a c file about the queue.c
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 04时55分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Circle_Queue
 *  Description:  init a queue
 * =====================================================================================
 */
	Circle_queue
Init_Circle_Queue ( )
{
	Circle_queue new_queue;

	new_queue	= malloc ( sizeof(struct circle_queue) );
	if ( new_queue==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	new_queue->base	= (int *)malloc ( sizeof(int) * QUEUE_LENGTH );
	if ( new_queue->base==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	new_queue->front=0;
	new_queue->rear=0;


	return new_queue;
}		/* -----  end of function Init_Circle_Queue  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Enqueue
 *  Description:  insert a number into the queue
 * =====================================================================================
 */
	void
Enqueue ( Circle_queue queue, int number  )
{
	if(queue->front==queue->rear)
	{
		queue->base[queue->front]=number ;
		return;
	}
	else
	{
		if(queue->rear+1!=queue->front)
		{
			if(queue->rear!=QUEUE_LENGTH-1)
			{
				queue->rear++;
				queue->base[queue->rear]=number ;
			}
			else
			{
				if(queue->front==0)
				{
					fprintf(stderr,"\n the queue is full \n ");
					return ;
				}
				else
				{
					queue->rear=0;
					queue->base[queue->rear]=number;
				}
			}
		}
		else
		{
			fprintf(stderr,"\nthe queue is full\n");
			return ;
		}
	}
	return ;
}		/* -----  end of function Enqueue  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Dequeue
 *  Description:  this is for mu dequeueu
 *  * =====================================================================================
 */
	void
Dequeue ( Circle_queue queue )
{
	if(queue->rear==queue->front)
	{
		fprintf(stderr,"\n the queue is empty \n");
		return ;
	}
	else
	{
		if(queue->front!=QUEUE_LENGTH-1)
		{
			queue->front--;

		}
		else
		{
			queue->front=0;
		}
	}

	return;
}		/* -----  end of function Dequeue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Queue
 *  Description:  print all the element in the queue
 * =====================================================================================
 */
	void
Print_Queue ( Circle_queue queue )
{
	int i;
	i=queue->front;
	while(i!=queue->rear)
	{
		printf("%d\t\t", queue->base[i]);
		if(i==QUEUE_LENGTH-1)
		i=0;
		else
		i++;

	}

	printf("%d\t\t", queue->base[i]);
	return;
}		/* -----  end of function Print_Queue  ----- */
