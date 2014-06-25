/*
 * =====================================================================================
 *
 *       Filename:  string.c
 *
 *    Description:  This is a c file about the array string
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 23时21分49秒
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
#include"string.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Concat
 *  Description:  merge two stringd into a new string
 * =====================================================================================
 */
	int
Concat (String merge_string, String string1 , String string2 )
{
	int str1_len,str2_len;
	int i,j;
	str1_len=Str_Length(string1);
	str2_len=Str_Length(string2);
	/*  class 1 */
	if(str1_len+str2_len<=MAXSTRLEN)
	{
		for(i=0;i<str1_len;i++)
		{
			merge_string[i]=string1[i];
		}
		for(j=0;j<str2_len;j++)
		{
			merge_string[j+i]=string2[j];
		}
		return 1;
	}
	/*  class 2 */
	if(str1_len+str2_len>MAXSTRLEN)
	{
					
		for(i=0;i<str1_len;i++)
		{
			merge_string[i]=string1[i];
		}
		for(j=0;j<MAXSTRLEN;j++)
		{
			merge_string[j+i]=string2[j];
		}
		return 1;
	}
	/*  class 3 */
	if(str1_len==MAXSTRLEN)
	merge_string=string1;
	return 1;
}		/* -----  end of function Concat  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Str_Length
 *  Description:  count the length of a string
 * =====================================================================================
 */
	int
Str_Length ( String string )
{
	int length=0;
	while(string[length]!='\0')
	{
		length++;
	}
	return length;
}		/* -----  end of function Str_Length  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_String
 *  Description:  print a string 
 * =====================================================================================
 */
	void
Print_String ( String string )
{
	int i=0;
	while(string[i]!='\0')
	{
		printf("%c", string[i]);
		i++;
	}
	printf("\n");

	return ;
}		/* -----  end of function Print_String  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Input_String
 *  Description:  input for a string
 * =====================================================================================
 */
	void
Input_String (String string )
{
	char c;
	unsigned char i=0;
	while((c=getc(stdin))!='\n')
	{
		string[i]=c;
		i++;
	}
	return;
}		/* -----  end of function Input_String  ----- */
