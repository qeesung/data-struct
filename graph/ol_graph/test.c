/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  测试函数
 *
 *        Version:  1.0
 *        Created:  2014年08月11日 13时59分37秒
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
#include    "queue.h"
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
    Create_Graph(my_graph , "./dn_graph.info");
    Print_Graph(my_graph);
   /* Destory_Graph(&my_graph);
    Print_Graph(my_graph);
    printf("**********Put vertex***********\n");
    Put_Vertex(my_graph , "V1", "VX");
    Print_Graph(my_graph);
    printf("**********First Adj***********\n");
    printf("V1 First_Adj is %s\n", Get_Vertex(my_graph ,First_Adj(my_graph, 0)));
    printf("**********Next Adj***********\n");
    printf("V1 next adj is %s\n", Get_Vertex(my_graph,Next_Adj(my_graph, 0, First_Adj(my_graph ,0))));
    printf("********** Insert Ver***********\n");
    Insert_Ver(my_graph ,"VX");
    Print_Graph(my_graph);
    printf("********** delete Ver***********\n");
    Delete_Ver(my_graph, "V2");
    printf("********** Insert Arc***********\n");
    Insert_Arc(my_graph ,"VX","V1");
    Print_Graph(my_graph);
    printf("********** delete Arc***********\n");
    Delete_Arc(my_graph, "V1", "V3");
    Print_Graph(my_graph);*/
    printf("**********  DFS Traverse***********\n");
    DFS_Traverse(my_graph);
    printf("**********  BFS Traverse***********\n");
    BFS_Traverse(my_graph);
    

    


    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
