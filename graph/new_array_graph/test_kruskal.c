/*
 * =====================================================================================
 *
 *       Filename:  test_kruskal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 22时36分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

int main()
{
    Graph my_graph;
    my_graph = Init_Graph();
    Create_Graph(my_graph , "./kruskal_graph.info");
    Print_Graph(my_graph);
    printf("************\n");
    Kruskal(my_graph);
}
