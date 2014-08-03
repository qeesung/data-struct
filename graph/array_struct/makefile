graph_out:test.o graph.o
	gcc test.o graph.o -o graph_out

test.o:graph.h
graph.o:graph.h

.PHONY:clean
clean:
	rm -f *.o
