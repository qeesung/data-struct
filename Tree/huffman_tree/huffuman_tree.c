/*
 * =====================================================================================
 *
 *       Filename:  huffuman_tree.c
 *
 *    Description:  huffuman tree 的c文件
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 14时49分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include"huffuman_tree.h"
#include<limits.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Min
 *  Description:  得到序号之前的最小的那个序列号
 * =====================================================================================
 */
    int
Get_Min (Huff_tree my_tree , int index )
{
    unsigned int weight = UINT_MAX;
    int k=0;
    int min_index;
    for(k=0;k<index;k++)
    {
        if(my_tree[k].parent==0 && my_tree[k].weight < weight)
        {
            min_index = k;
        }
    }
    my_tree[min_index].parent=1;
    return min_index;
    
}		/* -----  end of function Get_Min  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Select
 *  Description:  选出在树中最小的两个序列号码
 * =====================================================================================
 */
    void
Select (Huff_tree my_tree , int last_index , int * index1 , int * index2 )
{
    int temp;
    *index1 = Get_Min(my_tree , last_index);
    *index2 = Get_Min(my_tree , last_index);
    if(*indx1 < *index2)
    {
        temp = *index2;
        *index2=*index1;
        *index1=temp;
    }
    return ;
}		/* -----  end of function Select  ----- */



