*************************************************************
Matthew Ajayi			0921003
CIS 3110 			Assignment 3
March 26th, 2018
*************************************************************

********************
Compilation
********************

The command line used to compile the program (s) is either "make dine" or "make holes" or gcc -std=c99 -Wall  -pthread src/dine.c -o bin/dine and gcc -std=c99 -Wall src/holes.c  src/holeSim.c  -Iinclude -o bin/holes

********************
Running the program
********************
To run the diner program use make Makefile get an executable and run the executable bin/dine 3 2 or whatever number the user wants to enter. To run the memory usage program: bin/holes assets/input.txt or whatever file user has.

The user cannot enter  "1 2" for the diner program or else it goes into infinite loop. 

********************
References
********************

- Old code was used from 2520 summer semester.
- Lecture and lab notes were used
- https://www.cs.mtu.edu/~shene/NSF-3/e-Book/MUTEX/TM-example-philos-1.html.