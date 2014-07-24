/*
 * =====================================================================================
 *
 *       Filename:  thread_binary_tree.h
 *
 *    Description:  define thread binary tree header file
 *
 *        Version:  1.0
 *        Created:  2014年07月24日 17时03分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */
#ifndef _THREAD_BINARY_TREE
#define _THREAD_BINARY_TREE
struct tree_node
{
    char *  data;
    struct tree_node * leftchild;
    struct tree_node * rightchild;
    int lefttag;
    int righttag;
    /*  lefttag == 0 point to leftchild 
     *  lefttag ==1 point to previous
     *  righttag ==0 point to rightchild
     *  righttag ==1 point to next*/
}
typedef struct tree_node * Tree_node;
typedef Tree_node Tree;

Tree Init_Bithrtree();// need create a header node
Craete_Bithrtree(Tree tree,int leftorright, char * data);// assign for every node

#endif
