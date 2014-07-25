/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  this is queue c file
 *
 *        Version:  1.0
 *        Created:  2014年07月25日 22时59分01秒
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
 *         Name:  Init_Queue
 *  Description:  init q queue
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

    /*  create list header */ 
    new_queue->queue_list	= malloc ( sizeof(struct list_node) );
    if ( new_queue->queue_list==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_queue->front = new_queue->queue_list;
    new_queue->rear = new_queue->queue_list;
    return new_queue;
}		/* -----  end of function Init_Queue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Enqueue
 *  Description:  enqueue a data with index
 * =====================================================================================
 */
    void
Enqueue ( Queue my_queue , char data, int index )
{
    List_node new_node;
    if(my_queue==NULL)
    {
        fprintf(stderr, "\n the queue have not init \n ");
        return ;
    }
    
    new_node	= malloc ( sizeof(struct list_node) );
    if ( new_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_node->data= data;
    new_node->index= index;
    my_queue->rear->next=new_node;
    my_queue->rear=new_node;
    return ;
}		/* -----  end of function Enqueue  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Dequeue
 *  Description:  dequeue function
 * =====================================================================================
 */
    List_node
Dequeue ( Queue my_queue )
{
    List_node dequeue_node=NULL;
    if(my_queue == NULL)
    {
        fprintf(stderr, "\n the queue have not init \n ");
        return NULL;
    }
    if(my_queue->front == my_queue->rear)
    {
        fprintf(stderr, "\n the queue is empty\n");
        return NULL; 
    }

    if(my_queue->front->next == my_queue->rear)
    {
        dequeue_node = my_queue->rear;
        my_queue->rear= my_queue->front;
        return dequeue_node;
    }
    dequeue_node= my_queue->front->next;
    my_queue->front->next=dequeue_node->next;
    return dequeue_node;
}		/* -----  end of function Dequeue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Queue
 *  Description:  print a queue all detail massge
 * =====================================================================================
 */
    void
Print_Queue( Queue my_queue)
{
    List_node temp;
    if(my_queue==NULL ||  my_queue->front==my_queue->rear)
    {
        return ;
    }
    temp=my_queue->front;
    while(temp->next!=NULL)
    {
        printf("<data:%c ++ index:%d>\n", temp->next->data,temp->next->index);
        temp = temp->next;
    }
    return ;
}		/* -----  end of function Print_Queue  ----- */
