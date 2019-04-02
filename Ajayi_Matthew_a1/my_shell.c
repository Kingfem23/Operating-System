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
#include "myshellFunctions.h"

extern char **getln();

int main() 
{
	int i;
	char **args;
	
	while(1) 
	{
		args = getln();
		for(i = 0; args[i] != NULL; i++) 
		{
			printf("Argument %d = %s\n", i, args[i]);
		}

		//Exit arguement
		if (strcmp(args[0],"exit")== 0) 
		{
			printf("*************************************************************************\n"); 
			printf("Thank you for using my shell program.\n");
			printf("*************************************************************************\n"); 
			exit(0);
		}

		else if(strcmp(args[0],"add")== 0)
		{
			printf("*************************************************************************\n"); 
			addFunction(args);
			printf("*************************************************************************\n"); 
		}

		else if(strcmp(args[0],"o/e")== 0)
		{
			printf("*************************************************************************\n"); 
			oddEvenFunc(args);
			printf("*************************************************************************\n"); 
		}

		else if(strcmp(args[0],"mul")== 0)
		{
			printf("*************************************************************************\n"); 
			multipleFunc(args);
			printf("*************************************************************************\n"); 
		}

		else if(strcmp(args[0], "args") == 0)
		{
			printf("*************************************************************************\n"); 
			argsCounterFunc(args);
			printf("*************************************************************************\n"); 
		}

		else 
		{
			printf("*************************************************************************\n"); 
			arguementCheckFunction(args);	
			printf("*************************************************************************\n"); 
		}

	}
}

