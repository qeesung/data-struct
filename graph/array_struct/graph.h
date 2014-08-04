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
typedef char Vertex_name[20];// 一个点的最长名字就是20
typedef enum {DG , DN , UDG , UDN} Graph_kind;
struct graph
{
    Vertex_name vertex_name[MAX_GRAPH_SIZE];//用来存储每个顶点的信息 现在用啦存储顶点信息
    int arcs[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];//另接矩阵
    int vertex_number ;
    int arcs_number;
    Graph_kind kind;    
};
typedef struct graph * Graph;

void err_msg(char * msg);
Graph Init_Graph();
int Locate_vertex(Graph my_graph, char * vertex_name);
void Create_Graph(Graph my_graph , char * filename);
void Create_Net(Graph my_graph , char * filename);
void Print_Graph(Graph my_graph);
void Destory_Graph(Graph my_graph);
char * Get_Vertex(Graph my_graph , int index );
void Put_Vertex(Graph my_graph , Vertex_name old_name , Vertex_name new_name);
int Get_First_Adjacent(Graph my_graph , Vertex_name name);
int Get_Next_Adjacent(Graph my_graph , Vertex_name name_i , Vertex_name name_j);
void Insert_Vertex(Graph my_graph , Vertex_name new_name);
void Insert_Arcs(Graph my_graph , Vertex_name from , Vertex_name to);

#endif
