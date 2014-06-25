/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This is main.c to test the string 
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 23时42分25秒
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
	String string1;
	String string2;
	String merge_string;
	Input_String(string1);
	Input_String(string2);
	Print_String(string1);
	Print_String(string2);
	Concat(merge_string,string1,string2);
	Print_String(merge_string);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

