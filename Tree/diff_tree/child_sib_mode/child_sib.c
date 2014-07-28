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
    if(my_tree ==NULL)
        err_msg("\nqueue have not init\n");
    my_queue= Init_Queue();
    printf("Enter root value:");
    scanf("%c%*c",&input_ch);

    my_tree	= malloc ( sizeof(struct tree_node) );
    if ( my_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    my_tree->data = input_ch;
    my_tree->firstchild = NULL;
    my_tree->nextsibling = NULL;
    Enqueue(my_queue, my_tree);
    while((dequeue_node=Dequeue(my_queue))!=NULL)
    {
        printf("Enter %c chlildren:",dequeue_node->node_data.data);
        fgets(buf , 256 , stdin);
        if(strcmp(buf , ".\n")==0)
            continue;
        length=strlen(buf);
        /*  创建左孩子 */            
        dequeue_node->firstchild	= malloc ( sizeof(struct tree_node) );
        if ( dequeue_node->firstchild==NULL ) {
              fprintf ( stderr, "\ndynamic memory allocation failed\n" );
              exit (EXIT_FAILURE);
         }
        dequeue_node->firstchild->data = buf[0];
        /*  将左孩子入队列 */
        Enqueue(dequeue_node->firstchild);
        for(k=1;k<length;k++)
        {
            /*  创建右兄弟 */
            dequeue_node->nextsibling	= malloc ( sizeof(struct tree_node) );
            if ( dequeue_node->nextsibling==NULL ) {
                fprintf ( stderr, "\ndynamic memory allocation failed\n" );
                exit (EXIT_FAILURE);
            }
            dequeue_node->nextsibling->data=buf[k];
            /*  将右兄弟入队列 */
            Enqueue(my_queue,dequeue_node->nextsibling);
            dequeue_node = dequeue_node->nextsibling;
        }


    }
    return ;

}		/* -----  end of function Create_CStree  ----- */

