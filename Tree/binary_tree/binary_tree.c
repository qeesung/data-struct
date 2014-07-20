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
    {"A",21},
    {"B",22},
    {"C",23},
    {"D",24},
    {"E",25},
    {"F",26},
    {"G",27},
    {"H",28},
    {"I",29},
    {"J",30}

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
    list_size=10;
    printf("list_size : %d\n ", list_size);
    for(i=0;i<list_size;i++)
    {
        tree[i].name = my_person_list[i].name;
        tree[i].age = my_person_list[i].age;
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
        i++;
    }
    return;
}		/* -----  end of function Print_Bitree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Empty()
 *  Description:  check if the tree is empty
 * =====================================================================================
 */
    int 
Bitree_Empty ( Tree tree )
{
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree have not inited \n ");
        return -1;
    }
    if(tree[0].name=="None" && tree[0].age==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}		/* -----  end of function Bitree_Empty()  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Depth
 *  Description:  get the depth of the binary tree
 * =====================================================================================
 */
    int
Bitree_Depth ( Tree tree )
{   
    int i;
    int depth=0;
    for(i=0;i<MAX_TREE_SIZE;i++)
    {
        if(tree[i].name=="None" && tree[i].age==0)
            break;
    }
    i-=1;
    while((i+1)/2-1 !=0)
    {
        depth++;
    }
    depth++;
    return depth;
}		/* ----- end of function Bitree_Depth  ----- */
