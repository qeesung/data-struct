/*
 * =====================================================================================
 *
 *       Filename:  floyd.c
 *
 *    Description:  floyd算法
 *
 *        Version:  1.0
 *        Created:  2014年08月19日 10时35分07秒
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

void floyd(Graph my_graph)
{
    if(my_graph == NULL)
        return;
    int k,i,j;
    int graph_size;
    int matrix[graph_size][graph_size];
    for(i=0;i<graph_size;i++)
    {
        for(j=0;j<graph_size;j++)
        {
            matrix[i][j] = my_graph->arcs[i][j];
            if(i==j)
                matrix[i][j]=0;
        }
    }
    for(k=0;k<graph_size;k++)
    {
        for(i=0;i<graph_size;i++)
        {
            for(j=0;j<graph_size;j++)
            {
                if(matrix[i][j]> matrix[i][k]+matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k]+matrix[k][j];
                }
            }
        }
    }
    printf("********************************\n");
    for(i=0;i<graph_size;i++)
    {
        for(j=0;j<graph_size;j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

int main()
{
    Graph my_graph;
    my_graph = Init_Graph();
    Create_Graph(my_graph , "./floyd_graph.info");
    Print_Graph(my_graph);
    floyd(my_graph);
}

