/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This is a the main file to test insert sort
 *
 *        Version:  1.0
 *        Created:  2014年06月24日 23时51分06秒
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
#include	<limits.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Sort
 *  Description:  
 * =====================================================================================
 */
	void
Insert_Sort ( int A[] , int size)
{
	int i,j;// for rotary
	int temp;
	int pos;
	int min=INT_MAX;
	for(i=0;i<size-1;i++)
	{
		min=INT_MAX;
		for(j=i;j<size;j++)
		{
			/*  find the minist number after i */
			if(min > A[j])
			{
				min=A[j];
				pos=j;
			}
		}
		temp=A[i];
		A[i]=A[pos];
		A[pos]=temp;
	}
	return ;
}		/* -----  end of function Insert_Sort  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Array
 *  Description:  
 * =====================================================================================
 */
	void
Init_Array ( int A[], int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		A[i]=random()%100;
	}
	return ;
}		/* -----  end of function Init_Array  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Array
 *  Description:  
 * =====================================================================================
 */
	void
Print_Array ( int A[], int size )
{
	int i=0;
	for(i=0;i<size;i++)
	{
		printf("%d\t\t",A[i]);
	}
	printf("\n ");
	return ;
}		/* -----  end of function Print_Array  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int my_array[10];
	Init_Array(my_array, 10);
	printf("before the sort\n");
	Print_Array(my_array,10);
	Insert_Sort(my_array, 10);
	printf("after the sort\n ");
	Print_Array(my_array, 10);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

