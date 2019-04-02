*************************************************************
Matthew Ajayi			0921003
CIS 2520 			Assignment 1
January 29th, 2018
*************************************************************

********************
Compilation
********************

The command line used to compile the program with additions is "make" or "make msh"

********************
Running the program
********************
To run the program use make Makefile get an executable and run the executable ./msh

After the executable is ran there may be a warning that pops up but it will not affect the program. The user can enter one of the following commands into the shell: "add, mul, o/e" and the terminal commands from the assignment. My two algorithms for this assignment was a odd and even checker that detects if the number entered in the shell is odd or even after parsing it (space delimited). So if the user entered: "o/e 23, 1, 2" the output would be "odd, odd. even". The second algorithm is a multiplier that calculates the product between decimal values and hexadecimal values. So if the user enters "mul 2 3 4" the output would be 24. An assumption i made was that the user will enter the commands and values all in one line, like "add 2 3". 
********************
Problems
********************
I was unable to get the command with the "&" symbol working correctly. Also reading in the file with the "<" is not completely correct. Finally my code is sometimes glitchy and manages to leave the while loop on some cases. All other commands should work accordingly.

