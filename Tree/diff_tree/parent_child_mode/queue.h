/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  new queue header file
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 02时32分43秒
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
#include"child_mode.h"
struct queue_node
{
    char data;
    int index;
    List_node pointer_data;
    struct queue_node * next;
};
typedef struct queue_node * Queue_node;
struct queue
{
    Queue_node header;
    Queue_node front;
    Queue_node rear;

};
typedef struct queue * Queue;
//void err_sys(char * err_msg);
Queue Init_Queue();
void Enqueue(Queue my_queue, char data , int index , List_node node_pointer);
Queue_node Dequeue(Queue my_queue);
void Print_Queue(Queue my_queue);
#endif
