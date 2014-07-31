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
 *         Name:  Random_Weight
 *  Description:  
 * =====================================================================================
 */
    int *
Random_Weight ( )
{
    int * weight_array;
    int k=0;
    weight_array	= malloc ( sizeof(int) * 5 );
    if ( weight_array==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    weight_array[0]=3;
    weight_array[1]=1;
    weight_array[2]=4;
    weight_array[3]=5;
    weight_array[4]=2;
    return weight_array;
}		/* -----  end of function Random_Weight  ----- */

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



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Hufftree
 *  Description:  创建一颗huffuman tree
 * =====================================================================================
 */
    void
Create_Hufftree ( Huff_tree my_tree , Huff_code my_code , int * weight_array , int char_number )
{
   
    int node_number = 2*char_number -1;
    int k=0;
    int min_index1;
    int min_index2;
    char code_buf[char_number];
    int start_index;
    int parent_temp;
    int child_temp;
    Huff_tree temp;
    my_tree	= malloc ( sizeof(struct huff_tree) *(node_number+1) );
    if ( my_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    temp = my_tree;
    /*  将树初始化 */
    for(k=1;k<char_number+1;k++)
    {
        temp[k]={weight_array[k-1], 0 ,0,0};
    }
    for(;k<node_numberi+1;k++)
    {
        temp[k]={0,0,0,0};
    }
    /* 现在开始建立树 */
    for(k=char_number+1;k<node_number+1;k++)
    {
        Select(my_tree , k-1 , &min_index1, &min_index2);
        my_tree[min_index1].panrent = k ;
        my_tree[min_index2].panrent = k ;
        my_tree[k].leftchild = min_index1;
        my_tree[k].rightchild = min_index2;
        my_tree[k].weight = my_tree[min_index1].weight + my_tree[min_index2].weight;
    }
    /*  从叶子向根求huffuman编码 */
    for(k=1;k<char_number+1;k++)
    {
        start_index = char_number-1;
        code_buf[start_index]='\0';
        parent_temp  = my_tree[k].parent;
        child_temp = k;
        while(parent_temp!=0)
        {
            if(my_tree[parent_temp].leftchild == child_temp )
                code_buf[--start_idnex]='0';
            if(my_tree[parent_temp].rightchild == child_temp )
                code_buf[--start_index]='1';
            child_temp = parent_temp;
            parent_temp = my_tree[parent_temp].parent;
        }


        my_code[k]	= malloc ( sizeof(char) *(char_number - start_index)  );
        if ( my_code[k]==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        strcpy(my_code[k], &code_buf[start_index]);
    }
    return ;

}
