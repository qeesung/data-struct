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
    int k=0;
    Graph my_graph;
    Graph my_graph1;
    my_graph = Init_Graph();
    my_graph1 = Init_Graph();
    Create_Graph(my_graph , "./udg_graph.info");
    Create_Graph(my_graph1 , "./udg_graph.info");
    Print_Graph(my_graph);
    printf("*******Get vertex**********\n");
    printf("the v3 name  is :%s\n",Get_Vertex(my_graph , 2));
    printf("*******Put vertex**********\n");
    Put_Vertex(my_graph , "V3" ,"XXOO");
    printf("the v3 name after changed is :%s\n",Get_Vertex(my_graph , 2));
    Put_Vertex(my_graph , "XXOO" ,"V3");
    printf("******First Adjacent*********\n");
    printf("The V1 first adjacent is :%s\n",Get_Vertex(my_graph,First_Adjacent(my_graph , "V1")));
    printf("******Next Adjacent*********\n");
    printf("and next adjacent is :");
    k = Next_Adjacent(my_graph , "V1",Get_Vertex(my_graph,First_Adjacent(my_graph , "V1")));
    while(k!=-1)
    {
        printf("%s\t",Get_Vertex(my_graph,k));
        k= Next_Adjacent(my_graph , "V1", Get_Vertex(my_graph , k));
    }
    printf("\n");
    printf("****** Insert_Vertex*********\n");
    Insert_Vertex(my_graph , "QQ");
    Print_Graph(my_graph);
    printf("****** delete_Vertex*********\n");
    Delete_Vertex(my_graph , "V2");
    Print_Graph(my_graph);
    printf("********Insert Arcs*********\n");
    Delete_Vertex(my_graph , "QQ");
    Insert_Vertex(my_graph , "V2");
    Insert_Arcs(my_graph , "V1","V2");
    Insert_Arcs(my_graph , "V3","V2");
    Insert_Arcs(my_graph , "V5","V2");
    Print_Graph(my_graph);
    printf("********Delete Arcs*********\n");
    Delete_Arcs(my_graph , "V1", "V2");
    Print_Graph(my_graph);
    printf("craete a new graph---------->\n");
    Print_Graph(my_graph1);
    system("sleep 5");
    printf("************DFS_TRAVERse**********\n");
    DFS_Traverse(my_graph1 , Visit);
    system("sleep 5");
    printf("***********BFS_TRAVERE*************\n");
    BFS_Traverse(my_graph1 , Visit);
    
    free(my_graph);
    my_graph=NULL;
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
