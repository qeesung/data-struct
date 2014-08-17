
vpath %.h child_sib_mode
dij:test_dij.o adjacency_list.o queue.o 
	gcc	test_dij.o adjacency_list.o queue.o  -o dij
topo:test_topo.o adjacency_list.o queue.o 
	gcc	test_topo.o adjacency_list.o queue.o  -o topo

graph:test.o adjacency_list.o queue.o child_sib.o
	gcc	test.o adjacency_list.o queue.o child_sib.o -o graph
test.o: adjacency_list.h
adjacency_list.o:adjacency_list.h queue.h child_sib.h
queue.o:queue.h
child_sib.o:child_sib.h
test_topo.o: adjacency_list.h
test_dij.o: adjacency_list.h



.PHONY:clean
clean:
	rm -f *.o
