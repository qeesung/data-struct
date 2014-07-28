
tree_final: queue.o  child_mode.o test_tree.o
	gcc queue.o  child_mode.o test_tree.o -o tree_final

queue_final:queue.o test_queue.o
	gcc queue.o test_queue.o -o queue_final
queue.o:queue.h child_mode.h
test_queue.o:queue.h child_mode.h
child_mode.o:queue.h child_mode.h


.PHONY:clean
clean:
	rm -f *.o
