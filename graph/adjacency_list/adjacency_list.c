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
    new_graph->arcs_number =0;
    return new_graph;
}		/* -----  end of function Init_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Craete_Graph
 *  Description:  由数据文件来创建一个图, 出错返回-1
 * =====================================================================================
 */
    int
Create_Graph ( Graph my_graph  , char * filename )
{
    List_node temp;
    List_node new_node;
    int index1 , index2;
    char buf[20];
    char buf_aim[20];
    int weight;
    int length=0;
    FILE * myfile;
    int k=0;
    if(init_error(my_graph))
        return -1;
    if(filename == NULL)
        return -1;
    /*  打开文件 */
    if((myfile = fopen(filename , "r"))==NULL)
    {
        fprintf(stderr, "\nopen the file stream failed\n");
        return -1;
    }
    /*  读取点的个数 */
    if(fgets(buf , 20 , myfile)==NULL)
    {
        fprintf(stderr, "\n fgets error\n");
        return -1;
    }
    my_graph->vertex_number = atoi(buf);
    /*  读取弧的个数 */
    if(fgets(buf , 20 , myfile)==NULL)
    {
        fprintf(stderr, "\n fgets error\n");
        return -1;
    }
    my_graph->arcs_number = atoi(buf);
    /*  读取图的类型 */
    if(fgets(buf , 20 , myfile)==NULL)
    {
        fprintf(stderr, "\n fgets error\n");
        return -1;
    }
    if(strcmp(buf , "DG\n")==0)
        my_graph->kind = DG;
    else
    {
        if(strcmp(buf , "DN\n")==0)
            my_graph->kind = DN;
        else
        {
            if(strcmp(buf , "UDN\n")==0)
                my_graph->kind = UDN;
            else
            {
                if(strcmp(buf , "UDG\n")==0)
                    my_graph->kind = UDG;
                else
                {
                    fprintf(stderr, "\n wrong graph kind\n");
                    return -1;
                }
            }
        }
    }
    /*  获取点的名字 */
    for(k=0;k<my_graph->vertex_number ; k++)
    {
        if(fgets(buf , 20 , myfile)==NULL)
        {
            fprintf(stderr, "\nfgets error\n");
            return -1;
        }
        length = strlen(buf);
        buf[length-1]='\0';
        strcpy(my_graph->nodes[k].vertex_name , buf);
    }
    /*  获取弧的信息 */
    for(k=0;k<my_graph->arcs_number ; k++)
    {
        /* 下面开始处理图 */
        if(my_graph->kind == DG || my_graph->kind == UDG)
        {
            fscanf(myfile , "%s%s",buf , buf_aim);
            index1 = Locate_Vertex(my_graph , buf);
            index2 = Locate_Vertex(my_graph , buf_aim);
            if(index1 ==-1 || index2==-1)
            {
                fprintf(stderr,"\nLocate error\n");
                return -1;
                
            }
            new_node	= malloc ( sizeof(struct list_node) );
            if ( new_node==NULL ) {
                fprintf ( stderr, "\ndynamic memory allocation failed\n" );
                exit (EXIT_FAILURE);
            }
            new_node->index=index2;
            temp = my_graph->nodes[index1].adj_list->next;
            my_graph->nodes[index1].adj_list->next = new_node;
            my_graph->nodes[index1].adj_list->next->next = temp;
            if(my_graph->kind == UDG)
            {
                new_node	= malloc ( sizeof(struct list_node) );
                if ( new_node==NULL ) {
                    fprintf ( stderr, "\ndynamic memory allocation failed\n" );
                    exit (EXIT_FAILURE);
                }
                new_node ->index = index1;
                temp = my_graph->nodes[index2].adj_list->next;
                my_graph->nodes[index2].adj_list->next = new_node;
                my_graph->nodes[index2].adj_list->next->next = temp;
            }
        
        }
        /*   下面开始处理网 */
        else
        {
            fscanf(myfile , "%s%s %d", buf , buf_aim , &weight);
            index1 = Locate_Vertex(my_graph,buf);
            index2 = Locate_Vertex(my_graph , buf_aim);
            if(index1 ==-1 || index2==-1)
                return -1;
            
            new_node	= malloc ( sizeof(struct list_node) );
            if ( new_node==NULL ) {
                fprintf ( stderr, "\ndynamic memory allocation failed\n" );
                exit (EXIT_FAILURE);
            }
            new_node->index = index2;
            new_node ->weight = weight;
            temp = my_graph->nodes[index1].adj_list->next;
            my_graph->nodes[index1].adj_list->next=new_node;
            my_graph->nodes[index1].adj_list->next->next = temp;
            if(my_graph->kind == UDN)
            {
                new_node	= malloc ( sizeof(struct list_node) );
                if ( new_node==NULL ) {
                    fprintf ( stderr, "\ndynamic memory allocation failed\n" );
                    exit (EXIT_FAILURE);
                }
                new_node->index = index1;
                new_node ->weight = weight;
                temp = my_graph->nodes[index2].adj_list->next;
                my_graph->nodes[index2].adj_list->next=new_node;
                my_graph->nodes[index2].adj_list->next->next = temp;
            }

        }
    }
    printf("create graph done\n");
    return 1;
}		/* -----  end of function Craete_Graph  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_Graph
 *  Description:  摧毁一张图
 * =====================================================================================
 */
    void
