
vpath %.h ./
vpath %.h ../link_list/index_list/
vpath %.h ../link_list/string_list/

vpath %.c ./
vpath %.c ../link_list/index_list/
vpath %.c ../link_list/string_list/


final:test_file_deal.o string_list.o index_list.o file_deal.o
	gcc -o final test_file_deal.o string_list.o index_list.o file_deal.o
final_gdb:test_file_deal.o string_list.o index_list.o file_deal.o
	gcc -o final_gdb -g test_file_deal.o string_list.o index_list.o file_deal.o

test_file_deal.o:file_deal.h string_list.h

file_deal.o:file_deal.h string_list.h

string_list.o:string_list.h 

index_list.o:index_list.h




.PHONY:clean
clean:
	rm -f *.o
