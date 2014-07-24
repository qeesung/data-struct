

final:test.o binary_tree.o queue.o
	gcc test.o binary_tree.o queue.o -o final
test.o:binary_tree.h
binary_tree.o:binary_tree.h
queue.o:queue.h


.PHONY:clean
clean:
	rm -f *.o
