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
#include    "queue.h"
#include    "child_sib_mode/child_sib.h"
#include    <limits.h>
int visited[MAX_GRAPH_SIZE];
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
        new_graph->nodes[k].adj_list->next=NULL;
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



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Next_Adjver
 *  Description:  得到一条弧的下一个的邻接点
 * =====================================================================================
 */
    int
Next_Adjver ( Graph my_graph , Vertex_name name1 , Vertex_name name2 )
{
    List_node temp;
    int index;
    if(init_error(my_graph))
        return -1;
    if(name1 == NULL || name2==NULL)
        return -1;
    if((index = Locate_Vertex(my_graph , name1))==-1)
    {
        fprintf(stderr,"\n can not find the %s vertex\n", name1);
        return -1;
    }
    temp = my_graph->nodes[index].adj_list;
    while(temp->next!=NULL && strcmp(Get_Vertex(my_graph , temp->next->index), name2)!=0)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
        return -1;
    if(temp->next->next!=NULL)
        return temp->next->next->index;
    else
        return -1;
}		/* -----  end of function Next_Adjver  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Ver
 *  Description:  在图里插入一个点 
 * =====================================================================================
 */
    void
Insert_Ver ( Graph my_graph, Vertex_name new_name )
{
    if(init_error(my_graph))
        return;
    if(my_graph->vertex_number >= MAX_GRAPH_SIZE)
    {
        fprintf(stderr, "\ngraph is full\n");
        return;
    }
    strcpy(my_graph->nodes[my_graph->vertex_number].vertex_name , new_name);
    my_graph->vertex_number++;
    return ;
}		/* -----  end of function Insert_Ver  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Ver
 *  Description:  删除一个点 并且弧全部删除掉
 * =====================================================================================
 */
    void
Delete_Ver ( Graph my_graph , Vertex_name del_name )
{
    int index;
    int k=0;
    List_node temp;
    List_node temp1;
    if(init_error(my_graph))
        return;
    if(del_name == NULL)
        return;
    if((index = Locate_Vertex(my_graph , del_name))==-1)
    {
        fprintf(stderr, "\ncan not find the %s vertex\n", del_name);
        return;
    }
    /*  首先删除掉所有的无向图的对称边 */
    for(k=0;k<my_graph->vertex_number;k++)
    {
        if(k==index)
            continue;
        temp = my_graph->nodes[k].adj_list;
        while(temp->next!=NULL)
        {
            
           if(temp->next->index > index)
           {
                temp->next->index--;
           }
           else
           {
                if(temp->next->index == index)
                {
                    temp1 = temp->next->next;
                    free(temp->next);
                    temp->next =temp1;
                }

           }
           temp=temp->next;
           if(temp == NULL)
               break;
        }
        
    }
    /*  现在删除掉点对应的所有邻接点 */
    temp = my_graph->nodes[index].adj_list;
    while(temp!=NULL)
    {
        temp1= temp->next;
        free(temp);
        temp = temp1;
    }
    temp=NULL;
    /*  开始将数组向上移动 */
    for(k = index ; k<my_graph->vertex_number-1 ; k++)
    {
       my_graph->nodes[k]= my_graph->nodes[k+1]; 
    }
    my_graph->vertex_number--;
    return;

}		/* -----  end of function Delete_Ver  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Arcs
 *  Description:  插入一条弧
 * =====================================================================================
 */
    void
