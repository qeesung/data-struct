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
	int i;
	char input;
	FILE * my_file;
	char * temp;
	if(argc!=2)
	{
		fprintf(stderr, "\n the number of the main is error \n ");
		return -1;
	}
	stack=Init_Stack();
	while(input!='\n')
	{
		input=getchar();
		switch(input)
		{
			case '#':Pop(stack);
				break;
			case '@':Clear_Stack();
				break;
			default:Push(stack,input);
		}
	}
	/*  now write all the data into the file */
	if((my_file=fopen("./testfile","w+"))==NULL)
	{
		fprintf(stderr,"\n open the FILE my_file failed \n ");
		return -1;
	}
	temp=++stack->base;
	for(i=0;i<stack->stack_size;i++)
	{
		if(putc(*temp,my_file)==EOF)
		{
			fprintf(stderr,"\n write the char failed \n ");
			return -1;
		}
		temp++;
	}
}
