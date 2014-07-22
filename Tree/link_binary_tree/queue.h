/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  This is queue header file
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 06时29分24秒
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
#include"binary_tree.h"
struct list
{
    struct tree tree_node;
    struct list * next ;

};

typedef struct list * List;
struct queue
{
    List queue_list;
    List front ;
    List rear;
};
typedef struct queue * Queue;

Queue Init_Queue();
void Enqueue(Queue my_queue , struct tree * tree_node);
Tree Dequeue(Queue my_queue);
void Print_Queue(Queue my_queue);

#endif
