
vpath %.h child_sib_mode
graph:test.o adjacency_list.o queue.o child_sib.o
	gcc	test.o adjacency_list.o queue.o child_sib.o -o graph
test.o: adjacency_list.h
adjacency_list.o:adjacency_list.h queue.h child_sib.h
queue.o:queue.h
child_sib.o:child_sib.h



.PHONY:clean
clean:
	rm -f *.o
