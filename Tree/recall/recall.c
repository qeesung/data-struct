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
#include    "list.h"
#include    <math.h>

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
Turnpike ( int point [] , List distance_list,int array_size )
{
    point[1]=0;
    point[array_size] = Get_Max(distance_list);
    Delete(distance_list,point[array_size]);
    point[array_size-1] = Get_Max(distance_list);
    Delete(distance_list ,point[array_size-1] );
    if(Check_Ele(distance_list,point[array_size]- point[array_size-1]))
    {
        Delete(distance_list , point[array_size]-point[array_size-1]);
        printf("distance_list:");
        Print_List(distance_list);
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
    int check1=0;
    int check2=0;
    List temp_list=NULL;
    List_node temp_node;
    temp_list = Init_List();
    if(List_Empty(distance_list))
        return 1;
    /*  现在检测这条路是否能通 */
    point[right] = Get_Max(distance_list);
    Delete(distance_list , point[right]);
    printf("LEFT for node %d\n",point[right]);
    for(i=1;i<left;i++)
    {
        printf("LEFT1:ABS:%d\n",abs(point[right]-point[i]));
        if(Check_Ele(distance_list , abs(point[right]-point[i]))==0)
        {
            if(point[right]!=abs(point[right]-point[i]))
            check1=-1;
        }
    }
    for(j=array_size ; j>right ;j--)
    {
        printf("LEFT2:ABS:%d\n",abs(point[right]-point[j]));
        if(Check_Ele(distance_list , abs(point[right]-point[j]))==0)
            check2=-1;
    }
    printf("LEFT:<check1:%d,check2:%d>\n",check1, check2);
    if(check1 != -1 && check2 != -1)
    {
        /*  这个是条件满足的情况，要继续向下一深度拓展*/
        /*  现在需要将符合情况的点全都删除 */
        for(i=1;i<left;i++)
        {
            Insert(temp_list , abs(point[right]-point[i]));
            Delete(distance_list , abs(point[right]-point[i]));
        }
        for(j=array_size ; j>right ;j--)
        {
            Insert(temp_list , abs(point[right]-point[j]));
            Delete(distance_list , abs(point[right]-point[j]));
        }
        printf("!!!LEFT!!!\n");
        printf("temp_list:\n");
        Print_List(temp_list);
        printf("distance_list:\n");
        Print_List(distance_list);
        found = Recall(point , distance_list , array_size , left , right-1);
        if(found == -1)
        {
            /*  这条路以后的路都走不通 */
            temp_node = temp_list;
            while(temp_node->next!=NULL)
            {
                Insert(distance_list, temp_node->next->data);
            }
            Destory_List(distance_list);
        }
    }
    else
    {
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
    point[left] = point[array_size]-Get_Max(distance_list);
    Delete(distance_list,point[left]);
    printf("RIGHT for node:%d\n",point[left]);
    for(i=1;i<left;i++)
    {
        printf("RIGHT1:ABS:%d\n",abs(point[left]-point[i]));
        if(Check_Ele(distance_list , abs(point[left]-point[i]))==0)
            if(point[left]!=abs(point[left]-point[j]))
            check1=-1;
    }
    for(j=array_size;j>right;j--)
    {
        printf("RIGHT2:ABS:%d\n",abs(point[left]-point[j]));
        if(Check_Ele(distance_list,abs(point[left]-point[j]))==0)
            check2=-1;
    }
    printf("RIGHT:<check1:%d,check2:%d>\n",check1, check2);
    /* ************************************* */
   if(found ==-1 && check1 != -1 && check2!=-1)
   {
        for(i=1;i<left;i++)
        {
            Insert(temp_list, abs(point[left]-point[i]));
            Delete(distance_list,abs(point[left]-point[i]));
        }
        for(j=array_size;j>right;j--)
        {
            Insert(temp_list, abs(point[left]-point[j]));
            Delete(distance_list,abs(point[left]-point[j]));
        }
        printf("!!!RIGHT!!!\n");
        printf("temp_list:\n");
        Print_List(temp_list);
        printf("distance_list:\n");
        Print_List(distance_list);
        found = Recall(point , distance_list , array_size, left+1,right);
        if(found == -1)
        {
            temp_node = temp_list;
            while(temp_node->next!=NULL)
                Insert(distance_list , temp_node->next->data);
            Destory_List(temp_list);
        }
   }
   else
    Insert(distance_list , point[left]);
   free(temp_list);
   return found;
}
