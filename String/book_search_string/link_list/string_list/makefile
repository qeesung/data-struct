
vpath %.h ./
vpath %.h ../index_list/

vpath %.c ./
vpath %.c ../index_list/

string_list:test_string_list.o string_list.o index_list.o
	gcc test_string_list.o string_list.o index_list.o -o string_list
test_string_list.o:string_list.h
string_list.o:string_list.h index_list.h
index_list.o:index_list.h


.PHONY:clean
clean:
	rm -f *.o
