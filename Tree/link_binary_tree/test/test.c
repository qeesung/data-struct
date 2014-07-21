/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  test for huawei mianshi
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 01时13分06秒
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

#define MAX_TREE_SIZE 50
#define None -1
typedef int * Tree;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Tree
 *  Description:  int my binary tree
 * =====================================================================================
 */
    Tree
Init_Tree ( )
{
    Tree new_tree;
    int i=0;
    new_tree	= malloc ( sizeof(int) * MAX_TREE_SIZE );
    if ( new_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    for(i=0;i<MAX_TREE_SIZE ; i++)
    {
       new_tree[i]=None;
    }

    return new_tree;
}		/* -----  end of function Init_Tree  ----- */

void Create_Tree(Tree tree)
{
    int i=0;
    if(tree == NULL)
    {
        fprintf(stderr,"\n the Tree have not init \n ");
        return;
    }
    for(i=0;i<MAX_TREE_SIZE ;i++)
    {
        tree[i]=i+1;
    }
    return ;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
