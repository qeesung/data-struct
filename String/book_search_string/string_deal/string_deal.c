/*
 * =====================================================================================
 *
 *       Filename:  string_deal.c
 *
 *    Description:  string deal c file
 *
 *        Version:  1.0
 *        Created:  2014年07月01日 00时52分11秒
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
#include"string_deal.h"
#include<strig.h>
void Str_Copy(char * str1 , char * str2 , int pos , int length)
{
	int i=0;
	if(pos<0 || length <0 || pos+length > strlen(str2))
	{
		fprintf(stderr, "\n the error usage \n ");
		return ;
	}

	str1	= malloc ( sizeof(char ) * length );
	if ( str1==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	for(i=0;i<length;i++)
	{
		str1[i]=str2[i+length];
	}
	return;
	

}
