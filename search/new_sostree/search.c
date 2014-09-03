/*
 * =====================================================================================
 *
 *       Filename:  search.c                                                                      
 *                                                      
 *    Description:  查找表的C文件                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月03日 14时32分40秒                       
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
#include <unistd.h>
#include "bitree.h"
#include "search.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_ST
 *  Description:  初始化一个顺序查找表
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
    new_st->slist = NULL;
    return new_st;
}		/* -----  end of function Init_ST  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_ST
 *  Description:  从一个文件来创建一个顺序表
 * =====================================================================================
 */
    void
Create_ST ( ST my_st , char * filename)
{
    if (my_st == NULL || filename == NULL)
    {
        return;
    }
    FILE * myfile;
    char buf1[20];
    char buf2[20];
    int k;
    if ((myfile = fopen(filename , "r"))==NULL)
    {
        perror("Open the file FILE failed");
        return ;
    }
    /* 首先得到表的长度 */
    if (fgets(buf1 , 20 , myfile)==NULL)
    {
        perror("Get search table size failed");
        return;
    }
    my_st->length = atoi(buf1);

    new_st->slist	= malloc ( sizeof(struct table_node) );
    if ( new_st->slist==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    /* 接下来得到表的数据 */
    for(k=0;k<my_st->length ; k++)
    {
        if(fscanf(myfile , "%s %s",buf1 , buf2)==NULL)
        {
            perror("fscanf error");
            return;
        }
        my_st->slist[k].key = (char)atoi(buf1);
        my-st->slist[k].weight = atoi(buf2);
    }
}		/* -----  end of function Create_ST  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_ST
 *  Description:  摧毁一个表
 * =====================================================================================
 */
    void
Destory_ST ( ST my_st)
{
    if (my_st == NULL)
        return;
    free(my_st->slist);
    my_st->slist = NULL;
    free(my_st);
    my_st = NULL;
    return;
}		/* -----  end of function Destory_ST  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Search_K
 *  Description:  搜寻算法的核心算法
 * =====================================================================================
 */
    void
Search_K ( SOStree my_tree , ST my_st , int sw[] , int left , int right)
{
    if(my_st == NULL)
        return;
    if(left > right)
        return;
    int temp;
    int min;
    int k=0;
    int j=left;
    min = sw[right]-sw[left];
    temp = sw[right] + sw[left-1];
    for(k = left ; k<=right ;k++)
    {
        if(min > abs(temp - sw[k]-sw[k-1]))
        {
           j = k;
           min = abs(temp-sw[k]-sw[k-1]);
        }
    }

    my_tree	= malloc ( sizeof(struct bitree) );
    if ( my_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    my_tree->data = (char)my_st->slist[j].key;
    my_tree->index = j;
    if(j == left)
        my_tree->leftchild = NULL;
    else
        Search_K(my_tree->leftchild, my_st , sw , left , j-1);
    if(j == right)
        my_tree->rightchild = NULL;
    else
        Search_K(my_tree->rightchild , my_st , sw , j+1 , right);
}		/* -----  end of function Search_K  ----- */





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

