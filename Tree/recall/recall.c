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
#include    <math.h>
int my_point[POINT_ARRAY_SIZE];

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



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Turnpike
 *  Description:  回溯算法的驱动代码
 * =====================================================================================
 */
    int
Turnpike ( int point [] , List distance_h,int array_size )
{
    point[0]=0;
    point[array_size] = Get_Max(distance_list);
    Delete(distance_list,point[array]);
    point[array_size-1] = Get_Max(diatance_list);
    Delete(distance_list ,point[array_size-1] );
    if(Check_Ele(distance_list,point[array_size]- point[array_size-1]))
    {
        return Recall(point , distance_list , array_size , 2,array_size-2);
    }
    return -1;
}		/* -----  end of function Turnpike  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Recall
 *  Description:  回溯算法
 * =====================================================================================
 */


int Recall(int point [] , List distance_list , int array_size , int left , int right)
{   
    /*  采用递归来完成 */
    int found=-1;
    int i,j;
    int check1;
    int check2;
    if(List_Empty(distance_list))
        return 1;
    /*  现在检测这条路是否能通 */
    point[right] = Get_Max(distance_list);
    Delete(distance_list , point[right]);
    for(i=1;i<left;i++)
    {
        if(Check_Ele(distance_list , abs(point[right]-point[i]))==0)
        /*  说明现在条件不符合 */
            check1=-1;
    }
    for(j=array_size ; j>right ;j++)
    {
        if(Check_Ele(distance_list , abs(point[right]-point[j]))==0)
            check2=-1;
    }
    if(check1 != -1 && check2 != -1)
    {
        /*  这个是条件满足的情况，要继续向下一深度拓展*/
        found = Recall(point , distance_list , array_size , left , right-1);
        if(found == -1)
            /*  这条路以后的路都走不通 */
            Insert(distance_list , point[right]);
    }
    else
    {
        /*  条件不满的情况 */
        Insert(distance_list, point[right]);
    }
    check1=0;
    check2=0;
    /*  
     *
     *
     *  现在开始尝试另外的一条路
     *
     *
     *  */
    point[left] = Get_Max(distance_list);
    Delete(distance_List, point[left]);
    for(i=1;i<left;i++)
    {
        if(Check_Ele(distance_list , abs(point[left]-point[i]))==0)
            check1=-1;
    }
    for(j=array_size;j>right;j++)
    {
        if(Check_Ele(distance_list,abs(point[left]-point[j]))==0)
            check2=-1;
    }
   if(check1 != -1 && check2!=-1)
   {
        found = Recall(point , distance_list , array_size, left+1,right);
        if(found == -1)
            Insert(distance_list , point[left]);
   }
   else
   {
        Insert(distance_list , point[left]);
   }
   return found;
}
