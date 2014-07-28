/*
 * =====================================================================================
 *
 *       Filename:  test_tree.c
 *
 *    Description:  this is a test file for my tree of child mode
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 21时57分37秒
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
#include    "child_mode.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    Ctree my_tree;
    char * all_data;
    char ch;
    int index;
    int k=0;
    my_tree = Init_Ctree();
    Create_Ctree(&my_tree);
    printf("***************Traverse_Ctree()*************\n");
    Traverse_Ctree(my_tree);
    printf("**************Ctree_Empty()*************\n");
    if(Ctree_Empty(my_tree))
        printf("Tree is empty\n");
    else
        printf("Tree is not empty\n");
    printf("**************Ctree_Depth()*************\n");
    printf("Tree depth is %d\n", Ctree_Depth(my_tree));
    printf("**************Root()*************\n");
    printf("Root value is :%c\n",Root(my_tree));
    printf("*************value()*************\n");
    printf("Index 4 value is:%c\n", Value(my_tree, 4));
    printf("*************Assigni()*************\n");
    Assign(my_tree, 4, 'X');
    printf("After assign the index 4,value is :%c\n", Value(my_tree,4));
    Assign(my_tree, 4, 'D');
    printf("*************Parent()*************\n");
    printf("G index panret is :%c\n",Parent(my_tree , 7));
    printf("*************Leftchild()*************\n");
    ch = Leftchild(my_tree , 1,&index);
    printf("A point left child is %c and index is :%d\n", ch , index);
    printf("*************Rightsibling()*************\n");
    all_data=Rightsibling(my_tree , 7);
    if(all_data==NULL)
    {
        fprintf(stderr,"Rightsiling error\n");
        return -1;
    }
    printf("G point rightsinling is :");
    for(k=1;k<(int)all_data[0]+1;k++)
    {
        printf("%c\t",all_data[k]);
    }
    printf("\n");
    printf("*************Print_tree()*************\n");
    Print_Ctree(my_tree);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
