

graph:test.o adjacency_list.o queue.o
	gcc	test.o adjacency_list.o queue.o -o graph
test.o adjacency_list.o:adjacency_list.h queue.h
queue.o:queue.h


.PHONY:clean
clean:
	rm -f *.o
