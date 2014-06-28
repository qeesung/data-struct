/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main file to test KMP 
 *
 *        Version:  1.0
 *        Created:  2014年06月29日 05时30分41秒
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
#include	"string.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	String my_string ;
	String mode_string;
	int i;
	Init_String(my_string , "This is my_string");
	Init_String(mode_string , "my_string");

	printf("\n ++++++++my_string+++++++++++\n");
	Print_String(my_string);
	printf("\n ++++++++mode_string+++++++++++\n");
	Print_String(mode_string);
	printf("\n ++++++++Start to KMP+++++++++++\n");
	i=Index_Kmp(my_string , mode_string );
	if(i==-1)
	{
		printf("\n can not find the string : %s \n ", mode_string );
	}
	else
	{
		printf("\n find the string : %s in the string %s at position %d \n", mode_string , my_string , i);
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
