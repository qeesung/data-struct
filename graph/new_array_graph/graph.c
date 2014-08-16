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
#include    "queue.h"

int visited[MAX_GRAPH_SIZE]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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
    printf("Get the %s\n location failed\n");
    fflush(stdout);
    return -1;
}		/* -----  end of function Locate_Vertex  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Graph
 *  Description:  由数据文件创建一个图
 * =====================================================================================
 */
    void
Create_Graph (Graph my_graph , char * filename)
{
    FILE * myfile;
    int k1 ;
    int k2;
    char buf1[10];
    char buf2[10];
    int length;
    int kind_value;
    int weight;
    int index1, index2;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return;
    }
    if(filename == NULL)
    {
        fprintf(stderr,"\nEnter the filename\n");
        return;
    }
    if((myfile = fopen(filename , "r"))==NULL)
    {
        fprintf(stderr,"open the file:%s failed\n",filename);
        return ;
    }
    /*  get the vertex number  */
    if(fgets(buf1 , 10 , myfile)==NULL)
    {
        fprintf(stderr,"1read the file error\n");
        return;
    }
    my_graph->vertex_number = atoi(buf1);
    /*  get the arcs number */
    if(fgets(buf1 , 10 , myfile)==NULL)
    {
        fprintf(stderr,"2read the file error\n");
        return;
    }
    my_graph->arcs_number = atoi(buf1);
    /*  get the graph kind */
    if(fgets(buf1 , 10 , myfile)==NULL)
    {
        fprintf(stderr,"3read the file error\n");
        return;
    }
    length = strlen(buf1);
    buf1[length-1]='\0';//除掉回车符号
    if(strcmp(buf1, "DN")==0)
        my_graph->kind=DN;
    else
    {
        if(strcmp(buf1 , "DG")==0)
            my_graph->kind = DG;
        else
        {
            if(strcmp(buf1,"UDG")==0)
                my_graph->kind = UDG;
            else
            {
                if(strcmp(buf1, "UDN")==0)
                    my_graph->kind = UDN;
                else
                {
                    fprintf(stderr,"wrong graph kind \n");
                    return;
                }
            }
        }
    }

    /*  get the vertex name */
    for(k1=0;k1<my_graph->vertex_number ; k1++)
    {
        if(fgets(buf1 , 10 , myfile)==NULL)
        {
            fprintf(stderr,"4read the file error\n");
            return ;
        }
        length = strlen(buf1);
        buf1[length-1]='\0';
        strcpy(my_graph->vertex_name[k1],buf1);
    }
    /*  init the arcs matrix */
    if(my_graph->kind == DG || my_graph->kind == UDG)
        kind_value = 0;
    else
        kind_value = INT_MAX;
    for(k1=0;k1<my_graph->vertex_number ;k1++)
    {
         for(k2=0;k2<my_graph->vertex_number;k2++)
             my_graph->arcs[k1][k2]=kind_value;
    }
    /*  get the arcs matrix info */
    for(k1 =0 ;k1<my_graph->arcs_number ;k1++)
    {
        /*  graph kind */
        if(my_graph->kind == DG || my_graph->kind == UDG)
        {
            if(fscanf(myfile, "%s%s", buf1, buf2)==EOF)
            {
                fprintf(stderr,"5read the file error\n");
                return;
            }
            length = strlen(buf2);
            buf2[length]='\0';
            index1 = Locate_Vertex(my_graph , buf1);
            index2 = Locate_Vertex(my_graph , buf2);
            if(index1 == -1 || index2 ==-1)
            {
                fprintf(stderr,"Get the location failed\n");
                return ;
            }
            my_graph->arcs[index1][index2]=1;
            if(my_graph->kind == UDG)
            {
            
                my_graph->arcs[index2][index1]=1;
                my_graph->arcs_number++;
            }
        }
        else
        {
            /*  net kind */
            if(fscanf(myfile, "%s%s %d", buf1 , buf2 ,&weight)==EOF)
            {
                fprintf(stderr,"\n6read the file error\n");
                return ;
            }
            index1 = Locate_Vertex(my_graph , buf1);
            index2 = Locate_Vertex(my_graph , buf2);
            if(index1 ==-1 || index2 ==-1)
            {
                fprintf(stderr,"Get the location failed\n");
                return ;
            }
            my_graph->arcs[index1][index2]=weight;
            if(my_graph->kind == UDN)
            {
                
                my_graph->arcs[index2][index1]=weight;
                my_graph->arcs_number++;
            }
        }

     }
       
    return;
}		/* -----  end of function Create_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Graph
 *  Description:  将一个图的全部信息打印出来
 * =====================================================================================
 */
    void
