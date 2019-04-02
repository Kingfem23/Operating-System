CC          =	gcc
# Flags that are sent to the compiler

CFLAGS      =	-Wall -std=c99 -pedantic -g

prog:
	$(CC) $(CFLAGS) src/main.c  src/simulation.c  -Iinclude -o bin/simcpu

clean:
	rm bin/*