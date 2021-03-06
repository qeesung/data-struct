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
#define MAX_TREE_SIZE 100
#define MAX_BUF_SIZE 256
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

struct ctree
{
    struct tree_node nodes[MAX_TREE_SIZE];
    int number;

};
typedef struct ctree * Ctree;
void err_sys(char * err_msg);
Ctree Init_Ctree();
void Create_Ctree(Ctree * my_tree);
int Ctree_Empty(Ctree my_tree);
int Ctree_Depth(Ctree my_tree);
char Root(Ctree my_tree);
char Value(Ctree my_tree , int index);
void Assign(Ctree my_tree , int index , char new_value);
char Parent(Ctree my_tree , int child_index);
char Leftchild(Ctree my_tree , int parent_index, int * child_index);
char * Rightsibling(Ctree my_tree , int leftchild_index );
void Print_CTree(Ctree my_tree);
void Traverse_CTree(Ctree my_tree);
#endif
