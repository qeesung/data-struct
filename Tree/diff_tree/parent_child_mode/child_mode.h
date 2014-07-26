/*
 * =====================================================================================
 *
 *       Filename:  child_mode.h
 *
 *    Description:  This is header file of child mode
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 02时06分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#ifndef _CHILD_MODE_H
#define _CHILD_MODE_H
#define MAX_TREE_SIZE 256
struct tree_node
{
    char data;
    int parent;
    struct list_node * next;
};
typedef struct tree_node * Tree_node;

struct list_node
{
    int child_index;
    struct list_node * next;
};
typedef struct list_node * List_node;

struct c_tree
{
    struct tree_node nodes[MAX_TREE_SIZE];
    int number;

};
typedef struct c_tree * C_tree;

Ctree Init_Ctree();
Create(Ctree * my_tree);
#endif
