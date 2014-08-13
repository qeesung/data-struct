/*
 * =====================================================================================
 *
 *       Filename:  test_topo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月13日 21时21分42秒
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
#include    "adjacency_list.h"
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
    Create_Graph(my_graph , "topo_graph.info");
    Print_Graph(my_graph);
    printf("\n++++++++++++++++++++++++++++\n");
    Topo_Sort(my_graph);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