Print_Graph (Graph my_graph )
{
    int k1 ,k2;
    if(my_graph ==NULL)
    {
        fprintf(stderr,"the graph have not init\n");
        return ;
    }
    if(my_graph->vertex_number ==0 && my_graph->arcs_number ==0)
    {
        printf("\nThe graph is not exists\n");
        return;
    }
    printf("Vertex_number:%d\n",my_graph->vertex_number);
    printf("Arcs_number:%d\n",my_graph->arcs_number);
    printf("Graph kind:");
    switch(my_graph->kind)
    {
        case DG:printf("direct graph\n");
            break;
        case DN:printf("direct net\n");
            break;
        case UDG:printf("undirect graph\n");
            break;
        case UDN:printf("undirect net\n");
            break;
        default:
            printf("unknown graph kind\n");
    }

    printf("Vertex name:\t");
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        printf("%s\t",my_graph->vertex_name[k1]);
    }
    printf("\n");
    printf("Adjacent Matrix:\n");
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        for(k2=0;k2<my_graph->vertex_number;k2++)
        {
            printf("%d\t",my_graph->arcs[k1][k2]);
        }
        printf("\n");
    }
    return;

}		/* -----  end of function Print_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_Graph
 *  Description:  摧毁一张图
 * =====================================================================================
 */
    void
Destory_Graph(Graph my_graph )
{
    int k1 ,k2,kind_value;
    if(my_graph == NULL)
    {
        fprintf(stderr,"the graph have not init\n");
        return;
    }
    /*  clear vertex name */
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
       // my_graph->vertex_name[k1]=;
       strcpy(my_graph->vertex_name[k1]," ");
    }
    /* revalue the arcs */
    if(my_graph->kind %2 ==0)
        kind_value = 0;
    else
        kind_value = INT_MAX;
    for(k1=0;k1<my_graph->vertex_number ;k1++)
    {
        for(k2=0;k2<my_graph->vertex_number;k2++)
        {
            my_graph->arcs[k1][k2]=kind_value;
        }
    }
    my_graph->vertex_number=0;
    my_graph->arcs_number=0;

}		/* -----  end of function Destory_Graph  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Vertex
 *  Description:  得到一个点的索引 返回-1的时候就是没有找到这个点
 * =====================================================================================
 */
   char *
Get_Vertex ( Graph my_graph , int index )
{
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return NULL;
    }
    if(index>my_graph->vertex_number)
    {
        fprintf(stderr,"The index should less than the %d\n", my_graph->vertex_number);
        return NULL;
    }
    return my_graph->vertex_name[index];
}		/* -----  end of function Get_Vertex  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Put_Vertex
 *  Description:  为一个点重新设置信息 （现在就是设置对应的名字）
 * =====================================================================================
 */
    void
Put_Vertex ( Graph my_graph , Vertex_name old_name , Vertex_name new_name )
{
    int index;
    if(my_graph == NULL)
    {
        fprintf(stderr,"the graph have not init\n");
        return ;
    }
    index = Locate_Vertex(my_graph ,old_name);
    if(index==-1)
        return;
    strcpy(my_graph->vertex_name[index],new_name);
    return;
}		/* -----  end of function Put_Vertex  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  First_Adjacent
 *  Description:  得到第一个邻接点的索引
 * =====================================================================================
 */
    int
First_Adjacent ( Graph my_graph , Vertex_name my_name )
{
    int index;
    int k;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return -1;
    }
    index = Locate_Vertex(my_graph , my_name);
    if(index == -1)
        return -1;
    for(k=0;k<my_graph->vertex_number;k++)
    {
        if(my_graph->arcs[index][k]!=0 && my_graph->arcs[index][k]!=INT_MAX)
            return k;
    }
    return -1;
}		/* -----  end of function First_Adjacent  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Next_Aajacent
 *  Description:  得到一条弧的下一个邻接点 -1为没有找到
 * =====================================================================================
 */
    int
