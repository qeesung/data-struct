#ifndef _LIST_YAN_H
#define _LIST_YAN_H

struct Listnode;
typedef struct Listnode * List;
typedef List Position;
/* Create a list */
List Create_List(int number);
/* get the #i number */
Position Get_Node(List my_list,int i);
#endif
