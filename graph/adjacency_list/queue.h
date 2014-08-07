/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  this is queue header file
 *        Version:  1.0
 *        Created:  2014年07月25日 22时47分39秒
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

struct queue_list_node
{
    int index;/*  store the node index */
    struct queue_list_node * next;
};
typedef struct queue_list_node * Queue_list_node;
typedef Queue_list_node Queue_list;
struct queue
{   
    Queue_list queue_list;
    Queue_list_node front;
    Queue_list_node rear;
};
typedef struct queue * Queue;

Queue Init_Queue();
void Enqueue(Queue my_queue,int index);
Queue_list_node Dequeue(Queue my_queue);
void Print_Queue(Queue my_queue);
#endif
