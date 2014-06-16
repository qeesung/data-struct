#ifndef _LIST_H
#define _LIST_H

struct listnode;
typedef struct listnode * List;//pointer to listnode
typedef List Position;

//init the List
List init_list();
//insert number into the list 
int insert_number(List L,int number,Position pos);
//delete number from the list
int delete_number(List L,int number);
//delete the List
int delete_List(List L);
//find the number
Position position_find(List L,int numher);
//print the list number
void print_list(List my_list);
//insert the number after the header
int insert_direct(List my_list,int number);
// delete the number after the header
int delete_direct(List my_list);
// merge two list 
List merge_list(List list1,List list2);
#endif
