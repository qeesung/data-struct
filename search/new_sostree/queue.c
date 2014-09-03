/*
 * =====================================================================================
 *
 *       Filename:  queue.c                                                                      
 *                                                      
 *    Description:  队列的实现函数                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月03日 15时50分23秒                       
 *       Revision:  none                                
 *       Compiler:  gcc                                 
 *                                                          
 *         Author:  qeesung (), 1245712564@qq.com     
 *   Organization:  Stay hangry , Stay foolish                      
 *                                                              
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Queue
 *  Description:  初始化一个队列
 * =====================================================================================
 */
Queue Init_Queue()
{
    Queue new_queue;

    new_queue	= malloc ( sizeof(struct queue) );
    if ( new_queue==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    new_queue->head	= malloc ( sizeof(struct bitree) );
    if ( new_queue->head==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_queue->tail = new_queue->head;
    return new_queue;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Enqueue
 *  Description:  入队列
 * =====================================================================================
 */
    void
Enqueue ( Queue my_queue  , Bitree tree_node )
{
    List new_node;
    if(my_queue == NULL || tree_node ==NULL)
        return;

    new_node	= malloc ( sizeof(struct list_node) );
    if ( new_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_node->tree_node.data = tree_node->data;
    new_node->tree_node.index = tree_node->index;
    new_node->tree_node.leftchild  = tree_node->leftchild;
    new_node->tree_node.rightchild = tree_node->rightchild;
    my_queue->tail->next = new_node;
    my_queue->tail = new_node;
    return;
}		/* -----  end of function Enqueue  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Dequeue
 *  Description:  出队列函数
 * =====================================================================================
 */
    Bitree
Dequeue ( Queue my_queue )
{
    if(my_queue == NULL)
        return NULL; 
    Bitree dequeue_node;
    if(my_queue->head == my_queue->tail)
    {
        return NULL;//empty queue
    }
    List_node temp;
    if(my_queue->head->next==my_queue->tail)
    {
        dequeue_node = &(my_queue->tail->tree_node);
        my_queue->tail = my_queue->head;
        return dequeue_node;
    }
    dequeue_node = &(my_queue->head->next->tree_node);
    my_queue->head->next = my_queue->head->next->next;;
    return dequeue_node;
}		/* -----  end of function Dequeue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Traverse_Queue
 *  Description:  遍历队列
 * =====================================================================================
 */
    void
Traverse_Queue ( Queue my_queue)
{
     if(my_queue==NULL)
         return;
     if(my_queue->head == my_queue->tail)
         return;
     List_node temp;
     temp = my_queue->head;
     while(temp->next!=my_queue->tail)
     {
        printf("%d>>>%c\n",temp->next->tree_node.index , temp->next->tree_node.data);
        temp = temp->next;
     }
     printf("%d>>>%c\n",temp->next->tree_node.index , temp->next->tree_node.data);
     return;
}		/* -----  end of function Traverse_Queue  ----- */





/*
 * =====================================================================================
                                       _ooOoo_
                                      o8888888o
                                      88" . "88
                                      (| -_- |)
                                      O\  =  /O
                                   ____/`---'\____
                                 .'  \\|     |//  `.
                                /  \\|||  :  |||//  \
                               /  _||||| -:- |||||-  \
                               |   | \\\  -  /// |   |
                               | \_|  ''\---/''  |   |
                               \  .-\__  `-`  ___/-. /
                             ___`. .'  /--.--\  `. . __
                          ."" '<  `.___\_<|>_/___.'  >'"".
                         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
                         \  \ `-.   \_ __\ /__ _/   .-` /  /
                    ======`-.____`-.___\_____/___.-`____.-'======
                                       `=---='
                    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                             佛祖保佑       永无BUG
 * =====================================================================================
 */

