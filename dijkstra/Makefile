cc:=g++
CFLAGS := -g -Wall -O3
CPPFLAGS := $(CFLAGS)
objects = test.o Vertex.o Edge.o Graph.o
 
test:$(objects)
	$(cc) -o test $(objects)
 
test.o: Vertex.h Edge.h
Graph.o: Vertex.h Edge.h
 
clean:
	rm test $(objects)
