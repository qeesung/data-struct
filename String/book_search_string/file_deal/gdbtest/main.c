/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月01日 04时43分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#include<stdio.h>


int func(int n)
{
	int i=0;
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=i;
	}

	return sum;
	
}

int main()
{
	int i;
	int result=0;
	for(i=0;i<100;i++)
	{
		result+=100;
	}
	printf("the result form [0-100] is : %d \n ", result);
	printf("the result form [0-250] is : %d \n ", func(250));
}
