/*
 * =====================================================================================
 *
 *       Filename:  graph.h
 *
 *    Description:  这是一个新的自我的矩阵来存储节点的信息
 *
 *        Version:  1.0
 *        Created:  2014年08月04日 22时08分47秒
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
typedef char Vertex_name[20];
typedef void (* my_func)(Vertex_name); 
struct graph
{
    Vertex_name vertex_name[MAX_GRAPH_SIZE];
    int arcs[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];
    int vertex_number;
    int arcs_number;
    Graph_kind kind;
};
typedef struct graph * Graph;

Graph Init_Graph();
int Locate_Vertex(Graph my_graph , Vertex_name my_name);
void Create_Graph(Graph my_graph , char * filename);
void Print_Graph(Graph my_graph);
void Destory_Graoh(Graph my_graph);
char * Get_Vertex(Graph my_graph ,int index);
void Put_Vertex(Graph my_graph , Vertex_name old_name , Vertex_name new_name);
int First_Adjacent(Graph my_graph , Vertex_name my_name);
int Next_Adjacent(Graph my_graph , Vertex_name name_from , Vertex_name name_to);
void Insert_Vertex(Graph my_graph , Vertex_name my_name);
void Delete_Vertex(Graph my_graph , Vertex_name my_name);
void Insert_Arcs(Graph my_graph , Vertex_name name1 , Vertex_name name2);
void Delete_Arcs(Graph my_graph , Vertex_name name1 , Vertex_name name2);
void Visit(Vertex_name my_name);
void DFS(Graph my_graph ,int index_start);
void DFS_Traverse(Graph my_graph , my_func my_visit);
void BFS_Traverse(Graph my_graph , my_func my_visit);
#endif
