objects = test.o Date.o

all: test

test: $(objects)
	g++ -o test $(objects)

test.o: test.cc
	g++ -c test.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

clean:
	rm -f test *.o
