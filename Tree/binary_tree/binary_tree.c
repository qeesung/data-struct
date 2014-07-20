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
    while((i=(i+1)/2-1) !=0)
    {
        depth++;
    }
    depth++;
    return depth+1;
}		/* ----- end of function Bitree_Depth  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Root
 *  Description:  get the root value
 * =====================================================================================
 */
    Person
Bitree_Root (Tree tree )
{
    Person root_person;
    if(Bitree_Empty(tree))
    {
        fprintf(stderr,"The tree is empty\n");
        return NULL;
    }
    root_person	= malloc ( sizeof(struct person) );
    if ( root_person==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    root_person->name=tree[0].name;
    root_person->age = tree[0].age;
    return root_person;
}		/* -----  end of function Bitree_Root  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Value
 *  Description:  get the positiob value
 * =====================================================================================
 */
    Person
Bitree_Value ( Tree tree , struct position pos )
{
    Person value_person;
    int i=0;
    int level=1;
    if(tree == NULL)
    {
        fprintf(stderr,"\n the tree is not exists\n ");
        return NULL;
    }

    value_person	= malloc ( sizeof(struct person) );
    if ( value_person==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    while(level!=pos.level)
    {
        i=2*i+1;
        level+=1;
    }
    i+=(pos.number-1);
    value_person->name= tree[i].name;
    value_person->age = tree[i].age;
    return value_person;
}		/* -----  end of function Bitree_Value  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Assign
 *  Description:  assign a new value for position pos
 * =====================================================================================
 */
    void
Bitree_Assign ( Tree tree , struct position pos, struct person new_person)
{
    int i ;
    int level=1;
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree is not exists \n");
        return ;
    }
    i=0;
    while(level != pos.level)
    {
        i=2*i+1;
        level++;
    }
    i+=pos.number-1;
    if(i>=MAX_TREE_SIZE)
    {
        fprintf(stderr,"the tree number is greater than %d please enter a new position \n", MAX_TREE_SIZE);
        return;
    }
    tree[i].name = new_person.name;
    tree[i].age = new_person.age;
    return ;
}		/* -----  end of function Bitree_Assign  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Parent
 *  Description:  get a position element parent
 * =====================================================================================
 */
    Person
Bitree_Parent ( Tree tree , struct position pos )
{
    Person parent_person;
    int i=0;
    int level=1;
    if(tree ==NULL)
    {
        fprintf(stderr, "\n the tree is not init \n ");
        return NULL;
    }
    if(pos.level==1)
    {
        fprintf(stderr, "\n the root have not parent\n ");
        return NULL;
    }
    while(level != pos.level)
    {
        i=2*i+1;
        level++;
    }
    i+=pos.number-1;
    if(i >= MAX_TREE_SIZE)
    {
        fprintf(stderr,"\n the position overflow the %d try another position less than it\n", MAX_TREE_SIZE);
        return NULL;
    }

    parent_person	= malloc ( sizeof(struct person) );
    if ( parent_person==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    i=(i+1)/2 -1; /*  get the parent position  */
    parent_person->name = tree[i].name;
    parent_person->age = tree[i].age;
    return parent_person;
}		/* -----  end of function Bitree_Parent  ----- */
