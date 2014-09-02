/*
 * =====================================================================================
 *
 *       Filename:  search.h
 *
 *    Description:  这是是静态树表的头文件
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 19时36分19秒
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
struct st_node
{
    int key;
    int weight;
};
typedef struct st_node * ST_node;
struct search_table
{
    struct st_node * slist;
    int length;
};
typedef Bitree SOStree;

void Second_Optimal(SOStree my_tree , ST my_st , int sw[] , int low , int high);
void Find_SW(ST my_st);
void Create_SOStree(SOStree my_tree , ST my_st);
int Search_ST(SOStree my_tree , int key);
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

