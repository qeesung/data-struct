/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  this is main.c for me test char * and char [];
 *
 *        Version:  1.0
 *        Created:  2014年06月26日 00时56分12秒
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

void main()
{
	char name[10] = {'1','2', '3' , '4', '5', '6', '7', '8','9'};
	char * string = name;
	printf("%s\n",string);
}