Destory_Graph ( Graph my_graph )
{
    List_node temp;
    List_node temp1;
    int k=0;
    if(init_error(my_graph))
        return ;
    for(k=0;k<my_graph->vertex_number ;k++)
    {
        temp = my_graph->nodes[k].adj_list;
        while(temp!=NULL)
        {
            temp1 = temp->next;
            free(temp);
            temp=temp1;
        }
    }
    free(my_graph);
    my_graph = NULL;

}		/* -----  end of function Destory_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Vertex
 *  Description:  得到一个点的名字
 * =====================================================================================
 */
    char * 
Get_Vertex (Graph my_graph , int index )
{
    if(init_error(my_graph))
        return NULL;
    if(index > my_graph->vertex_number)
        return NULL;
    return my_graph->nodes[index].vertex_name;
}		/* -----  end of function Get_Vertex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Graph
 *  Description:  打印一张图
 * =====================================================================================
 */
    void
Print_Graph ( Graph my_graph )
{
    int k;
    List_node temp;
    if(init_error(my_graph))
        return;
    printf("graph vertex_number is : %d\n", my_graph->vertex_number);
    printf("graph arcs number is :%d\n", my_graph->arcs_number);
    printf("graph kind is :");
    switch(my_graph->kind)
    {
        case DG:printf("DG\n");
            break;
        case UDG:printf("UDG\n");
            break;
        case DN:printf("DN\n");
            break;
        case UDN:printf("UDN\n");
            break;
        default:
            printf("unknows graph kind\n");
    }
    for(k=0;k<my_graph->vertex_number;k++)
    {
        printf("%s",my_graph->nodes[k].vertex_name);
        temp= my_graph->nodes[k].adj_list;
        while(temp->next!=NULL)
        {
            if(my_graph->kind %2 ==0)
                printf("---->%s",Get_Vertex(my_graph , temp->next->index));
            else
                printf("----%d--->%s", temp->next->weight, Get_Vertex(my_graph , temp->next->index));
            temp = temp->next;
        }
        printf("\n");
    }
    return ;

}		/* -----  end of function Print_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Put_Vertex
 *  Description:  将一个点重新赋值
 * =====================================================================================
 */
    void
Put_Vertex ( Graph my_graph , Vertex_name old_name , Vertex_name new_name)
{
    int index;
    if(init_error(my_graph))
        return ;
    index = Locate_Vertex(my_graph , old_name );
    if(index == -1)
    {
        fprintf(stderr, "\n can not find the vertex %s \n", old_name);
        return ;
    }
    strcpy(my_graph->nodes[index].vertex_name, new_name);
    return;
}		/* -----  end of function Put_Vertex  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  First_Adjver
 *  Description:  得到一个点的第一个邻接点
 * =====================================================================================
 */
    int
First_Adjver ( Graph my_graph , Vertex_name my_name )
{
    int index;
    if(init_error(my_graph))
        return -1;
    index = Locate_Vertex(my_graph , my_name);
    if(index ==-1)
    {
        fprintf(stderr, "\n can not find %s vertex \n", my_name);
        return -1;
    }
    if(my_graph->nodes[index].adj_list->next!=NULL)
        return my_graph->nodes[index].adj_list->next->index;
    else
        return -1;
}		/* -----  end of function First_Adjver  ----- */

