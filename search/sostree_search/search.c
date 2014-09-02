/*
 * =====================================================================================
 *
 *       Filename:  search.c                                                                      
 *                                                      
 *    Description:  静态树表的查找C文件                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月02日 19时46分55秒                       
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
#include "bitree.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Second_Optimal
 *  Description:  创建静态树表的驱动函数
 * =====================================================================================
 */

void Second_Optimal(Bitree my_tree, ST my_st , int left , int right)
{
   int leftsumn;
   int rightsum;
   int k=0;
   int j=left;
   min =prisum(my_set , left , right); 
   for(k=left+1 ;k<right;k++)
   {
        leftsum = prisum(my_set , left , k-1 );
        rightsum = prisum(my_set , k+1 , right);
        if(abs(rightsum - leftsum) < min)
        {
            j = k;
            min = abs(rightsum - leftsum);
        }
   }
   
   my_tree	= malloc ( sizeof(struct my_tree) );
   if ( my_tree==NULL ) {
       fprintf ( stderr, "\ndynamic memory allocation failed\n" );
       exit (EXIT_FAILURE);
   }
    my_tree->data = `my_st->slist[j].key;
   if(j == left)
   {
        my_tree->leftchild=NULL;
   }
   else
       Second_Optimal(my_tree->leftchild , my_st , left , j-1);
   if(j == right)
   {
        my_tree->rightchild =NULL;
   }
   else
       Second_Optimal(my_tree->rightchild , my_st , j+1 , right);
   return;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  prisum
 *  Description:  得到权重之和
 * =====================================================================================
 */
    int
prisum ( ST my_st , int left , int right )
{
    int k=0;
    int sum=0;
    if(left == right)
        return my_st->slist[left].weight;
    for(k=left , k<=rght ;k++)
    {
        sum+=my_st->slist[k].weight
    }
    return sum;
}		/* -----  end of function prisum  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_SOStree
 *  Description:  创建静态树表
 * =====================================================================================
 */
    void
Create_SOStree ( SOStree my_tree , ST my_st )
{
    Second_Optimal(my_tree , my_st , 0 , my_st->length);
}		/* -----  end of function Create_SOStree  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_ST
 *  Description:  通过文件来创建查找表
 * =====================================================================================
 */
    void
Create_ST ( ST my_st , char * filename )
{
    if(my_st == NULL)
        return;
    FILE * myfile;
    char buf1[20];
    char buf2[20];
    if ((myfile = fopen(filename))==NULL)
    {
        perror("Open the file failed");
        return;
    }
    /* 得到对应的查找表的长度 */
    if(fgets(buf1 , 20 , myfile)==NULL)
    {
        perror("Get search table failed");
        return;
    }
    my_st->length = atoi(buf1);
    
    my_st->slist	= malloc ( sizeof(struct st_node) );
    if ( my_st->slist==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    /* 得到表项里面的实际元素 */
    for(k=0;k<my_st->length;k++)
    {
        fscanf(myfile , "%s %s",buf1, buf2 );
        my_st->slist[k].key = atoi(buf1);
        my_st->slist[k].weight = atoi(buf2);
    }
    return ;
}		/* -----  end of function Create_ST  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Search_ST
 *  Description:  查找对应简直元素 
 * =====================================================================================
 */
    void
Search_ST ( ST my_st )
{
    int number;
    SOStree my_tree;
    Create_SOStree(my_tree , my_st  );
    if(my_tree->data)
}		/* -----  end of function Search_ST  ----- */



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

