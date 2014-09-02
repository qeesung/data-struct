/*
 * =====================================================================================
 *
 *       Filename:  search.c                                                                      
 *                                                      
 *    Description:  顺序查找的C文件                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月02日 12时48分59秒                       
 *       Revision:  none                                
 *       Compiler:  gcc                                 
 *                                                          
 *         Author:  qeesung (), 1245712564@qq.com     
 *   Organization:  Stay hangry , Stay foolish                      
 *                                                              
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_ST
 *  Description:  初始化查找表
 * =====================================================================================
 */
    ST
Init_ST ( void )
{
    ST new_st;

    new_st	= malloc ( sizeof(struct search_table) );
    if ( new_st==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_st->ele= NULL;
    return search_table;

}		/* -----  end of function Init_ST  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create
 *  Description:  通过filename来创建对应的查找表
 * =====================================================================================
 */
    void
Create ( ST my_st , char * filename)
{
    if(my_st == NULL)
    {
        fprintf(stderr,"The search table have not init\n");
        return;
    }
    if(filename == NULL)
    {
        fprintf(stderr,"can not find the file!\n");
        return ;
    }
    FILE * my_file;
    char ch;
    char buf[512];
    int number;
    int k=1;
    if ((my_file = fopen(filename , "r"))==NULL)
    {
        perror("Open the file failed\n");
        return ;
    }
    if(fgets(buf , 512 , my_file)==NULL)
    {
        fprintf(stderr,"Get search table size failed\n");
        return ;
    }
    number = atoi(buf);
    my_st->length = number;

    my_st->ele	= malloc ( sizeof(sizeof(int) * (number+1)) );
    if ( my_st->ele==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    /* 首先得到表的大小 */
    for(k=1;k<number+1;k++)
    {
        if(fgets(buf , 512 , my_file)==NULL)
        {
            perror("read the file failed\n");
            return ;
        }
        my_st->ele[k] = atoi(buf);
    }
    return ;

}		/* -----  end of function Create  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory
 *  Description:  摧毁一个表
 * =====================================================================================
 */
    void
Destory (ST my_st)
{
    if(my_st == NULL)
    return;
    free(my_st->ele);
    my_st->ele = NULL;
    free(my_st);
    my_st = NULL;
    return;
}		/* -----  end of function Destory  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Search
 *  Description:  查找一个元素
 * =====================================================================================
 */
    int
Search (ST my_st , int key )
{
    if(my_st == NULL)
        return -1;
    int k;
    my_st->ele[0]=key;
    for(k=my_st->length ; key!=my_st->ele[k];k--);
    return k;
}		/* -----  end of function Search  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Traverse
 *  Description:  遍历查找表
 * =====================================================================================
 */
    void
Traverse ( ST my_st )
{
    if(my_st == NULL)
        return;
    int k=0;
    for(k=1;k<my_st->length ;k++)
    {
        printf("#%d>>>%d\t" ,k , my_st->ele[k]);
    }
    return ;
}		/* -----  end of function Traverse  ----- */







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

