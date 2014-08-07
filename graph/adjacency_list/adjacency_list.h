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
    int weight;
};
typedef struct list_node * List_node;
typedef List_node List;

struct graph_node 
{
    Vertex_name vertex_name;
    List adj_list;
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
typedef void ( *my_func)(Vertex_name);

int init_error(Graph my_graph);
int Locate_Vertex( Graph , Vertex_name vertex_name);
Graph Init_Graph(); 
int Create_Graph(Graph my_graph , char * filename);
void Destory_Graph(Graph);
char* Get_Vertex(Graph my_graph , int index);
void Print_Graph(Graph);
void Put_Vertex(Graph my_graph , Vertex_name old_name , Vertex_name new_name);
int First_Adjver(Graph my_graph , Vertex_name my_name);
int Next_Adjver(Graph , Vertex_name , Vertex_name);
void Insert_Ver(Graph my_graph , Vertex_name new_name);
void Delete_ver(Graph my_graph , Vertex_name del_name);
void Insert_Arcs(Graph , Vertex_name , Vertex_name);
void Delete_Arcs(Graph , Vertex_name , Vertex_name);
void Init_Visited_Array();
void Visit(Vertex_name my_name);
void DFS(Graph my_graph , int index , my_func visit);
void DFS_Traverse(Graph my_graph , my_func visit);
void BFS_Traverse(Graph my_graph, my_func visit);
#endif
