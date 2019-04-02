CC          =   gcc
# Flags that are sent to the compiler

CFLAGS      =   -Wall -std=c99 -pedantic -pthread -g

CFLAGS2      =   -Wall -std=c99 -pedantic -g

dine:
	$(CC) $(CFLAGS) src/dine.c  -o bin/dine

holes:
	$(CC) $(CFLAGS2) src/holes.c  src/holeSim.c  -Iinclude -o bin/holes

clean:
	rm bin/*