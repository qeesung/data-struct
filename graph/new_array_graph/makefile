dij1:dijkstra.o graph.o queue.o
	gcc dijkstra.o graph.o queue.o -o dij1
dij:test_dij.o graph.o queue.o
	gcc test_dij.o graph.o queue.o -o dij
kruskal:test_kruskal.o graph.o queue.o
	gcc test_kruskal.o graph.o queue.o -o kruskal
prim:test_prim.o graph.o queue.o
	gcc test_prim.o graph.o queue.o -o prim
graph:test.o graph.o queue.o
	gcc test.o graph.o queue.o -o graph
test.o:graph.h
graph.o:graph.h queue.h
queue.o:queue.h
test_prim.o:graph.h
test_kruskal.o:graph.h
test_dij.o:graph.h
dijkstra.o:graph.h

.PHONY:clean
clean:
	rm -f *.o
