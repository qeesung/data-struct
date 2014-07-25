/*
 * =====================================================================================
 *
 *       Filename:  parent_mode.h
 *
 *    Description:  this is parent mode to show a tree
 *
 *        Version:  1.0
 *        Created:  2014年07月25日 21时36分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#ifndef _PARENT_MODE_H
#define _PARENT_MODE_H
#define MAX_TREE_SIZE 100
struct tree_node
{
    char data;
    int parent;
};
typedef struct tree_node * Tree_node;

struct ptree
{
    struct tree_node nodes[MAX_TREE_SIZE];
    int number;
};
typedef struct ptree * Ptree;
Ptree Init_Ptree();
void Create_Ptree(Ptree * my_tree);
#endif
