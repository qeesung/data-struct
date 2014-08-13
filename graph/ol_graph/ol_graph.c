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
#include"queue.h"
int visited[20];

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
    int k;
    new_graph	= malloc ( sizeof(struct ol_graph) );
    if ( new_graph==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_graph->vertex_number =0;
    new_graph->arcs_number =0;
    for(k=0;k<MAX_GRAPH_SIZE;k++)
    {
        new_graph->nodes[k].first_in=NULL;
        new_graph->nodes[k].first_out=NULL;
    }
    
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
        if(strcmp(name ,graph->nodes[k].vertex_name)==0)
            return k;
    }
    fprintf(stderr, "can not find %s\n", name);
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
    int k ;
    int k1;
    char buf1[20];
    char buf2[20];
    int weight;
    int number;
    int index1;
    int index2;
    List_node new_node;
    List_node temp;
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
        strcpy(graph->nodes[k].vertex_name , buf1);
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
        printf("%d----->%d\n",index1, index2);
        if(index1 == -1 && index2 ==-1)
            return;

        new_node	= malloc ( sizeof(struct list_node) );
        if ( new_node==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        new_node->head = index2;
        new_node->tail  = index1;
        new_node->next_head = graph->nodes[index2].first_in;
        new_node->next_tail = graph->nodes[index1].first_out;
        new_node->weight = weight;
        graph->nodes[index1].first_out=new_node;
        graph->nodes[index2].first_in = new_node;
/*    for(k1=0;k1<graph->vertex_number;k1++)
    {
        temp = graph->nodes[k1].first_out;
        if(temp == NULL)
            continue;
        while(temp!=NULL)
        {
            printf("%d:::%d\t",temp->tail, temp->head);
            temp=temp->next_tail;
        }
        printf("\n");
    } */
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
Destory_Graph (Graph *graph )
{
    List_node temp, temp1;
    int k=0;
    if(init_error(*graph ))
        return ;
    for(k=0;k<(*graph)->vertex_number;k++)
    {
        temp = (*graph)->nodes[k].first_out;
        while(temp!=NULL)
        {
           temp1= temp->next_tail;
           free(temp);
           temp = temp1;
        }
    }
    free(*graph);
    *graph=NULL;
    return ;
}		/* -----  end of function Destory_Graph  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Vertex
 *  Description:  得到一个点的信息 （名字）
 * =====================================================================================
 */
    char *
Get_Vertex ( Graph graph , int index )
{
    if(init_error(graph))
        return NULL;
    if(index >= graph->vertex_number)
        return NULL;
    return graph->nodes[index].vertex_name;
}		/* -----  end of function Get_Vertex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Put_Vertex
 *  Description:    将一个点重命名
 * =====================================================================================
 */
    void
Put_Vertex ( Graph graph , Vertex_name old_name , Vertex_name new_name )
{
    int index;
    if(init_error(graph))
        return;
    index =Locate_Vertex(graph , old_name);
    if(index ==-1)
        return;
    strcpy(graph->nodes[index].vertex_name , new_name);
    return ;
    
}		/* -----  end of function Put_Vertex  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  First_Adj
 *  Description:  得到一个点的第一个邻接点
 * =====================================================================================
 */
    int
First_Adj ( Graph graph , int index)
{
    if(init_error(graph))
        return -1;
    if(index >= graph->vertex_number)
        return -1;
    if(graph->nodes[index].first_out==NULL)
        return -1;
    return graph->nodes[index].first_out->head;
}		/* -----  end of function First_Adj  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Next_Adj
 *  Description:  得到下一个邻接点
 * =====================================================================================
 */
    int
Next_Adj (Graph graph , int index1 , int index2 )
{
    List_node temp;
    if(init_error(graph))
        return -1;
    if(index1 >= graph->vertex_number || index2 >= graph->vertex_number)
        return -1;
    if((temp = graph->nodes[index1].first_out)==NULL)
        return -1;
    while(temp!=NULL && temp->head != index2)
    {
        temp = temp->next_tail;
    }
    if(temp== NULL)
        return -1;
    if(temp->next_tail==NULL)
        return -1;
    return temp->next_tail->head;
}		/* -----  end of function Next_Adj  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Ver
 *  Description:  插入一个新的点
 * =====================================================================================
 */
    void
Insert_Ver ( Graph graph , Vertex_name new_name )
{
    int index;
    if(init_error(graph))
        return ;
    if(graph->vertex_number >= MAX_GRAPH_SIZE)
    {
        fprintf(stderr,"grapg size should less than %d\n", MAX_GRAPH_SIZE);
        return;
    }
    if((index = Locate_Vertex(graph , new_name))!=-1)
        return ;
    strcpy(graph->nodes[graph->vertex_number].vertex_name , new_name);
    graph->vertex_number++;
}		/* -----  end of function Insert_Ver  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Ver
 *  Description:  删除一个已经存在的点
 * =====================================================================================
 */
    void
Delete_Ver ( Graph graph , Vertex_name name )
{
    int index;
    int k;
    List_node temp1;
    List_node temp2;
    if(init_error(graph))
        return;
    if((index = Locate_Vertex(graph , name))==-1)
        return;
    printf("The vertex %s will be deleted\n",Get_Vertex(graph , index));
    for(k=0;k<graph->vertex_number;k++)
    {
        if( k == index)
            continue;
        temp1 = graph->nodes[k].first_in;
        if(temp1==NULL)
            continue;
        if(temp1->tail==index)
        {
            graph->nodes[k].first_in = temp1->next_head;
            continue;
        }
        while(temp1!=NULL && temp1->tail!=index)
        {
            temp2=temp1;
            temp1 = temp1->next_head;
        }
        if(temp1==NULL)
            continue;
        temp2->next_head  = temp1->next_head;
    }
    /* 现在将全部与点index相关联的删除 */
    for(k=0;k<graph->vertex_number;k++)
    {
        if(k == index)
            continue;
        temp1 = graph->nodes[k].first_out;
        if(temp1==NULL)
            continue;
        if(temp1->head !=index)
        {
            if(temp1->head> index )
                temp1->head--;
            if(temp1->tail> index )
                temp1->tail--;
            while(temp1->next_tail!=NULL)
            {

                if(temp1->next_tail->head>index || temp1->next_tail->tail>index)
                {
                    if(temp1->next_tail->head>index)
                        temp1->next_tail->head--;
                    if(temp1->next_tail->tail >index)
                        temp1->next_tail->tail--;
                }
                else
                {
                    if(temp1->next_tail->head==index)
                    {
                        temp2= temp1->next_tail->next_tail;
                        free(temp1->next_tail);
                        temp1->next_tail = temp2;
                        graph->arcs_number--;
                    }
                }
                temp1= temp1->next_tail;
                if(temp1==NULL)
                    break;
            }
                
        }
        
        else
        {
            temp1 = graph->nodes[k].first_out->next_tail;
            free(graph->nodes[k].first_out);
            graph->nodes[k].first_out = temp1;
            graph->arcs_number--;

            while(temp1!=NULL)
            {
                if(temp1->head > index)
                    temp1->head --;
                if(temp1->tail > index)
                    temp1->tail --;
                temp1=temp1->next_tail;
            }
            
        
        }

    }
    /*  将index的全部点删除 */
    temp1 = graph->nodes[index].first_out;
    while(temp1!=NULL)
    {
        temp2= temp1->next_tail;
        free(temp1);
        temp1=temp2;
        graph->arcs_number--;
    }
    /*  全部点向上移动 */
    for(k=index;k<graph->vertex_number-1;k++)
    {
        graph->nodes[k]= graph->nodes[k+1];
    }
    graph->vertex_number--;
    return;
}		/* -----  end of function Delete_Ver  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Arc
 *  Description:  插入一条弧
 * =====================================================================================
 */
    void
Insert_Arc (Graph  graph , Vertex_name name1, Vertex_name name2 )
{
    int index1;
    int index2;
    List_node new_node;
    int weight;
    if(init_error(graph))
        return;
    index1=Locate_Vertex(graph , name1);
    index2=Locate_Vertex(graph , name2);
    if(index1 == -1 || index2 == -1)
        return ;

    new_node	= malloc ( sizeof(struct list_node) );
    if ( new_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_node->tail = index1;
    new_node->head = index2;
    new_node->next_tail = graph->nodes[index1].first_out;
    new_node->next_head = graph->nodes[index2].first_in;
    if(graph->kind == DN)
    {
        printf("Enter new arc weight:");
        scanf("%d", &weight);
        new_node->weight = weight;
    }
    graph->nodes[index1].first_out = new_node;
    graph->nodes[index2].first_in = new_node;
    graph->arcs_number ++;
}		/* -----  end of function Insert_Arc  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Arc
 *  Description:   删除一条弧线
 * =====================================================================================
 */
    void
Delete_Arc ( Graph graph , Vertex_name name1, Vertex_name name2 )
{
    int index1;
    int index2;
    List_node temp1;
    List_node temp2;
    List_node temp3;
    List_node temp4;
    if(init_error(graph))
        return;
    index1= Locate_Vertex(graph ,name1);
    index2= Locate_Vertex(graph ,name2);
    if(index1 == -1 || index2== -1)
        return;
    /* 首先操作index2的指针变化*/
    temp1= graph->nodes[index2].first_in;
    if(temp1==NULL)
        return;
    if(temp1->tail == index1)
    {
        graph->nodes[index2].first_in = temp1->next_head;
        goto next;
    }
    while(temp1!=NULL && temp1->tail != index1)
    {
        temp2=temp1;
        temp1=temp1->next_head;
    }
    if(temp1==NULL)
        return;
    temp2->next_head = temp1->next_head;
next:
    /* index1饿得指针变化 */
    temp1=graph->nodes[index1].first_out;
    if(temp1== NULL)
        return;
    if(temp1->head != index2)
    {
        while(temp1->next_tail!=NULL && temp1->next_tail->head!=index2)
        {
            temp1 = temp1->next_tail;
        }
        if(temp1->next_tail==NULL)
            return;
        temp3=temp1->next_tail->next_tail;
        free(temp1->next_tail);
        temp1->next_tail = temp3;
    }
    else
    {
        temp2 = temp1->next_tail;
        free(temp1);
        graph->nodes[index1].first_out=temp2;
    }

    graph->arcs_number--;
    return;
}		/* -----  end of function Delete_Arc  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  dfs 
 * =====================================================================================
 */
    void
DFS ( Graph graph , int index )
{
    int k;
    List_node temp;
    if(init_error(graph))
        return;
    if(index >= graph->vertex_number)
        return;
    if(visited[index]==1)
        return;
    else
    {
        Visit(Get_Vertex(graph , index));
        visited[index]=1;
    }
    temp = graph->nodes[index].first_out;
    while(temp!=NULL)
    {
        if(visited[temp->head]==1)
        {
            temp= temp->next_tail;
            continue;
        }
        Visit(Get_Vertex(graph , temp->head));
        visited[temp->head]=1;
        if(graph->nodes[temp->head].first_out==NULL)
            continue;
        DFS(graph , graph->nodes[temp->head].first_out->head);
        temp= temp->next_tail;
    }
    return;
}		/* -----  end of function DFS  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS_Traverse
 *  Description:  
 * =====================================================================================
 */
    void
DFS_Traverse ( Graph graph )
{
    int k=0;
    for(k=0;k<graph->vertex_number;k++)
    {
        visited[k]=0;
    }
    for(k=0;k<graph->vertex_number;k++)
    {
        if(visited[k]==1)
            continue;
        DFS(graph , k);
    }
    return;
}		/* -----  end of function DFS_Traverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  BFS_Traverse
 *  Description:  
 * =====================================================================================
 */
    void
BFS_Traverse (Graph graph )
{
    int k;
    List_node temp;
    Queue_list_node dequeue_node;
    Queue my_queue;
    my_queue = Init_Queue();
    Enqueue(my_queue , 0);
    for(k=0;k<graph->vertex_number;k++)
    {
        visited[k]=0;
    }
    while((dequeue_node = Dequeue(my_queue))!=NULL)
    {
       if(visited[dequeue_node->index]==1)
           continue;
       Visit(Get_Vertex(graph , dequeue_node->index));
       visited[dequeue_node->index]=1;
       temp = graph->nodes[dequeue_node->index].first_out;
       while(temp!=NULL)
       {
            if(visited[temp->head]==1)
            {
                temp=temp->next_tail;
                continue;
            }
            Enqueue(my_queue, temp->head);
            temp=temp->next_tail;
       }
    }
        
}		/* -----  end of function BFS_Traverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Graph
 *  Description:  打印一张图
 * =====================================================================================
 */
    void
Print_Graph (Graph graph )
{
    int k;
    List_node temp;
    if(init_error(graph))
        return;
    printf("graph vertex number is %d\n", graph->vertex_number);
    printf("graph arcs number is %d\n", graph->arcs_number);
    printf("graph kind is :");
    if(graph->kind == DG)
        printf("DG\n");
    else
        printf("DN\n");
    printf("Vertex name is :");
    for(k=0;k<graph->vertex_number;k++)
    {
        printf("\t%s\t", graph->nodes[k].vertex_name);
    }
    printf("\n");
    /* first_out---------------------------------> */
    printf("/* first_out---------------------------------> */\n");
    for(k=0;k<graph->vertex_number;k++)
    {
        printf("%s::::::::", graph->nodes[k].vertex_name);
        temp = graph->nodes[k].first_out;
        if(graph->kind==DG)
        while(temp!=NULL)
        {
            printf("{%s------>%s}",graph->nodes[k].vertex_name,Get_Vertex(graph , temp->head));
            temp=temp->next_tail;
        }
        else
        while(temp!=NULL)
        {
            printf("{%s---%d--->%s}",graph->nodes[k].vertex_name,temp->weight,Get_Vertex(graph , temp->head));
            temp=temp->next_tail;
        }
        printf("\n");

    }
    printf("/* first_in---------------------------------> */\n");
    for(k=0;k<graph->vertex_number;k++)
    {
        printf("%s::::::::", graph->nodes[k].vertex_name);
        temp = graph->nodes[k].first_in;
        if(graph->kind==DG)
        while(temp!=NULL)
        {
            printf("{%s------>%s}",Get_Vertex(graph , temp->tail),graph->nodes[k].vertex_name);
            temp=temp->next_head;
        }
        else
        while(temp!=NULL)
        {
            printf("{%s---%d--->%s}",Get_Vertex(graph , temp->tail),temp->weight,graph->nodes[k].vertex_name);
            temp=temp->next_head;
        }
        printf("\n");

    }
}		/* -----  end of function Print_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Visit
 *  Description:  
 * =====================================================================================
 */
    void
Visit (char * my_name )
{
    printf("%s", my_name);
    printf("\n");
}		/* -----  end of function Visit  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Topo_Sort
 *  Description:  拓扑排序
 * =====================================================================================
 */
    void
Topo_Sort ( Graph my_graph )
{
    int k = 0 ;
    while(my_graph->vertex_number!=0)
    {
        for(k=0;k<my_graph->vertex_number;k++)
        {
            if(my_graph->nodes[k].first_in==NULL)
            {
                printf("%s\t",Get_Vertex(my_graph , k)); 
                Delete_Ver(my_graph,Get_Vertex(my_graph , k));
            }
        }
    }
}		/* -----  end of function Topo_Sort  ----- */
