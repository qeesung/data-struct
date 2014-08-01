/*
 * =====================================================================================
 *
 *       Filename:  recall.c
 *
 *    Description:  回溯算法C文件
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 15时51分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */
#include    <stdio.h>
#include    <stdlib.h>
#include    "recall.h"
#include    <list.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  void Init_Distance_List
 *  Description:  将初始值赋值链表
 * =====================================================================================
 */
void Init_Distance_List ( List distance_list )
{
    Insert_List(distance_list , 1);
    Insert_List(distance_list , 2);
    Insert_List(distance_list , 2);
    Insert_List(distance_list , 2);
    Insert_List(distance_list , 3);
    Insert_List(distance_list , 3);
    Insert_List(distance_list , 3);
    Insert_List(distance_list , 4);
    Insert_List(distance_list , 5);
    Insert_List(distance_list , 5);
    Insert_List(distance_list , 5);
    Insert_List(distance_list , 6);
    Insert_List(distance_list , 7);
    Insert_List(distance_list , 8);
    Insert_List(distance_list , 10);
}		/* -----  end of function void Init_Distance_List  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete
 *  Description:  将链表里面的一个元素删除
 * =====================================================================================
 */
    void
Delete ( List distance_list , int data )
{
    Delete_List(distance_list , data);
    return ;
}		/* -----  end of function Delete  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert
 *  Description:  在链表里面插入一个数据
 * =====================================================================================
 */
    void
Insert ( List distance_list , int data )
{
    Insert_List(distance_list , data);
    return;
}		/* -----  end of function Insert  ----- */
