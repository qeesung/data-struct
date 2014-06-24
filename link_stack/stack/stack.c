/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  this is the c file about the stack
 *
 *        Version:  1.0
 *        Created:  2014年06月22日 04时51分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<stdio.h>
#include"stack.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Stack
 *  Description:  init a stack
 * =====================================================================================
 */
	Stack
Init_Stack ( )
{	
	Stack new_stack;
	
	new_stack	= malloc ( sizeof(struct Stack_node) );
	if ( new_stack==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	new_stack->top	= (struct Person_node * )malloc ( sizeof(struct Person_node ) * STACK_INIT_SIZE );
	if ( new_stack->top==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	new_stack->base=new_stack->top;
	new_stack->stack_size=STACK_INIT_SIZE;
	return new_stack;
	

		
}		/* -----  end of function Init_Stack  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Push
 *  Description:  push a element into the stack
 * =====================================================================================
 */
	void
Push ( Stack stack , int number , char * name)
{
	if(stack->top-stack->base >= stack->stack_size-1)
	{
		
		stack->base	= realloc (stack->base , sizeof(struct Person_node ) * (STACK_INIT_SIZE + STACK_INCREMENT) );
		if ( stack->base==NULL ) {
			fprintf ( stderr, "\ndynamic memory allocation failed\n" );
			exit (EXIT_FAILURE);
		}
		stack->top=stack->base+stack->stack_size-1;
		stack->stack_size+=STACK_INCREMENT;

	}
	stack->top++;
	stack->top->number = number ;
	stack->top->name = name;
	return;
	return;
}		/* -----  end of function Push  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Pop
 *  Description: pop a element from the stack 
 * =====================================================================================
 */
	struct Person_node *
Pop ( Stack stack )
{
	
	struct Person_node * pop_person_node;
	if(stack->base == stack->top)
	{
		fprintf(stderr , "\n can not pop a empty satck\n");
		return NULL;
	}

	pop_person_node	= malloc ( sizeof(struct Person_node) );
	if ( pop_person_node==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	pop_person_node->number = stack->top->number;
	pop_person_node->name = stack->top->name;
	stack->top--;
	return pop_person_node;
}		/* -----  end of function Pop  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Top
 *  Description:  get the top of  stack
 * =====================================================================================
 */
	struct Person_node *
Get_Top ( Stack stack)
{	
	struct Person_node * top_person_node;
	if(stack->base == stack->top)
	{
		fprintf(stderr,"\n here is top \n ");
		return NULL;
	}

	top_person_node	= malloc ( sizeof(struct Person_node) );
	if ( top_person_node==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	top_person_node->number = stack->top->number;
	top_person_node->name=stack->top->name;
	return top_person_node;



	return ;
}		/* -----  end of function Get_Top  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Stack
 *  Description:  print all the element in the stack
 * =====================================================================================
 */
	void
Print_Stack ( Stack stack )
{
	struct Person_node * temp;
	temp=stack->top;
	while(temp!=stack->base)
	{
		printf("the number is %d | the name is %s \n",temp->number , temp->name);
		temp--;
	}
	return;
}		/* -----  end of function Print_Stack  ----- */
