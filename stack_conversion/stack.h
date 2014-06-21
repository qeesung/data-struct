/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  This is a header file
 *
 *        Version:  1.0
 *        Created:  2014年06月22日 06时12分30秒
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
struct Stack_node {
	int * top;
	int * base;
	int stack_size;
};				/* ----------  end of struct stack_node  ---------- */

typedef struct Stack_node  * Stack;

Stack Init_Stack();
void Push(Stack stack);
int Pop(Stack stack);

#endif
