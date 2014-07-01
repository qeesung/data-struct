/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  test for my matrix 
 *
 *        Version:  1.0
 *        Created:  2014年07月02日 06时01分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */


#include	<stdio.h>
#include	<stdlib.h>
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
	int i;
	Matrix my_matrix ;
	my_matrix=Create_Matrix(5,5);
	Insert_Matrix(my_matrix,2,2,4);
	Insert_Matrix(my_matrix,4,4,1);
	Insert_Matrix(my_matrix,2,3,14);
	Insert_Matrix(my_matrix,3,3,3);
	Insert_Matrix(my_matrix,5,5,7);
	Insert_Matrix(my_matrix,1,1,5);
	Print_Matrix(my_matrix);
	for(i=0;i<my_matrix->tu;i++)
	{
		printf("%d \t ",my_matrix->data[i].number);
	}
	printf("\n ++++++++++++++++++++\n ");
	Delete_Matrix(my_matrix,2,3);
	Print_Matrix(my_matrix);
	for(i=0;i<my_matrix->tu;i++)
	{
		printf("%d \t ",my_matrix->data[i].number);
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
