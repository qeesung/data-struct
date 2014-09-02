/*
 * =====================================================================================
 *
 *       Filename:  search.h
 *
 *    Description:  有序表的头文件
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 16时23分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#pragma once

struct search_table
{
    int * slist;
    int length;
};

typedef struct search_table * ST;

ST Init_ST(void);
void Create_ST(ST my_st , char * filename);
void Destory_ST(ST my_st);
int Search_ST(ST my_st , int key);
void Traverse_ST(ST my_st);
int Search_K(ST my_st , int left , int right , int data);








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

