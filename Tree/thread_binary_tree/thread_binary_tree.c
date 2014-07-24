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
    void
Create_Bithrtree ( Tree tree,int leftorright, char * data )
{
    Tree_node new_tree_node;
    if(tree==NULL)
    {
        fprintf(stderr, "\n the tree node have not init yet \n ");
        return;
    }

    new_tree_node	= malloc ( sizeof(struct tree_node) );
    if ( new_tree_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_tree_node->data= data;

    if(leftorright == 0)// add leftchild
        tree->leftchild=new_tree_node;       
    if(leftorright ==1)// add right child
        tree->rightchild=new_tree_node;
    return ;
}		/* -----  end of function Create_Bithrtree  ----- */



