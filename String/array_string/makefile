string:main.o string.o	
	gcc main.o string.o -o string
main.o:string.h
string.o:string.h

.PHONY:clean
clean:
	rm -f *.o
