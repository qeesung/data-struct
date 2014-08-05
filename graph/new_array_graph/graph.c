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
        fprintf(stderr,"read the file error\n");
        return;
    }
    my_graph->vertex_number = atoi(buf1);
    /*  get the arcs number */
    if(fgets(buf1 , 10 , myfile)==NULL)
    {
        fprintf(stderr,"read the file error\n");
        return;
    }
    my_graph->arcs_number = atoi(buf1);
    /*  get the graph kind */
    if(fgets(buf1 , 10 , myfile)==NULL)
    {
        fprintf(stderr,"read the file error\n");
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
            fprintf(stderr,"read the file error\n");
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
                fprintf(stderr,"read the file error\n");
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
                my_graph->arcs[index2][index1]=1;
        }
        else
        {
            /*  net kind */
            if(fscanf(myfile, "%s%s %d", buf1 , buf2 ,&weight)==EOF)
            {
                fprintf(stderr,"\nread the file error\n");
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
                my_graph->arcs[index2][index1]=weight;
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
Destory_Graph (Graph my_graph )
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
        my_graph->vertex_name[k1]=NULL;
    }
    /* revalue the arcs */
    if(my_graph->kind %2 ==0)
        kind_value = 0;
    else
        kind_value = INT_MAX;
    for(k1=0;k1<my_graoh->vertex_number ;k1++)
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
    return my_graph->vertex_name;
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
First_Adjacent ( Grapg my_graph , Vertex_name my_name )
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
        if(my_graph->arcs[index][k]!=1 &&  my_graph->arcs[index][k]!=INT_MAX)
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
Next_Aajacent ( Graph my_graph , Vertex_name from_name , Vertex_name to_name )
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
        kind_value INT_MAX;
    strcpy(my_graph->vertex_name[vertex_number],my_name);
    for(k=0;k<=my_graph->vertex_number;k++)
    {
        my_graph->arcs[k][my_graph->veretx_numer]=kind_value;
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
        strcpy(my_graph->vertex_name[index], my_graph->vertex_name[index+1]);
    }
    /*  移动邻接矩阵 */
    // 全部向左移动
    for(k1=0;k1<my_graph->vertex_number;k1++)
    {
        if(my_graph->arcs[k1][index]!=0 && my_graph->arcs[k1][index]!=INT_MAX)
            my_graph->arcs_number--;
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
            if(my_graph->arcs[index][k2]!=0 && my_graph->arcs[index][k2]!=INT_MAX)
                 my_graph->arcs_number--;
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
    return;
}		/* -----  end of function Delete_Arcs()  ----- */
