
path:queue.o ol_graph.o test_path.o
	gcc queue.o ol_graph.o test_path.o -o path
topo_sort:queue.o ol_graph.o test_topo.o
	gcc queue.o ol_graph.o test_topo.o -o topo

graph:queue.o ol_graph.o test.o
	gcc queue.o ol_graph.o test.o -o graph
queue.o:queue.h
ol_graph.o:queue.h ol_graph.h
test.o:ol_graph.h
test_topo.o:ol_graph.h
test_path.o:ol_graph.h


.PHONY:clean
clean:
	rm -f *.o