Next_Adjacent ( Graph my_graph , Vertex_name from_name , Vertex_name to_name )
{
    int k=0;
    int index1;
    int index2;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return -1;
    }
    index1 = Locate_Vertex(my_graph , from_name);
    index2 = Locate_Vertex(my_graph , to_name);
    if(index1 == -1 || index2 ==-1)
        return -1;
    for(k=index2+1;k<my_graph->vertex_number ;k++)
    {
        if(my_graph->arcs[index1][k]!=0 && my_graph->arcs[index1][k]!=INT_MAX)
            return k;
    }
    return -1;
}		/* -----  end of function Next_Aajacent  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Vertex
 *  Description:  插入一个点
 * =====================================================================================
 */
    void
Insert_Vertex (Graph my_graph , Vertex_name my_name )
{
    int k;
    int kind_value ;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return ;
    }
    if(my_graph->vertex_number>=MAX_GRAPH_SIZE)
    {
        fprintf(stderr,"\nThe graph size should less than %d\n",MAX_GRAPH_SIZE);
        return;
    }   
    if(my_graph->kind %2 ==0)
        kind_value = 0;
    else
        kind_value =INT_MAX;
    strcpy(my_graph->vertex_name[my_graph->vertex_number],my_name);
    for(k=0;k<=my_graph->vertex_number;k++)
    {
        my_graph->arcs[k][my_graph->vertex_number]=kind_value;
        my_graph->arcs[my_graph->vertex_number][k]=kind_value;
    }
    my_graph->vertex_number ++;

}		/* -----  end of function Insert_Vertex  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Vertex
 *  Description:  删除一个点
 * =====================================================================================
 */
    void
Delete_Vertex ( Graph my_graph , Vertex_name my_name )
{
    int index ;
    int kind_value ;
    int temp;
    int index_temp;
    int k1=0;
    int k2=0;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return;
    }
    index = Locate_Vertex(my_graph , my_name);
    if(index == -1)
        return;
    index_temp = index;
    /*  移动整个名字数组 */
    while(index_temp <= my_graph->vertex_number-2)
    {
        strcpy(my_graph->vertex_name[index_temp], my_graph->vertex_name[index_temp+1]);
        index_temp++;
    }
    /*  移动邻接矩阵 */
    for(k1==0;k1<my_graph->vertex_number;k1++)
    {
        if(my_graph->arcs[k1][index]!=0 && my_graph->arcs[k1][index]!=INT_MAX)
            my_graph->arcs_number--;
    }
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        if(my_graph->arcs[index][k1]!=0 && my_graph->arcs[index][k1]!=INT_MAX)
            my_graph->arcs_number--;
    }
    // 全部向左移动
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        for(k2=index;k2<my_graph->vertex_number-1;k2++)
        {
            my_graph->arcs[k1][k2]=my_graph->arcs[k1][k2+1];
        }
    }
    // 全部向右移动
   for(k1=index;k1<my_graph->vertex_number;k1++)
   {
        for(k2=0;k2<my_graph->vertex_number-1;k2++)
        {
            my_graph->arcs[k1][k2]=my_graph->arcs[k1+1][k2];
        }
   }
   my_graph->vertex_number--;
}		/* -----  end of function Delete_Vertex  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_Arcs()
 *  Description:  插入一条弧线
 * =====================================================================================
 */
    void
Insert_Arcs( Graph my_graph , Vertex_name name1, Vertex_name name2)
{
    int index1 ;
    int index2;
    int kind_value;
    int weight;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return ;
    }
    index1 =Locate_Vertex(my_graph , name1);
    index2 = Locate_Vertex(my_graph , name2);
    if(index1 == -1 || index2==-1)
        return;
    if(my_graph->kind %2 ==0)
        kind_value = 1;
    else
    {
        printf("Enter the arcs weight:");
        scanf("%d\n",&weight);
    }
    if(my_graph->arcs[index1][index2]!=0 && my_graph->arcs[index1][index2]!=INT_MAX)
    {
        fprintf(stderr,"\nThe arcs have been exists\n");
        return;
    }
    my_graph->arcs[index1][index2]=kind_value;
    if(my_graph->kind >=2)
        my_graph->arcs[index2][index1]=kind_value;
    my_graph->arcs_number ++;
}		/* -----  end of function Insert_Arcs()  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Arcs()
 *  Description:  
 * =====================================================================================
 */
    void
