/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  this is queue c file
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 06时40分10秒
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
 *  Description:  init a empty queue
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
    
    new_queue->queue_list	= malloc ( sizeof(struct tree) );
    if ( new_queue->queue_list==NULL ) {
        free(new_queue);
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_queue->front= new_queue->queue_list;
    new_queue->rear = new_queue->queue_list;
    return new_queue;
}		/* -----  end of function Init_Queue  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Enqueue
 *  Description:  enqueue a tree node
 * =====================================================================================
 */
    void
Enqueue ( Queue my_queue, Tree tree_node )
{
    List new_list_node;
    if(my_queue==NULL)
    {
        fprintf(stderr, "\n the queue have not init yet\n");
        return ;
    }
    if(tree_node == NULL)
    {
        fprintf(stderr, "\n the tree node have not massage\n ");
        return;
    }
    
    new_list_node	= malloc ( sizeof(struct list) );
    if ( new_list_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_list_node ->tree_node.name = tree_node ->name;
    new_list_node ->tree_node.age = tree_node->age;

    my_queue->rear->next= new_list_node;
    my_queue->rear = new_list_node;

    return ;
}		/* -----  end of functioEnqueue  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Dequeue
 *  Description:  dequeue my queue
 * =====================================================================================
 */
    Tree
Dequeue ( Queue my_queue )
{
    List temp;
    Tree dequeue_tree;
    if(my_queue==NULL)
    {
        fprintf(stderr, "\n the queue have not init \n  ");
        return NULL;
    }
    if(my_queue->front == my_queue->rear)
    {
        fprintf(stderr, "\n the queue is empty \n" );
        return NULL;
    }
    
    dequeue_tree	= malloc ( sizeof(struct tree) );
    if ( dequeue_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    if(my_queue->front->next == my_queue->rear)
    {
        dequeue_tree -> name = my_queue->rear->tree_node.name;
        dequeue_tree -> age = my_queue->rear->tree_node.age;
        free(my_queue->rear);
        my_queue->rear= my_queue->front;
    }
    else
    {
        temp = my_queue->front->next->next;
        dequeue_tree->name = my_queue->front->next->tree_node.name;
        dequeue_tree->age = my_queue->front->next->tree_node.age;
        free(my_queue->front->next);
        my_queue->front->next=temp;
    }

    return dequeue_tree;
}		/* -----  end of function Dequeue  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Queue
 *  Description:  print queue massage
 * =====================================================================================
 */
    void
Print_Queue ( Queue my_queue )
{
    List temp;
    if(my_queue == NULL)
    {
        fprintf(stderr, "the queue have not init yet \n");
        return;
    }
    if(my_queue->front == my_queue->rear)
    {
        printf("\n the queue is empty \n ");
        return ;
    }
    temp = my_queue->front;
    while(temp->next!=NULL)
    {
        printf("<%s , %d>:::\t", temp->next->tree_node.name, temp->next->tree_node.age);
        temp=temp->next;
    }
    
    return ;
}		/* -----  end of function Print_Queue  ----- */
