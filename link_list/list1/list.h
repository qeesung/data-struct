/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  This is list.h file that will define some function
 *        Version:  1.0
 *        Created:  2014年06月19日 05时10分45秒
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
	int number;
	char * name;
	struct Listnode * next;
};				/* ----------  end of struct Listnode  ---------- */

typedef struct Listnode * List;
typedef List Position;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_List
 *  Description:  create a empty List with header
 * =====================================================================================
 */
List Create_List(void);
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_List
 *  Description:  insert a element into the List
 * =====================================================================================
 */
void Insert_List(List list,Position pos,int number,char * name);
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_List
 *  Description:  delete a element from the list
 * =====================================================================================
 */
void Delete_List(List list,Position pos);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Position
 *  Description:  Find a position with given number and name
 * =====================================================================================
 */
Position Find_Position(List list , int number ,char * name);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_List
 *  Description:  print all the element in the list
 * =====================================================================================
 */

void Print_List ( List list );
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_All_List
 *  Description:  
 * =====================================================================================
 */

void Delete_All_List (List list  );
#endif
