/*
 Author: Matthew Ajayi
 Date: January 29th 2018
 Purpose: test code.
 
 University of Guelph, 2018.
 CIS*3110
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

//add function
void addFunction(char ** args);

//Creation 1: check if number inputted is odd or even
void oddEvenFunc(char ** args);

//Creation 2: Multiple two types of numbers hex or decimal
void multipleFunc(char ** args);

//parse and count the number of arguements
void argsCounterFunc(char ** args);

//performs terminal commands
void arguementCheckFunction(char ** args);