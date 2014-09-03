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
    char ch;
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

    my_st->slist	= malloc ( sizeof(struct table_node) * (my_st->length + 1));
    if ( my_st->slist==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    /* 接下来得到表的数据 */
    for(k=1;k<my_st->length+1 ; k++)
    {
        if(fscanf(myfile , "%c %s\n",&ch, buf1)==-1)
        {
            perror("fscanf error");
            return;
        }
        my_st->slist[k].key = ch;
        my_st->slist[k].weight = atoi(buf1);
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
Search_K ( SOStree * my_tree , ST my_st , int sw[] , int left , int right)
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

    *my_tree	= malloc ( sizeof(struct bitree) );
    if ( my_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    (*my_tree)->data = (char)my_st->slist[j].key;
    (*my_tree)->index = j;
    fprintf(stderr,"Get the index %d\n",j);
    if(j == left)
        (*my_tree)->leftchild = NULL;
    else
        Search_K(&((*my_tree)->leftchild), my_st , sw , left , j-1);
    if(j == right)
        (*my_tree)->rightchild = NULL;
    else
        Search_K(&((*my_tree)->rightchild) , my_st , sw , j+1 , right);
}		/* -----  end of function Search_K  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Findsw
 *  Description:  计算权重之和的函数
 * =====================================================================================
 */
    int *
Findsw ( int sw[] , ST my_st )
{
    if(my_st == NULL)
        return NULL;
    int k=0;
    sw[0] = 0;
    for(k=1;k<my_st->length+1;k++)
    {
        sw[k]=sw[k-1] + my_st->slist[k].weight;
    }
    return sw;
}		/* -----  end of function Findsw  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_SOStree
 *  Description:  创建一棵最有查找树
 * =====================================================================================
 */
    void
Create_SOStree ( SOStree * my_tree , ST my_st )
{
    int sw[my_st->length+1];
    if(Findsw(sw , my_st)==NULL)
        return;
    Search_K(my_tree , my_st , sw , 1 , my_st->length);
   /* fprintf(stderr,"#%d---->%c\n",my_tree->index, my_tree->data);
    fprintf(stderr,"#%d---->%c\n",my_tree->leftchild->index, my_tree->leftchild->data);
    fprintf(stderr,"#%d---->%c\n",my_tree->rightchild->index, my_tree->rightchild->data);*/
    if((*my_tree)->leftchild==NULL )
        fprintf(stderr,"leftchild is NULL\n");
    else
        fprintf(stderr,"%d>>>%c\n",(*my_tree)->leftchild->index , (*my_tree)->leftchild->data);
}		/* -----  end of function Create_SOStree  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Search_ST
 *  Description:  查找函数 
 * =====================================================================================
 */
    int
Search_ST ( ST my_st , char key)
{
    if(my_st == NULL)
        return -1;
    SOStree my_tree , temp;
    Create_SOStree(&my_tree , my_st);
    Levelorder_Traverse(my_tree);
    fprintf(stderr, "hello!\n");
    temp = my_tree;
    if(temp == NULL)
    {
        fprintf(stderr,"create sostree failed\n");
    }
    while(1)
    {
        if(temp == NULL)
            return -1;
        if(temp->data == key)
            return temp->index;
        if(temp->data < key)
            temp = temp->rightchild;
        else
            temp = temp->leftchild;
    }
    fprintf(stderr,"moximoxi\n");
    Destory_Bitree(my_tree);
}		/* -----  end of function Search_ST  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Traverse_ST
 *  Description:  遍历有序表
 * =====================================================================================
 */
    void
Traverse_ST ( ST my_st)
{
    int k=0 ;
    for(k=1;k<my_st->length+1;k++)
    {
        printf("#%d+++%c>>>%d\n",k,my_st->slist[k].key , my_st->slist[k].weight);
    }
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

