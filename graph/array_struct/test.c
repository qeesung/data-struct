/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  测试我的数组表示图的函数s
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 15时10分12秒
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
    Graph my_graph1 ;
    Graph my_graph2 ;
    Graph my_graph3 ;
    Graph my_graph4 ;
    my_graph1 = Init_Graph();
    my_graph2 = Init_Graph();
    my_graph3 = Init_Graph();
    my_graph4 = Init_Graph();
    Create_Graph(my_graph1,"./dg_graph.info");
    Print_Graph(my_graph1);
    printf("\n*****************************************\n");
    Create_Graph(my_graph2,"./udg_graph.info");
    Print_Graph(my_graph2);
    printf("\n*****************************************\n");
    Create_Net(my_graph3 , "./dn_graph.info");
    Print_Graph(my_graph3);
    printf("\n*****************************************\n");
    Create_Net(my_graph4 , "./udn_graph.info");
    Print_Graph(my_graph4);
    printf("\n*****************************************\n");
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
