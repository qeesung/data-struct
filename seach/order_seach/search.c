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
 *         Name:  Create
 *  Description:  通过filename来创建对应的查找表
 * =====================================================================================
 */
    void
Create ( ST my_st , char * filename)
{
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

