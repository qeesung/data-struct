/*
 * =====================================================================================
 *
 *       Filename:  test_queue.c
 *
 *    Description:  用来测试队列函数
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 19时41分51秒
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
#include    "child_sib.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    int k=0;
    Queue my_queue;
    Tree_node my_tree_node;
    Queue_node dequeue_node;

    my_tree_node	= malloc ( sizeof(struct tree_node) );
    if ( my_tree_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    my_tree_node->data='A';
    my_tree_node->firstchild=NULL;
    my_tree_node->nextsibling = NULL;

    my_queue = Init_Queue();
    for(k=0;k<7;k++)
    {
        Enqueue(my_queue, my_tree_node);
        my_tree_node->data='A'+k+1;
    }
    Print_Queue(my_queue);
    printf("\n");
    while((dequeue_node=Dequeue(my_queue))!=NULL)
    {
        printf("<!!%c!!>\n",dequeue_node->node_data.data);
        free(dequeue_node);
        Print_Queue(my_queue);
        printf("**************************\n\n");
    }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
