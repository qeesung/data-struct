/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  测试我的图函数是否可行 
 *
 *        Version:  1.0
 *        Created:  2014年08月04日 23时18分54秒
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
    Create_Graph(my_graph , "./udg_graph.info");
    Print_Graph(my_graph);
    free(my_graph);
    my_graph=NULL;
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
