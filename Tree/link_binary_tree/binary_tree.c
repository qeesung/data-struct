/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.c
 *
 *    Description:  This is c file about my link binary tree
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 05时55分13秒
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Tree
 *  Description:  Init a bianry tree
 * =====================================================================================
 */
    Tree
Init_Tree (  )
{
    Tree new_tree;
    new_tree = NULL;
    return new_tree;
}		/* -----  end of function Init_Tree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_Tree
 *  Description:  Destory a binary tree
 * =====================================================================================
 */
    void
Destory_Tree ( Tree tree )
{
    if(tree == NULL)
    {
        return;
    }
    if(tree -> leftchild !=NULL)
    {
        Destory_Tree(tree->leftchild);
    }
    if(tree -> rightchild !=NULL)
    {
        Destory_Tree(tree->rightchild);
    }
    free(tree);
    return;
}		/* -----  end of function Destory_Tree  ----- */
