/*
 * =====================================================================================
 *
 *       Filename:  warshall.c
 *
 *    Description:  测试我的warshall算法
 *
 *        Version:  1.0
 *        Created:  2014年08月19日 09时22分56秒
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
#include"../../graph/new_array_graph/graph.h"
#include"../../graph/new_array_graph/queue.h"
/*  这里要采用fifo将数据指针传送过来 */
void warshall(Graph my_graph)
{
    if(my_graph==NULL)
    {
        fprintf(stderr,"The graph have not init\n");
        return;
    }
    int k,i,j;
    int graph_size = my_graph->vertex_number;
    int matrix[graph_size][graph_size];
    for(i=0;i<graph_size;i++)
    {
        for(j=0;j<graph_size;j++)
        {
            matrix[i][j] = my_graph->arcs[i][j];
        }
    }
    for(k=0;k<graph_size;k++)
    {
        for(i=0;i<graph_size;i++)
        {
            for(j=0;j<graph_size;j++)
            {
                if(matrix[i][k]==1 && matrix[k][j]==1)
                {
                    matrix[i][j]=1;
                }
            }
        }
    }
    for(i=0;i<graph_size;i++)
    {
        for(j=0;j<graph_size;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

}
int main()
{   
    Graph my_graph;
    my_graph = Init_Graph();
    Create_Graph(my_graph , "./warshall_graph.info");
    Print_Graph(my_graph);
    printf("*************************\n");
    warshall(my_graph);

}
