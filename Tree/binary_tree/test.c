/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  test for my binary tree
 *
 *        Version:  1.0
 *        Created:  2014年07月20日 05时42分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include    <stdio.h>
#include    "binary_tree.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */

extern struct person person_list[10];
    int
main ( int argc, char *argv[] )
{
    Tree tree;
    struct position pos;
    struct person new_person;
    Person root_person;
    Person level_person;
    Person parent_person;
    Person leftchild_person;
    Person rightchild_person;
    Person leftsibling_person;
    Person rightsibling_person;

    tree=Init_Bitree();
    Create_Bitree(tree, person_list);
    Print_Bitree(tree);
    if(!Bitree_Empty(tree))
    {
        printf("the tree depth is :%d\n", Bitree_Depth(tree));
    }
    pos.level=2;
    pos.number = 2;
    
    root_person = Bitree_Root(tree);
    level_person = Bitree_Value(tree , pos);
    printf("the root person name is %s and age is %d \n ", root_person->name , root_person->age);
    printf("the level %d and number %d person name is %s and age is %d\n", \
            pos.level, pos.number,level_person->name, level_person->age);
    new_person.name = "new_name";
    new_person.age = 31;
    Bitree_Assign(tree , pos,new_person );
    printf("\n**************bfter assign value***************\n");
    Print_Bitree(tree);
    parent_person = Bitree_Parent(tree , pos);
    printf("the level %d number %d parent peson name is %s and age is %d \n", pos.level, pos.number ,parent_person->name , parent_person->age);

    if((leftchild_person = Bitree_Child(tree , pos , 0))!=NULL)
    {
        printf("the pos level %d number %d left child person name is %s ang age is %d \n",\
                pos.level , pos.number, leftchild_person->name , leftchild_person->age);
    }
    if((rightchild_person = Bitree_Child(tree, pos , 1))!=NULL)
    {
        printf("the pos level %d number %d right child person name is %s ang age is %d \n",\
                pos.level , pos.number, rightchild_person->name , rightchild_person->age);
    }
/*  need to change the pos */

    if((leftsibling_person=Bitree_Sibling(tree , pos,0 ))!=NULL)
    {
        printf("the pos level %d number %d left sibling person name is %s ang age is %d \n",\
                pos.level , pos.number, leftsibling_person->name , leftsibling_person->age);
    }
    if((rightsibling_person=Bitree_Sibling(tree , pos,1 ))!=NULL)
    {
        printf("the pos level %d number %d right sibling person name is %s ang age is %d \n",\
                pos.level , pos.number, rightsibling_person->name , rightsibling_person->age);
    }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
