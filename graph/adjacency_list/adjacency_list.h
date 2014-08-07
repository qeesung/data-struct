/*
 * =====================================================================================
 *
 *       Filename:  adjacency_list.h
 *
 *    Description:  邻接链表的头文件
 *
 *        Version:  1.0
 *        Created:  2014年08月07日 17时53分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#ifndef _ADJACENCY_LIST_H
#define _ADJACENCY_LIST_H
#define MAX_GRAPH_SIZE 20

typedef enum {DG, DN , UDG , UDN} Graph_kind;
typedef char Vertex_name[10];
struct list_node
{
    int index;
    struct list_node * next;
};
typedef struct list_node * List_node;
typedef List_node List;

struct graph_node 
{
    Vertex_name vertex_name;
    List adjacent_vertex;
};
typedef struct graph_node * Graph_node;

struct graph
{
    struct graph_node nodes[MAX_GRAPH_SIZE];
    int vertex_number;
    int arcs_number;
    Graph_kind kind;
};
typedef struct graph * Graph;
int Locate_Vertex(Vertex_name vertex_name);
Graph Init_Graph(); 
int Create_Graph(Graph my_graph , char * filename);
#endif
