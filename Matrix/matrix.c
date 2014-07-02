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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_Matrix
 *  Description:  destory a matrix
 * =====================================================================================
 */
	void
Destory_Matrix ( Matrix my_matrix )
{
	if(my_matrix==NULL)
	{
		fprintf(stderr, "\n the matrix is empty\n");
		return ;
	}
	free(my_matrix);
	return ;
}		/* -----  end of function Destory_Matrix  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Matrix
 *  Description:  insert a number that is not equal to 0 to the matrix
 * =====================================================================================
 */
	void
Insert_Matrix (Matrix my_matrix , int mu , int nu , int number )
{
	int k1, k2,k3;
	nu--;
	mu--;
	if(my_matrix==NULL)
	{
		fprintf(stderr,"\n the martrix is empty in the %s \n  ", __func__);
		return;
	}
	if(my_matrix->tu==MATRIX_NODE_NUMBER)
	{
		fprintf(stderr,"\n overflow the maxsize of the matrix\n");
		return;
	}
	if(mu>my_matrix->mu || nu>my_matrix->nu)
	{
		fprintf(stderr,"the mu is < %d the tu is < %d", my_matrix->mu , my_matrix->nu);
		return ;
	}
	if(number == 0)
	{
		return;
	}
	for(k1=0;k1<my_matrix->tu;k1++)
	{
		if(my_matrix->data[k1].i > mu)
		{
			for(k2=my_matrix->tu;k2>k1;k2--)
			{
				my_matrix->data[k2]=my_matrix->data[k2-1];
			}
			my_matrix->data[k2].i=mu;
			my_matrix->data[k2].j=nu;
			my_matrix->data[k2].number=number;
			my_matrix->tu++;
			return;
		}
		if(my_matrix->data[k1].i == mu)
		{
			for(k2=k1;my_matrix->data[k2].i == mu ; k2++)
			{
				if(my_matrix->data[k2].j > nu)
				{
					break;
				}
				if(my_matrix->data[k2].j == nu)
				{
					my_matrix->data[k2].number = number ;
					return;
				}
			}

			for(k3=my_matrix->tu;k3>k2;k3--)
			{
				my_matrix->data[k3]=my_matrix->data[k3-1];
			}
			my_matrix->data[k2].i=mu;
			my_matrix->data[k2].j=nu;
			my_matrix->data[k2].number=number;
			my_matrix->tu++;
			return;
		}
	}
	my_matrix->data[my_matrix->tu].i=mu;
	my_matrix->data[my_matrix->tu].j=nu;
	my_matrix->data[my_matrix->tu].number=number;
	my_matrix->tu++;
//	my_matrix->data[tu].i=mu;
//	my_matrix->data[tu].j=tu;
//	my_matrix->data[tu].number=number;
//	matrix->tu++;
	return ;
}		/* -----  end of function Insert_Matrix  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Matrix
 *  Description:  delete a node form the matrix
 * =====================================================================================
 */
	void
Delete_Matrix ( Matrix my_matrix , int mu , int nu )
{
	int k1, k2;
	k1=0;
	k2=0;
	mu--;
	nu--;
	while(k1<my_matrix->tu )
	{
		if(my_matrix->data[k1].i==mu && my_matrix->data[k1].j==nu)
		break;
		k1++;
	}
	if(k1==my_matrix->tu)
	{
		fprintf(stderr,"\n can not find the <%d , %d > number \n ", mu , nu);
		return;
	}
//	printf("the i==%d , and j==%d \n ",my_matrix->data[k1].i , my_matrix->data[k1].j);
	for(k2=k1;k2<my_matrix->tu-1;k2++)
	{
	//	if(k2==my_matrix->tu-1)
	//	break;
		my_matrix->data[k2]=my_matrix->data[k2+1];
	}
	my_matrix->tu--;
	return ;
}		/* -----  end of function Delete_Matrix  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Matrix
 *  Description:  print all the matrix 
 * =====================================================================================
 */
	void
Print_Matrix ( Matrix my_matrix )
{
	int k1,k2;
	Matrix_node temp;
	if(my_matrix == NULL)
	{
		fprintf(stderr,"\n can not print a empty matrix \n ");
		return;
	}
	for(k1=0;k1<my_matrix->mu;k1++)
	{
		for(k2=0;k2<my_matrix->nu;k2++)
		{
			if((temp=Get_Matrix_Node(my_matrix, k1 , k2))!=NULL)
			{
				printf("%d\t",temp->number);
			}
			else
			{
				printf("%d\t",0);
			}
		}
		printf("\n");
	}
	return ;
}		/* -----  end of function Print_Matrix  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Matrix_Node
 *  Description:  get a matrix node msg
 * =====================================================================================
 */
	Matrix_node
Get_Matrix_Node ( Matrix my_matrix , int mu , int nu )
{
	int k1;
	k1=0;
	while(k1<my_matrix->tu )
	{
		if(my_matrix->data[k1].i==mu && my_matrix->data[k1].j==nu)
		break;
		k1++;
	}
	if(k1==my_matrix->tu)
	{
//		fprintf(stderr,"\n can not find the <%d , %d > number \n ", mu , nu);
		return NULL;
	}
	return &(my_matrix->data[k1]);
}		/* -----  end of function Get_Matrix_Node  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Transpose_Matrix
 *  Description:  transpose a matrix
 * =====================================================================================
 */
	Matrix
