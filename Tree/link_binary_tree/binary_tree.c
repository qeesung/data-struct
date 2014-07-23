/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.c
 *
 *    Description:  This is c file about my link binary tree
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 05时55分13秒
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
#include"binary_tree.h"
#include"queue.h"

struct person person_list[]={
    {"A", 21},
    {"B", 22},
    {"C", 23},
    {"D", 24},
    {"E", 25},
    {"F", 26},
    {"G", 27},
    {"H", 28},
    {"I", 29},
    {"J", 30}
};
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Tree
 *  Description:  Init a bianry tree
 * =====================================================================================
 */
    Tree
Init_Tree (  )
{
    Tree new_tree;
    new_tree = NULL;
    return new_tree;
}		/* -----  end of function Init_Tree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destory_Tree
 *  Description:  Destory a binary tree
 * =====================================================================================
 */
    void
Destory_Tree ( Tree my_tree )
{
    if(my_tree == NULL)
    {
        return;
    }
    if(my_tree -> leftchild !=NULL)
    {
        Destory_Tree(my_tree->leftchild);
    }
    if(my_tree -> rightchild !=NULL)
    {
        Destory_Tree(my_tree->rightchild);
    }
    free(my_tree);
    return;
}		/* -----  end of function Destory_Tree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Visit
 *  Description:  visit the tree node 
 * =====================================================================================
 */
    void
Visit ( Tree tree_node )
{
    printf("%s -----> %d \n", tree_node->name, tree_node->age);
    return;
}		/* -----  end of function Visit  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Preorder_Traverse
 *  Description:  traverse the binary tree with preorder
 * =====================================================================================
 */
    void
Preorder_Traverse ( Tree my_tree , funcpointer my_fun )
{
    if(my_tree == NULL || my_fun == NULL)
    {
        return;
    }
    my_fun(my_tree);
    if(my_tree->leftchild !=NULL)
        Preorder_Traverse(my_tree->leftchild, my_fun);
    if(my_tree->rightchild !=NULL)
        Preorder_Traverse(my_tree->rightchild. my_fun);
    return ;
}		/* -----  end of function Preorder_Traverse  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Inorder_Traverse
 *  Description:  traverse the binary tree with mode inorder
 * =====================================================================================
 */
    void
Inorder_Traverse ( Tree my_tree , funcpointer my_fun )
{
    if(my_tree == NULL || my_fun===NULL)
    {
        return ;
    }
    Inorder_Traverse(my_tree->leftchild, my_fun);
    my_fun(my_tree);
    Inorder_Traverse(my_tree->rightchild, my_fun);
    return ;
}		/* -----  end of function Inorder_Traverse  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Postorder_Traverse
 *  Description:  traverse the tree with mode postorder
 * =====================================================================================
 */
    void
Postorder_Traverse ( Tree my_tree , funcpointer my_fun )
{
    if(my_tree == NULL || my_fun== NULL)
    {
        return;
    }
    Postorder_Traverse(my_tree->leftchild , my_fun);
    Postorder_Traverse(my_tree->rightchild, my_fun);
    my_fun(my_tree);
    return;
}		/* -----  end of function Postorder_Traverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Levelorder_Traverse
 *  Description:  traverse the binary tree with the mode level order
 * =====================================================================================
 */
    void
Levelorder_Traverse ( Tree my_tree , funcpointer my_fun )
{
    Queue tree_queue;
    Tree tree_node;
    if(my_tree==NULL || my_fun == NULL)
    {
        return;
    }
    tree_queue = Init_Queue();
    Enqueue(tree_queue, my_tree);
    while((tree_node=Dequeue(tree_queue))!=NULL)
    {
        my_fun(tree_node);
        if(tree_node->leftchild!=NULL)
            Enqueue(tree_queue, tree_node->leftchild);
        if(tree_node->rightchild!=NULL)
            Enqueue(tree_queue, my_tree->rightchild);
    }
    return ;
}		/* -----  end of function Levelorder_Traverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Tree
 *  Description:  create a binry tree with person list
 * =====================================================================================
 */
    void
Create_Tree ( Tree my_tree ,int leftorright,  struct person my_person )
{
    /*  create the tree left child<leftorright ==0 >
     *  creete the tree right child<leftorright ==1 >*/
    Tree new_tree_node;
    new_tree_node	= malloc ( sizeof(struct tree) );
    if ( new_tree_node==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    new_tree_node -> name = my_person.name;
    new_tree_node -> age - my_person.age ;

    if(my_tree == NULL)/*  need to create root */
    {
        my_tree=new_tree_node;        
        return;
    }
    if(leftorright == 0)
        my_tree->leftchild = new_tree_node ;
    if(leftorright == 1)
        my_tree -> rightchild = new_tree_node;
    return;
}		/* -----  end of function Create_Tree  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Tree_Empty
 *  Description:  test if the tree is empty
 * =====================================================================================
 */
    int
Tree_Empty ( Tree my_tree )
{
    if(my_tree== NULL)
        return 1;
    else
        return 0
}		/* -----  end of function Tree_Empty  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Tree_Depth
 *  Description:  work out the tree depth
 * =====================================================================================
 */
    int
Tree_Depth ( Tree my_tree )
{
    int depth;
    int i=0;
    int j=0;
    if(my_tree == NULL)
        return 0;
    if(my_tree -> leftchild == NULL && my_tree-> rightchild == NULL)
        return 1;
    if(my_tree-> leftchild!=NULL)
        i += Tree_Depth(my_tree->leftchild);
    if(my_tree -> rightchild != NULL)
        j += Tree_Depth(my_tree->rightchild);
    return i>j ? i+1:j+1;
}		/* -----  end of function Tree_Depth  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Root
 *  Description:  return root value 
 * =====================================================================================
 */
    Person
Root ( Tree my_tree )
{
    Person root_person;

    root_person	= malloc ( sizeof(struct person) );
    if ( root_person==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    if(my_tree! = NULL)
    {
        root_person->name = my_tree->name ;
        root_person->age = my_tree->age;
    }
    else
    {
        free(root_person);
        fprintf(stderr, "\n the tree is empty \n ");
        return NULL;
    }
}		/* -----  end of function Root  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Value
 *  Description:  get a tree_node value 
 * =====================================================================================
 */
    Person
Value (Tree my_tree_node )
{
    Person tree_node_person;
    if(my_tree_node != NULL)
    {
        
        my_tree_node	= malloc ( sizeof(struct person) );
        if ( my_tree_node==NULL ) {
            fprintf ( stderr, "\ndynamic memory allocation failed\n" );
            exit (EXIT_FAILURE);
        }

        tree_node_person->name=my_tree_node->name;
        tree_node_person->age = my_tree_node->age;
        return tree_node_person;
    }
    else
    {
        fprintf(stderr, "\n the tree_node is not exists\n ");
        return NULL;
    }

}		/* -----  end of function Value  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Assign
 *  Description:  assign for a tree_node with new_name and new_age
 * =====================================================================================
 */
    void
Assign ( Tree my_tree_node, char * new_name , int new_age )
{
    if(my_tree_node !=NULL)
    {
        my_tree_node -> name = new_name;
        my_tree_node -> age = new_age;
    }
    return ;
}		/* -----  end of function Assign  ----- */
