
#ifndef _LIST_H
#define _LIST_H
#include<stdio.h>
struct listnode;
typedef struct listnode *  LIST;
typedef LIST position;
/* define basicn functions */
//clear the list
LIST makeempty();
//insert a element into the list
int insertele(LIST list,int element,position p);
//delete a element from the list
int deleteele(LIST list int element,position p);
//find the element position
position  find(LIST list int element);
//delete a list
void deletelist(LIST list);
#endif

