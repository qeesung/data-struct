/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  用于回溯算法的链表实现
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 15时55分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */
#ifndef _LIST_H
#define _LIST_H
struct list_node
{   
    int data;
    struct list_node * next;
};
typedef struct list_node * List_node;
typedef List_node List;

void err_msg(char * info);
List Init_List();
void Insert_List(List my_list , int data);
void Delete_List(List my_list , int data);
int List_Empty(List my_list);
int Check_Ele(List my_list , int data);
void Print_List(List my_list);
int Get_Max(List my_list);
void Destory_List(List my_list);
#endif
