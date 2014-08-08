/*
 * =====================================================================================
 *
 *       Filename:  ol_graph.h
 *
 *    Description: 这个是十字链表的头文件 
 *
 *        Version:  1.0
 *        Created:  2014年08月08日 21时38分46秒
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
#define MAX_GRAPH_SIZE 20
struct arcbox
{
    int headvex;
    int tailvex;
    struct arcbox * next_head;
    struct arcbox * next_tail;
    int weight;
};
typedef struct arcbox * Arcbox;

typedef char Vertex_name[20];
struct vertex
{
    Vertex_name vertex_name;
    struct arcbox * first_in;
    struct arcbox * firstout;
} ;  
typedef struct vertex Vertex;

struct ol_graph
{
    struct vertex nodes[MAX_GRAPH_SIZE];
    int vertex_number;
    int arcs_number;
    int graph_kind;
};
typedef struct ol_graph * OL_graph;

int init_error(OL_graph);
int Locate_Ver(OL_graph , Vertex_name name);
OL_graph Init_Graph();



#endif
