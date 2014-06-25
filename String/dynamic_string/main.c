/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main.c to test dymanic string
 *
 *        Version:  1.0
 *        Created:  2014年06月26日 05时42分49秒
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
	String string1, string2 , merge_string;
	String string1_1,string2_2;
	string1=Init_String("This is String1");
	string2=Init_String("and then is String2");
	string1_1=Str_Assign(string1);
	string2_2=Str_Assign(string2);
	printf("+++++++++++++++The string1 & string2 is :+++++++++++++++\n  ");
	Print_String(string1);
	Print_String(string2);
	printf("+++++++++++The string1_1 & string2-2 is : ++++++++++++++\n ");
	Print_String(string1_1);
	Print_String(string2_2);

	Clear_String(string1_1);
	Clear_String(string2_2);

	printf("++++++++++++++now test the Concat:++++++++++\n");
	string1_1 = Concat(string1, string2);
	Print_String(string1_1);
	printf("\n ++++++++++now test is Sub_String:++++++++++\n ");
	string2_2 = Sub_String(string1 , 2, 4);
	Print_String(string2_2);
	string2_2 = Init_String("xixigaga");
	printf("++++++++the bew_string is xixigaga and now insert into string2  at pos 3:+++++++++\n");
	Str_Insert(string2,3,string2_2);
	Print_String(string2);
	return EXIT_SUCCESS;

}				/* ----------  end of function main  ---------- */