Insert_Arcs ( Graph my_graph , Vertex_name name_from, Vertex_name name_to )
{
    int index1 ;
    int index2;
    List_node temp,temp1;
    List_node new_node;
    int weight;
    if(init_error(my_graph))
        return;
    if(name_from == NULL || name_to == NULL)
        return ;
    index1= Locate_Vertex(my_graph,name_from);
    index2= Locate_Vertex(my_graph ,name_to);
    if(index1==-1 || index2==-1)
    {
        fprintf(stderr,"\ncan not find the %s or %s vertex\n", name_from, name_to);
        return;
    }
    temp = my_graph->nodes[index1].adj_list;
    /*   检测这条弧是否已经存在 */
    while(temp->next!=NULL)
    {
        if(temp->next->index == index2)
            return;
        temp= temp->next;
    }
    temp = my_graph->nodes[index1].adj_list;
    
    new_node	= malloc ( sizeof(struct list_node) );
    if ( new_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_node -> index = index2;
    if(my_graph->kind % 2 !=0)
    {
        printf("Enter the arcs weight:");
        scanf("%d", &weight);
        new_node->weight = weight;
    }
    temp1= temp->next;
    temp->next=new_node;
    temp->next->next = temp1;
    if(my_graph->kind >1)
    {
        temp = my_graph->nodes[index2].adj_list;
        
        new_node	= malloc ( sizeof(struct list_node) );
        if ( new_node==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        new_node -> index = index1;
        if(my_graph->kind %2 !=0)
            new_node->weight = weight;
        temp1 = temp->next;
        temp->next = new_node;
        temp->next->next = temp1;
    }
    my_graph->arcs_number++;
}		/* -----  end of function Insert_Arcs  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Arcs
 *  Description:  删除对应的弧线
 * =====================================================================================
 */
    void
Delete_Arcs ( Graph my_graph , Vertex_name name_from , Vertex_name name_to )
{
    int index1 ;
    int index2;
    List_node temp;
    List_node temp1;
    if(init_error(my_graph))
        return;
    index1 = Locate_Vertex(my_graph , name_from );
    index2 = Locate_Vertex(my_graph , name_to );
    if(index1 ==-1 || index2==-1)
    {
        fprintf(stderr, "\ncan not find %s or %s vertex \n", name_from , name_to);
        return;
    }
    temp = my_graph->nodes[index1].adj_list ;
    while(temp->next!=NULL &&  temp->next->index !=index2)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)/*  找不到这条弧 */
        return ;
    else
    {
        /*  找到了这条弧  删除 */
        temp1 = temp->next->next;
        free(temp->next);
        temp->next=temp1;
    }
    if(my_graph ->kind >1)
    {
        temp = my_graph->nodes[index2].adj_list ;
        while(temp->next!=NULL && temp->next->index !=index1)
        {
            temp=temp->next;
        }
        /*  找到了这条弧  删除 */
        if(temp->next==NULL)
            return ;
        temp1 = temp->next->next;
        free(temp->next);
        temp->next=temp1;

    }
    my_graph->arcs_number--;

}		/* -----  end of function Delete_Arcs  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Visited_Array
 *  Description:  初始化我的访问数组
 * =====================================================================================
 */
    void
Init_Visited_Array (  )
{
    int k=0;
    for(k=0;k<MAX_GRAPH_SIZE;k++)
    {
        visited[k]=0;
    }
    return;
}		/* -----  end of function Init_Visited_Array  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Visit
 *  Description:  我的节点访问函数
 * =====================================================================================
 */
    void
Visit ( Vertex_name my_name )
{
    printf("%s\n",my_name );
    return;
}		/* -----  end of function Visit  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  深度遍历 从任意一个点开始
 * =====================================================================================
 */
    void
DFS ( Graph my_graph , int index , my_func visit)
{
    List_node temp;
    if(init_error(my_graph))
        return ;
    if(index >= my_graph->vertex_number)
        return;
    if(visited[index]==1)
        return;
    visit(my_graph->nodes[index].vertex_name);
    visited[index]=1;/*   表明已经访问过了 */
    temp = my_graph->nodes[index].adj_list;
    while(temp->next != NULL)
    {
        DFS(my_graph , temp->next->index, visit);
        temp = temp->next;
    }
}		/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS_Traverse
 *  Description:  深度遍历 从第一颗开始
 * =====================================================================================
 */
    void
DFS_Traverse ( Graph my_graph , my_func visit)
{
    int k=0;
    if(init_error(my_graph))
        return;
    Init_Visited_Array();
    for(k=0;k<my_graph->vertex_number ;k++)
    {
        DFS(my_graph  , k , visit);
    }
    return;
}		/* -----  end of function DFS_Traverse  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  BFS_Traverse
 *  Description:  广度遍历
 * =====================================================================================
 */
    void
BFS_Traverse ( Graph my_graph , my_func  visit )
{
    List_node temp;
    Queue my_queue;
    Queue_list_node dequeue_node;
    /*  这里需要一个队列 */
    if(init_error(my_graph))
        return ;
    Init_Visited_Array();;
    my_queue=Init_Queue();
    Enqueue(my_queue , 0);
    while((dequeue_node= Dequeue(my_queue))!=NULL)
    {
        if(visited[dequeue_node->index]==1)
            continue;
        visit(Get_Vertex(my_graph , dequeue_node->index));
        visited[dequeue_node->index]=1;
        temp = my_graph->nodes[dequeue_node->index].adj_list;
        while(temp->next!=NULL)
        {
            if(visited[temp->next->index]!=1)
                Enqueue(my_queue, temp->next->index);
            temp=temp->next;
        }
    }
    return ;
}		/* -----  end of function BFS_Traverse  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS_Forest
 *  Description:  最小生成森林
 * =====================================================================================
 *
    void
DFS_Forest ( Graph my_graph , CStree * my_tree )
{
    Tree_node new_node;
    Tree_node temp_node;
    int k;
    for(k=0;k<my_graph->vertex_number;k++)
    {
        visited[k]=0;
    }
    for(k=0;k<my_graph->vertex_number;k++)
    {

        if(visited[k]==1)
            continue;
        new_node	= malloc ( sizeof(struct tree_node) );
        if ( new_node==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        new_node->firstchild = NULL;
        new_node->nextsibling = NULL;
        new_node->data = Get_Vertex(my_graph , k);
        if(*my_tree == NULL)// root
            *my_tree = new_node;
        else
            temp_node->nextsibling = new_node;

        temp_node = new_node;
        // 现在开始最小生成树
        GFS_Tree(my_graph, k , &temp_node);

    }
    return;
}		/* -----  end of function DFS_Forest  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS_Tree
 *  Description:  从一个节点生成一棵树
 * =====================================================================================
 *
    void
DFS_Tree ( Graph my_graph , int index ,Tree_node * my_tree_node )
{
    Tree_node new_node;
    int k;
    int first = 0;
    for(k=FirstAdjver(my_graph , index);k!=-1;k=Next_Adjver(my_graph , Get_Vertex(my_graph , index), Get_Vertex(my_graph, k)))
    {
        if(visited[k]==1)
            continue;
            
        new_node	= malloc ( sizeof(struct tree_node) );
        if ( new_node==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        new_node->firstchild = NULL;
        new_node->nextsibling = NULL;
        new_node->data = Get_Vertex(my_graph , k);
        if(first== 0)
        {
            (*my_tree_node)->firstchild = new_node;
            first= 1;
        }
        else
            (*my_tree_node)->nextsibling = new_node;
        *my_tree_node = new_node;
        DFS_Tree(my_graph , k , &new_node);
    }
}		/* -----  end of function DFS_Tree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Topo_Sort
 *  Description:  拓扑排序
 * =====================================================================================
 */
    void
Topo_Sort ( Graph my_graph )
{
    if(my_graph == NULL)
    {
        fprintf(stderr, "\nThe graph have not init\n");
        return;
    }
    int indegree[my_graph->vertex_number];
    int k;
    int count=0;
    List_node temp;
    /* 初始化我的入度数组 */
    for(k=0;k<my_graph->vertex_number;k++)
        indegree[k]=0;
    for(k=0;k<my_graph->vertex_number;k++)
    {
        temp = my_graph->nodes[k].adj_list;
        while(temp->next!=NULL)
        {
            indegree[temp->next->index]++;
            temp = temp->next;
        }
    
    }
    for(k=0;k<my_graph->vertex_number;k++)
    {
        printf("#%d::%d\t",k,indegree[k]);
    }
    printf("\n");
    fflush(stdout);


    while(count <= my_graph->vertex_number)
    {
        for(k=0;k<my_graph->vertex_number;k++)
        {
            if(indegree[k]==INT_MAX)
            {
                count++;
                continue;
            }
            if(indegree[k]==0)
            {
               printf("%s\t",Get_Vertex(my_graph , k));
               indegree[k]=INT_MAX;
               temp=my_graph->nodes[k].adj_list;
               count++;
               while(temp->next!=NULL)
               {
                    indegree[temp->next->index]--;
                    temp = temp->next;
               }
            }
        }
    }


}		/* -----  end of function Topo_Sort  ----- */
