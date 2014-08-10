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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Graph
 *  Description:  创建一个图 通过一个文件
 * =====================================================================================
 */
    void
Create_Graph ( Graph graph , char * filename )
{
    FILE * myfile;
    int length;
    int k;
    char buf1[20];
    char buf2[20];
    int weight;
    int number;
    int index1;
    int index2;
    List_node new_node;
    if(init_error(graph))
        return;
    if(filename == NULL)
    {
        fprintf(stderr, "filename can not be empty\n");
        return ;
    }
    /*  打开文件 */
    if((myfile = fopen(filename, "r"))==NULL)
    {
        fprintf(stderr, "open file failed\n");
        return;
    }
    /*  读取点个数 */
    fscanf(myfile , "%d", &number);
    graph->vertex_number = number;
    /*  读取弧个数 */
    fscanf(myfile , "%d", &number);
    graph->arcs_number = number;
    /*   读取图的类型 */
    fscanf(myfile , "%s", buf1);
    if(strcmp(buf1 , "DG")==0)
        graph->kind=DG;
    else
    {
        if(strcmp(buf1 , "DN")==0)
            graph->kind = DN;
        else
        {
            fprintf(stderr,"unknown graph kind\n");
            return;
        }
    }
    
    /*  读取点的名字 */
    for(k=0;k<graph->vertex_number;k++)
    {
        fscanf(myfile , "%s", buf1);
        strcmp(graph->nodes[k].vertex_name , buf1);
    }
    /* 读取弧的信息 */
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
        if(index1 == -1 && index2 ==-1)
            return;

        new_node	= malloc ( sizeof(struct list_node) );
        if ( new_node==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        new_node->head = index1;
        new_node->tail  = index2;
        new_node->next_head = graph->nodes[index2].first_in;
        new_node->next_tail = graph->nodes[index1].first_out;
        new_node->weight = weight;
        graph->nodes[index1].first_in=new_node;
        graph->nodes[index2].first_out = new_node;
    }
    return;

}		/* -----  end of function Create_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_Graph
 *  Description:  摧毁一张图
 * =====================================================================================
 */
    void
Destory_Graph (Graph graph )
{
    List_node temp, temp1;
    int k=0;
    if(init_error(graph ))
        return ;
    for(k=0;k<graph->vertex_number;k++)
    {
        temp = graph->nodes[k].first_out;
        while(temp!=NULL)
        {
           temp1= temp->next_tail;
           free(temp);
           temp = temp1;
        }
    }
    free(graph);
    graph=NULL;
    return ;
}		/* -----  end of function Destory_Graph  ----- */
