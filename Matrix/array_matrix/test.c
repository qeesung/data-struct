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
	Matrix trans_matrix;
	Matrix add_matrix;
	Matrix sub_matrix;
	Matrix mul_matrix;
	Matrix fast_trans_matrix;
	my_matrix=Create_Matrix(5,5);
	Insert_Matrix(my_matrix,2,5,4);
	Insert_Matrix(my_matrix,4,1,1);
	Insert_Matrix(my_matrix,3,2,8);
	Insert_Matrix(my_matrix,3,3,3);
	Insert_Matrix(my_matrix,5,2,7);
	Insert_Matrix(my_matrix,1,1,5);
	Print_Matrix(my_matrix);
	printf("\n ++++++++++after delete++++++++++\n ");
	Delete_Matrix(my_matrix,3,3);
	Print_Matrix(my_matrix);
	/*for(i=0;i<my_matrix->tu;i++)
	{
		printf("%d \t ",my_matrix->data[i].number);
	}*/
	printf("\n ++++++++++after transpose++++++++++\n ");
	trans_matrix=Transpose_Matrix(my_matrix);
	Print_Matrix(trans_matrix);
	printf("\n ++++++++++after fast transpose++++++++++\n ");
	fast_trans_matrix=Fast_Transpose_Matrix(my_matrix);
	Print_Matrix(fast_trans_matrix);
	add_matrix=Add_Matrix(my_matrix,trans_matrix);
	printf("\n ++++++++++after add++++++++++\n ");
	Print_Matrix(add_matrix);
	sub_matrix=Sub_Matrix(my_matrix, trans_matrix);
	printf("\n ++++++++++after sub++++++++++\n ");
	Print_Matrix(sub_matrix);
	printf("\n ++++++++++after mul++++++++++\n ");
	mul_matrix=Mul_Matrix(my_matrix, trans_matrix);
	Print_Matrix(mul_matrix);

	/*  destrory all the matrix */
	Destory_Matrix(my_matrix);
	Destory_Matrix(sub_matrix);
	Destory_Matrix(add_matrix);
	Destory_Matrix(trans_matrix);
	Destory_Matrix(mul_matrix);



	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
