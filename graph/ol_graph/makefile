
graph:queue.o ol_graph.o test.o
	gcc queue.o ol_graph.o test.o -o graph
queue.o:queue.h
ol_graph.o:queue.h ol_graph.h
test.o:ol_graph.h

.PHONY:clean
clean:
	rm -f *.o
