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

#define MAX_TREE_SIZE (50)
#define None (-1)
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Tree
 *  Description:  create my binary tree
 * =====================================================================================
 */
void Create_Tree(Tree tree , int number)
{
    int i=0;
    if(tree == NULL)
    {
        fprintf(stderr,"\n the Tree have not init \n ");
        return;
    }
    if(number > MAX_TREE_SIZE)
    {
        fprintf(stderr, "\n the tree size should less than %d \n ", MAX_TREE_SIZE);
        return;
    }
    for(i=0;i<number ;i++)
    {
        tree[i]=i+1;
    }
    return ;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Tree
 *  Description:  print all the massage in the tree
 * =====================================================================================
 */
    void
Print_Tree ( Tree tree )
{
    int i=0;
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree have not initn ");
        return;
    }
    for(i=0;i<MAX_TREE_SIZE;i++)
    {
        if(tree[i]!=None)
        {
            printf("***%d***\n", tree[i]);
        }
    }
    
    return;
}		/* -----  end of function Print_Tree  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Visit
 *  Description:  print the derail massage about  Integre
 * =====================================================================================
 */
    void
Visit ( int number )
{
    printf("***%d***\n" , number);
    return ;
}		/* -----  end of function Visit  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Inorder_Traverse
 *  Description:  in order traverse my binary tree
 * =====================================================================================
 */
    void
Inorder_Traverse ( Tree tree , int index )
{
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree have not init \n ");
        return;
    }
    if(tree[index]==None)
    {
        return ;
    }
    Inorder_Traverse(tree , index*2+1);
    Visit(tree[index]);
    Inorder_Traverse(tree , index*2+2);
    return;
}		/* -----  end of function Inorder_Traverse  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{

    Tree tree;
    tree=Init_Tree();
    Create_Tree(tree ,7);
    Print_Tree(tree);
    printf("\n\n");
    Inorder_Traverse(tree, 0);
    free(tree);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
