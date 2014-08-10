


source_tree=queue.o test_tree.o child_sib.o
tree_test:$(source_tree)
	gcc $(source_tree) -o tree_test
source_queue=queue.o test_queue.o
queue_test:$(source_queue)
	gcc $(source_queue) -o queue_test
queue.o:queue.h child_sib.h
test_queue.o:queue.h child_sib.h
test_tree.o:queue.h child_sib.h


.PHONY:clean
clean:
	rm -f *.o
