/*
 * =====================================================================================
 *
 *       Filename:  child_sib.c
 *
 *    Description:  child sib mode c file
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 18时53分25秒
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
#include"child_sib.h"
#include"queue.h"
#include<string.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_CStree
 *  Description:  初始化孩子兄弟树
 * =====================================================================================
 */
    CStree
Init_CStree () 
{
    CStree new_tree;
    new_tree == NULL;
    return new_tree;
}		/* -----  end of function Init_CStree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_CStree
 *  Description:  为孩子兄弟树赋值
 * =====================================================================================
 */
    void
Create_CStree (CStree * my_tree )
{
    /*  需要为孩子兄弟创建一个队列来实现 */ 
    Queue my_queue;
    Queue_node dequeue_node;
    char input_ch;
    char buf[256];
    int k=0;
    int length;
    Tree_node new_tree_node;
    if((*my_tree) ==NULL)
        err_msg("\nqueue have not init\n");
    my_queue= Init_Queue();
    printf("Enter root value:");
    scanf("%c%*c",&input_ch);

    (*my_tree)	= malloc ( sizeof(struct tree_node) );
    if ( (*my_tree)==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    (*my_tree)->data = input_ch;
    (*my_tree)->firstchild = NULL;
    (*my_tree)->nextsibling = NULL;
    Enqueue(my_queue, *my_tree);
    while((dequeue_node=Dequeue(my_queue))!=NULL)
    {
        printf("Enter %c chlildren:",dequeue_node->node_data->data);
        fgets(buf , 256 , stdin);
        if(strcmp(buf , ".\n")==0)
            continue;
        length=strlen(buf)-1;
        /*  创建左孩子 */            
        dequeue_node->node_data->firstchild	= malloc ( sizeof(struct tree_node) );
        if ( dequeue_node->node_data->firstchild==NULL ) {
              fprintf ( stderr, "\ndynamic memory allocation failed\n" );
              exit (EXIT_FAILURE);
         }
        dequeue_node->node_data->firstchild->data = buf[0];
        /*  将左孩子入队列 */
        Enqueue(my_queue, dequeue_node->node_data->firstchild);
        new_tree_node = dequeue_node->node_data;
        for(k=1;k<length;k++)
        {
            /*  创建右兄弟 */
            new_tree_node->nextsibling	= malloc ( sizeof(struct tree_node) );
            if ( new_tree_node->nextsibling==NULL ) {
                fprintf ( stderr, "\ndynamic memory allocation failed\n" );
                exit (EXIT_FAILURE);
            }
            new_tree_node->nextsibling->data=buf[k];
            /*  将右兄弟入队列 */
            Enqueue(my_queue,new_tree_node->nextsibling);
            new_tree_node = new_tree_node->nextsibling;
        }


    }
    return ;

}		/* -----  end of function Create_CStree  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CStree_Empty
 *  Description:  检测树是否为空
 * =====================================================================================
 */
    int
CStree_Empty (CStree my_tree )
{
    if(my_tree == NULL)
        return 1;
    else
        return 0;
}		/* -----  end of function CStree_Empty  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CStree_Depth
 *  Description:  求算树的深度
 * =====================================================================================
 */
    int
CStree_Depth (CStree my_tree)
{
    int max=0;
    int depth=0;
    Tree_node my_tree_node;
    if(my_tree == NULL)
        return 0;
    if(my_tree->firstchild==NULL)
        return 1;
    /*  递归求解所有孩子的深度 */

    max=CStree_Depth(my_tree->firstchild)+1;
    for(my_tree_node=my_tree->nextsibling;my_tree_node!=NULL;my_tree_node = my_tree_node->nextsibling)
    {
        depth = CStree_Depth(my_tree_node)+1;
        if(depth>max)
            max=depth;
    }
    return max;
}		/* -----  end of function CStree_Depth  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Root
 *  Description:  得到根的值
 * =====================================================================================
 */
    char
Root ( CStree my_tree )
{
    if(my_tree == NULL)
    {
        return (char)0;
    }
    return my_tree->data;
}		/* -----  end of function Root  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Value
 *  Description:  得到一个指针的节点的值
 * =====================================================================================
 */
    char
Value ( Tree_node my_node )
{
    if(my_node == NULL)
        return (char)0;
    else
        return my_node->data;
}		/* -----  end of function Value  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Point
 *  Description:  找到一个值为old_value 并且返回其指针
 * =====================================================================================
 */
    Tree_node
Find_Point (CStree my_tree , char data )
{
    /*  这里要用到队列来取得所有的值来比较 */
    Queue my_queue;
    Queue_node dequeue_node;
    my_queue = Init_Queue();
    Tree_node my_tree_node;
    Tree_node tempsib_tree_node;
    if(my_tree == NULL)
        return NULL;
    Enqueue(my_queue , my_tree);/*  root enqueue */

    while((dequeue_node= Dequeue(my_queue))!=NULL)
    {
        my_tree_node = dequeue_node->node_data;

        if(my_tree_node->data == data)
            break;
        if(my_tree_node->firstchild!=NULL)
            Enqueue(my_queue , my_tree_node->firstchild);
        if(my_tree_node->nextsibling!=NULL)
            Enqueue(my_queue,my_tree_node->nextsibling);
    }
    return my_tree_node;
}		/* -----  end of function Find_Point  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Assign
 *  Description: 为一个点重新赋值
 * =====================================================================================
 */
    void
Assign ( CStree my_tree , char old_value , char new_value )
{
    Tree_node find_point;
    if(my_tree == NULL)
        err_msg("The node is empty\n");
    if((find_point=Find_Point(my_tree, old_value))!=NULL)
        find_point->data = new_value;
    return;
    
}		/* -----  end of function Assign  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Parent()
 *  Description:  找到一个孩子的父亲
 * =====================================================================================
 */
    char
Parent( CStree my_tree , char child_value )
{
    Queue my_queue;
    Queue_node dequeue_node;
    Tree_node my_node;
    Tree_node temp;
    if(my_tree == NULL)
    {
        fprintf(stderr, "\nThe tree have not init \n");
        return (char)0;
    }
    /*  这里需要队列来实现 */
    if(my_tree -> data == child_value)
        return (char)0;
    my_queue= Init_Queue();
    Enqueue(my_queue , my_tree);
    while((dequeue_node = Dequeue(my_queue))!=NULL)
    {
        my_node = dequeue_node->node_data;
        if(my_node->firstchild==NULL)
            continue;
        if(my_node->firstchild->data == child_value)
            return my_node->data;
        Enqueue(my_queue,my_node->firstchild);
        temp = my_node->nextsibling;
        while(temp!=NULL)
        {
            if(temp->data == child_value)
                return my_node->data;
            if(temp->firstchild!=NULL)
                Enqueue(my_queue,temp->firstchild);
            temp = temp->nextsibling;
        }
    }
}		/* -----  end of function Parent()  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Leftchild
 *  Description:  返回第一个孩子
 * =====================================================================================
 */
    char
Leftchild ( Tree_node my_tree_node )
{
    if(my_tree_node == NULL)
        err_msg("\nThe tree node is not exists\n");
    if(my_tree_node->firstchild!=NULL)
        return my_tree_node->firstchild->data;
    return (char)0;
}		/* -----  end of function Leftchild  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Rightsibling
 *  Description:  返回除左孩子以外的全部右兄弟
 * =====================================================================================
 */
    char *
Rightsibling (Tree_node my_tree_node)
{
    char * sib_data;
    int k=0;
    Tree_node temp;
    if(my_tree_node == NULL)
        err_msg("\nThe tree node is not exists\n");

    sib_data	= malloc ( sizeof(char) );
    if ( sib_data==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    sib_data[0]=0;
    temp = my_tree_node ->nextsibling;
    k=1;
    while(temp!=NULL)
    {
        
        sib_data	= realloc (sib_data, sizeof(char) * (k+1));
        if ( sib_data==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }
        sib_data[k]=temp->data;
        k++;
        sib_data[0]++;
        temp=temp->nextsibling;
    }
    return sib_data;
    
}		/* -----  end of function Rightsibling  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Postorder_Traverse
 *  Description:  后序遍历树, 先遍历孩子， 然后再访问父亲
 * =====================================================================================
 */
    void
Postorder_Traverse ( CStree my_tree )
{
    Tree_node temp;
    if(my_tree == NULL)
            return;
    if(my_tree->firstchild!=NULL)
        Postorder_Traverse(my_tree->firstchild);
    else
        goto last;
    temp = my_tree->nextsibling;
    while(temp!=NULL)
    {
        Postorder_Traverse(temp);
        temp=temp->nextsibling;
    }
last:
    printf("%c\t",my_tree->data);
    fflush(stdout);

}		/* -----  end of function Postorder_Traverse  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Levelorder_Traverse
 *  Description:  层序遍历一个树
 * =====================================================================================
 */
    void
Levelorder_Traverse ( CStree my_tree )
{
    Queue my_queue;
    Queue_node dequeue_node;
    Tree_node my_node;
    Tree_node temp;

    if(my_tree == NULL)
        err_msg("\nThe tree have not init\n");
    my_queue = Init_Queue();
    printf("%c\t",my_tree->data);
    Enqueue(my_queue, my_tree);
    while((dequeue_node = Dequeue(my_queue))!=NULL)
    {
        my_node = dequeue_node->node_data;
        if(my_node->firstchild!=NULL)
        {
            printf("%c\t",my_node->firstchild->data);
            Enqueue(my_queue , my_node->firstchild);
        }
        else
            continue;
        temp = my_node->nextsibling;
        while(temp!=NULL)
        {
            printf("%c\t", temp->data);
            Enqueue(my_queue,temp);
            temp=temp->nextsibling;
        }
    }
    printf("\n");
    return;
}		/* -----  end of function Levelorder_Traverse  ----- */



