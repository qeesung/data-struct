
graph:test.c graph.o
	gcc test.c graph.o -o graph
test.o:graph.h
graph.o:graph.h

.PHONY:clean
clean:
	rm -f *.o
