/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  这是队列的C实现文件 
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 18时58分16秒
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
 *         Name:  err_msg
 *  Description:  处理错误情况
 * =====================================================================================
 */
   inline  void
err_msg ( char * my_msg )
{
    fprintf(stderr, my_msg);
    exit(EXIT_FAILURE);
}		/* -----  end of function err_msg  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Queue
 *  Description:  初始化队列
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

    new_queue->front	= malloc ( sizeof(struct queue_node) );
    if ( new_queue->front==NULL ) {
        free(new_queue);
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_queue->rear = new_queue->front;
    return new_queue;
}		/* -----  end of function Init_Queue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Enqueue
 *  Description:  将一个Tree_node指向的树节点数据入队列
 * =====================================================================================
 */
    void
Enqueue (Queue my_queue, Tree_node my_node)
{
    Queue_node new_node;
    if(my_queue == NULL || my_node== NULL)
        err_msg("queue is not init or node data is Node\n");
    
    new_node	= malloc ( sizeof(struct queue_node) );
    if ( new_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    //new_node->node_data.data = my_node->data;
    //new_node->node_data.firstchild = my_node->firstchild;
    //new_node->node_data.nextsibling = my_node->nextsibling;
    new_node->node_data = my_node;

    my_queue->rear->next=new_node;
    my_queue->rear = new_node;
    return ;
}		/* -----  end of function Enqueue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Dequeue
 *  Description:  出队列操作
 * =====================================================================================
 */
    Queue_node
Dequeue ( Queue my_queue )
{
    Queue_node dequeue_node;
    if(my_queue == NULL)
        err_msg("\nQueue have not init\n");
    if(my_queue->front == my_queue->rear)
        return NULL;
    if(my_queue->front->next == my_queue->rear)
    {
        dequeue_node = my_queue->rear;
        my_queue->rear = my_queue->front;
        return dequeue_node;
    }
    dequeue_node = my_queue->front->next;
    my_queue->front->next = dequeue_node->next;
    return dequeue_node;
}		/* -----  end of function Dequeue  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Queue
 *  Description:  打印队列的全部信息
 * =====================================================================================
 */
    void
Print_Queue ( Queue my_queue)
{
    Queue_node temp;
    if(my_queue == NULL)
        err_msg("\nQueue have not init\n");
    if(my_queue->front == my_queue->rear)
        return;
    temp=my_queue->front;
    while(temp->next!=NULL)
    {
        printf("<::%c::>\t",temp->next->node_data->data);
        temp=temp->next;
    }
    return;
}		/* -----  end of function Print_Queue  ----- */



