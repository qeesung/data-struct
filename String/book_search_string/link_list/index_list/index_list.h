/*
 * =====================================================================================
 *
 *       Filename:  index_list.h
 *
 *    Description:  this is index_list header file
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 04时59分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */


#ifndef _INDEX_LIST_H
#define _INDEX_LIST_H
#include<stdio.h>

struct index_node {
	int index_number ;
	struct index_node * next;
};				/* ----------  end of struct index_node  ---------- */

typedef struct index_node *  Index_node;
typedef  Index_node Index_list;
typedef Index_list Index_position;

Index_list Init_Index_List();
void Insert_Index_List(Index_list list ,int number );
void Delete_Index_List(Index_list list , int number);
Index_position Find_Index_Position(Index_list list , int number );
void Print_Index_List(Index_list list);
void Write_Index_List( Index_list list);




#endif
