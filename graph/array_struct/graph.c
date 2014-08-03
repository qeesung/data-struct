/*
 * =====================================================================================
 *
 *       Filename:  graph.c
 *
 *    Description:  数组表示法的C文件
 *
 *        Version:  1.0
 *        Created:  2014年08月03日 13时44分24秒
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
#include    "graph.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  err_msg
 *  Description:  处理出错信息的
 * =====================================================================================
 */
    void
err_msg ( char * msg )
{
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
}		/* -----  end of function err_msg  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Graph
 *  Description:  初始化一个图
 * =====================================================================================
 */
    Graph
Init_Graph ( )
{
    Graph new_graph;
    int k1=0, k2=0;
    new_graph	= malloc ( sizeof(struct graph) );
    if ( new_graph==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    return new_graph;
}		/* -----  end of function Init_Graph  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Locate_vertex
 *  Description:  定位一个点的坐标
 * =====================================================================================
 */
    int
Locate_vertex ( Graph my_graph , char * vertex_name)
{
    for(k=0;k<my_graph->vertex_number ;k++)
    {
        if(strcmp(vertex_name , my_graph->vertex_name[k])==0)
            return k;
        
    }
    fprintf(stderr , "can not find the point%s \n",vertex_name);
    exit(EXIT_FAILURE);
}		/* -----  end of function Locate_vertex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_DG
 *  Description:  由文件来创建一个有向图
 * =====================================================================================
 */
    void
Create_Graph ( Graph  my_graph, char * filename )
{
    FILE * my_file;
    char buf[256];
    char buf2[256];
    int k=0;
    int m=0;
    int i ;
    int j;
    if(my_graph == NULL)
        err_msg("graph have not init\n");
    if(filename == NULL)
        err_msg("filename can not be empty\n");
    if((my_file = fopen(filename , "r"))==NULL)
        err_msg("open the file :%s failed \n",filename);
    /*  得到点的个数 */
    if(fgets(buf , 256 , my_file)==NULL)
        err_msg("read file error\n");
    my_graph->vertex_number =  atoi(buf);
    if(my_graph->vertex_number > MAX_GRAPH_SIZE)
    {
        free(my_graph);
        err_msg("vertex number should less than MAX_GRAPH_SIZE\n");
    }
    /* 得到弧的个数 */
    if(fgets(buf , 256 , my_file)==NULL)
        err_msg("read file error\n");
    my_graph->arcs_number = atoi(buf);
    /*   得到这个图的类型， 有向 还是无向 */
    if(fgets(buf , 256 , my_buf )==NULL)
        err_msg("read file error\n");
    if(strcmp(buf , "DG")==0)
        my_graph->kind = DG;
    else
        my_graph->kind = UDG;
    /*  得到每个节点的名字 */
    for(k=0;k<graph->vertex_number ; k++)
    {
        if(fgets(buf ,256 , my_file)==NULL)
            err_msg("read the file error\n");
        strcpy(my_graph->vertex_name[k], buf);
    }
    /*  初始话矩阵 */
    for(k=0;k<arcs_number ;k++)
    {
       for(m=0;m<arcs_number ;m++)
        my_graph->arcs[k][m] =0 ;
    }
    /* 得到矩阵的信息  */
    for(k=0;k<my_graph->arcs_number;k++)
    {
       if( fscanf(my_file , "%s,%s",buf, buf2)==EOF)
       {
           free(my_graph);
           err_msg("read the file error\n");
       }
       i = locate_vertex(my_graph , buf);
       j = locate_vertex(my_graph , buf2);
       graph->arcs[i][j] = 1;
       if(my_graph->kind == UDG)
           graph->arcs[j][i] = 1;
    }



    

}		/* -----  end of function Create_DG  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_DN
 *  Description:  创建一个网 文件实现
 * =====================================================================================
 */
    void
Create_Net ( Graph my_graph , char * filename )
{
    FILE * my_file;
    char buf[256];
    char buf2[256];
    int k=0;
    int m=0;
    int i ;
    int j;
    int weight;
    if(my_graph == NULL)
        err_msg("graph have not init\n");
    if(filename == NULL)
        err_msg("filename can not be empty\n");
    if((my_file = fopen(filename , "r"))==NULL)
        err_msg("open the file :%s failed \n",filename);
    /*  得到点的个数 */
    if(fgets(buf , 256 , my_file)==NULL)
        err_msg("read file error\n");
    my_graph->vertex_number =  atoi(buf);
    if(my_graph->vertex_number > MAX_GRAPH_SIZE)
    {
        free(my_graph);
        err_msg("vertex number should less than MAX_GRAPH_SIZE\n");
    }
    /* 得到弧的个数 */
    if(fgets(buf , 256 , my_file)==NULL)
        err_msg("read file error\n");
    my_graph->arcs_number = atoi(buf);
    /*   得到这个网的类型， 有向 还是无向 */
    if(fgets(buf , 256 , my_buf )==NULL)
        err_msg("read file error\n");
    if(strcmp(buf , "DN")==0)
        my_graph->kind = DN;
    else
        my_graph->kind = UDN;
    /*  得到每个节点的名字 */
    for(k=0;k<graph->vertex_number ; k++)
    {
        if(fgets(buf ,256 , my_file)==NULL)
            err_msg("read the file error\n");
        strcpy(my_graph->vertex_name[k], buf);
    }
    /*  初始话矩阵 */
    for(k=0;k<arcs_number ;k++)
    {
       for(m=0;m<arcs_number ;m++)
        my_graph->arcs[k][m] =INT_MAX ;
    }
    /* 得到矩阵的信息  */
    for(k=0;k<my_graph->arcs_number;k++)
    {
       if( fscanf(my_file , "%s,%s %d",buf, buf2, &weight)==EOF)
       {
           free(my_graph);
           err_msg("read the file error\n");
       }
       i = locate_vertex(my_graph , buf);
       j = locate_vertex(my_graph , buf2);
       graph->arcs[i][j] = weight;
       if(my_graph->kind == UDN)
           graph->arcs[j][i] = weight;
    }

}		/* -----  end of function Create_DN  ----- */



