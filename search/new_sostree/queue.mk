
queue:queue.o test_queue.o
	gcc queue.o test_queue.o -o queue
queue.o:queue.h bitree.h
test_queue.o:queue.h bitree.h
