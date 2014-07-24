/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  test for my binary tree
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 06时49分27秒
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
extern struct person person_list[];
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    int i=0;
    Tree my_tree;
    Tree my_tree_node;
    Tree temp;
    my_tree = Init_Tree();
    my_tree_node = my_tree;
    printf("mimi\n");
    /*  test for create tree */
    
    my_tree_node	= malloc ( sizeof(struct tree) );// create root
    if ( my_tree_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    my_tree_node->name = person_list[0].name;
    my_tree_node->age = person_list[0].age;
    my_tree = my_tree_node;
    Create_Tree(my_tree_node, 0 , person_list[1] );// create root left child
    Create_Tree(my_tree_node, 1 , person_list[2] );// craete root right child
    temp = my_tree_node;
    my_tree_node = my_tree_node->leftchild;
    Create_Tree(my_tree_node, 0 , person_list[3] );
    Create_Tree(my_tree_node, 1 , person_list[4] );
    my_tree_node = temp->rightchild;
    Create_Tree(my_tree_node, 0 , person_list[5] );
    Create_Tree(my_tree_node, 1 , person_list[6] );
    temp=my_tree_node;
    my_tree_node = my_tree_node->leftchild;
    Create_Tree(my_tree_node, 0 , person_list[7] );
    Create_Tree(my_tree_node, 1 , person_list[8] );
    my_tree_node = temp->rightchild;
    Create_Tree(my_tree_node, 0 , person_list[9] );
    printf("*******************Inorder Traverse*************\n");
    Inorder_Traverse(my_tree , Visit);
    printf("*******************Preorder Traverse*************\n");
    Preorder_Traverse(my_tree , Visit);
    printf("*******************Postorder Traverse*************\n");
    Postorder_Traverse(my_tree , Visit);
    printf("*******************levelorder Traverse*************\n");
    Levelorder_Traverse(my_tree , Visit);
    printf("***************** Root *************\n");
    printf("root name is : %s age is %d\n", Root(my_tree)->name, Root(my_tree)->age);
    printf("***************** Find_Point *************\n");
    my_tree_node = Find_Point(my_tree , "D", 24);
    printf("find point name is %s age is %d \n",my_tree_node->name, my_tree_node->age);
    printf("***************** Assign *************\n");
    Assign(Find_Point(my_tree,"D",24),"X",11);
    Levelorder_Traverse(my_tree,Visit);
    

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
