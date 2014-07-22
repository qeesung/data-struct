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

Tree Init_Tree();
void Destory_Tree(Tree tree);


#endif
