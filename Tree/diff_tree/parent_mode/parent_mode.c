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
 *         Name:  err_sys
 *  Description:  deal with the error
 * =====================================================================================
 */
    void
err_sys (char * string )
{
    fprintf(stderr,string);
    exit(EXIT_FAILURE);
    return ;		/* -----  end of function err_sys  ----- */
}
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



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Ptree_Empty
 *  Description:  check is the tree is empty
 * =====================================================================================
 */
    int
Ptree_Empty ( Ptree my_tree )
{
    if(my_tree == NULL)
        err_sys("the tree is not init\n");
    if(my_tree->number ==0)
        return 1;
    else
        return 0;
    return ;
}		/* -----  end of function Ptree_Empty  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Ptree_Depth
 *  Description:  work out the tree depth
 * =====================================================================================
 */
    void
Ptree_Depth ( Ptree my_tree)
{
    int depth =0 ;
    int p_index;
    int k=0;
    int max_depth=0;
    if(my_tree == NULL)
        err_sys("the tree is not init\n ");
    for(k=0;k<my_tree->number;k++)
    {
        p_index=my_tree->nodes[k].parent;
        while(p_index!=-1)
        {
            p_index=my_tree->nodes[p_index];
            depth++;
        }
        if(depth>max)
            max=depth;
        depth=0;
    }
    return depth+1;
}		/* -----  end of function Ptree_Depth  ----- */
