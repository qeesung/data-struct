/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.c
 *
 *    Description:  c file for my binary tree 
 *
 *        Version:  1.0
 *        Created:  2014年07月20日 05时29分47秒
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

struct person person_list[10]=
{
    {"A",21},
    {"B",22},
    {"C",23},
    {"D",24},
    {"E",25},
    {"F",26},
    {"G",27},
    {"H",28},
    {"I",29},
    {"J",30}

};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Bitree
 *  Description:  init my binary tree
 * =====================================================================================
 */

Tree Init_Bitree()
{
    int i=0;
    Tree new_tree;
    new_tree	= malloc ( sizeof(struct person)  * MAX_TREE_SIZE);
    if ( new_tree==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    for(i=0;i<MAX_TREE_SIZE;i++)
    {
        new_tree[i].name="None";
        new_tree[i].age=0;
    }
    return new_tree;

}
/* -----  end of function Init_Bitree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Create_Bitree()
 *  Description:  create binary tree with person list 
 * =====================================================================================
 */
    void
Create_Bitree( Tree tree, struct person my_person_list[] , int list_size)
{
    int i=0;
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree have not init \n ");
        return;
    }
    if(my_person_list==NULL)
    {
        fprintf(stderr,"\n the person list is empty \n ");
        return;
    }
    printf("list_size : %d\n ", list_size);
    for(i=0;i<list_size;i++)
    {
        tree[i].name = my_person_list[i].name;
        tree[i].age = my_person_list[i].age;
    }
    return;

}		/* -----  end of function Create_Bitree()  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_Bitree
 *  Description:  print all the element in the binary tree
 * =====================================================================================
 */
    void
Print_Bitree ( Tree tree )
{
    int i=0;
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree is not init \n ");
        return;
    }
    while(tree[i].name != "None" && tree[i].age!=0)
    {
        printf("%s ____> %d \n ", tree[i].name, tree[i].age);
        i++;
    }
    return;
}		/* -----  end of function Print_Bitree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Empty()
 *  Description:  check if the tree is empty
 * =====================================================================================
 */
    int 
Bitree_Empty ( Tree tree )
{
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree have not inited \n ");
        return -1;
    }
    if(tree[0].name=="None" && tree[0].age==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}		/* -----  end of function Bitree_Empty()  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Depth
 *  Description:  get the depth of the binary tree
 * =====================================================================================
 */
    int
Bitree_Depth ( Tree tree )
{   
    int i;
    int depth=0;
    for(i=0;i<MAX_TREE_SIZE;i++)
    {
        if(tree[i].name=="None" && tree[i].age==0)
            break;
    }
    i-=1;
    while((i=(i+1)/2-1) !=0)
    {
        depth++;
    }
    depth++;
    return depth+1;
}		/* ----- end of function Bitree_Depth  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Root
 *  Description:  get the root value
 * =====================================================================================
 */
    Person
