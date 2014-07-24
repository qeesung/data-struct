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
        Preorder_Traverse(my_tree->rightchild, my_fun);
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
    if(my_tree == NULL || my_fun==NULL)
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
       // Visit(tree_node->leftchild);
        //Visit(tree_node->rightchild);
        my_fun(tree_node);
        if(tree_node->leftchild!=NULL)
        {
            Enqueue(tree_queue, tree_node->leftchild);
            //printf("I am En queue\n name : %s  age : %d", tree_node->leftchild->name, tree_node->leftchild->age);
        }
        if(tree_node->rightchild!=NULL)
        {
            Enqueue(tree_queue, tree_node->rightchild);
           // printf("I am En queue\n name : %s age : %d", tree_node->rightchild->name , tree_node->rightchild->age);    
        }
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
    new_tree_node -> age = my_person.age ;
    new_tree_node->leftchild=NULL;
    new_tree_node->rightchild=NULL;


    if(my_tree == NULL)/*  need to create root */
    {
        my_tree=new_tree_node;        
        fprintf(stderr, "\n this is NULL situation \n ");
        return;
    }
    if(leftorright == 0)
        (my_tree)->leftchild = new_tree_node ;
    if(leftorright == 1)
        (my_tree) -> rightchild = new_tree_node;
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
        return 0;
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

    if(my_tree!= NULL)
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Parent
 *  Description:  get a tree node parent
 * =====================================================================================
 */
    Tree
Parent ( Tree my_tree , Tree my_tree_node )
{
    Queue my_queue;
    Tree dequeue_node;
    my_queue= Init_Queue();
    Enqueue(my_queue, my_tree);
    while((dequeue_node = Dequeue(my_queue))!= NULL)
    {
        if(dequeue_node -> leftchild!=NULL && dequeue_node->leftchild->name == my_tree_node->name && dequeue_node->leftchild->age==my_tree_node->age )
            return dequeue_node;
        if(dequeue_node -> rightchild!=NULL && dequeue_node->rightchild->name == my_tree_node->name && dequeue_node->rightchild->age==my_tree_node->age )
            return dequeue_node;
        if(dequeue_node -> leftchild !=NULL)
            Enqueue(my_queue, dequeue_node->leftchild);
        if(dequeue_node-> rightchild != NULL)
            Enqueue(my_queue, dequeue_node->rightchild);
        
    }
    return ;
}		/* -----  end of function Parent  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Point
 *  Description:  find a point pointer with name and value 
 * =====================================================================================
 */
    Tree
Find_Point ( Tree my_tree , char * name, int age )
{
    Queue my_queue;
    Tree dequeue_node;
    if(my_tree == NULL)
        return NULL;
    my_queue=Init_Queue();
    Enqueue(my_queue, my_tree);
    while((dequeue_node= Dequeue(my_queue))!=NULL)
    {
//        printf("%s -----> %d\n", dequeue_node->name, dequeue_node->age);
        if(strcmp(dequeue_node->name, name)==0 && dequeue_node -> age == age)
            return dequeue_node;
        if(dequeue_node->leftchild!=NULL)
            Enqueue(my_queue,dequeue_node->leftchild);
        if(dequeue_node->rightchild!=NULL)
            Enqueue(my_queue, dequeue_node->rightchild);
    }
    fprintf(stderr, "\n can not find the point with name %s age %d \n", name , age);
    return NULL;
}		/* -----  end of function Find_Point  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Leftchild
 *  Description:  get a point left child
 * =====================================================================================
 */
    Tree
Get_Leftchild ( Tree my_tree_node )
{
    if(my_tree_node == NULL)
    {
        fprintf(stderr,"\n the node is not exists\n ");
        return NULL;
    }
    if(my_tree_node->leftchild!=NULL)
        return my_tree_node->leftchild;
    return NULL;
}		/* -----  end of function Get_Leftchild  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Rightchild
 *  Description:  get a tree node rightchild
 * =====================================================================================
 */
    Tree
Get_Rightchild ( Tree my_tree_node )
{
    if(my_tree_node == NULL)
    {
        fprintf(stderr, "\n the tree node is not exists\n ");
        return NULL;
    }
    if(my_tree_node->rightchild!=NULL)
        return my_tree_node->rightchild;
    return NULL;
}		/* -----  end of function Get_Rightchild  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Leftsibling
 *  Description:  get a node left sibling
 * =====================================================================================
 */
    Tree
Get_Leftsibling (Tree my_tree,  Tree my_tree_node )
{
    Tree parent_point;
    if(my_tree_node==NULL || my_tree==NULL)
    {
        fprintf(stderr, "\n the tree node or tree is not exists\n ");
        return NULL;
    }
    parent_point = Parent(my_tree ,my_tree_node);
    if(parent_point==NULL)
        return ;
    if(parent_point->leftchild==my_tree_node)
    {
        fprintf(stderr, "\n leftchild have no leftsibling\n");
        return NULL;
    }
    else
    {
        if(parent_point -> leftchild == NULL)
        {
            fprintf(stderr, "\n have not left sibling \n ");
            return NULL;
        }
        if(parent_point->leftchild!=NULL)
            return parent_point ->leftchild;
    }
    return NULL;
}		/* -----  end of function Get_Leftsibling  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Rightsibling
 *  Description:  get a node right sibling
 * =====================================================================================
 */
    Tree
Get_Rightsibling (Tree my_tree,  Tree my_tree_node )
{
    Tree parent_point;
    if(my_tree_node==NULL || my_tree==NULL)
    {
        fprintf(stderr, "\n the tree node or tree is not exists\n ");
        return NULL;
    }
    parent_point = Parent(my_tree ,my_tree_node);
    if(parent_point==NULL)
        return ;
    if(parent_point->rightchild==my_tree_node)
    {
        fprintf(stderr, "\n rightchild have no rightsibling\n");
        return NULL;
    }
    else
    {
        if(parent_point -> rightchild == NULL)
        {
            fprintf(stderr, "\n have not left sibling \n ");
            return NULL;
        }
        if(parent_point->rightchild!=NULL)
            return parent_point ->rightchild;
    }
    return NULL;
}		/* -----  end of function Get_Rightsibling  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_Child
 *  Description:  delete tree node left or right child tree
 * =====================================================================================
 */
    void
Delete_Child ( Tree my_tree_node, int leftorright )
{
    if(my_tree_node == NULL)
    {
        return ;
    }
    if(leftorright == 0 && my_tree_node->leftchild!=NULL)
    { /*  这里要把一颗子树的左右两颗子树都删除了 */
        Delete_Child(my_tree_node->leftchild, 0);
        Delete_Child(my_tree_node->leftchild, 1);
    }
    if(leftorright == 1 && my_tree_node->rightchild != NULL)
    {
        Delete_Child(my_tree_node->rightchild,0);
        Delete_Child(my_tree_node->rightchild,1);
    }
    free(my_tree_node);
    return ;
}		/* -----  end of function Delete_Child  ----- */
