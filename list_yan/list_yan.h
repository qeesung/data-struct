#ifndef _LIST_YAN_H
#define _LIST_YAN_H
#define LIST_SIZE 10
struct Listnode;
typedef struct Listnode * List;
typedef List Position;
/* Create a list */
List Create_List(int number);
/* get the #i number */
Position Get_Node(List my_list,int i);
/* Insert the element into the list of the psotion #i */
void Insert_List(List my_list ,int i , int number ,char * name);
/* delete the element in the #i */
void Delete_List(List my_list , int i );
/* printf all the element in the list */
void Print_List(List my_list);
#endif
