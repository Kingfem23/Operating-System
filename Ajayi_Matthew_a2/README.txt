*************************************************************
Matthew Ajayi			0921003
CIS 2520 			Assignment 2
February 26th, 2018
*************************************************************

********************
Compilation
********************

The command line used to compile the program is "make", "make prog" or gcc -std=c99 -Wall main.c simulation.c -Iinclude -o simcpu

********************
Running the program
********************
To run the program use make Makefile get an executable and run the executable bin/simcpu -d -r 10 <  assets/testcase1.txt or whatever mode the user wants to enter. 

The user can enter one of the following modes: -d, -v, -r  into the command line or enter all of them.  If  "-r" is not included in the command line my program will automatically assume  the user wants to perform an first come first serve algorithm. The program will generally run a fcfs algorithm or round robin and display all the required information.

********************
Problems
********************
I was unable to get the command verbose mode to work accurately and switch from interrupt state to a highest priority. 

********************
Questions
********************
i. Does your simulator include switch overhead for the first ready state to running state transition? Explain.
ii. Does your simulator include switch overhead if a thread moves from ready state to running state and the CPU is idle? Explain.
iii. Does your simulator include switch overhead if a thread moves from running state to blocked state and the ready queue is empty? Explain.
iv. Does your simulation include switch overhead if a thread is interrupted
(due to a time slice) and either the ready queue is empty or the thread has
the highest priority? Explain.

i) My simulator includes a switch overhead for all the threads in the testcases.
ii/iii) I made an assumption that theres a thread switch for every process time. My simulator does not work for blocked to ready queues. 
iv) My simulator does not accurately work for switching from interrupt state to a highest priority. 

********************
References
********************

Old code was used from 2520 summer semester.
