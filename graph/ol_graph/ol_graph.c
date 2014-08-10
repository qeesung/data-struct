/*
 * =====================================================================================
 *
 *       Filename:  ol_graph.c
 *
 *    Description:  十字链表的C文件
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 16时03分56秒
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
#include<string.h>
#include"ol_graph.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  init_error
 *  Description:  检测初始化错误
 * =====================================================================================
 */
    int
init_error ( Graph graph )
{
    if(graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return 1;
    }
    return 0;

}		/* -----  end of function init_error  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Graph
 *  Description:  初始化一个图
 * =====================================================================================
 */
    Graph
Init_Graph (  )
{
    Graph new_graph;

    new_graph	= malloc ( sizeof(struct ol_graph) );
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
 *  Description:  定位一个点的索引
 * =====================================================================================
 */
    int
Locate_Vertex (Graph graph , Vertex_name name )
{
    int k=0;
    if(init_error(graph))
        return -1;
    for(k=0;k<graph->vertex_number;k++)
    {
        if(strmp(name ,graph->nodes[k].vertex_name)==0)
            return k;
    }
    fprintf(stderr, "\n can not find %s\n", name);
    return -1;
}		/* -----  end of function Locate_Vertex  ----- */

