

list:list.o main.o
	$(CC) list.o main.o -o list
list.o:list.h list.c
	$(CC) -c list.c -o list.o
main.o:main.c list.h
	$(CC) -c main.c -o main.o

.PHONY:clean
clean:
	$(RM) *.o 