Delete_Arcs(Graph my_graph , Vertex_name name1 , Vertex_name name2 )
{
    int index1 ;
    int index2;
    int kind_value;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return ;
    }
    index1 = Locate_Vertex(my_graph, name1);
    index2 = Locate_Vertex(my_graph , name2);
    if(index1 ==-1 || index2 ==-1)
        return;
    if(my_graph->kind%2==0)
        kind_value =0;
    else
        kind_value = INT_MAX;
    if(my_graph->arcs[index1][index2]==kind_value)
    {
        fprintf(stderr, "\nThe arcs is not exists\n");
        return;
    }
    my_graph->arcs[index1][index2]=kind_value;
    if(my_graph->kind >=2)
        my_graph->arcs[index2][index1]=kind_value;
    my_graph->arcs_number--;
    return;
}		/* -----  end of function Delete_Arcs()  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Visit
 *  Description:  一个点的访问函数
 * =====================================================================================
 */
    void
Visit ( Vertex_name my_name )
{
    printf("%s\n", my_name);
    return;
}		/* -----  end of function Visit  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  深度遍历
 * =====================================================================================
 */
    void
DFS ( Graph my_graph , int index_start )
{
    int adjacent;    
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph hav enot init\n");
        return;
    }
    if(index_start>my_graph->vertex_number)
    {
        fprintf(stderr,"The index start should less than %d\n",my_graph->vertex_number);
        return;
    }
    visited[index_start] = 1;
    Visit(my_graph->vertex_name[index_start]);
    for(adjacent=First_Adjacent(my_graph,my_graph->vertex_name[index_start]);\
            adjacent!=-1;\
            adjacent = Next_Adjacent(my_graph , my_graph->vertex_name[index_start],my_graph->vertex_name[adjacent]))
        if(visited[adjacent]==0)
            DFS(my_graph, adjacent);
}		/* -----  end of function DFS  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS_Traverse
 *  Description:  深度遍历
 * =====================================================================================
 */
    void
DFS_Traverse ( Graph my_graph , my_func visit )
{
    int k=0;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\n the Graph have not init\n");
        return;
    }
    for(k=0;k<my_graph->vertex_number;k++)
        visited[k]=0;
    for(k=0;k<my_graph->vertex_number;k++)
    {
        if(visited[k]==0)
            DFS(my_graph , k);
    }
}		/* -----  end of function DFS_Traverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  BFS_Traverse
 *  Description:  广度优先非递归遍历图
 * =====================================================================================
 */
    void
BFS_Traverse ( Graph my_graph , my_func my_visit )
{
    Queue my_queue;
    List_node dequeue_node;
    int k=0;
    int adjacent;
    if(my_graph == NULL)
    {
        fprintf(stderr,"\n the Graph have not init\n");
        return;
    }
    for(k=0;k<my_graph->vertex_number;k++)
    {
        visited[k] =0;
    }
    my_queue = Init_Queue();
    Enqueue(my_queue, 0);
    while((dequeue_node= Dequeue(my_queue))!=NULL)
    {
       /*if(visited[dequeue_node->index]==0)
        {
            my_visit(my_graph->vertex_name[dequeue_node->index]);
            visited[dequeue_node->index]=1;
        }*/
        adjacent = First_Adjacent(my_graph,my_graph->vertex_name[dequeue_node->index]);
        while(adjacent!=-1)
        {
            if(visited[adjacent]!=1)
            {
                my_visit(my_graph->vertex_name[adjacent]);
                visited[adjacent]=1;
                Enqueue(my_queue,adjacent);
            }
            adjacent=Next_Adjacent(my_graph ,Get_Vertex(my_graph , dequeue_node->index), Get_Vertex(my_graph , adjacent));
        }

    }
    printf("\n");
    return;
}		/* -----  end of function BFS_Traverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Prim
 *  Description:  prim 
 * =====================================================================================
 */
    void
