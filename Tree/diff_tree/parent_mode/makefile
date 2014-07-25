source=queue.o test_ptree.o parent_mode.o
ptree_test:$(source)
	gcc $(source) -o ptree_test
queue_test:queue.o test_queue.o
	gcc queue.o test_queue.o -o queue_test
queue.o:queue.h
test_queue.o:queue.h
parent_mode.o:parent_mode.h

.PHONY:clean
clean:
	rm -f *.o
