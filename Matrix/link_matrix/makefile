

test:test.o matrix.o
	gcc test.o matrix.o -o test
test.o:matrix.h
matrix.o:matrix.h

.PHONY:clean
clean:
	rm -f *.o
