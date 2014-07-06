/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  this is  a test file to test link matrix
 *   
 *        Version:  1.0
 *        Created:  2014年07月06日 21时40分51秒
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
#include	"matrix.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Matrix my_matrix ;
	my_matrix = Init_Matrix(5, 5);
	Insert_Matrix(my_matrix , 4,3 , 5);
	Insert_Matrix(my_matrix , 2,3 , 4);
	Insert_Matrix(my_matrix , 1,5 , 3);
	Insert_Matrix(my_matrix , 2,4 , 2);
	Insert_Matrix(my_matrix , 3,3 , 1);
	Insert_Matrix(my_matrix , 5,2 , 9);
	Print_Matrix(my_matrix);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
