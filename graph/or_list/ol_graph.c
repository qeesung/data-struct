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



