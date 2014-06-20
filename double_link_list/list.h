/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  This header file is for double link list
 *
 *        Version:  1.0
 *        Created:  2014年06月20日 23时15分06秒
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

struct Listnode {
	int number ;
	struct Listnode * next;/*  point to next element */
	struct Listnode * prior;/*  ponter to last element */
};				/* ----------  end of struct Listnode  ---------- */

typedef struct Listnode * List;
typedef List Position;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_List
 *  Description:  create a empty list
 * =====================================================================================
 */
	List
Create_List ();

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_List
 *  Description:  insert a element into the list
 * =====================================================================================
 */
	void
Insert_List (List list ,Position index , int number ); 

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_List
 *  Description:  delete a element form the list
 * =====================================================================================
 */
	void
Delete_List (List list , int number); 



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_List
 *  Description:  print all the element in the list
 * =====================================================================================
 */
	void
Print_List ( List list);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Position
 *  Description:  Find a pointer that pointer the number is number 
 * =====================================================================================
 */
	Position
Find_Position ( List list , int number  );

#endif
