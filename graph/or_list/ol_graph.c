/*
 * =====================================================================================
 *
 *       Filename:  ol_graph.c
 *
 *    Description:  这是十字链表的C文件
 *
 *        Version:  1.0
 *        Created:  2014年08月08日 21时47分41秒
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
#include"ol_graph.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  init_error
 *  Description:  初始化检测函数
 * =====================================================================================
 */
    inline int
init_error ( OL_graph graph )
{
    if(graph == NULL)
    {
        fprintf(stderr,"the graph have not init\n");
        return 1;
    }
    return 0;
}		/* -----  end of function init_error  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Locate_Ver
 *  Description:  定位一个点的函数
 * =====================================================================================
 */
    int
Locate_Ver ( OL_graph graph , Vertex_name name )
{
    int k;
    if(init_error(graph))
        return -1;
    if(name == NULL)
        return -1;
    for(k=0;k<vertex_number;k++)
    {
        if(strcmp(graph->nodes[k].vertex_name, name)==0)
            return k;
    }
    printf("can not find vertex %s \n", name);
    return -1;
}		/* -----  end of function Locate_Ver  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Graph
 *  Description:  初始话一个图
 * =====================================================================================
 */
    OL_graph
Init_Graph (  )
{
    OL_graph new_graph;
    int k;
    new_graph	= malloc ( sizeof(struct ol_graph) );
    if ( new_graph==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    /*  创建头节点 */
    for(k=0;k<MAX_GRAPH_SIZE;k++)
    {
        
        new_graph->nodes[k].first_in	= malloc ( sizeof(struct arcbox) );
        if ( new_graph->nodes[k].first_in==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        new_graph->nodes[k].first_in->next_head=NULL;
        new_graph->nodes[k].first_in->next_tail=NULL;


        new_graph->nodes[k].first_out	= malloc ( sizeof(struct arcbox) );
        if ( new_graph->nodes[k].first_out==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        new_graph->nodes[k].first_out->next_head=NULL;
        new_graph->nodes[k].first_out->next_tail=NULL;

    }

    return new_graph;
}		/* -----  end of function Init_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Graph
 *  Description:  由文件来创建一个图
 * =====================================================================================
 */
    void
Create_Graph ( OL_graph graph , char * filename )
{
    /* 现在这个图的类型只创建有向图 */
    FILE * myfile;
    int length;
    char buf1[20];
    char buf2[20];
    int number;
    int weight;
    int k=0;
    int index1;
    int index2;
    Arcbox new_arc;
    if(init_error(graph))
        return ;
    if(filename == NULL)
    {
        fprintf(stderr,"filname can not be empty\n");
        return;
    }
    /*打开文件 */
    if((myfile = fopen(filename , "r"))==NULL)
    {
        fprintf(stderr, "\n open the file faield\n");
        return ;
    }
    /*  获得点的个数 */
    fscanf(myfile , "%d", &number);
    graph->vertex_number = number;
    /* 获取弧的个数 */
    fscanf(myfile , "%d", &number);
    graph->arcs_number = number;
    /*  获取图的类型 */
    fscanf(myfile , "%s", buf1);
    if(strcmp(buf1 , "DG")==0)
        graph->kind = DG;
    else
    {
        if(strcmp(buf1, "DN")==0)
            graph->kind = DN;
        else
        {
            fprintf(stderr, "unknown graph kind\n");
            return;
        }
    }
    /* 获取点的名字信息 */
    for(k=0;k<graph->vertex_number;k++)
    {
        fscanf(myfile , "%s%s", buf1);
        strcpy(graph->nodes[k].vertex_name , buf1);
    }
    /*  获取弧的信息 */
    for(k=0;k<graph->arcs_number;k++)
    {
        if(graph->kind == DG)
        {
            fscanf(myfile , "%s%s", buf1 , buf2);
        }
        else
        {
            fscanf(myfile , "%s%s %d", buf1 , buf2, &weight);
        }
        index1 = Locate_Vertex(graph , buf1);
        index2 = Locate_Vertex(graph , buf2);
        if(index1 == -1 || index2 == -1)
            return ;
        
        new_arc	= malloc ( sizeof(struct arcbox) );
        if ( new_arc==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }

        new_arc->next_head = graph->nodes[index2].first_in;
        new_arc->next_tail = graph->nodes[index1].first_out;
        new_arc->head = index2;
        new_arc->tail = index1;
        if(graph->kind == DN)
            new_arc->weight = weight;
    }



}		/* -----  end of function Create_Graph  ----- */
