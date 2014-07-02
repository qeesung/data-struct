/*
 * =====================================================================================
 *
 *       Filename:  matrix.h
 *
 *    Description:  this is matrix  header file
 *
 *        Version:  1.0
 *        Created:  2014年07月02日 04时02分23秒
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
#define MATRIX_NODE_NUMBER 100

struct matrix_node {
	int i;
	int j;
	int number ;
};				/* ----------  end of struct matrix_node  ---------- */

typedef struct matrix_node * Matrix_node ;

struct matrix {
	struct matrix_node data[MATRIX_NODE_NUMBER];
	int mu;
	int nu;
	int tu;
};				/* ----------  end of struct matrix  ---------- */

typedef struct matrix *  Matrix;

Matrix Create_Matrix(int mu , int nu);
void Destory_Matrix(Matrix my_matrix);
void Insert_Matrix(Matrix my_matrix ,int mu , int nu, int number );
void Delete_Matrix(Matrix my_matrix,int mu , int nu);
Matrix Add_Matrix(Matrix my_matrix1 , Matrix my_matrix2);
Matrix Sub_Matrix(Matrix my_matrix1 , Matrix my_matrix2);
Matrix Mul_Matrix(Matrix my_matrix1 , Matrix my_matrix2);
Matrix Transpose_Matrix(Matrix my_matrix);
void Print_Matrix(Matrix my_matrix);
Matrix_node Get_Matrix_Node(Matrix my_matrix , int mu , int nu);
Matrix Fast_Transpose_Matrix(Matrix my_matrix);

#endif
