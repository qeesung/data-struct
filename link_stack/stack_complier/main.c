/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  this is mian file to test my stack conversion
 *
 *        Version:  1.0
 *        Created:  2014年06月22日 06时35分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */



#include	<stdlib.h>
#include	<stdio.h>
#include	"stack.h"
#include	<fcntl.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Stack stack;
	FILE * my_file;
	char input;
	char * temp;
	if(argc!=2)
	{
		fprintf(stderr,"\n the number of the main is error\n ");
		return -1;
	}
	if((my_file=fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr,"\n open the FILE my_file failed \n ");
		return -1;
	}
	stack=Init_Stack();
	while(1)
	{
		if((input=getc(my_file))==EOF)
		{
			if(ferror(my_file))
			{
				fprintf(stderr,"\n read the file :<%s> failed ");
				return -1;
			}
			if(feof(my_file))
			{
				printf("\n +++++++++++complier the file done++++++++++++++ \n");
				break;
			}
		}
		switch(input)
		{
			case '(':
				Push(stack,input);
				break;

			case ')':
				if(*(stack->top)=='(')
				Pop(stack);
				else
				Push(stack,input);
				break;

			case '{':
				Push(stack,input);
				break;

			case '}':
				if(*(stack->top)=='{')
				Pop(stack);
				else
				Push(stack,input);
				break;

			case '<':	
				Push(stack,input);
				break;
			case '>':
				if(*(stack->top)=='<')
				Pop(stack);
				else
				Push(stack,input);
				break;
			default:
				break;
				
		}
		printf("\n+++++++++++++++++\n");
		Print_Stack(stack);
		printf("\n+++++++++++++++++\n\n");

	}
		if(stack->top==stack->base)
		{
			printf("\n++++++++++++++the file is correct++++++++++++++++\n");
		}
		else
		{
			printf("\n+++++++++++++++the file is not correct++++++++++++++\n");
		}

}
