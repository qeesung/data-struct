/*
 * =====================================================================================
 *
 *       Filename:  bitree.c                                                                      
 *                                                      
 *    Description:  二叉树的实现文件                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月03日 14时28分40秒                       
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
#include "bitree.h"
#include "queue.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_Bitree
 *  Description:  销毁一颗二叉树
 * =====================================================================================
 */
    void
Destory_Bitree ( Bitree my_tree )
{
    if(my_tree == NULL)
        return;
    Bitree temp1, temp2;
    temp1 = my_tree->leftchild;
    temp2 = my_tree->rightchild;
    free(my_tree);
    my_tree=NULL;
    Destory_Bitree(temp1);
    Destory_Bitree(temp2);
    return;
}		/* -----  end of function Destory_Bitree  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Levelorder_Traverse
 *  Description:  层序遍历函数
 * =====================================================================================
 */
    void
Levelorder_Traverse ( Bitree my_tree )
{
    if(my_tree == NULL)
        return;
    Queue my_queue;
    my_queue = Init_Queue();
    Bitree dequeue_node;
    Enqueue(my_queue , my_tree);
    while((dequeue_node = Dequeue(my_queue))!=NULL)
    {
    //    Traverse_Queue(my_queue);
        printf("#%d>>>%c\n",dequeue_node->index , dequeue_node->data);
        fflush(stdout);
        if(dequeue_node->leftchild != NULL)
            Enqueue(my_queue, dequeue_node->leftchild);
        if(dequeue_node->rightchild !=NULL)
            Enqueue(my_queue , dequeue_node->rightchild);
    }
    return;
}		/* -----  end of function Levelorder_Traverse  ----- */






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

