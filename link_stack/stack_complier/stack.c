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
Push ( Stack stack , char number  )
{
	if(stack->top-stack->base >=stack->stack_size-1)
	{
				
		stack->base = (char *)malloc ( sizeof(char ) * (stack->stack_size + STACK_INCREMENT) );
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



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Pop
 *  Description:  pop a number from the stack
 * =====================================================================================
 */
	char
Pop ( Stack stack )
{
	char number ;
	if(stack->top==stack->base)
	{
		fprintf(stderr, "\n can not pop empty stack \n");
		return -1;
	}
	number =*( stack->top);
	stack->top--;
	return;
}		/* -----  end of function Pop  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Stack
 *  Description:  Print all the number  in the stack
 * =====================================================================================
 */
	void
Print_Stack (Stack stack )
{
	char  * temp;
	temp=stack->top;
	while(temp!=stack->base )
	{
		printf("%c\n",*(temp));
		temp--;
	}
	return ;
}		/* -----  end of function Print_Stack  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Clear_Stack
 *  Description:  clear all the char in the stack
 * =====================================================================================
 */
	void
Clear_Stack ( Stack stack )
{
	stack->top=stack->base;
	stack->stack_size=0;
	return ;

}		/* -----  end of function Clear_Stack  ----- */

