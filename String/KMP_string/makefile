

KMP:main.o string.o KMP.o
	gcc main.o string.o KMP.o -o KMP

main.o:string.h
KMP.o:string.h KMP.h
string.o:string.h KMP.h


.PHONY:clean
clean:
	rm -f *.o
