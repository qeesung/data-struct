/*
 * =====================================================================================
 *
 *       Filename:  test_queue.c
 *
 *    Description:  test for my queue
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 07时08分31秒
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

void main()
{
    struct tree tree_list[4]={
        {"A", 21},
        {"B", 22},
        {"C", 23},
        {"D", 24}
    };
    Queue my_queue;
    Tree tree_node;
    int i;
    my_queue=Init_Queue();
    for(i=0;i<4 ; i++)
    {
        Enqueue(my_queue, &tree_list[i]);
    }
    for(i=0;i<4;i++)
    {
        Print_Queue(my_queue);
        tree_node = Dequeue(my_queue);
        printf("Name : %s --------> Age : %d\n", tree_node->name, tree_node->age);
    }
    Enqueue(my_queue, &tree_list[0]);
    Print_Queue(my_queue);
    printf("\n");
    Enqueue(my_queue, &tree_list[1]);
    Print_Queue(my_queue);
    
}

