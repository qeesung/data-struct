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
Destory_Tree ( Tree my_tree )
{
    if(my_tree == NULL)
    {
        return;
    }
    if(my_tree -> leftchild !=NULL)
    {
        Destory_Tree(my_tree->leftchild);
    }
    if(my_tree -> rightchild !=NULL)
    {
        Destory_Tree(my_tree->rightchild);
    }
    free(my_tree);
    return;
}		/* -----  end of function Destory_Tree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Visit
 *  Description:  visit the tree node 
 * =====================================================================================
 */
    void
Visit ( Tree tree_node )
{
    printf("%s -----> %d \n", tree_node->name, tree_node->age);
    return;
}		/* -----  end of function Visit  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Preorder_Traverse
 *  Description:  traverse the binary tree with preorder
 * =====================================================================================
 */
    void
Preorder_Traverse ( Tree my_tree , funcpointer my_fun )
{
    if(my_tree == NULL || my_fun == NULL)
    {
        return;
    }
    my_fun(my_tree);
    if(my_tree->leftchild !=NULL)
        Preorder_Traverse(my_tree->leftchild, my_fun);
    if(my_tree->rightchild !=NULL)
        Preorder_Traverse(my_tree->rightchild. my_fun);
    return ;
}		/* -----  end of function Preorder_Traverse  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Inorder_Traverse
 *  Description:  traverse the binary tree with mode inorder
 * =====================================================================================
 */
    void
Inorder_Traverse ( Tree my_tree , funcpointer my_fun )
{
    if(my_tree == NULL || my_fun===NULL)
    {
        return ;
    }
    Inorder_Traverse(my_tree->leftchild, my_fun);
    my_fun(my_tree);
    Inorder_Traverse(my_tree->rightchild, my_fun);
    return ;
}		/* -----  end of function Inorder_Traverse  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Postorder_Traverse
 *  Description:  traverse the tree with mode postorder
 * =====================================================================================
 */
    void
Postorder_Traverse ( Tree my_tree , funcpointer my_fun )
{
    if(my_tree == NULL || my_fun== NULL)
    {
        return;
    }
    Postorder_Traverse(my_tree->leftchild , my_fun);
    Postorder_Traverse(my_tree->rightchild, my_fun);
    my_fun(my_tree);
    return;
}		/* -----  end of function Postorder_Traverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Levelorder_Traverse
 *  Description:  traverse the binary tree with the mode level order
 * =====================================================================================
 */
    void
Levelorder_Traverse ( Tree my_tree , funcpointer my_fun )
{

    return ;
}		/* -----  end of function Levelorder_Traverse  ----- */
