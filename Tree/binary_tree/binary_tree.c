/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.c
 *
 *    Description:  c file for my binary tree 
 *
 *        Version:  1.0
 *        Created:  2014年07月20日 05时29分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include"binary_tree.h"

struct person person_list[10]=
{
    ("A",21),
    ("B",22),
    ("C",23),
    ("D",24),
    ("E",25),
    ("F",26),
    ("G",27),
    ("H",28),
    ("I",29),
    ("J",30)

};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Bitree
 *  Description:  init my binary tree
 * =====================================================================================
 */

Tree Init_Bitree()
{
    int i=0;
    Tree new_tree;
    new_tree	= malloc ( sizeof(struct person)  * MAX_TREE_SIZE);
    if ( new_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    for(i=0;i<MAX_TREE_SIZE;i++)
    {
        new_tree[i].name="None";
        new_tree[i].age=0;
    }
    return new_tree;

}
/* -----  end of function Init_Bitree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Bitree()
 *  Description:  create binary tree with person list 
 * =====================================================================================
 */
    void
Create_Bitree( Tree tree, struct person my_person_list[])
{
    int i=0;
    int list_size;
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree have not init \n ");
        return;
    }
    if(my_person_list==NULL)
    {
        fprintf(stderr,"\n the person list is empty \n ");
        return;
    }
    list_size=sizeof(my_person_list)/sizeof(struct person);
    for(i=0;i<list_size;i++)
    {
        tree[i] = my_person_list[i];
    }
    return;

}		/* -----  end of function Create_Bitree()  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Bitree
 *  Description:  print all the element in the binary tree
 * =====================================================================================
 */
    void
Print_Bitree ( Tree tree )
{
    int i=0;
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree is not init \n ");
        return;
    }
    while(tree[i].name != "None" && tree[i].age!=0)
    {
        printf("%s ____> %d \n ", tree[i].name, tree[i].age);
    }
    return;
}		/* -----  end of function Print_Bitree  ----- */
