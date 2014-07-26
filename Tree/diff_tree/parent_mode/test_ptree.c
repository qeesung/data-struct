/*
 * =====================================================================================
 *
 *       Filename:  test_ptree.c
 *
 *    Description:  test for my ptree
 *
 *        Version:  1.0
 *        Created:  2014年07月26日 00时08分32秒
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
#include    "parent_mode.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    Ptree my_tree;
    int child_index;
    char * sib_data;
    int sib_sum;
    int k=0;
    my_tree=Init_Ptree();
    Create_Ptree(&my_tree);
    /*  test Ptree_Empty() */
    printf("********Ptree_Empty*********\n");
    if(Ptree_Empty(my_tree))
        printf("Tree is empty\n");
    else
    printf("tree is not emtpy\n");
    printf("********Ptree_Depth*********\n");
    printf("the tree depth is %d\n",Ptree_Depth(my_tree));
    printf("*************Root***********\n");
    printf("Root value is %c\n", Root(my_tree));
    printf("*************value***********\n");
    printf("The index %d value is %c\n", 4,Value(my_tree,4));
    printf("*************assign***********\n");
    Assign(my_tree , 4, 'X');
    printf("assign index 4 point after:%c\n",Value(my_tree ,4) );
    printf("\n");
    Traverse(my_tree);
    printf("*************parent***********\n");
    printf("E father is %c\n",Parent(my_tree,5));
    printf("*************Leftchild***********\n");
    printf("F leftchild is %c and", Leftchild(my_tree , 6 , &child_index)); 
    printf("child index number is :%d\n", child_index);
    printf("*************rightsib***********\n");
    printf("the G righsib is :");
    sib_data = Rightsibling(my_tree , 7, &sib_sum);
    for(k=0;k<sib_sum;k++)
    {
        printf("%c\t",sib_data[k]);
    }
    printf("\n");
    printf("*************print tree***********\n");
    Print_Ptree(my_tree); 



    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
