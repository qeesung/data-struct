/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.h
 *
 *    Description:  binary tree header file
 *
 *        Version:  1.0
 *        Created:  2014年07月20日 05时24分39秒
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

struct person {
    char * name;
    int age;
};				/* ----------  end of struct person  ---------- */
typedef struct person * Person;
typedef struct person * Tree;


struct position {
    int level;
    int number;
};				/* ----------  end of struct position  ---------- */
typedef struct position * Position;

Tree Init_Bitree();
void Create_Bitree(Tree  tree, Person my_person_list);
void Print_Bitree(Tree tree);
int Bitree_Empty(Tree tree);
int Bitree_Depth(Tree tree);
Person Bitree_Root(Tree tree);
Person Bitree_Value(Tree tree, struct position pos);

#endif