Bitree_Root (Tree tree )
{
    Person root_person;
    if(Bitree_Empty(tree))
    {
        fprintf(stderr,"The tree is empty\n");
        return NULL;
    }
    root_person	= malloc ( sizeof(struct person) );
    if ( root_person==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    root_person->name=tree[0].name;
    root_person->age = tree[0].age;
    return root_person;
}		/* -----  end of function Bitree_Root  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Value
 *  Description:  get the positiob value
 * =====================================================================================
 */
    Person
Bitree_Value ( Tree tree , struct position pos )
{
    Person value_person;
    int i=0;
    int level=1;
    if(tree == NULL)
    {
        fprintf(stderr,"\n the tree is not exists\n ");
        return NULL;
    }

    value_person	= malloc ( sizeof(struct person) );
    if ( value_person==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    while(level!=pos.level)
    {
        i=2*i+1;
        level+=1;
    }
    i+=(pos.number-1);
    value_person->name= tree[i].name;
    value_person->age = tree[i].age;
    return value_person;
}		/* -----  end of function Bitree_Value  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Assign
 *  Description:  assign a new value for position pos
 * =====================================================================================
 */
    void
Bitree_Assign ( Tree tree , struct position pos, struct person new_person)
{
    int i ;
    int level=1;
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree is not exists \n");
        return ;
    }
    i=0;
    while(level != pos.level)
    {
        i=2*i+1;
        level++;
    }
    i+=pos.number-1;
    if(i>=MAX_TREE_SIZE)
    {
        fprintf(stderr,"the tree number is greater than %d please enter a new position \n", MAX_TREE_SIZE);
        return;
    }
    tree[i].name = new_person.name;
    tree[i].age = new_person.age;
    return ;
}		/* -----  end of function Bitree_Assign  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Parent
 *  Description:  get a position element parent
 * =====================================================================================
 */
    Person
Bitree_Parent ( Tree tree , struct position pos )
{
    Person parent_person;
    int i=0;
    int level=1;
    if(tree ==NULL)
    {
        fprintf(stderr, "\n the tree is not init \n ");
        return NULL;
    }
    if(pos.level==1)
    {
        fprintf(stderr, "\n the root have not parent\n ");
        return NULL;
    }
    while(level != pos.level)
    {
        i=2*i+1;
        level++;
    }
    i+=pos.number-1;
    if(i >= MAX_TREE_SIZE)
    {
        fprintf(stderr,"\n the position overflow the %d try another position less than it\n", MAX_TREE_SIZE);
        return NULL;
    }

    parent_person	= malloc ( sizeof(struct person) );
    if ( parent_person==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    i=(i+1)/2 -1; /*  get the parent position  */
    parent_person->name = tree[i].name;
    parent_person->age = tree[i].age;
    return parent_person;
}		/* -----  end of function Bitree_Parent  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Child
 *  Description:  get left child(leftorright==0) or right child(leftorright==1)
 * =====================================================================================
 */
    Person
Bitree_Child ( Tree tree , struct position pos , int leftorright )
{
    Person child_person;
    int i =0;
    int level =1;
    if(tree == NULL)
    {
        fprintf(stderr,"\n the tree is not init \n ");
        return NULL;
    }
    while(level!=pos.level)
    {
        i=2*i+1;
        level++;
    }
    i+=pos.number-1;
    if(i > MAX_TREE_SIZE )
    {
        fprintf(stderr, "\n the number is overflow %d \n ", MAX_TREE_SIZE);
        return NULL;
    }
    
    child_person	= malloc ( sizeof(struct person) );
    if ( child_person==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }
    if( leftorright == 0 && 2*i+1 < MAX_TREE_SIZE && (tree[2*i+1].name != "None" && tree[2*i+1].age!=0))
    {
        child_person->name = tree[2*i+1].name;
        child_person->age = tree[2*i+1].age;
        return child_person;
    }
    if(leftorright==1 && 2*i+2 < MAX_TREE_SIZE &&(tree[2*i+2].name != "None" && tree[2*i+2].age != 0))
    {
        child_person->name = tree[2*i+2].name ;
        child_person->age = tree[2*i+2].age;
        return child_person;
    }
    free(child_person);
    printf("\n can not get the child \n ");
    return NULL;
}		/* -----  end of function Bitree_Child  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Bitree_Sibling
 *  Description:  get the binary tree sibling 
 * =====================================================================================
 */
    Person
Bitree_Sibling ( Tree tree , struct position pos , int leftorright)
{
    /* leftorright ==0 is get left sibling
     * leftorright ==1 is get right sibling*/
    Person sib_person;
    int i =0;
    int level=1;
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree have not init \n ");
        return NULL;
    }
    while(level!=pos.level)
    {
        level++;
        i=2*i+1;
    }
    i+=pos.number-1;
    if(i>=MAX_TREE_SIZE)
    {
        fprintf(stderr, "\n the size of tree is gtreater than %d \n ", MAX_TREE_SIZE);
        return NULL;
    }

    sib_person	= malloc ( sizeof(struct person) );
    if ( sib_person==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    if(leftorright==0 && i%2==0)
    {   
        i=(i+1)/2-1;
        i=2*i+1;
        sib_person->name = tree[i].name ;
        sib_person->age = tree[i].age;
        return sib_person;
                 
    }
    if(leftorright==1 && i%2!=0)
    {
        i=(i+1)/2-1;
        i=2*i+2;
        if(tree[i].name == "None" && tree[i].age == 0)
        {
            fprintf(stderr, "\n have no right sibling\n ");
            free(sib_person);
            return NULL;
        }
        sib_person->name = tree[i].name ;
        sib_person->age = tree[i].age;
        return sib_person;
    }
    free(sib_person);
    fprintf(stderr, "\n right sibling have not right sibling\n or \n left sibling have not left sibling \n ");
    return NULL;
}		/* -----  end of function Bitree_Sibling  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Move_Bitree
 *  Description:  move tree1 at index i to tree2 at index j
 * =====================================================================================
 */
    void
Move_Bitree (Tree tree1 , int index1, Tree tree2 , int index2 )
{
    if(tree1 == NULL || tree2 == NULL)
    {
        fprintf(stderr, "\n tree1 ot tree2 is not init \n ");
            return ;
    }
    if(tree1[index1*2+1].name != "None" && tree1[index1*2+1].age !=0)
    {
        Move_Bitree(tree1, 2*index1+1,tree2,2*index2+1);
    }
    if(tree1[index1*2+2].name != "None" && tree1[index1*2+2].age!=0)
    {
        Move_Bitree(tree1, 2*index1+2 , tree2 , 2*index2+2);
    }
    tree2[index1].name = tree1[index2].name;
    tree2[index1].age = tree1[index2].age;
    tree1[index2].name = "None";
    tree1[index2].age = 0;
}		/* -----  end of function Move_Bitree  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Visit
 *  Description:  print detail massage struct of person
 * =====================================================================================
 */
    void
Visit ( struct person my_person )
{
    printf("%s -----> %d\n", my_person.name, my_person.age);
    return;

}		/* -----  end of function Visit  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Preorder_Traverse
 *  Description:  先序遍历binary tree
 * =====================================================================================
 */
    void
Preorder_Traverse ( Tree tree , int index )
{
    if(tree== NULL)
    {
        fprintf(stderr,"\n the tree have not init \n");
        return;
    }
    if(tree[index].name == "None" && tree[index].age == 0)
    {
        return ;
    }
    Visit(tree[index]);
    Preorder_Traverse(tree, index*2+1);
    Preorder_Traverse(tree , index*2+2);
    return;
}		/* -----  end of function Preorder_Traverse  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Inorder_Traverse
 *  Description: 中序遍历binary tree
 * =====================================================================================
 */
    void
Inorder_Traverse ( Tree tree , int index )
{
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree have not init \n ");
        return;
    }
    if(tree[index].name == "None" && tree[index].age == 0)
    {
        return;
    }
    Inorder_Traverse(tree , index*2+1);
    Visit(tree[index]);
    Inorder_Traverse(tree , index*2+2);

    return ;
}		/* -----  end of function Inorder_Traverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Postorder_Traverse
 *  Description:  后序遍历binary tree
 * =====================================================================================
 */
    void
Postorder_Traverse ( Tree tree , int index )
{
    if(tree == NULL)
    {
        fprintf(stderr, "\n the tree have not init \n ");
        return ;
    }
    if(tree[index].name == "None" && tree[index].age == 0)
    {
        return ;
    }
    Postorder_Traverse(tree , index*2+1);
    Postorder_Traverse(tree , index*2+2);
    Visit(tree[index]);
    return ;
}		/* -----  end of function Postorder_Traverse  ----- */
