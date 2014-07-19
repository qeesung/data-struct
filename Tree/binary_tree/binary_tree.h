/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.h
 *
 *    Description:  This is a binary tree header file
 *
 *        Version:  1.0
 *        Created:  2014年07月20日 01时53分36秒
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
#define MAX_TREE_SIZE 100
struct person
{
    char * name;
    int age;

};
typedef struct person * Person;

struct position {
    int level;
    int number;
};				/* ----------  end of struct position  ---------- */
typedef struct position * Position;
typedef struct person Tree[MAX_TREE_SIZE];// define the tree

Tree Init_Bitree();
void Destory_Bitree(Tree tree);
void Create_Bitree(Tree tree , Person my_person);
void Clear_Bitree(Tree tree);
int Bitree_Empty(Tree tree);
int Bitree_Depth(Tree tree);
Person Root(Tree tree);
Person Bitree_Value(Tree tree, Position pos);

#endif
