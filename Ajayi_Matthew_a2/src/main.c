#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulation.h"


int main(int argc, char *argv[])
{


	int detailMode;
	int verboseMode;
	int robinMode;
	int value;
	//int fcfs;

	detailMode = verboseMode = robinMode = value = 0;


	//checks for mode
    for(int i = 0; i < argc; i++)
    {
	    if(strcmp(argv[i], "-d") == 0)
	    {
	    	detailMode = 1;
	    }

	    if(strcmp(argv[i], "-v") == 0)
	    {
	    	verboseMode=1;
	    }

	    if(strcmp(argv[i], "-r") ==0)
	    {
	    	robinMode = 1;
	    	value = atoi(argv[i+1]);
	    }

  	}

  	//Go into rr function
	if (robinMode == 1)
  	{
  		printf("\n-------------------------------Round Robin Mode-------------------------------\n");
  		roundRobin(detailMode, verboseMode, value);
  		printf("\n------------------------------------------------------------------------------\n");
  	}

  	//Go into fcfs
  	else
  	{
  		printf("\n-------------------------------First Come First Serve Mode-------------------------------\n");
		firstComeFirstServe(detailMode, verboseMode);
		printf("\n-----------------------------------------------------------------------------------------\n");
  	}


}

