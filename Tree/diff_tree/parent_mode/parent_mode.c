/*
 * =====================================================================================
 *
 *       Filename:  parent_mode.c
 *
 *    Description:  this is parent mode tree
 *
 *        Version:  1.0
 *        Created:  2014年07月25日 23时52分05秒
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
#include    "parent_mode.h"
#include    "queue.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Ptree
 *  Description:  init my own ptree
 * =====================================================================================
 */
    Ptree
Init_Ptree ( )
{
    Ptree new_tree;

    new_tree	= malloc ( sizeof(struct ptree) );
    if ( new_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    
    new_tree->number = 0;// have not tree_node in the tree

    return new_tree;
}		/* -----  end of function Init_Ptree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Ptree
 *  Description:  assign for the ptree
 * =====================================================================================
 */
    void
Create_Ptree ( Ptree * my_tree )
{
    Queue my_queue;
    int i=1;
    int j=0;
    int length;
    char line[MAX_TREE_SIZE];
    List_node dequeue_node;
    char input_ch;
    my_queue = Init_Queue();
    printf("enter the root data:");
    scanf("%c%*c", &input_ch);
    //input_ch = fgetc(stdin);
    (*my_tree)->nodes[0].data=input_ch;
    (*my_tree)->nodes[0].parent=-1;
    Enqueue(my_queue,input_ch, 0);
    while((dequeue_node=Dequeue(my_queue))!=NULL)
    {
        printf("enter the %c all childs:",dequeue_node->data=='\n'?'X':dequeue_node->data);
        fflush(stdout);
        fgets(line, MAX_TREE_SIZE,stdin);
        //gets(line);
        if(strcmp(line, ".\n")==0)
            continue;
        length=strlen(line)-1;
        for(j=0;j<length;j++)
        {
            (*my_tree)->nodes[i].data=line[j];
            (*my_tree)->nodes[i].parent=dequeue_node->index;
            Enqueue(my_queue,line[j],i);
            i++;
            if(i>=MAX_TREE_SIZE)
            {
                fprintf(stderr, "\n overflow the tree size\n ");
                (*my_tree)->number =0 ;
                return ;
            }
        }
    }
    (*my_tree)->number = i;

    return ;
}		/* -----  end of function Create_Ptree  ----- */
