/*
 * =====================================================================================
 *
 *       Filename:  test_path.c
 *
 *    Description:  关键路径的测试文件
 *
 *        Version:  1.0
 *        Created:  2014年08月14日 17时52分45秒
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
#include    "ol_graph.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    Graph my_graph ;
    my_graph = Init_Graph();
    Create_Graph(my_graph , "./path_graph.info");
    Print_Graph(my_graph);
    printf("\n+++++++++++++++++++++++++\n");
    Critical_Path(my_graph);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
