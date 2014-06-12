#include<stdio.h>
#include<stdlib.h>
#include"./list.h"

int main()
{
	
	List my_list;
	Position my_position;
	my_list=init_list();
	insert_direct(my_list,10);
	insert_direct(my_list,9);
	insert_direct(my_list,8);
	insert_direct(my_list,7);
	insert_direct(my_list,6);
	insert_direct(my_list,5);
	insert_direct(my_list,4);
	print_list(my_list);
	my_position = position_find(my_list,8);
	if(my_position == NULL)
	{
		printf("can not find the number\n");
	}
	insert_number(my_list,14,my_position);
	insert_number(my_list,78,my_position);
	print_list(my_list);
	my_position=position_find(my_list,14);
	delete_number(my_list,14);
	print_list(my_list);
	
	return 0;
}
