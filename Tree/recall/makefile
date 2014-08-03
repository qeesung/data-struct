recall_out:list.o recall_test.o recall.o
	gcc list.o recall_test.o recall.o -o recall_out

list_out:list.o list_test.o
	gcc list.o list_test.o -o list_out
list.o:list.h
list_test.o:list.h
recall_test.o:list.h recall.h
recall.o:list.h recall.h


.PHONY:clean
clean:
	rm -f *.o
