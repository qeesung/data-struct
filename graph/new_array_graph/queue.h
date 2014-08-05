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

struct list_node
{
    int index;/*  store the node index */
    struct list_node * next;
};
typedef struct list_node * List_node;
typedef List_node List;
struct queue
{   
    List queue_list;
    List_node front;
    List_node rear;
};
typedef struct queue * Queue;

Queue Init_Queue();
void Enqueue(Queue my_queue,int index);
List_node Dequeue(Queue my_queue);
void Print_Queue(Queue my_queue);
#endif
