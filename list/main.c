#include<stdio.h>
#include<stdlib.h>
#include"./list.h"

int main()
{
	List my_list;
	my_list=init_list();
	insert_direct(my_list,10);
	insert_direct(my_list,9);
	insert_direct(my_list,8);
	insert_direct(my_list,7);
	insert_direct(my_list,6);
	insert_direct(my_list,5);
	insert_direct(my_list,4);
	print_list(my_list);
	delete_direct(my_list);
	print_list(my_list);

	return 0;
}
