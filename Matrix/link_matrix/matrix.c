/*
 * =====================================================================================
 *
 *       Filename:  matrix.c
 *
 *    Description:  this is c file about link matrix
 *
 *        Version:  1.0
 *        Created:  2014年07月03日 05时59分08秒
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
 *         Name:  Init_Matrix
 *  Description:  init a matrix 
 * =====================================================================================
 */
	Matrix
Init_Matrix ( int mu , int nu  )
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
	// malloc the r * mu
	new_matrix->rhead	= malloc ( sizeof(struct matrix_node ) * mu );
	if ( new_matrix->rhead==NULL ) {
		free(new_matrx);
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	// malloc the c * nu 
	
	new_matrix->chead	= malloc ( sizeof(struct matrix_node) * nu);
	if ( new_matrix->chead==NULL ) {
		free(new_matrix);
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	return new_matrix;
}		/* -----  end of function Init_Matrix  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Matrix
 *  Description:  insert a element into the matrix
 * =====================================================================================
 */
	void
Insert_Matrix ( Matrix my_matrix, int i ,int j , int number)
{
	Matrix_node new_node;
	Matrix_node temp;
	Matrix_node temp1;
	if(my_matrix==NULL)
	{
		fprintf(stderr,"\n the matrix is not init \n ");
		return ;
	}
	if(i< 1 || j< 1 || j>my_matrix->nu ||i>my_matrix->mu || number==0 )
	{
		fprintf(stderr, "\n i or j or number is not correct \n ");
		return ;
	}
	i--;
	j--;

	new_node	= malloc ( sizeof(struct matrix_node) );
	if ( new_node==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	new_node->i=i;
	new_node->j=j;
	new_node->number = number;
	/*  now set the right pointer and down pointer */
	temp=&(my_matrix->chead[j]);
	if(temp->down ==NULL)
	{
		/*  this c is empty  */
		temp->down=new_node;
	}
	else
	{
		while(temp->down!=NULL && temp->down->j < j)
		{
			temp=temp->down ;
		}
		temp1=temp->down;
		temp->down =new_node;
		temp->down->down=temp1;
	}
	//++++++++++++++++++++++++++++++++++++++++++++++++++
	temp=&(my_matrix->rhead[i]);
	if(temp->right==NULL)
	{
		temp->right=new_node;
	}
	else
	{
		while(temp->right!=NULL && temp->right->i < i)
		{
			temp=temp->right;
		}
		temp1=temp->right;
		temp->right=new_node;
		temp->right->right=temp1;
	}
	my_matrix->tu++;
	return ;
}		/* -----  end of function Insert_Matrix  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Matrix
 *  Description:  delete a element form matrix
 * =====================================================================================
 */
	void
Delete_Matrix ( Matrix my_matrix , int i ,int j )
{
	Matrix_node temp;
	Matrix_node temp1;
	if(my_matrix==NULL)
	{
		fprintf(stderr, "\n the matrix have not benn init \n ");
		return ;
	}
	if(i < 1 || j < 1 || j> my_matrix->nu || i> my_matrix->mu )
	{
		fprintf(stderr ,"\n the i or j is not correct\n ");
		return;
	}
	i--;
	j--;
	temp=Find_Position(my_matrix ,i, j);
	if(temp==NULL)
	return ;
	else
	{
		temp1=temp->next->next;
		free(temp->next);
		temp->next=temp1;// done
	}
	return;
}		/* -----  end of function Delete_Matrix  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Position
 *  Description:  find a node <i , j> previous element 
 * =====================================================================================
 */
	Matrix_node
Find_Position ( Matrix my_matrix , int i , int j)
{
	Matrix_node find_node;
	Matrix_node temp;
	if(my_matrix == NULL)
	{
		fprintf(stderr, "\n the matrix have not been init \n ");
		return NULL;
	}
	if(i < 1 || j< 1 || i > my_matrix->mu || j > my_matrix->nu)
	{
		fprintf(stderr ,"\n the i or j is not correct \n ");
		return NULL;
	}
	i--;
	j--;
	temp=&(my_matrix->chead[j]);
	if(temp->down==NULL)
	{
		fprintf(stderr , "\n can not find the element \n ");
		return NULL;
	}
	else
	{
		while(temp->down  !=NULL && temp->down->j !=j)
		{
			temp=temp->down;
		}
		if(temp->down == NULL)
		{
			fprintf(stderr , "\n can not find the element \n ");
			return NULL;
		}
		else
		{
			if(temp->down->j == j)
			{
				return temp;
			}
		}
	}
}	/* -----  end of function Find_Position  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Matrix
 *  Description:  printf the matrix 
 * =====================================================================================
 */
	void
Print_Matrix ( Matrix my_matrix  )
{
	Matrix_node temp;
	int k1 , k2;
	if(my_matrix == NULL)
	{
		fprintf(stderr , "\n the matrix have not inited \n ");
		return ;
	}
	for(k1==0 ; k1 < my_matrix->mu ; k1++)
	{
		temp=&(my_matrix->rhead[k1]);
		if(temp->right==NULL)
		continue;
		for(k2==0 ; k2< my_matrix->nu ; k2++)
		{
			if(temp->right->j == k2)
			{
				printf("%d\t" , temp->right->number);
				temp=temp->right;
			}
			else
			{
				printf("%d\t", 0);
			}
			
		}
	}

	return ;
}		/* -----  end of function Print_Matrix  ----- */
