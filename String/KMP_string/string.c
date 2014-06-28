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
#include"KMP.h"

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
	
/*  	string	= malloc ( sizeof(char )  * STR_MAX_SIZE);
	if ( string==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	} */

	while(j<STR_MAX_SIZE && msg[i]!='\0')
	{
		string[j]=msg[i];
		i++;
		j++;
	}
	string[j]=msg[i];
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
	Next_Array my_next;
	int i , j;
	if(string2[0]==0)
	{
		fprintf(stderr,"\n the string2 is empty \n ");
		return -1;
	}
	if(string1[0]==0)
	{
		fprintf(stderr, "\n can not find the %s \n ", string2);
		return -1;
	}


	/* set string2 next array  */
	Set_Next(string2 , my_next);
	printf("\n ++++++++++++the next_array+++++++++\n");
	for(i=1;i<string2[0];i++)
	{
		printf("%d\t",my_next[i]);
	}
	fflush(stdout);
	/*  start to get index */
	i=1;
	j=1;
	while(i<=string1[0] && j<=string2[0])
	{
		if(j==1 || string1[i]==string2[j])
		{
			i++;
			j++;
		}
		else
		j=my_next[j];
	
	}
	if(j>string2[0])
	return i-string2[0];
	else
	return -1;

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
		fprintf(stderr,"\n the string is empty\n ");
		return ;
	}
	for(i=1;i<=string[0];i++)
	{
		printf("%c", string[i]);
	}
	printf("\n ");
	return ;
}		/* -----  end of function Print_String  ----- */
