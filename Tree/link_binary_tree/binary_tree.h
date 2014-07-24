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
struct person
{
    char * name;
    int age;
};
typedef struct person * Person;
struct tree
{
    char * name ;
    int age ;
    struct tree * leftchild;
    struct tree * rightchild;
};
typedef struct tree * Tree;
typedef void (* funcpointer ) (struct tree *);// a pointer to a function with parameter struct tree

Tree Init_Tree();
void Destory_Tree(Tree my_tree);
void Visit(struct tree  *my_tree);
void Preorder_Traverse(Tree my_tree , funcpointer my_fun);
void Inorder_Traverse(Tree  my_tree , funcpointer my_fun);
void Postorder_Traverse(Tree my_tree , funcpointer my_fun);
void Levelorder_Traverse(Tree my_tree , funcpointer my_fun);
void Create_Tree(Tree my_tree ,int leftorright,  struct person my_person );
int Tree_Empty(Tree my_tree);
int Tree_Depth(Tree my_tree);
Person Root(Tree my_tree);
Person Value(Tree my_tree_node);/*  maybe This two function need search function return result */
void Assign(Tree my_tree_node , char * name, int age);
Tree Parent(Tree my_tree , Tree my_tree_node);
Tree Find_Point(Tree my_tree, char * name , int age);
Tree Get_Leftchild(Tree my_tree_node);
Tree Get_Rightchild(Tree my_tree_node);
Tree Get_Leftsibling(Tree my_tree, Tree my_tree_node);
Tree Get_Rightsibling(Tree my_tree , Tree my_tree_node);
void Delete_Child(Tree my_tree_node, int leftorright);

#endif
