/*
 * =====================================================================================
 *
 *       Filename:  adjacency_list.c
 *
 *    Description:  这是图的邻接表的C文件
 *
 *        Version:  1.0
 *        Created:  2014年08月07日 17时52分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    "adjacency_list.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  init_error
 *  Description:  
 * =====================================================================================
 */
    inline int
init_error (Graph my_graph )
{
    if(my_graph == NULL)
    {
        fprintf(stderr, "\nThe graph have not init\n");
        return 1;
    }
    return 0;
}		/* -----  end of function init_error  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Locate_Vertex
 *  Description:  定位一个点的坐标
 * =====================================================================================
 */
    int
Locate_Vertex (Graph my_graph ,  Vertex_name name )
{
    int k=0;
    if(init_error(my_graph))
        return -1;
    for(k=0;k<my_graph->vertex_number;k++)
    {
        if(strcmp(my_graph->nodes[k].vertex_name, name)==0)
            return k;
    }
    return -1;
}		/* -----  end of function Locate_Vertex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Graph
 *  Description:  初始化一个graph
 * =====================================================================================
 */
    Graph
Init_Graph (  )
{
    Graph new_graph;
    int k;
    new_graph	= malloc ( sizeof(struct graph) );
    if ( new_graph==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    for(k=0;k<MAX_GRAPH_SIZE;k++)
    {

        new_graph->nodes[k].adj_list	= malloc ( sizeof(struct list_node) );
        if ( new_graph->nodes[k].adj_list==NULL ) {
            free(new_graph);
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
    }
    new_graph->vertex_number =0;
    new_graph->arcs_numebr =0;
    return new_graph;
}		/* -----  end of function Init_Graph  ----- */
