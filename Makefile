CC = gcc
CCFLAGS = -lm
all:
	$(CC) gauss_jordan.c -o gauss $(CCFLAGS)
	$(CC) gauss_seidel.c -o gausss $(CCFLAGS)
clean:
	rm gauss_jordan.o
	rm gauss_seidel.o
