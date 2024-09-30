flags=-Wall -O2  -std=c2x
ldflags=

all: tree
	
tree: tree.o
	cc ${flags} $^ -o $@ 

tree.o: tree.c
	cc ${flags} -c $^ ${ldflags}

clean: 
	rm -f *.o tree