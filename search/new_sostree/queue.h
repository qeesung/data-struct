/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  队列的头文件
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 15时44分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#pragma once
#include "bitree.h"
struct list_node
{
    struct bitree tree_node;
    struct list_node * next;
};
 typedef struct list_node * List_node;
 typedef List_node List;

 struct queue
{
    List head;
    List tail;
};
typedef struct queue * Queue;

Queue Init_Queue();
void Enqueue(Queue my_queue , Bitree tree_node);
Bitree Dequeue(Queue my_queue);
void Traverse_Queue(Queue my_queue);


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

