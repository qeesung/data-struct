object=bitree.o search.o test.o queue.o
test:$(object)
	gcc $(object) -o  test
bitree.o:bitree.h
search.o:bitree.h search.h
test.o:bitree.h search.h

include queue.mk

.PHONY:clean
clean:
	rm -f *.o
