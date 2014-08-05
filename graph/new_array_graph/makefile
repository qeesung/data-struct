
graph:test.c graph.o queue.o
	gcc test.c graph.o queue.o -o graph
test.o:graph.h
graph.o:graph.h queue.h
queue.o:queue.h

.PHONY:clean
clean:
	rm -f *.o
