/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  回溯算法链表的C文件
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 15时59分55秒
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
#include    "list.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  err_msg
 *  Description:  打印错误信息
 * =====================================================================================
 */
    void
err_msg ( char * msg)
{
    fprintf(stderr,msg);
    exit(EXIT_FAILURE);
}		/* -----  end of function err_msg  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_List
 *  Description:  初始化链表， 创建表头
 * =====================================================================================
 */
    List
Init_List ( )
{
    List new_list ;

    new_list	= malloc ( sizeof(struct list_node) );
    if ( new_list==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    return new_list;
}		/* -----  end of function Init_List  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_List
 *  Description:  将一个元素按照升序插入到链表中
 * =====================================================================================
 */
    void
Insert_List (List my_list , int data)
{
    List_node temp;
    List_node new_node;
    if(my_list == NULL)
        err_msg("\n list have not init\n");
    
    new_node	= malloc ( sizeof(struct list_node) );
    if ( new_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_node->data = data;

    while(my_list->next!=NULL && my_list->next->data < data)
    {
       my_list = my_list->next; 
    }
    temp = my_list->next;
    my_list->next = new_node;
    my_list->next->next = temp;// insert done
}		/* -----  end of function Insert_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_List
 *  Description:  将列表里面的一个删除
 * =====================================================================================
 */
    void
Delete_List ( List my_list , int data )
{
    List_node temp;
    if(my_list == NULL)
        err_msg("\nlist have not init\n");
    while(my_list->next!=NULL && my_list->next->data !=data)
    {
        my_list = my_list ->next;
    }
    if(my_list->next == NULL)
    {
        fprintf(stderr,"\ncan not find node %d\n",data);
        return;
    }
    temp = my_list->next->next;
    free(my_list->next);
    my_list->next = temp;
    // delete done
}		/* -----  end of function Delete_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  List_Empty
 *  Description:  检测链表是否为空
 * =====================================================================================
 */
    int
List_Empty ( List my_list )
{
    if(my_list == NULL)
        err_msg("\nlist hav enot init\n");
    if(my_list->next == NULL)
        return 1;
    else
        return 0;
}		/* -----  end of function List_Empty  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Check_Ele
 *  Description:  检测元素是否在链表中， 并且返回元素个数
 * =====================================================================================
 */
    int
Check_Ele (List my_list, int data )
{
    int count=0;
    if(my_list == NULL)
        err_msg("\nlist have not init\n");
    while(my_list->next!=NULL)
    {
        if(my_list->next->data == data)
            count++;
        my_list = my_list->next;
    }
    return count;
}		/* -----  end of function Check_Ele  ----- */
