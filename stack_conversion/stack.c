/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  This is the stack c file
 *
 *        Version:  1.0
 *        Created:  2014年06月22日 06时16分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Stack
 *  Description:  Init a stack
 * =====================================================================================
 */
	Stack
Init_Stack ( )
{
	Stack stack;
	
	stack	= malloc ( sizeof(struct Stack_node) );
	if ( stack==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
		
	stack->base	= malloc ( sizeof(int) * STACK_INIT_SIZE );
	if ( stack->base==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	stack->top=stack->base;
	stack->stack_size=STACK_INIT_SIZE;
	return stack;


}		/* -----  end of function Init_Stack  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Push
 *  Description:  push a number into the satck
 * =====================================================================================
 */
	void
Push ( Stack stack , int number  )
{
	if(stack->top-stack->base >=stack->stack_size-1)
	{
				
		stack->base = (int *)malloc ( sizeof(int ) * (stack->stack_size + STACK_INCREMENT) );
		if ( stack->base==NULL ) {
			fprintf ( stderr, "\ndynamic memory allocation failed\n" );
			exit (EXIT_FAILURE);
		}
		stack->top=stack->base + stack->stack_size-1;
		stack->stack_size+=STACK_INCREMENT;

	}
	stack->top++;
	*(stack->top)=number;
	return;
}		/* -----  end of function Push  ----- */



