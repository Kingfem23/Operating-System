
/*
 Author: Matthew Ajayi
 Date: March 26th, 2018
 Purpose: Main code to run simulation for philosopher diner
 
 University of Guelph, 2018.
 CIS*3110 W18
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "holeSim.h"

int main(int argc, char *argv[])
{
	FILE * file;
    file = NULL;
    file = fopen(argv[1],"r");
    Queue * q;
    q = initializeList(printData, NULL, NULL);;

    if(argc != 2)
    {
        printf("Incorrect number of arguements\n");
        exit(1);
    }

    if(file == NULL)
    {
        printf("File does not exist\n");
        exit(1);
    }

  	printf("\nThe parsed data is:\n");
    parseFile(file, q);


    printf("\n-------------------------------First Fit Mode-----------------------------------------\n");
    firstFit(q);
  	printf("\n--------------------------------------------------------------------------------------\n");

  	printf("\n-------------------------------Next Fit Mode------------------------------------------\n");
    nextFit(q);
  	printf("\n--------------------------------------------------------------------------------------\n");

  	printf("\n-------------------------------Worst Fit Mode-----------------------------------------\n");
    worstFit(q);
  	printf("\n--------------------------------------------------------------------------------------\n");
    
    printf("\n-------------------------------Best Fit Mode------------------------------------------\n");
    bestFit(q);
  	printf("\n--------------------------------------------------------------------------------------\n");

}
