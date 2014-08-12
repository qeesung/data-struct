/*
 * =====================================================================================
 *
 *       Filename:  test_prim.c
 *
 *    Description:  test for my prim 
 *
 *        Version:  1.0
 *        Created:  2014年08月12日 16时47分59秒
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
   Create_Graph(my_graph , "./prim_graph.info");
   Print_Graph(my_graph);
   printf("*********************\n\n");
   Prim1(my_graph , "V1");
}
