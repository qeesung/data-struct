#include<stdio.h>
#include<stdlib.h>
#include"./list.h"

int main()
{
	
	List list1,list2,new_list;
	Position my_position;
	list1=init_list();
	list2=init_list();
	insert_direct(list1,67);
	insert_direct(list1,78);
	insert_direct(list1,9);
	insert_direct(list1,37);
	insert_direct(list1,56);
	insert_direct(list1,15);
	insert_direct(list1,24);

	print_list(list1);

	insert_direct(list2,56);
	insert_direct(list2,23);
	insert_direct(list2,45);
	insert_direct(list2,12);
	insert_direct(list2,29);
	insert_direct(list2,37);
	insert_direct(list2,18);
	print_list(list2);
	new_list=merge_list(list1,list2);
	print_list(new_list);
	
	return 0;
}
