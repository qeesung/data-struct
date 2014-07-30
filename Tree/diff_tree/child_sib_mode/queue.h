/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  这是队列的申明头文件
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 18时58分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#ifndef _QUEUE_H
#define _QUEUE_H
#include"child_sib.h"

struct queue_node
{
    struct tree_node *  node_data;
    struct queue_node * next;
};
typedef struct queue_node * Queue_node;

struct queue
{
    Queue_node front;
    Queue_node rear;
};
typedef struct queue * Queue;
void err_msg(char * string);
Queue Init_Queue();
void Enqueue(Queue my_queue, Tree_node my_node);
Queue_node Dequeue(Queue my_queue);
void Print_Queue(Queue my_queue);

#endif
