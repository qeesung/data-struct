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
    my_tree = Init_Ctree();
    Create_Ctree(&my_tree);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
