/*
 * =====================================================================================
 *
 *       Filename:  search.h
 *
 *    Description:  超找学生个人成绩的函数
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 14时00分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#pragma once

struct stu_node
{
    long number;
    char name[20];
    int math;
    int english ;
    int pe;
    int biology;
    int total;
};

typedef struct stu_node * STU;
struct search_table
{
    int length;
    STU stu_list;
};
typedef struct search_table * ST;


ST Init_ST(void);
Create_ST(ST , char *);
Destory_ST(ST);
Traverse_ST(ST);
Search_ST(ST , long number):


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

