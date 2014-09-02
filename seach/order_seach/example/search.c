/*
 * =====================================================================================
 *
 *       Filename:  search.c                                                                      
 *                                                      
 *    Description:  这个是成绩查询的实现文件                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月02日 14时06分42秒                       
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
#include "search.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_ST
 *  Description:  初始化查找表
 * =====================================================================================
 */
    ST
Init_ST (  )
{
    ST new_st;

    new_st	= malloc ( sizeof(struct search_table) );
    if ( new_st==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_st->ele = NULL;
    return new_st;

}		/* -----  end of function Init_ST  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_ST
 *  Description:  创建一个查找表
 * =====================================================================================
 */
    void
Create_ST (ST my_st , char * filename )
{
    if(my_st == NULL)
        return;
    if(filename == NULL)
        return;
    FILE * myfile;
    char buf1[20];
    int number;
    int math;
    int pe;
    int english;
    int biology;
    int total;
    int k=1;
    if ((myfile = fopen(filename , "r"))==NULL)
    {
        perror("Open the file failed");
        return;
    }
    /* 首先得到表的元素的大小 */
    if(fgets(buf1 , 20 , my_file)==NULL)
    {
        perror("Get search table size failed");
        return ;
    }
    my_st->length = atoi(buf1);

    my_st->stu_list	= malloc ( sizeof(struct stu_node) * (my_st->lenght+1) );
    if ( my_st->stu_list==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    /* 得到表的实际内容部分 */
    while(fscanf(myfile , "%d %s %d %d %d %d",&number,buf1,&math , &english , &pe , &biology )!=0)
    {
        my_st->stu_list[k].math = math;
        my_st->stu_list[k].english = english;
        my_st->stu_list[k].pe = pe;
        my_st->stu_list[k].biology = biology;
        total = math + english + pe+ biology;
        my_st->stu_list[k].total = total;
        k++;
    }


}		/* -----  end of function Create_ST  ----- */






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

