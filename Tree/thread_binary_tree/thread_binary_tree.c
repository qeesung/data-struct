/*
 * =====================================================================================
 *
 *       Filename:  thread_binary_tree.c
 *
 *    Description:  this is thread binary link tree c file
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 17时10分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#include    <stdio.h>
#include    <stdlib.h>
#include    "thread_binary_tree.h"

Tree_node pre;// 创建一个全局变量

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Bithrtree
 *  Description:  init a thread binary tree
 * =====================================================================================
 */
    Tree
Init_Bithrtree ( )
{
    Tree_node header;

    header	= malloc ( sizeof(struct tree_node) );
    if ( header==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    header->righttag=1;// point to last tree_node
    header->rightchild=NULL;
    header->leftchild=NULL;
    header->lefttag=0;// point to root
    return header;
}		/* -----  end of function Init_Bithrtree  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Bithrtree
 *  Description:  assign for every tree node
 * =====================================================================================
 */

void Create_Bithrtree(Tree tree)
{
    char input_string[2];
    Tree_node new_tree_node;
    printf(">");
    scanf("%s",input_string);
    if(strcmp(input_string , ".")==0)
        return;

    new_tree_node	= malloc ( sizeof(struct tree_node) );
    if ( new_tree_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    strcpy(new_tree_node->data , input_string);
    new_tree_node->leftchild=NULL;
    new_tree_node->lefttag=0;
    new_tree_node->rightchild = NULL;
    new_tree_node->righttag=0;
    Create_Bithrtree(tree->leftchild);
    Create_Bithrtree(tree->rightchild);
    return; 

}
