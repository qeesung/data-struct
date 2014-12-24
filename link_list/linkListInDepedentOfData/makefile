fileHelper:menu.o linkList.o main.o
	gcc menu.o linkList.o main.o -o fileHelper

linkList.o:linkList.h
menu.o:linkList.h menu.h
main.o:linkList.h menu.h

.PHONY:clean

clean:
	rm -f *.o