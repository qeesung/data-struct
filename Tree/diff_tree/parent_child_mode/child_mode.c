/*
 * =====================================================================================
 *
 *       Filename:  child_mode.c
 *
 *    Description:  This is child mode c file
 *
 *        Version:  1.0
 *        Created:  2014年07月27日 02时06分36秒
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
#include"child_mode.h"
#include"queue.h"
char buf[MAX_BUF_SIZE];
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  err_sys
 *  Description:  
 * =====================================================================================
 */
    void
err_sys ( char * string )
{
    fprintf(stderr, string);
    exit(EXIT_FAILURE);
}		/* -----  end of function err_sys  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Ctree
 *  Description:  init my_ctree
 * =====================================================================================
 */
    Ctree
Init_Ctree ( )
{
    Ctree new_tree;
    int k=0;
    new_tree	= malloc ( sizeof(struct ctree) );
    if ( new_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_tree->number =0 ;
    /*  需要为每一个列表指针创建一个头节点 */
    for(k=0;k<MAX_TREE_SIZE;k++)
    {
        
        new_tree->nodes[k].next	= malloc ( sizeof(struct list_node) );
        if ( new_tree->nodes[k].next==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }


    }
    return new_tree;

}		/* -----  end of function Init_Ctree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Ctree
 *  Description:  assign for every tree node
 * =====================================================================================
 */
    void
Create_Ctree ( Ctree * my_tree )
{
    Queue my_queue;
    Queue_node dequeue_node;
    List_node node_point;
    int i=1;
    char input_ch;
    int length;
    int k=0;
    if((*my_tree)==NULL)
        err_sys("the tree have not init\n ");
    my_queue=Init_Queue();
    printf("请输入Root数据:");
    scanf("%c%*c",&input_ch);
    (*my_tree)->nodes[0].data=input_ch;
    (*my_tree)->nodes[0].parent=-1;// root 没有父亲
    Enqueue(my_queue,input_ch,0,(*my_tree)->nodes[0].next);
    while((dequeue_node = Dequeue(my_queue))!=NULL)
    {
        printf("enter %c child:",dequeue_node->data);
        fgets(buf , MAX_BUF_SIZE, stdin);
        if(strcmp(buf ,".\n")==0)
        {
           // printf("\n");
            continue;
        }
        length=strlen(buf)-1;
        node_point = dequeue_node->pointer_data;
        for(k=0;k<length;k++)
        {
            
            (*my_tree)->nodes[i].data= buf[k];
            (*my_tree)->nodes[i].parent=dequeue_node->index;
            Enqueue(my_queue,buf[k],i,(*my_tree)->nodes[i].next);
            node_point->next	= malloc ( sizeof(struct list_node) );
            if ( node_point->next==NULL ) {
                fprintf ( stderr, "\ndynamic memory allocation failed\n" );
                exit (EXIT_FAILURE);
            }
            node_point->next->child_index=i; 
            node_point = node_point->next;
            i++;
            if(i>MAX_TREE_SIZE)
                err_sys("tree size overflow maxtreesize\n ");
        
        }
    }

    (*my_tree)->number = i;
    
    return ;
}		/* -----  end of function Create_Ctree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Ctree_Empty
 *  Description:  检测树是否为空
 * =====================================================================================
 */
    int
Ctree_Empty ( Ctree my_tree )
{
    if(my_tree==NULL)
        return -1;
    if(my_tree->number==0)
        return 1;
    else
        return 0;
    return;
}		/* -----  end of function Ctree_Empty  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Ctree_Depth
 *  Description:  求取树的深度
 * =====================================================================================
 */
    int
Ctree_Depth ( Ctree my_tree )
{
    int depth;
    int max_depthi=0;
    int k=0;
    int parent_index=0;
    if(my_tree == NULL)
    {
        fprintf(stderr,"\n th Tree have not init\n");
        return -1;
    }
    for(k=0;k<my_tree->number;k++)
    {
        depth=0;
        parent_index = my_tree->nodes[k].parent;
        while(parent_index!=-1)
        {
            depth++;
            parent_index = my_tree->nodes[parent_index].parent;
        }
        if(depth > max_depth)
            max_depth = depth;

    }
    return max_depth+1;
}		/* -----  end of function Ctree_Depth  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Root
 *  Description:  得到根的数据
 * =====================================================================================
 */
    char
Root (Ctree  my_tree )
{
    if(my_tree==NULL)
    {
        fprintf(stderr,"\nthe tree is not init\n");
        return char(0);
    }
    else
    return my_tree->nodes[0].data;
}		/* -----  end of function Root  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Value
 *  Description:  得到一个点的值
 * =====================================================================================
 */
    char 
Value ( Ctree my_tree , int index )
{
    if(my_tree==NULL)
    {
        fprintf(stderr,"\nthe tree is not init\n");
        return char(0);
    }
    if(index>my_tree->number)
    {
        fprintf(stderr,"\nthe index should less than %d\n",my_tree->number);
        return;
    }
    return my_tree->nodes[index].data;
}		/* -----  end of function Value  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Assign
 *  Description:  为一个点重新赋值
 * =====================================================================================
 */
    void
Assign ( Ctree my_tree , int index , char new_value )
{
    if(my_tree == NULL)
        err_sys("the tree is not init\n");
    if(index>my_tree->number)
        err_sys("index should less than tree max size\n");
    my_tree->nodes[index].data=new_value;
    return;
}		/* -----  end of function Assign  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Parent
 *  Description:  得到子节点的父亲的值
 * =====================================================================================
 */
    char
Parent ( Ctree my_tree, int child_index;)
{
    if(my_tree==NULL)
    {
        fprintf(stderr,"\nthe tree have not inited\n");
        return (char)0;
    }
    if(child_index > my_tree->number)
    {
        fprintf(stderr, "\nTree size should less than max tree size\n");
        return (char)0;
    }
    return my_tree->nodes[my_tree->nodes[child_index].parent];
}		/* -----  end of function Parent  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Leftchild
 *  Description:  得到父亲的左孩子
 * =====================================================================================
 */
    char
Leftchild (Ctree my_tree , int parent_index , int * child_index )
{
    int leftchild_index;
    if(my_tree == NULL)
    {
        fprintf(stderr, "\nTree have not init\n");
        return (char)0;
    }
    if(parent_index>my_tree->number)
    {
        fprintf(stderr, "\npanrer_index should less than max tree size\n");
        return (char)0;
    }
    if(my_tree->nodes[parent_index].next->next==NULL)
        return (char)0;
    leftchild_index= my_tree->nodes[parent_index].next->next->child_index;
    return my_tree->nodes[leftchild_parent].data;
        
}		/* -----  end of function Leftchild  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Rightsibling
 *  Description:  得到右兄弟的所有值， 传入到数组中返回
 * =====================================================================================
 */
    char *
Rightsibling ( Ctree my_tree , int leftchild_index  )
{
    int k=0;
    char * all_data;
    List_node temp;
    if(my_tree == NULL)
    {
        fprintf(stderr,"\nTree have not init\n");
        return NULL;
    }
    if(leftchild_index>my_tree->number)
    {
        fprintf(stderr, "\nTree size should less than max tree size\n");
        return NULL;
    }
    
    all_data	= malloc ( sizeof(char) );
    if ( all_data==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
     }
    all_data[0]=0;// 记录右兄弟的个数
    
    for(k=0;k<my_tree->number;k++)
    {
        if(my_tree->nodes[k].next->next->data==leftchild_index)
            break;
    }
    if(k==my_tree->number)
    {
        return NULL;
    }
    temp = my_tree->nodes[k].next->next->next;
    k=1;
    while(temp!=NULL)
    {
                
        all_data	= malloc ( sizeof(char) * (k+1) );
        if ( all_data==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        all_data[k]=my_tree->nodes[temp->child_index].data;
        temp=temp->next;
        k++;
        all_data[0]++;
    }
    return all_data;
}		/* -----  end of function Rightsibling  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Ctree
 *  Description:  完全的打印一棵树
 * =====================================================================================
 */
    void
Print_Ctree ( Ctree my_tree )
{
    if(my_tree == NULL)
        err_sys("\nTree have not init\n");
    int k=0;
    int temp_index;
    List_node temp;
    for(k=0;k<my_tree->number;k++)
    {
        printf("%c:::----->>>>\t",my_tree->nodes[k].data);
        temp=my_tree->nodes[k].next;
        while(temp->next!=NULL)
        {   
            temp_index = temp->next->child_index;
            printf("%c\t",my_tree->nodes[temp_index]);
            temp=temp->index;
        }
        printf("\n");
    }
    return;
}		/* -----  end of function Print_Ctree  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Traverse_Ctree
 *  Description:  遍历整个树
 * =====================================================================================
 */
    void
Traverse_Ctree ( Ctree my_tree )
{
    int k=0;
    if(my_tree == NULL)
        err_sys("Tree have not init\n ");
    for(k=0;k<my_tree->number;k++)
    {
        printf("%c\n",my_tree->nodes[k].data);
    }
}		/* -----  end of function Traverse_Ctree  ----- */
