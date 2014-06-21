/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  This is the list c file about the polyn
 *
 *        Version:  1.0
 *        Created:  2014年06月21日 02时45分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#include<stdlib.h>
#include<stdio.h>
#include"polyn.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Polyn
 *  Description: Create a empty polyn 
 * =====================================================================================
 */
	Polyn
Create_Polyn ( void  )
{
	Polyn new_polyn;

	new_polyn	= malloc ( sizeof(struct Polyn_node) );
	if ( new_polyn==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	
	return new_polyn;
}		/* -----  end of function Create_Polyn  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Polyn
 *  Description:  Insert a element into the list
 * =====================================================================================
 */
	void
Insert_Polyn ( Polyn polyn, int xishu, int zhishu )
{
	Polyn new_node;
	Position temp;

	new_node	= malloc ( sizeof(struct Polyn_node) );
	if ( new_node==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	new_node->xishu=xishu;
	new_node->zhishu=zhishu;
	if(polyn ->next==NULL)/*  insert into a empty polyn list */
	{
		polyn->next=new_node;
		return ;
	}
	while(polyn->next!=NULL && polyn->next->zhishu<zhishu)
	{
		polyn=polyn->next;
	}
	if(polyn->next==NULL)
	{
		polyn->next=new_node;
	}
	else
	{
		if(polyn->next->zhishu == zhishu)
		{
			polyn->next->xishu=xishu;/*  update the xishu */
			free(new_node);
		}
		else
		{
			/*  insert the element */
			temp=polyn->next;
			polyn->next=new_node;
			polyn->next->next=temp;
		}
		return ;
	}

	return ;
}		/* -----  end of function Insert_Polyn  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Polyn
 *  Description: delete a element from the polyn 
 * =====================================================================================
 */
	void
Delete_Polyn ( Polyn polyn, int zhishu )
{
	Position temp;
	if(polyn->next==NULL)
	{
		fprintf(stderr, "\n the polyn list is empty \n ");
		return ;
	}
	while(polyn->next!=NULL && polyn->next->zhishu!=zhishu)
	{
		polyn=polyn->next;
	}
	if(polyn->next==NULL)
	{
		printf("\n can not find the xishu : %d \n ",zhishu);
		return ;
	}
	temp=polyn->next->next;
	free(polyn->next);
	polyn->next=temp;
	return ;



}		/* -----  end of function Delete_Polyn  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Polyn
 *  Description:  print all the element in the polyn list
 * =====================================================================================
 */
	void
Print_Polyn ( Polyn polyn )
{
	if(polyn->next==NULL)
	{
		fprintf(stderr,"\n the polyn list is empty \n");
		return ;
	}
	while(polyn->next!=NULL)
	{
		printf("%dX^%d\t",polyn->next->xishu,polyn->next->zhishu);
		polyn=polyn->next;
	}
	return;
}		/* -----  end of function Print_Polyn  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Add_Polyn
 *  Description:  add two polyn lists
 * =====================================================================================
 */
	void
Add_Polyn ( Polyn polyn1 , Polyn polyn2 )
{
	/*  we will insert the polyn2 into plolyn2 */
	Position temp;
	while(polyn2->next!=NULL)
	{
		temp=Find_Position(polyn1,polyn2->next->zhishu);
		if(temp==NULL)
		{
			Insert_Polyn(polyn1,polyn2->next->xishu,polyn2->next->zhishu);
		}
		else
		{
			temp->xishu+=polyn2->next->xishu;/*  apdate the xishu */
			if(temp->xishu==0)
			Delete_Polyn(polyn1,temp->zhishu);/* if xishu==0 delete it */
		}
		polyn2=polyn2->next;
	}
	return ;
}		/* -----  end of function Add_Polyn  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Nul_Polyn
 *  Description:  Mul two polyn lists 
 * =====================================================================================
 */
	Polyn
Mul_Polyn ( Polyn polyn1 , Polyn polyn2 )
{
	Position temp;
	int temp_xishu;
	int temp_zhishu;
	Polyn temp_polyn;
	Polyn temp1_polyn;

	temp_polyn	= malloc ( sizeof(struct Polyn_node) );
	if ( temp_polyn==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	while(polyn1->next!=NULL)
	{
		temp1_polyn=polyn2;/*  save the polyn2 start pointer */
		while(polyn2->next!=NULL)
		{
			temp_xishu=polyn1->next->xishu*polyn2->next->xishu;
			temp_zhishu=polyn1->next->zhishu+polyn2->next->zhishu;
			temp=Find_Position(temp_polyn,temp_zhishu);
			if(temp==NULL)
			{
				Insert_Polyn(temp_polyn,temp_xishu,temp_zhishu);
			}
			else
			{
				temp->xishu+=temp->xishu;
				if(temp->xishu==0)
				Delete_Polyn(temp_polyn,temp_zhishu);
			}
				


			polyn2=polyn2->next;
		}
		polyn2=temp1_polyn;
		polyn1=polyn1->next;
	}
	return temp_polyn;
}		/* -----  end of function Nul_Polyn  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Position
 *  Description:  
 * =====================================================================================
 */
	Position
Find_Position ( Polyn polyn , int zhishu )
{
	Position my_pos;
	if(polyn->next==NULL)
	{
		fprintf(stderr, "\n the polyn list is empty\n ");
		return NULL;
	}
	while(polyn->next!=NULL && polyn->next->zhishu !=zhishu)
	{
		polyn=polyn->next;
	}
	if(polyn->next==NULL)
	{
//		fprintf(stderr , "\n can not find the zhishu: %d  \n ", zhishu);
		return NULL;
	}
	return polyn->next;
	/*  if the return value is NULL we would insert it into the polyn list */

}		/* -----  end of function Find_Position  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_All_Polyn
 *  Description:  delete all the elemnet in the polyn list
 * =====================================================================================
 */
	void
Delete_All_Polyn ( Polyn polyn )
{
	Position temp;
	if(polyn->next=NULL)
	{
		free(polyn);
		polyn==NULL;
	}
	else
	{
		while(polyn->next!=NULL)
		{
			temp=polyn->next;
			free(polyn);
			polyn=temp;
		}
		free(polyn);
	}
	return ;
}		/* -----  end of function Delete_All_Polyn  ----- */
