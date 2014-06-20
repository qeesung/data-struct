double_link_list:main.o list.o
	gcc main.o list.o -o double_link_list
main.o:list.h
list.o:list.h

.PHONY:clean
clean:
	rm -f *.o
