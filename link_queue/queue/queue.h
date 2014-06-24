/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  This is link queue header file
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 01时58分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#ifndef _QUEUE_H
#define _QUEUE_H

struct list_node {
	int number ;
	char * name;
	struct list_node * next;
};				/* ----------  end of struct list_node  ---------- */

typedef struct list_node  * List;
typedef List Position;

struct queue_node {
	Position front;
	Position rear;
	List queu_list;
};				/* ----------  end of struct Queue  ---------- */

typedef struct queue_node *  Queue;

Queue Init_Queue();// Create a empty queue
void Enqueue(Queue queue,int number , char * name);
void Dequeue(Queue queue);
void Detory_Queue();
void Print_Queue(Queue queue);



#endif
