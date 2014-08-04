/*
 * =====================================================================================
 *
 *       Filename:  graph.c
 *
 *    Description:  图的C文件
 *
 *        Version:  1.0
 *        Created:  2014年08月04日 22时16分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#include    <stdlib.h>
#include    <stdio.h>
#include    "graph.h"
#include    <string.h>
#include    <limits.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Graph
 *  Description:  初始化一个图
 * =====================================================================================
 */
    Graph
Init_Graph ()
{
    Graph new_graph ;
    
    new_graph	= malloc ( sizeof(struct graph) );
    if ( new_graph==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_graph->vertex_number =0;
    new_graph->arcs_number =0;

    return new_graph;

}		/* -----  end of function Init_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Locate_Vertex
 *  Description:  定位一个点的坐标 返回-1为找不到
 * =====================================================================================
 */
    int
Locate_Vertex (Graph my_graph, Vertex_name my_name)
{
    int k=0;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return -1;
    }
    for(k=0;k<my_graph->vertex_number;k++)
    {
        if(strcmp(my_graph->vertex_name[k],my_name)==0)
            return k;
    }
    return -1;
}		/* -----  end of function Locate_Vertex  ----- */
