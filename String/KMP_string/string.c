/*
 * =====================================================================================
 *
 *       Filename:  string.c
 *
 *    Description:  C file for my string
 *
 *        Version:  1.0
 *        Created:  2014年06月29日 04时50分19秒
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
 *         Name:  Init_String
 *  Description:  init a string with msg
 * =====================================================================================
 */
	void
Init_String (String string ,char * msg )
{
	int i=0;
	int j=1;
	if(msg==NULL)
	{
		fprintf(stderr,"\n the msg is empty \n ");
		return ;
	}
	
	string	= malloc ( sizeof(char )  * STR_MAX_SIZE);
	if ( string==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	while(j<STR_MAX_SIZE && msg[i]!='\0')
	{
		string[j]=msg[i];
		i++;
		j++;
	}
	string[0]=i;// store the string size;
	return ;
}		/* -----  end of function Init_String  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Index_Kmp
 *  Description:  index a string in mode string with KMP
 * =====================================================================================
 */
	int
Index_Kmp ( String string1 , String string2 )
{
	return ;
}		/* -----  end of function Index_Kmp  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_String
 *  Description:  print a string
 * =====================================================================================
 */
	void
Print_String ( String string )
{
	int i;
	if(string[0]==0)
	{
		return ;
	}
	for(i=1;i<=string[0],i++)
	{
		printf("%c", string[i]);
	}
	printf("\n ");
	return ;
}		/* -----  end of function Print_String  ----- */
