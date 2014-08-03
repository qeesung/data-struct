/*
 * =====================================================================================
 *
 *       Filename:  graph.h
 *
 *    Description:  这是数组表示法来表示一个图
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 13时34分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#ifndef _GRAPH_H
#define _GRAPH_H
#define MAX_GRAPH_SIZE 20
typedef enum {DG , DN , UDG , UDN} Graph_kind;
struct graph
{
    char * vertex_name[MAX_GRAPH_SIZE];//用来存储每个顶点的信息 现在用啦存储顶点信息
    int arcs[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];//另接矩阵
    int vertex_number ;
    int arcs_number;
    Graph_kind kind;    
};
typedef struct graph * Graph;

Graph Init_Graph();
void Create_Graph(Graph * my_graph);
#endif
