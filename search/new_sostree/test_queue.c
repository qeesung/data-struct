/*
 * =====================================================================================
 *
 *       Filename:  test_queue.c                                                                      
 *                                                      
 *    Description:  测试队列文件                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月03日 16时28分52秒                       
 *       Revision:  none                                
 *       Compiler:  gcc                                 
 *                                                          
 *         Author:  qeesung (), 1245712564@qq.com     
 *   Organization:  Stay hangry , Stay foolish                      
 *                                                              
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "queue.h"
#include "bitree.h"
int main(int argc, char *argv[])
{
    Queue my_queue;
    struct bitree my_tree;
    my_tree.index = 1;
    my_tree.data = 'A';
    Bitree dequeue_node;
    my_queue = Init_Queue();
    Enqueue(my_queue , &my_tree);
    my_tree.index++;my_tree.data++;
    Enqueue(my_queue , &my_tree);
    my_tree.index++;my_tree.data++;
    Enqueue(my_queue , &my_tree);
    my_tree.index++;my_tree.data++;
    Enqueue(my_queue , &my_tree);
    my_tree.index++;my_tree.data++;
    Enqueue(my_queue , &my_tree);
    my_tree.index++;my_tree.data++;
    Enqueue(my_queue , &my_tree);
    Traverse_Queue(my_queue);
    printf("***************************\n");
    fflush(stdout);
    while((dequeue_node=Dequeue(my_queue))!=NULL)
    {
      printf("Get %d>>>%c\n",dequeue_node->index, dequeue_node->data);
      free(dequeue_node);
      dequeue_node = NULL;
      printf("+++++++++++++++++++++++++++++\n");
      Traverse_Queue(my_queue);
    }

    
}








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

