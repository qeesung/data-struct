/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This is a the shunxu search
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 00时47分05秒
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
void Print_Array(int * , int size);
int Search(int * , int ,int);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Search
 *  Description:  
 * =====================================================================================
 */
	int 
Search ( int my_array[], int size, int number )
{
	int i;
	for(i=0;i<size+1;i++)
	{
		if(my_array[i]==number)
		if(i==size)
		{
			return -1;
		}
		else
		{
			return i;
		}

	}

}		/* -----  end of function Search  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Array
 *  Description:  
 * =====================================================================================
 */
	void
Print_Array ( int my_array[], int size )
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t\t", my_array[i]);
	}
	printf("\n");
	return;
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
	int my_array[10]={10,56,34,23,78,34,21,34,29,84};	
	int input;
	Print_Array(my_array,10);
	printf("\n enter the number you wanna search:\n ");
	scanf("%d", &input);
	printf("the number is in : %d \n",Search(my_array,10,input));

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
