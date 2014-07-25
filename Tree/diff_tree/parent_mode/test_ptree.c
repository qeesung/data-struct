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
    my_tree=Init_Ptree();
    Create_Ptree(&my_tree);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
