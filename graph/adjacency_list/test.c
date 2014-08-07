/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  图的测试代码
 *
 *        Version:  1.0
 *        Created:  2014年08月07日 20时48分40秒
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
#include    <string.h>
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
    if((my_graph=Init_Graph())==NULL)
        return -1;
    if(Create_Graph(my_graph , "./udn_graph.info")==-1)
        return -1;
    Print_Graph(my_graph);

    printf("***********Put Vertex********\n");
    Put_Vertex(my_graph ,"V2", "X2");
    Print_Graph(my_graph);
    Put_Vertex(my_graph ,"X2", "V2");
    printf("***********Fisrt Adjacent********\n");
    printf("V2 first Adjacent is :%s\n", Get_Vertex(my_graph , First_Adjver(my_graph, "V2")));
    printf("***********Next Adjacent********\n");
    printf("V2 to V5 next adjacent is %s\n" , Get_Vertex(my_graph , Next_Adjver(my_graph , "V2", "V5"))); 
    printf("V2 to V3 next adjacent is %s\n" , Get_Vertex(my_graph , Next_Adjver(my_graph , "V2", "V3"))); 
  /*  printf("***********Insert_Ver********\n");
    printf("After insert the new vertex V6\n");
    Insert_Ver(my_graph , "V6");
    Print_Graph(my_graph);
    printf("After delete the  vertex V3\n");
    Delete_Ver(my_graph , "V3");
    Print_Graph(my_graph);
    printf("After insert the new arcs  V1 V6\n");
    Insert_Arcs(my_graph , "V1", "V6");
    Print_Graph(my_graph);
    printf("After insert the new arcs  V2 V6\n");
    Insert_Arcs(my_graph , "V2", "V6");
    Print_Graph(my_graph);
    printf("After insert the new arcs  V2 V1\n");
    Insert_Arcs(my_graph , "V2", "V1");
    Print_Graph(my_graph);
    printf("After delete the  arcs  V2 V1\n");
    Delete_Arcs(my_graph , "V2", "V1");
    Print_Graph(my_graph);
    printf("After delete the  arcs  V2 V6\n");
    Delete_Arcs(my_graph , "V2", "V6");
    Print_Graph(my_graph);
    printf("After insert the new arcs  V1 V6\n");
    Delete_Arcs(my_graph , "V1", "V6");
    Print_Graph(my_graph);*/
    printf("*********DFS*******\n");
    Init_Visited_Array();
    DFS(my_graph , 0, Visit);
    printf("*********DFS*******\n");
    Init_Visited_Array();
    DFS(my_graph , 1, Visit);
    printf("*********DFS*******\n");
    Init_Visited_Array();
    DFS(my_graph , 3, Visit);
    printf("*********DFS_Traverse********\n"); 
    DFS_Traverse(my_graph , Visit);
    printf("********BFS_Traverse********\n");
    BFS_Traverse(my_graph , Visit);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
