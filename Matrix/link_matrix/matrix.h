/*
 * =====================================================================================
 *
 *       Filename:  matrix.h
 *
 *    Description:  define the matrix struct and funxtions
 *
 *        Version:  1.0
 *        Created:  2014年07月03日 05时51分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */
#ifndef _MATRIX_H
#define _MATRIX_H


struct matrix_node {
	int i;
	int j;
	int number;
	struct matrix_node * right;
	struct matrix_node * down;
};				/* ----------  end of struct matrix_node  ---------- */
typedef struct matrix_node * Matrix_node;

struct matrix
{
	int nu;
	int mu;
	int tu;
	Matrix chead;
	Matrix rhead;
};
typedef struct matrix * Matrix;

Matric Init_Matrix(int mu , int nu);
void Insert_Matrix(Matrix my_matrix , int i , int j , int number);
void Delete_Matrix(Matrix my_matrix , int i ,int j);
void Print_Matrix(Matrix my_matrix);


#endif
