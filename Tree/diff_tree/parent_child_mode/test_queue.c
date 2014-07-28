/*
 * =====================================================================================
 *
 *       Filename:  test_queue.c
 *
 *    Description:  test my_queue
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 02时55分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include    <stdio.h>
#include    "queue.h"
#include    "child_mode.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    List_node ptr_node=NULL;
    Queue my_queue;
    int k=0;
    Queue_node dequeue_node;
    my_queue = Init_Queue();
    Enqueue(my_queue,'A', 0,ptr_node);
    Enqueue(my_queue,'A'+1, 1,ptr_node);
    Enqueue(my_queue,'A'+2, 2,ptr_node);
    Enqueue(my_queue,'A'+3, 3,ptr_node);
    Enqueue(my_queue,'A'+4, 4,ptr_node);
    Enqueue(my_queue,'A'+5, 5,ptr_node);
    Print_Queue(my_queue);
    while((dequeue_node = Dequeue(my_queue))!=NULL)
    {
        printf("DATA:%c:::INDEX:%d\n", dequeue_node->data , dequeue_node->index);
        printf("*************************\n");
        Print_Queue(my_queue);
    }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
