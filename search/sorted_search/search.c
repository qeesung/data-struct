/*
 * =====================================================================================
 *
 *       Filename:  search.c                                                                      
 *                                                      
 *    Description:  有序表的查找C文件                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月02日 16时32分15秒                       
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
 *  Description:  初始化有序表
 * =====================================================================================
 */
    ST
Init_ST ( void )
{
    ST new_st;
    new_st	= (ST)malloc ( sizeof(struct search_table) );
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
 *  Description:  通过filename来创建查找表
 * =====================================================================================
 */
    void
Create_ST ( ST my_st , char * filename )
{
    if (my_st == NULL || filename == NULL)
        return;
    FILE * myfile;
    char buf1[20];
    int k;
    if ((myfile =fopen(filename , "r"))==NULL)
    {
        perror("Open the file failed");
        return ;
    }
    /* 得到有序表的元素个数 */
    if(fgets(buf1,20 , myfile)==NULL)
    {
        perror("Get the search table size failed");
        return ;
    }
    my_st->length = atoi(buf1);

    my_st->slist	= malloc ( sizeof(int) * my_st->length );
    if ( my_st->slist==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    /* 先面得到实际数据内容 */
    for(k = 0; k<my_st->length ;k++)
    {
        fgets(buf1 , 20 , myfile);
        my_st->slist[k]=atoi(buf1);
    }
    
}		/* -----  end of function Create_ST  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_ST
 *  Description:  销毁函数
 * =====================================================================================
 */
    void
Destory_ST ( ST my_st )
{
    if(my_st == NULL)
        return;
    free(my_st->slist);
    free(my_st);
    my_st =NULL;
    return ;
}		/* -----  end of function Destory_ST  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Search_ST
 *  Description:  查找函数
 * =====================================================================================
 */
    int
Search_ST (ST my_st, int key )
{
    return Search_K(my_st , 0 , my_st->length-1 , key);
}		/* -----  end of function Search_ST  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Search_K
 *  Description:  这个是查找函数的驱动函数 
 * =====================================================================================
 */
    int
Search_K ( ST my_st , int left , int right, int data )
{
    /* 这里采用二分法来实现有序查找的功能 */
    if(left > right)
        return -1;
    int mid = (left + right)/2;
    if(my_st->slist[mid]==data)
        return  mid;
    if(my_st->slist[mid] > data)
        return Search_K(my_st , left , mid-1 , data );
    else
        return Search_K(my_st , mid+1 , right , data);

}		/* -----  end of function Search_K  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Traverse_ST
 *  Description:  遍历有序表
 * =====================================================================================
 */
    void
Traverse_ST (ST my_st)
{
    if(my_st == NULL)
        return;
    int k=0;
    for(k =0 ; k< my_st->length ;k++)
    {
        printf("#%d>>>%d\t",k , my_st->slist[k]);
    }
    return ;
}		/* -----  end of function Traverse_ST  ----- */



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