Prim ( Graph my_graph )
{

    if(my_graph == NULL)
    {
        fprintf(stderr, "\nthe graph have not init\n");
        return ;
    }
    if(my_graph->kind != UDN )
    {
        fprintf(stderr, "\nThe graph must to be UDN kind for my prim\n");
        return;
    }
    struct close_edge my_edge[my_graph->vertex_number];
    List called;
    List ncalled;
    int k=0;
    int min = INT_MAX-1;
    int min_arcs;
    int all_sum=0;
    int k1;
    /* 从第一个点开始初始化my_edge 数组 */
    called = Init_List();
    ncalled = Init_List();
    Insert_List(called , 0);
    for(k=1;k<my_graph->vertex_number;k++)
    {
         my_edge[k].weight= my_graph->arcs[0][k] ;
         my_edge[k].index = 0;
         Insert_List(ncalled, k);
    }
    while(!List_Empty(ncalled))
    {
        /*  现在需要找到最小的那个 */
        for(k=1;k<my_graph->vertex_number;k++)
        {
            if(my_edge[k].weight < min)
            {
                min = my_edge[k].weight;
                min_arcs = my_edge[k].index;
                k1 = k;
            }
        }
        /* 找到了最小 */
        all_sum += min;
        printf("%s---%d--->%s\n", Get_Vertex(my_graph,min_arcs), min , Get_Vertex(my_graph , k1));
        min = INT_MAX-1;
        Delete_List(ncalled, k1);
        Insert_List(called , k1);
        my_edge[k1].weight = INT_MAX;
        printf("ncalled:");
        Print_List(ncalled);
        printf("called:");
        Print_List(called);
        /* 更新我的my_edge数组 */
        for(k=1;k<my_graph->vertex_number;k++)
        {
            if(In_List(called , k))
                continue;
            if(my_graph->arcs[k1][k] < my_edge[k].weight)
               {
                my_edge[k].weight = my_graph->arcs[k1][k];
                my_edge[k].index = k1;
               }
        }
        /*for(k=1;k<my_graph->vertex_number ;k++)
        {
            printf("weight:%d  index:%d\n", my_edge[k].weight , my_edge[k].index);
        }*/
        printf("\n****************************\n");
    }
    printf("the min length is %d \n" , all_sum);
    return;

}		/* -----  end of function Prim  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Prim1
 *  Description:  prim算法
 * =====================================================================================
 */
    void
Prim1 (Graph my_graph , Vertex_name name1 )
{
    int index;
    int k;
    if(my_graph == NULL)
    {
        fprintf(stderr, "The graph have not init\n");
        return;
    }
    int called[my_graph->vertex_number];
    int ncalled[my_graph->vertex_number];
    struct close_edge my_edge[my_graph->vertex_number];
    int empty=0;
    int min  = INT_MAX-1;
    int k1;
    int min_index;
    int all_sum=0;
    if((index = Locate_Vertex(my_graph , name1))==-1)
        return;
    for(k=0;k<my_graph->vertex_number;k++)
    {
        ncalled[k]=1;
        called[k]=0;
    }
    ncalled[index] = 0;
    called[index]= 1;
    /* 初始化边界数组 */
    for(k=0;k<my_graph->vertex_number;k++)
    {
        if(k== index)
            continue;
        my_edge[k].weight = my_graph->arcs[index][k];
        my_edge[k].index = index;
    }
    while(!empty)
    {
        /* 下面检测是否还有点尚未合并 */
        /*   下面找到值最小的边  */
        for(k=0;k<my_graph->vertex_number;k++)
        {
            if(called[k]==1)/* 这个点已经合并过 */
                continue;
            if(my_edge[k].weight < min)
            {
                min = my_edge[k].weight;
                min_index = my_edge[k].index;
                k1 = k;
            }
        }
        /* 打印出这个找到的点 */
        printf("%s---%d--->%s\n", Get_Vertex(my_graph , min_index),min , Get_Vertex(my_graph , k1));
        all_sum+=min;
        min = INT_MAX -1;
        called[k1] = 1;
        ncalled[k1] = 0;
        /* 现在更新边界数组 */
        for(k =0; k<my_graph->vertex_number;k++)
        {
            if(called[k]==1)
                continue;
            if(my_graph->arcs[k1][k] < my_edge[k].weight)
            {
                my_edge[k].weight = my_graph->arcs[k1][k];
                my_edge[k].index  = k1;
            }
        }
        empty = 1;
        for(k=0;k<my_graph->vertex_number;k++)
        {
            if(ncalled[k]==1)
                empty = 0;
        }
    }
    printf("the minniset path is %d\n", all_sum);

}		/* -----  end of function Prim1  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Kruskal
 *  Description:  kruskal算法
 * =====================================================================================
 */
    void
