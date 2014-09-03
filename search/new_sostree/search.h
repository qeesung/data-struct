/*
 * =====================================================================================
 *
 *       Filename:  saerch.h
 *
 *    Description:  定义查找表的结构与函数的定义
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 14时18分52秒
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
struct table_node
{
    char key;
    int weight;
};

struct search_table
{
    struct table_node * slist;
    int length;
};
typedef struct search_table * ST;
typedef Bitree SOStree;
ST Init_ST();
void Create_ST(ST my_st , char * filename);
void Destory_ST(ST my_st);
int Search_K(SOStree my_tree , ST my_st ,int sw[] ,  int left ,int right);
int Search_ST(ST my_st , char key);
int * Findsw(int sw[], ST my_st);
void Ceaete_SOStree(SOStree my_tree , ST my_st);
void Traverse_ST(ST my_st);

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

