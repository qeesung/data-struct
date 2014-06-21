/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  This is the header file for stack ADT
 *
 *        Version:  1.0
 *        Created:  2014年06月22日 04时44分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#ifndef _STACK_H
#define _STACK_H

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

struct Person_node {
	int number ;
	char * name;
};				/* ----------  end of struct Person_node  ---------- */

typedef struct Stack_node {
	struct Person_node * top;
	struct Person_node * base;
	int stack_size;
} * Stack;

/*-----------------------------------------------------------------------------
 *  Init a stack
 *-----------------------------------------------------------------------------*/
 Stack Init_Stack();

 /*-----------------------------------------------------------------------------
  *  Push a element into the Stack
  *-----------------------------------------------------------------------------*/
  void Push(Stack stack, int number , char * name);

  /*-----------------------------------------------------------------------------
   *  pop a element from the stack
   *-----------------------------------------------------------------------------*/
   struct Person_node  Pop(Stack stack);

   /*-----------------------------------------------------------------------------
    *  get the top form the stack
    *-----------------------------------------------------------------------------*/
    struct Person_node Get_Top(Stack stack);


#endif 

