CC = gcc
prog = myavl

all: $(prog)

$(prog): *.o
	$(CC) *.o -o $(prog)

*.o : *.c *.h
	$(CC) -c *.c

clean: 
	rm -f *.o

purge: clean
	rm -f $(prog)


	

