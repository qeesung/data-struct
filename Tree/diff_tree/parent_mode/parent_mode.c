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
    int
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
            p_index=my_tree->nodes[p_index].parent;
            depth++;
        }
        if(depth>max_depth)
            max_depth=depth;
        depth=0;
    }
    return max_depth+1;
}		/* -----  end of function Ptree_Depth  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Root
 *  Description:  get root value
 * =====================================================================================
 */
    char
Root (Ptree my_tree )
{
    if(my_tree== NULL)
        err_sys("Tree is not init\n");
    if(my_tree->number ==0)
    {
        return (char)0;
    }
    return my_tree->nodes[0].data;
}		/* -----  end of function Root  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Value
 *  Description:  get a tree node value
 * =====================================================================================
 */
    char
Value ( Ptree my_tree , int index )
{
    if(my_tree==NULL)
        err_sys("The tree is not init\n");
    if(index >= my_tree->number)
        err_sys("The  index greater than tree size\n");
    return my_tree->nodes[index].data;
}		/* -----  end of function Value  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Assign
 *  Description:  assign a tree node
 * =====================================================================================
 */
    void
Assign ( Ptree my_tree , int index , char new_value )
{
    if(my_tree==NULL)
        err_sys("The tree is not init\n");
    if(index >= my_tree->number)
        err_sys("The  index greater than tree size\n");
    my_tree->nodes[index].data= new_value;
    return;
}		/* -----  end of function Assign  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Parent
 *  Description:  get a node parent value
 * =====================================================================================
 */
    char 

Parent (Ptree my_tree , int index )
{
    int p_index;
    if(my_tree==NULL)
        err_sys("The tree is not init\n");
    if(index >= my_tree->number)
        err_sys("The  index greater than tree size\n");
    p_index = my_tree->nodes[index].parent;
    return my_tree->nodes[p_index].data;
}		/* -----  end of function Parent  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Leftchild
 *  Description:  get the parent left child
 * =====================================================================================
 */
    char
Leftchild ( Ptree my_tree , int index , int * child_index)
{
    int k;
    if(my_tree==NULL)
        err_sys("The tree is not init\n");
    if(index >= my_tree->number)
        err_sys("The  index greater than tree size\n");
    for(k=0;k<my_tree->number;k++)
    {
        if(my_tree->nodes[k].parent == index)
        {
            *child_index = k; 
            return my_tree->nodes[k].data;
        }
    }
   // printf("can not find the %c leftchild", my_tree->nodes[index].data);
   return (char)0;
}		/* -----  end of function Leftchild  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Rightsibling
 *  Description:  get leftchild all right sibling
 * =====================================================================================
 */
    char *
Rightsibling ( Ptree my_tree , int sib_index, int * sib_sum )
{
    int k=0;
    char * all_data;
    *sib_sum=1;
    int parent;
    char sib_data;
    int child_index;
    if(my_tree==NULL)
        err_sys("The tree is not init\n");
    if(sib_index >= my_tree->number)
        err_sys("The  index greater than tree size\n");

    all_data	= malloc ( sizeof(char) );
    if ( all_data==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    parent = my_tree->nodes[sib_index].parent;
    sib_data= my_tree->nodes[sib_index].data;
    if(sib_data!= Leftchild(my_tree, parent, &child_index))
        err_sys("the index need to be leftchild\n");
    for(k=0;k<my_tree->number ; k++)
    {
        if(my_tree->nodes[k].parent==parent && my_tree->nodes[k].data!=sib_data)
        {
            (*sib_sum)++;
            all_data	= realloc (all_data,*sib_sum);
            if ( all_data==NULL ) {
                fprintf ( stderr, "\ndynamic memory allocation failed\n" );
                exit (EXIT_FAILURE);
            }
            all_data[(*sib_sum)-2]=my_tree->nodes[k].data;
        }
    }
    return all_data;
}		/* -----  end of function Rightsibling  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Ptree
 *  Description:  print tree with father and child
 * =====================================================================================
 */
    void
Print_Ptree (Ptree my_tree )
{
    int k;
    int i;
    int sib_sum;
    char * sib_data;
    int sib_index;
    char leftchild_data;
    int leftchild_index;
    if(my_tree==NULL)
        err_sys("The tree is not init\n");
    for(k=0;k<my_tree->number;k++)
    {
        printf("%c---->children:\t\t",my_tree->nodes[k].data);
        leftchild_data=Leftchild(my_tree, k , &leftchild_index);
        if(leftchild_data==(char)0)
        {
            printf("\n");
            continue;
        }
        printf("%c\t\t",leftchild_data);
        sib_data= Rightsibling(my_tree , leftchild_index, &sib_sum);
        for(i=0;i<sib_sum ;i++)
        {
            printf("%c\t\t", sib_data[i]);
        }
        printf("\n");
        free(sib_data);

    }

    return;
}		/* -----  end of function Print_Ptree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Traverse
 *  Description:  traverse the p tree
 * =====================================================================================
 */
    void
Traverse ( Ptree my_tree )
{
    int k=0;
    for(k=0;k<my_tree->number;k++)
    {
        printf("data:%c\t\t parent:%d\n", my_tree->nodes[k].data,my_tree->nodes[k].parent);
    }
    return ;
}		/* -----  end of function Traverse  ----- */
