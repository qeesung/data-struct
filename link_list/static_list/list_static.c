/*
 * =====================================================================================
 *
 *       Filename:  list_static.c
 *
 *    Description:  This is a c file about the list_static.h
 *
 *        Version:  1.0
 *        Created:  2014年06月20日 05时44分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdio.h>
#include"list_static.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_List
 *  Description:  init the list
 * =====================================================================================
 */
	void
Init_List ( List list )
{
	int i;
	if(list==NULL)
	{
		fprintf(stderr , "\n the liss is null \n ");
		return ;
	}
	for(i=0;i<MAXSIZE;i++)
	{
	//	list->data[i].number =0 ;
	//	list->data[i].name="NULL";
		list->data[i].next=i+1;
	}
	list->data[MAXSIZE-1].next=0;
	list->size =0 ;
	return;
	
}		/* -----  end of function Init_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Malloc_List
 *  Description: malloc a memory for new data 
 * =====================================================================================
 */
	int 
Malloc_List ( List list )
{
	int i;
	i=list->data[0].next;
	if(i!=0)/*  if  i==0 then It means the list is full */
	{
		list->data[0].next=list->data[i].next;
		return i;
	}
	else
	{
	
		fprintf(stderr,"\n The list is Full \n ");
		return -1;
	}
}		/* -----  end of function Malloc_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Free_List
 *  Description: Free a node from the list and  insert into the free list
 * =====================================================================================
 */
	void 
Free_List ( List list , int k )
{
	list->data[k].next=list->data[0].next;
	list->data[0].next=k;
	
}		/* -----  end of function Free_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_List
 *  Description: Insert a elemnt into the list 
 * =====================================================================================
 */
	void
Insert_List ( List list , int number , char * name )
{
	int i;
	int j;
	int k=1;
	i=Malloc_List(list);/* get the free list first element */
	list->data[i].number = number;
	list->data[i].name = name;// insert done
	j=list->size;
	if(j==0)
	{
		list->data[1].next=0;
	}
	else
	{
		while(--j)
		{
			k=list->data[k].next;	
		}
		list->data[k].next=i;
		list->data[i].next=0;
	}
	list->size++;
	return;
}		/* -----  end of function Insert_List  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_List
 *  Description:  Delete a element from the list 
 * =====================================================================================
 */
	void
Delete_List (List list, int k)
{
	int i=1;
	int j=1;
	while(i!=0 && list->data[i].next!=k)
	{
		i=list->data[i].next;
		j++;
	}
	if(i==0)
	{
		fprintf(stderr, "\n can not find k\n ");
		return ;
	}
	else
	{
		if(list->data[i].next==k)
		{
			list->data[i].next=list->data[k].next;
		}
	}
	Free_List(list , k);
	list->size--;
	return;
	
}		/* -----  end of function Delete_List  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  int Find_Position
 *  Description:  
 * =====================================================================================
 */
	int
Find_Position (List list , int number , char * name )
{	
	int i=1;
	while(i!=0 && list->data[i].number !=number && list->data[i].name!=name)
	{
		i=list->data[i].next;
	}
	return i;
}		/* -----  end of function int Find_Position  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Merge_List
 *  Description:  Merge two lists with the mode (A_B)U(B-A)
 * =====================================================================================
 */
	void
Merge_List ( List list1 , List list2)
{
	/*  in the A and in the B  will be deleted*/	
	/*  in the B but not in the A will be insert */
	int number ;
	char * name;
	int i, index ;
	i=1;
	while(i!=0)
	{
		number = list2->data[i].number;
		name = list2->data[i].name;
		index = Find_Position(list1,number ,name);
		if(index == 0)
		{
			/*  it means that the number is  not in the list we can insert into */
			Insert_List(list1,number,name);
		}
		else
		{
			Delete_List(list1, index );
		}
		i=list2->data[i].next;
	}
	return;
}		/* -----  end of function Merge_List  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_List
 *  Description:  print all the number in the list
 * =====================================================================================
 */
	void 
Print_List ( List list )
{
	int i=1;
	if(list->size==0)
	{
		fprintf(stderr ,"\n The list is empty \n ");
		return ;
	}
	while(i!=0)
	{
		printf("The number is %d \t and the name is : %s\n ", list->data[i].number , list->data[i].name);
		i=list->data[i].next;
	}
	return ;


}		/* -----  end of function Print_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_All_List
 *  Description: delete all the element in the list 
 * =====================================================================================
 */
inline void
Delete_All_List ( List list )
{
	free(list);
	list=NULL;
	return;
}		/* -----  end of function Delete_All_List  ----- */
