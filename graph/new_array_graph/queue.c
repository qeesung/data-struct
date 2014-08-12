/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  this is queue c file
 *
 *        Version:  1.0
 *        Created:  2014年07月25日 22时59分01秒
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
#include"queue.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Queue
 *  Description:  init q queue
 * =====================================================================================
 */
    Queue
Init_Queue ( )
{
    Queue new_queue;

    new_queue	= malloc ( sizeof(struct queue) );
    if ( new_queue==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    /*  create list header */ 
    new_queue->queue_list	= malloc ( sizeof(struct list_node) );
    if ( new_queue->queue_list==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_queue->front = new_queue->queue_list;
    new_queue->rear = new_queue->queue_list;
    return new_queue;
}		/* -----  end of function Init_Queue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Enqueue
 *  Description:  enqueue a data with index
 * =====================================================================================
 */
    void
Enqueue ( Queue my_queue , int index )
{
    List_node new_node;
    if(my_queue==NULL)
    {
        fprintf(stderr, "\n the queue have not init \n ");
        return ;
    }
    
    new_node	= malloc ( sizeof(struct list_node) );
    if ( new_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_node->index= index;
    my_queue->rear->next=new_node;
    my_queue->rear=new_node;
    return ;
}		/* -----  end of function Enqueue  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Dequeue
 *  Description:  dequeue function
 * =====================================================================================
 */
    List_node
Dequeue ( Queue my_queue )
{
    List_node dequeue_node=NULL;
    if(my_queue == NULL)
    {
        fprintf(stderr, "\n the queue have not init \n ");
        return NULL;
    }
    if(my_queue->front == my_queue->rear)
    {
        fprintf(stderr, "\n the queue is empty\n");
        return NULL; 
    }

    if(my_queue->front->next == my_queue->rear)
    {
        dequeue_node = my_queue->rear;
        my_queue->rear= my_queue->front;
        return dequeue_node;
    }
    dequeue_node= my_queue->front->next;
    my_queue->front->next=dequeue_node->next;
    return dequeue_node;
}		/* -----  end of function Dequeue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Queue
 *  Description:  print a queue all detail massge
 * =====================================================================================
 */
    void
Print_Queue( Queue my_queue)
{
    List_node temp;
    if(my_queue==NULL ||  my_queue->front==my_queue->rear)
    {
        return ;
    }
    temp=my_queue->front;
    while(temp->next!=NULL)
    {
        printf("< ++ index:%d>\n", temp->next->index);
        temp = temp->next;
    }
    return ;
}		/* -----  end of function Print_Queue  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_List
 *  Description:  在链表里面插入一个元素
 * =====================================================================================
 */
    void
Insert_List ( List my_list , int index )
{
    List_node new_node;
    List_node temp;
    if(my_list == NULL)
    {
        fprintf(stderr, "\nThe list have not init\n");
        return;
    }
    
    new_node	= malloc ( sizeof(struct list_node) );
    if ( new_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_node->index = index;
    new_node->next == NULL;
    temp = my_list->next;
    my_list->next = new_node;
    my_list->next->next = temp;
    return;
}		/* -----  end of function Insert_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_List
 *  Description:  在链表里面删除一个元素
 * =====================================================================================
 */
    void
Delete_List ( List my_list , int index )
{
    List_node temp;
    if(my_list == NULL)
    {
        fprintf(stderr,"\nthe list have not init\n");
        return;
    }
    while(my_list->next!=NULL && my_list->next->index !=index)
    {
        my_list = my_list->next;
    }
    if(my_list->next==NULL)
        return;
    temp = my_list->next->next;
    free(my_list->next);
    my_list->next = temp;
    return;

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
    if(my_list->next== NULL)
        return 1;
    else
        return 0;
}		/* -----  end of function List_Empty  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_List
 *  Description:  初始化一个链表
 * =====================================================================================
 */
    List
Init_List (  )
{
    List new_list;

    new_list	= malloc ( sizeof(struct list_node) );
    if ( new_list==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_list->next == NULL;
    return new_list;

}		/* -----  end of function Init_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  In_List
 *  Description:  检测一个元素是否在链表中
 * =====================================================================================
 */
    int
In_List ( List my_list, int index)
{
    if(my_list == NULL)
    {
        fprintf(stderr, "\nThe list have not init\n");
        return -1;
    }
    while(my_list->next!=NULL && my_list->next->index !=index)
    {
        my_list = my_list->next;
    }
    if(my_list->next== NULL)
        return 0;
    else
        return 1;
}		/* -----  end of function In_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_List
 *  Description:  打印链表
 * =====================================================================================
 */
    void
Print_List ( List my_list )
{
    if(my_list == NULL)
    {
        fprintf(stderr, "The list have not init\n");
        return;
    }
    while(my_list->next!=NULL)
    {
        printf("---->%d",my_list->next->index);
        my_list=my_list->next;
    }
    printf("\n");
    return;
}		/* -----  end of function Print_List  ----- */