Kruskal (Graph my_graph )
{
    if(my_graph == NULL)
    {
        fprintf(stderr,"\nThe graph have not init\n");
        return;
    }
    int set[my_graph->vertex_number];
    int k;
    int i , j;
    int min=INT_MAX;
    int x, y;
    int all_sum=0;
    int number;
    /* 初始化set数组 */
    for(k=0;k<my_graph->vertex_number;k++)
    {
        set[k] = k;
    }
    while(1)
    {
        for(i=0;i<my_graph->vertex_number;i++)
        {
            for(j=i+1;j<my_graph->vertex_number;j++)
            {

                if(my_graph->arcs[i][j] < min)
                {
                    x = i;
                    y = j;
                    min = my_graph->arcs[i][j];
                }
                
            }
        }
        /* 得到最小的边以后，现在检测是否属于一个集合  */
        
        if(min == INT_MAX)
            return;
        my_graph->arcs[x][y] = INT_MAX;
        if(set[x] == set[y])
        {
              min= INT_MAX;
              continue;
        }
        printf("%s---%d--->%s\n",Get_Vertex(my_graph , x), min , Get_Vertex(my_graph , y));
        all_sum+=min;
        /* 将集合融合 */
        number = set[y];
        for(k=0;k<my_graph->vertex_number;k++)
        {
            if(set[k]== number)
                set[k] = set[x];
        }
        for(k=0;k<my_graph->vertex_number;k++)
        {
            printf("#%d:::%d\t", k , set[k]);
        }
        printf("\n");
        min= INT_MAX;
    }

}		/* -----  end of function Kruskal  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DIJ
 *  Description:  dijkstra 算法
 * =====================================================================================
 */
    void
DIJ ( Graph my_graph , int start )
{
    if(my_graph == NULL)
        return;
    if(start > my_graph->vertex_number)
        return;
    int visited[my_graph->vertex_number];
    struct dij_node my_node[my_graph->vertex_number];
    int k =0;
    int k1 , k2, k3, k4;
    int min;
    for(k=0;k<my_graph->vertex_number;k++)
    {
        visited[k] = 0;
        my_node[k].weight = my_graph->arcs[start][k] ;
        my_node[k].parent = -1;
        if(my_node[k].weight != INT_MAX)
            my_node[k].parent = start;
    }
    visited[start] = 1;
    my_node[start].weight = 0;
    fflush(stdout);
    for(k=1;k<my_graph->vertex_number;k++)
    {
        min = 30000;
        for(k1 = 0 ;k1< my_graph->vertex_number;k1++)
        {
            if(visited[k1]==0 && my_node[k1].weight < min)
            {
                min = my_node[k1].weight;
                k2 = k1;
            }
        }
        visited[k2] = 1;
        printf("get the point %s\n",Get_Vertex(my_graph, k2));
        for(k3=0;k3<my_graph->vertex_number;k3++)
        {
            if(visited[k3]==0 && my_graph->arcs[k2][k3]+my_node[k2].weight < my_node[k3].weight)
            {
                my_node[k3].weight = my_graph->arcs[k2][k3]+my_node[k2].weight;
                my_node[k3].parent = k2;
            }
            for(k4=0;k4<my_graph->vertex_number;k4++)
            {
                printf("%s+++%d+++%d\n",Get_Vertex(my_graph,k4), my_node[k4].weight, my_node[k4].parent);
            }
            printf("****************************\n");

        }
        
    }
    for(k=0;k<my_graph->vertex_number;k++)
    {
        printf("%s+++%d+++:",Get_Vertex(my_graph, k ), my_node[k].weight);
        k2 = my_node[k].parent;
        while(k2!=-1)
        {
            printf("%s\t", Get_Vertex(my_graph , k2));
            k2 = my_node[k2].parent;
        }
        printf("\n");
    }
}		/* -----  end of function DIJ  ----- */
