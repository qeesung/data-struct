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

#endif
