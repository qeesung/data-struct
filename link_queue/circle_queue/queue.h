/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  This is the header file about the circle queue
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 04时49分45秒
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
#define QUEUE_LENGTH 10
#if 0
this is a circle queue
#endif

struct circle_queue {
	int * base ;// point to a array
	int front ;
	int rear;
};				/* ----------  end of struct cir_cle_queue  ---------- */

typedef struct circle_queue *  Circle_queue;

Circle_queue Init_Circle_Queue();
void Enqueue(Circle_queue queue, int number );
void Dequeue(Circle_queue queue);
void Print_Queue(Circle_queue queue);

#endif
