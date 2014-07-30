/*
 * =====================================================================================
 *
 *       Filename:  child_sib.h
 *
 *    Description:  this is child sib mode header file
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 18时49分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#ifndef _CHILD_SIB_H
#define _CHILD_SIB_H

struct tree_node
{
    char data;
    struct tree_node * firstchild;
    struct tree_node * nextsibling;
};
typedef struct tree_node * Tree_node;
typedef Tree_node CStree;/*  CS ---> child sibling */

CStree Init_CStree();
void Create_CStree(CStree * my_tree);
int CStree_Empty(CStree my_tree);
int CStree_Depth(CStree my_tree);
char Root(CStree my_tree);
char Value(Tree_node tree_node);
Tree_node Find_Point(CStree my_tree , char data);
Tree_node Assign(CStree my_tree , char old_value , char new_value);
char Parent(CStree my_tree , char data);
char Leftchild(Tree_node my_tree_node);
char * Rightsibling(Tree_node my_tree_node);
void Postorder_Traverse(CStree my_tree);
void Levelorder_Traverse(CStree my_tree);
#endif
