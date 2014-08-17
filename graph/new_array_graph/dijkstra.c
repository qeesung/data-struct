/*
 * =====================================================================================
 *
 *       Filename:  dijkstra.c
 *
 *    Description:  这个是第二次编写dijkstra算法
 *
 *        Version:  1.0
 *        Created:  2014年08月17日 19时55分59秒
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

struct dij_vertex 
{
    int parent;
    int weight;
};
void Dijkstra(Graph my_graph , int index)
{
    if(my_graph == NULL)
    {
        fprintf(stderr, "The graph have not init\n");
        return ;
    }
    if(index >= my_graph->vertex_number)
    {
        fprintf(stderr, "The index should less than the %d\n", my_graph->vertex_number);
        return ;
    }
    int k1,k2,k3,k4;
    int min;
    struct dij_vertex nodes[my_graph->vertex_number];
    int visited[my_graph->vertex_number];
    /* 初始化两个数组 */
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        visited[k1]=0;
        nodes[k1].parent = -1;
        nodes[k1].weight = my_graph->arcs[index][k1];
        if(nodes[k1].weight!=INT_MAX)
            nodes[k1].parent = index;
    }
    nodes[index].weight = 0;
    visited[index]=1;
    printf("hello!\n");
    fflush(stdout);
    for(k1=1;k1<my_graph->vertex_number;k1++)
    {
        min = 300000;
        for(k2=0;k2<my_graph->vertex_number;k2++)
        {
            if(!visited[k2] && nodes[k2].weight<min)
            {
                k3 = k2;
                min = nodes[k2].weight;
            }
        }
        visited[k3]=1;
        for(k4=0;k4<my_graph->vertex_number;k4++)
        {
            if(visited[k4]==0 && my_graph->arcs[k3][k4]+nodes[k3].weight < nodes[k4].weight)
            {
                nodes[k4].weight = nodes[k3].weight + my_graph->arcs[k3][k4];
                nodes[k4].parent = k3;
            }
        }
    }
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        printf("parent:%d+++weight:%d\n",nodes[k1].parent , nodes[k1].weight);
    }
    printf("helo2\n");
    fflush(stdout);
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        printf("%s+++%d+++", Get_Vertex(my_graph , k1), nodes[k1].weight);
        k2 = nodes[k1].parent;
        while(k2!=-1)
        {
            printf("%s--->", Get_Vertex(my_graph, k2)); 
            k2 = nodes[k2].parent;
        }
        printf("\n");
    }
    printf("hello3");
    fflush(stdout);
}


int main()
{
    Graph my_graph;
    my_graph = Init_Graph();
    Create_Graph(my_graph , "./dij_graph.info");
    Print_Graph(my_graph);
    printf("********************\n");
    Dijkstra(my_graph , 0);
}
