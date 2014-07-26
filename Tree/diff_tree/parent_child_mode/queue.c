/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  new queue c file
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 02时32分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  err_sys
 *  Description:  deal with error 
 * =====================================================================================
 */
    void
err_sys (char * err_msg) 
{
    fprintf(stderr, err_msg);
    exit(EXIT_FAILURE);
}		/* -----  end of function err_sys  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Queue
 *  Description:  Init queue
 * =====================================================================================
 */
    Queue
Init_Queue ( )
{
    Queue new_queue;
    new_queue	= malloc ( sizeof(struct queue) );
    if ( new_queue==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    new_queue->header	= malloc ( sizeof(struct queue_node) );
    if ( new_queue->header==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_queue->front= new_queue->header;
    new_queue->rear= new_queue->header;
    return new_queue

}		/* -----  end of function Init_Queue  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Enqueue
 *  Description:  enqueue a data and index and List_node pointer
 * =====================================================================================
 */
    void
Enqueue (Queue my_queue, char data, int index , List_node pointer_data )
{
    Queue_node new_node;
    if(my_queue==NULL)
        err_sys("the queue have not init yet\n");
    return;

    new_node	= malloc ( sizeof(struct queue_node) );
    if ( new_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_node->data=data;
    new_node->index=index;
    new_node->pointer_data=pointer_data;

    my_queue->rear->next=new_node;
    my_queue->rear=new_node;
    return ;
}		/* -----  end of function Enqueue  ----- */

Queue_node Dequeue(Queue my_queue)
{
    Queue_node dequeue_node;
    if(my_queue==NULL)
        err_sys("the queue have not init\n");
    if(my_queue->front == my_queue->rear)
        return NULL;
    if(my_queue->front->next == my_queue->rear)
    {
        dequeue_node = my_queue->rear;
        my_queue->rear = my_queue->front;
        return dequeue_node;
    
    }
    dequeue_node = my_queue->front->next;
    my_queue->front->next=dequeue_node->next;
    return dequeue_node;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Queue
 *  Description:  print a queue
 * =====================================================================================
 */
    void
Print_Queue ( Queue my_queue )
{
    Queue_node temp;
    if(my_queue == NULL)
        err_sys("the queue have not init \n ");
    if(my_queue->front == my_queue->rear)
        return;
    temp= my_queue->front;
    while(temp->next!=NULL)
    {
        printf("<%c>:::<%d>\n");
        temp=temp->next;
    }
}		/* -----  end of function Print_Queue  ----- */

