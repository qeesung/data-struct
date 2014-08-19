vpath %.h ../../graph/new_array_graph
vpath %.c ../../graph/new_array_graph
warshall:graph.o warshall.o queue.o
	gcc graph.o warshall.o queue.o -o warshall
warshall.o graph.o:graph.h
queue.o:queue.h


.PHONY:clean
clean:
	 rm -f *.o
