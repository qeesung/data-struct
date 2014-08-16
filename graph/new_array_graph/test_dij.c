/*
 * =====================================================================================
 *
 *       Filename:  test_dij.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月16日 21时49分10秒
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
#include    "graph.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    Graph my_graph;
    my_graph = Init_Graph();
    Create_Graph(my_graph , "./dij_graph.info");
    Print_Graph(my_graph);
    DIJ(my_graph , 0);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
