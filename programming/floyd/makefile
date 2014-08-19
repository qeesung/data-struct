vpath %.h ../../graph/new_array_graph
vpath %.c ../../graph/new_array_graph
floyd:graph.o floyd.o queue.o
	gcc graph.o floyd.o queue.o -o floyd
floyd.o graph.o:graph.h
queue.o:queue.h


.PHONY:clean
clean:
	 rm -f *.o