Transpose_Matrix ( Matrix my_matrix )
{
	int k1 , k2;
	int pos=0;
	Matrix trans_matrix;
	if(my_matrix == NULL)
	{
		fprintf(stderr,"\n the matrix is empty \n ");
		return NULL;
	}
	trans_matrix=Create_Matrix(my_matrix->nu, my_matrix->mu);
	trans_matrix->tu=my_matrix->tu;
	for(k1=0;k1<trans_matrix->nu;k1++)
	{
		for(k2=0;k2<my_matrix->tu;k2++)
		{
			if(my_matrix->data[k2].j==k1)
			{
			//	printf("%d-->%d\t",k1,my_matrix->data[k2].number);
				trans_matrix->data[pos].i=my_matrix->data[k2].j;
				trans_matrix->data[pos].j=my_matrix->data[k2].i;
				trans_matrix->data[pos].number = my_matrix->data[k2].number;
			//	printf("<%d,%d>:%d\n",trans_matrix->data[pos].i, trans_matrix->data[pos].j, trans_matrix->data[pos].number);
				pos++;
			}
		}
	}
	
	return trans_matrix;
}		/* -----  end of function Transpose_Matrix  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Add_Matrix
 *  Description:  add two matrix 
 * =====================================================================================
 */
	Matrix
Add_Matrix ( Matrix my_matrix1 , Matrix my_matrix2 )
{
	Matrix add_matrix;
	Matrix_node node1, node2;
	int k1, k2;
	int number;
	int pos=0;
	if(my_matrix1==NULL || my_matrix2==NULL)
	{
		fprintf(stderr,"\n the matrix can not be empty\n ");
		return NULL;
	}
	if(my_matrix1->nu != my_matrix2->mu || my_matrix1->mu !=my_matrix2->mu)
	{
		fprintf(stderr,"\n The matrix nu !=nu or mu!=mu \n ");
		return NULL;
	}
	add_matrix=Create_Matrix(my_matrix1->mu , my_matrix1->nu);
	if(add_matrix==NULL)
	{
		return NULL;
	}
	for(k1=0;k1<my_matrix1->mu;k1++)
	{
		for(k2=0;k2<my_matrix1->nu;k2++)
		{
			number=0;
			if((node1=Get_Matrix_Node(my_matrix1,k1,k2))!=NULL)
			{
//				printf("\nget one in matrix1\n");
//				printf("add the number is : %d \n", node1->number);
				number+=node1->number;
			}
			if((node2=Get_Matrix_Node(my_matrix2,k1,k2))!=NULL)
			{
//				printf("\nget one in matrix2\n");
//				printf("add the number is : %d \n", node2->number);
				number+=node2->number;
			}
//			printf("%d\t\t",number );
			if(number!=0)
			{
				add_matrix->data[pos].i=k1;
				add_matrix->data[pos].j=k2;
				add_matrix->data[pos].number=number;
	//			printf("<%d , %d > : %d \n ",add_matrix->data[pos].i, add_matrix->data[pos].j,add_matrix->data[pos].number );
				pos++;
			}
		}
	}
	add_matrix->tu=pos;
	return add_matrix;
}		/* -----  end of function Add_Matrix  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Add_Matrix
 *  Description:  sub two matrix 
 * =====================================================================================
 */
	Matrix
Sub_Matrix ( Matrix my_matrix1 , Matrix my_matrix2 )
{
	Matrix sub_matrix;
	Matrix_node node1, node2;
	int k1, k2;
	int number;
	int pos=0;
	if(my_matrix1==NULL || my_matrix2==NULL)
	{
		fprintf(stderr,"\n the matrix can not be empty\n ");
		return NULL;
	}
	if(my_matrix1->nu != my_matrix2->mu || my_matrix1->mu !=my_matrix2->mu)
	{
		fprintf(stderr,"\n The matrix nu !=nu or mu!=mu \n ");
		return NULL;
	}
	sub_matrix=Create_Matrix(my_matrix1->mu , my_matrix1->nu);
	if(sub_matrix==NULL)
	{
		return NULL;
	}
	for(k1=0;k1<my_matrix1->mu;k1++)
	{
		for(k2=0;k2<my_matrix1->nu;k2++)
		{
			number=0;
			if((node1=Get_Matrix_Node(my_matrix1,k1,k2))!=NULL)
			{
//				printf("\nget one in matrix1\n");
//				printf("add the number is : %d \n", node1->number);
				number+=node1->number;
			}
			if((node2=Get_Matrix_Node(my_matrix2,k1,k2))!=NULL)
			{
//				printf("\nget one in matrix2\n");
//				printf("add the number is : %d \n", node2->number);
				number-=node2->number;
			}
//			printf("%d\t\t",number );
			if(number!=0)
			{
				sub_matrix->data[pos].i=k1;
				sub_matrix->data[pos].j=k2;
				sub_matrix->data[pos].number=number;
	//			printf("<%d , %d > : %d \n ",sub_matrix->data[pos].i, sub_matrix->data[pos].j,sub_matrix->data[pos].number );
				pos++;
			}
		}
	}
	sub_matrix->tu=pos;
	return sub_matrix;
}		/* -----  end of function Add_Matrix  ----- */

