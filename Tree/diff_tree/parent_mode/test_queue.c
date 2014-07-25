/*
 * =====================================================================================
 *
 *       Filename:  test_queue.c
 *
 *    Description:  test for queue
 *
 *        Version:  1.0
 *        Created:  2014年07月25日 23时27分17秒
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
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    List_node my_node;
    Queue my_queue;
    my_queue=Init_Queue();
    Enqueue(my_queue,'A', 0);
    Enqueue(my_queue,'A'+1, 1);
    Enqueue(my_queue,'A'+2, 2);
    Enqueue(my_queue,'A'+3, 3);
    Enqueue(my_queue,'A'+4, 4);
    Enqueue(my_queue,'A'+5, 5);
    Print_Queue(my_queue);
    printf("\n\n");
    while((my_node=Dequeue(my_queue))!=NULL)
    {
        printf("DATA: %c INDEX:%d\n",my_node->data, my_node->index);
        printf("*********************************\n");
        Print_Queue(my_queue);
    }
    

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
