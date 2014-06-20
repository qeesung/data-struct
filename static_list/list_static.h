/*
 * =====================================================================================
 *
 *       Filename:  list_static.h
 *
 *    Description:  use array to complete the List
 *
 *        Version:  1.0
 *        Created:  2014年06月20日 05时30分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */
#ifndef _LIST_H
#define _LIST_H
#define MAXSIZE 100/* define the array size */

struct listnode { 
	int number;
	char * name;
	int next;/* pointn to next element */
};				/* ----------  end of struct listnode  ---------- */


struct list_ele {
	struct listnode data[MAXSIZE];
	int size;
} ;			/*----------  end of struct List  ---------- */
typedef struct list_ele * List;

/*-----------------------------------------------------------------------------
 *  init the list
 *-----------------------------------------------------------------------------*/
void Init_List(List list);


/*-----------------------------------------------------------------------------
 *  insert the element into the list
 *-----------------------------------------------------------------------------*/

void Insert_List(List list, int number ,char * name);


/*-----------------------------------------------------------------------------
 *  delete a element from the list
 *-----------------------------------------------------------------------------*/
void Delete_List(List list , int index);


/*-----------------------------------------------------------------------------
 *  merge two lists with the mode (A-B)U(B-A)
 *-----------------------------------------------------------------------------*/

void  Merge_List(List list1 , List list2);


/*-----------------------------------------------------------------------------
 *  malloc a node for new data  and return the ponter
 *-----------------------------------------------------------------------------*/
 int Malloc_List(List list);


 /*-----------------------------------------------------------------------------
  *  Free a node in the list 
  *-----------------------------------------------------------------------------*/
  void Free_List(List list,int k);/*  delete the node k from the list */
  /*-----------------------------------------------------------------------------
   *  print all the message in the list
   *-----------------------------------------------------------------------------*/

void Print_List(List list);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_All_List
 *  Description:  
 * =====================================================================================
 */
	void
Delete_All_List (List list );
#endif

