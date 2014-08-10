/*
 * =====================================================================================
 *
 *       Filename:  ol_list.h
 *
 *    Description:  这是十字链表的图的实现
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 15时55分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */
#ifndef _OL_GRAPH_H
#define _OL_GRAPH_H

struct list_node
{
   int head;
   int tail;
   struct list_node * next_tail;
   struct list_node * next_head;
   int weight;
};
typedef struct list_node * List_node;

typedef char Vertex_name[20];
struct vertex_node
{
    Vertex_name ver_name;
    List_node first_in;
    List_node first_out;
};
typedef struct vertex_node * Vertex_node;

struct ol_graph
{
    struct vertex_node nodes[MAX_GRAPH_SIZE];  
    int vertex_number, arcs_number;
    Graph_kind kind;
};
typedef struct ol_graph * Graph;

int init_error(Graph graph);
int Locate_Vertex(Graph graph , Vertex_name name);
Graph init_Graph();
#endif
