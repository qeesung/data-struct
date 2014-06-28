/*
 * =====================================================================================
 *
 *       Filename:  KMP.c
 *
 *    Description:  This is  C file about the KMP
 *
 *        Version:  1.0
 *        Created:  2014年06月29日 05时07分28秒
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
#include"KMP.h"
#include"string.h"

void Set_Next(String string , Next_Array next)
{
	int j=0;
	int i=1;
	next[1]=0;
	while(i<string[0])
	{
		if(i==0 || string[i] == string [j])
		{
			j++;
			i++;
			next[i]=j;
		}
		else
		{
			j=next[j];
		}
	}
}
