/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.h
 *
 *    Description:  this is b binary tree header file
 *        Version:  1.0
 *        Created:  2014年07月23日 05时52分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

struct tree
{
    char * name ;
    int age ;
    struct tree * leftchild;
    struct tree * rightchild;
};
typedef struct tree * Tree;
typedef void (* funcpointer ) (struct tree);// a pointer to a function with parameter struct tree

Tree Init_Tree();
void Destory_Tree(Tree my_tree);
void Visit(struct tree  *my_tree);
void Preorder_Traverse(Tree my_tree , funcpointer my_fun);
void Inorder_Traverse(Tree  my_tree , funcpointer my_fun);
void Postorder_Traverse(Tree my_tree , funcpointer my_fun);
void Levelorder_Traverse(Tree my_tree , funcpointer my_fun);


#endif
