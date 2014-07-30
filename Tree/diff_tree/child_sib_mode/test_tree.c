/*
 * =====================================================================================
 *
 *       Filename:  test_tree.c
 *
 *    Description:  用来测试孩子兄弟树
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 20时53分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include    <stdio.h>
#include    "queue.h"
#include    "child_sib.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    
    CStree my_tree;
    Tree_node my_tree_node;
    char * sib_all;
    my_tree = Init_CStree();
    int k;
    Create_CStree(&my_tree);
    
    printf("*************Levelorder_Traverse()***************\n");
    Levelorder_Traverse(my_tree);
    printf("\n");
    printf("*************Postorder_Traverse()***************\n");
    Postorder_Traverse(my_tree);
    printf("\n");
    printf("*************CStree_Empty()***************\n");
    if(CStree_Empty(my_tree))
        printf("Tree is emtpy\n");
    else
        printf("Tree is not empty\n");
    printf("*************CStree_Depth()***************\n");
    printf("tree depth is :%d \n", CStree_Depth(my_tree));
    printf("*************Root()***************\n");
    printf("Root value is :%c\n", Root(my_tree));
    printf("************Value()***************\n");
    my_tree_node = Find_Point(my_tree , 'C'); 
    printf("C point value is %c\n",Value(my_tree_node));
    printf("*************Assign()***************\n");
    Assign(my_tree , 'C', 'X');
    my_tree_node = Find_Point(my_tree , 'X');
    printf("after assigned , we can find the node X:%c\n",Value(my_tree_node));
    printf("************Parent()***************\n");
    printf("E node parent is :%c\n", Parent(my_tree , 'E'));
    printf("*************Leftchild()***************\n");
    printf("F point leftchild is :%c\n",Leftchild(Find_Point(my_tree , 'F')));
    printf("*************Rightsibling()***************\n");
    sib_all = Rightsibling(Find_Point(my_tree , 'F'));
    for(k=1;k<(int)sib_all[0]+2;k++)
    {
        printf("%c\t", sib_all[k]);
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
