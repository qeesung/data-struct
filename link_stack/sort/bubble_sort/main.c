/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  this is the mian file for the bubble sort
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 00时17分19秒
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
#define ARRAY_SIZE 10



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bubble_Sort
 *  Description:  sort a array
 * =====================================================================================
 */
	void
Bubble_Sort ( int array[], int size )
{
	int i,j;
	int temp;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
	}
	return ;
}		/* -----  end of function Bubble_Sort  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Array
 *  Description:  print a array
 * =====================================================================================
 */
	void
Print_Array ( int array[], int size )
{	
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t\t", array[i]);
	}
	printf("\n ");
	return ;
}		/* -----  end of function Print_Array  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Array
 *  Description:  
 * =====================================================================================
 */
	void
Init_Array ( int array[], int size )
{
	int i=0;
	for(i=0;i<size;i++)
	{
		array[i]=random()%100;
	}
	return ;
}		/* -----  end of function Init_Array  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int my_array[ARRAY_SIZE];
	Init_Array(my_array,ARRAY_SIZE);	
	printf("+++++++++++++++++++++before sort+++++++++++++++\n ");
	Print_Array(my_array,ARRAY_SIZE);
	Bubble_Sort(my_array,ARRAY_SIZE);
	printf("+++++++++++++++++++++after sort+++++++++++++++\n ");
	Print_Array(my_array,ARRAY_SIZE);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

