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
#include    <string.h>
#include    <limits.h>
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
    int k=0;
    for(k=0;k<my_graph->vertex_number ;k++)
    {
        if(strcmp(my_graph->vertex_name[k],vertex_name)==0)
            return k;
        
    }
    fprintf(stderr , "can not find the point : %s \n",vertex_name);
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
        err_msg("open the file failed \n");
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
    if(fgets(buf , 256 , my_file )==NULL)
        err_msg("read file error\n");
    if(strcmp(buf , "DG\n")==0)
        my_graph->kind = DG;
    else
        my_graph->kind = UDG;
    /*  得到每个节点的名字 */
    for(k=0;k<my_graph->vertex_number ; k++)
    {
        if(fgets(buf ,256 , my_file)==NULL)
            err_msg("read the file error\n");
        buf[2]='\0';
        strcpy(my_graph->vertex_name[k], buf);
        printf("%s\n",my_graph->vertex_name[k]);
    }
    /*  初始话矩阵 */
    for(k=0;k<my_graph->arcs_number ;k++)
    {
       for(m=0;m<my_graph->arcs_number ;m++)
        my_graph->arcs[k][m] =0 ;
    }
    /* 得到矩阵的信息  */
    for(k=0;k<my_graph->arcs_number;k++)
    {
       if( fscanf(my_file , "%s%s",buf, buf2)==EOF)
       {
           free(my_graph);
           err_msg("read the file error\n");
       }
       i = Locate_vertex(my_graph , buf);
       j = Locate_vertex(my_graph , buf2);
       my_graph->arcs[i][j] = 1;
       if(my_graph->kind == UDG)
           my_graph->arcs[j][i] = 1;
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
        err_msg("open the file failed \n");
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
    if(fgets(buf , 256 , my_file )==NULL)
        err_msg("read file error\n");
    if(strcmp(buf , "DN\n")==0)
        my_graph->kind = DN;
    else
        my_graph->kind = UDN;
    /*  得到每个节点的名字 */
    for(k=0;k<my_graph->vertex_number ; k++)
    {
        if(fgets(buf ,256 , my_file)==NULL)
            err_msg("read the file error\n");
        buf[2]='\0';
        strcpy(my_graph->vertex_name[k], buf);
        printf("%s\n",my_graph->vertex_name[k]);
    }
    /*  初始话矩阵 */
    for(k=0;k<my_graph->arcs_number ;k++)
    {
       for(m=0;m<my_graph->arcs_number ;m++)
        my_graph->arcs[k][m] =INT_MAX ;
    }
    /* 得到矩阵的信息  */
    for(k=0;k<my_graph->arcs_number;k++)
    {
       if( fscanf(my_file , "%s%s %d",buf, buf2, &weight)==EOF)
       {
           free(my_graph);
           err_msg("read the file error\n");
       }
       i = Locate_vertex(my_graph , buf);
       j = Locate_vertex(my_graph , buf2);
       my_graph->arcs[i][j] = weight;
       if(my_graph->kind == UDN)
           my_graph->arcs[j][i] = weight;
    }

}		/* -----  end of function Create_DN  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Graph
 *  Description:  打印一个图的全部信息
 * =====================================================================================
 */
    void
Print_Graph ( Graph my_graph )
{
    int k=0;
    int m=0;
    if(my_graph == NULL)
        err_msg("\nGraph have not init\n");
    printf("顶点数为:%d\n",my_graph->vertex_number);
    printf("弧数为:%d\n",my_graph->arcs_number);
    printf("图的类新为:");
    switch(my_graph->kind)
    {
        case DN:printf("%s\n","有向网");
            break;
        case UDN:printf("%s\n","无向网");
            break;
        case DG:printf("%s\n","有向图");
            break;
        case UDG:printf("%s\n","无向图");
            break;
        default:printf("unknown graph kind\n");
    }
    printf("图的每个顶点名字为：");
    for(k=0;k<my_graph->vertex_number;k++)
    {
        printf("%s\t",my_graph->vertex_name[k]);
    }
    printf("\n");
    printf("对应的矩阵为:\n");
    for(k=0;k<my_graph->vertex_number;k++)
    {
        for(m=0;m<my_graph->vertex_number;m++)
            printf("%d\t",my_graph->arcs[k][m]);
        printf("\n");
    }

}		/* -----  end of function Print_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_Graph
 *  Description:  摧毁一个图
 * =====================================================================================
 */
    void
Destory_Graph ( Graph my_graph )
{
    int k1,k2;
    if(my_graph == NULL)
        err_msg("\nGraph have not init\n:");
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        my_graph->vertex_name[k1] = NULL;
    }
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        for(k2=0;k2<my_graph->vertex_number;k2++)
        {
            my_graph->arcs[k1][k2]=0;
        }
    }
    my_graph->vertex_number =0;
    my_graph->arcs_number =0;
    return ;
    
    
}		/* -----  end of function Destory_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Vertex
 *  Description:  得到一个点的名字信息
 * =====================================================================================
 */
    char *
Get_Vertex ( Graph my_graph , int index)
{
    char * get_name;
    int length;
    if(my_graph == NULL)
        err_msg("\nThe graph have not init\n");
    if(index > my_graph->vertex_number)
        err_msg("\nindex should less than graph vertex number\n");
    length = strlen(my_graph->vertex_name[index]);

    get_name	= malloc ( sizeof(char) * (length+1) );
    if ( get_name==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    if(strcpy(get_name , my_graph->vertex_name[index])==NULL)
    {
        fprintf(stderr,"strcpy error\n")
            return NULL;
    }
    get_name[length] = '\0';
    return get_name;
}		/* -----  end of function Get_Vertex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Put_Vertex
 *  Description:  将一个点重新赋值
 * =====================================================================================
 */
    void
Put_Vertex ( Graph my_graph , Vertex_name old_name , Vertex_name new_name )
{
    int index;
    if(my_graph == NULL)
        err_msg("\nThe graph have not init\n");
    index = Locate_Vertex(my_graph ,old_name);
    strcpy(my_graph->vertex_name[index],new_name);
    return;
}		/* -----  end of function Put_Vertex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_First_Adjacent
 *  Description:  得到相邻的第一个点的索引
 * =====================================================================================
 */
    int
Get_First_Adjacent (Graph my_graph , Vertex_name my_name )
{
    int index ;
    int k=0;
    if(my_graph == NULL)
        err_msg("The graph is empty\n");
    index = Locate_Vertex(my_graph , my_name);
    for(k=0;k<my_graph->vertex_number;k++)
    {
        if(my_graph->arcs[index][k]==1)
            return k;
    }
    return -1;
}		/* -----  end of function Get_First_Adjacent  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Next_Adjacent
 *  Description:  得到某一个点：
 * =====================================================================================
 */
    int
Get_Next_Adjacent ( Graph my_graph , Vertex_name i , Vertex_name j)
{
    int k1, k2;
    int index_i ;
    int index_j ;
    int kind;
    if(my_graph == NULL)
        err_msg("Graph have not init\n");
    index_i = Locate_vertex(my_graph , i);
    index_j = Locate_vertex(my_graph , j);
    if(my_graph->kind%2==0)
        kind =0;
    else
        kind = INT_MAX;
    k1= index_i;
     for(k2=index_j+1;k2<vertex_number;k2++ )
     {
         if(my_graph->arcs[k1][k2]==kind)
             return k2;
     }
     fprintf(stderr,"\n can not find next adjacent point\n");
     return -1;
}		/* -----  end of function Get_Next_Adjacent  ----- */
