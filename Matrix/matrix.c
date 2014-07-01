/*
 * =====================================================================================
 *
 *       Filename:  matrix.c
 *
 *    Description:  this is matrix c file 
 *
 *        Version:  1.0
 *        Created:  2014年07月02日 04时11分59秒
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
#include"matrix.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Matrix
 *  Description:  create a empty matrix
 * =====================================================================================
 */
	Matrix
Create_Matrix ( int mu , int nu )
{
	Matrix new_matrix;
	
	new_matrix	= malloc ( sizeof(struct matrix) );
	if ( new_matrix==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	new_matrix->mu=mu;
	new_matrix->nu=nu;
	new_matrix->tu=0;

	return new_matrix;
}		/* -----  end of function Create_Matrix  ----- */
