/*
 Author: Matthew Ajayi
 Date: January 29th 2018
 Purpose: test code.
 
 University of Guelph, 2018.
 CIS*3110
*/

#include "myshellFunctions.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

//add function
void addFunction(char ** args)
{
	int convertedNum;
	int total;
	total = convertedNum = 0;
	char * p;
	char * temp;

	//check if hex value then convert or else just convert string and add
	for(int j = 1; args[j]!= NULL; j++)
	{
		temp = args[j];

		if(temp[0] == '0')
		{
			convertedNum = strtol(temp, &p, 16);
		}

		else 
		{
			convertedNum = strtol(temp, &p, 10);
		}

		total = total + convertedNum;
	}

	printf("Your sum is: %d\n", total);

}

//Creation 1: check if number inputted is odd or even
void oddEvenFunc(char ** args)
{
	int convertedNum2;
	int total2;
	total2 = 1;
	char * p;
	char * d;


	for(int j = 1; args[j]!= NULL; j++)
	{
		d = args[j];

		if(d[0] == '0')
		{
			convertedNum2 = strtol(d, &p, 16);
		}

		else 
		{
			convertedNum2 = atoi(d);
		}

		/* odd or even chech */
		if ((convertedNum2 & 1) == 1)
	      printf("Odd\n");
	   	else
	      printf("Even\n");
	}

}

//Creation 2: Multiple two types of numbers hex or decimal
void multipleFunc(char ** args)
{
	int convertedNum1;
	int multipleTotal;
	multipleTotal = 1;
	convertedNum1 = 0;
	char * p;
	char * m;

	for(int j = 1; args[j]!= NULL; j++)
	{
		m = args[j];

		if(m[0] == '0')
		{
			convertedNum1 = strtol(m, &p, 16);
		}

		else 
		{
			convertedNum1 = atoi(m);
		}

		
		multipleTotal *= convertedNum1;		
	}

	printf("Your product is: %d\n", multipleTotal);
	multipleTotal = 1;

}

//parse and count the number of arguements
void argsCounterFunc(char ** args)
{
	char * argsLen;
	int argumentCount = 0;
	char temp1[100];

	// while(fgets(*args,sizeof(args), stdout) != NULL)
//  		{
//  			//if(temp1 == ",")
//  			//{
//  				argsLen = strtok(*args, ", \n");
//  				printf("Output: %s", argsLen);

//  				//argumentCount++;
//  			//}
		
//  		} 

	for(int j = 1; args[j] != NULL; j++)
	{
		argsLen = args[j];

		for(int k = 0; k < strlen(argsLen); k++)
		{
			//checks if empty space
			if(argsLen[k] == '\"')
			{
				strcat(temp1, argsLen);
				argumentCount = argumentCount + 1;
				break;
			}

			else
			{
				strcat(temp1, argsLen);
				argumentCount = argumentCount + 1;
				break;
			}
		}

		//split words after comma
		strcat (temp1, ", ");

	}

	printf ("Output: argc = %d args = %s\n",argumentCount,argsLen);

}

//performs terminal commands
void arguementCheckFunction(char ** args)
{
	pid_t  pid; 
	int processStat;
	FILE * file;
    file = NULL;
    int position;

	//check if there is only one arguement
	if (args[1] == NULL)
	{	
		pid = fork();
		
		//forking failed
		if (pid < 0)
		{
			printf ("An error was found: the forking process has failed\n");
			exit(1);
		}

		//exec failed
		else if (pid == 0)
		{
			
			//checks if execvp failed
			if (execvp(args[0],args) < 0)
			{
				printf ("An error was found: the exec process failed\n");
				exit(1);
			}

			
		}

		else 
		{
			while(wait(&processStat) != pid);
		}
	}

	else if (strcmp(args[1],"-l") == 0)
	{
		pid = fork();

		//forks failed
		if (pid < 0)
		{
			printf ("An error was found: the forking process has failed\n");
			exit(1);
		}

		//child process
		else if (pid == 0)
		{
			//execvp failed 
			if (execvp(args[0],args) < 0)
			{
				printf ("An error was found: the exec process failed\n");
				exit(1);
			}
		}

		else 
		{
			while(wait(&processStat) != pid);
		}

	}

	else if (strcmp(args[1],"-a") == 0)
	{
		pid = fork();

		//forking failed 
		if (pid < 0)
		{
			printf ("An error was found: the forking process has failed\n");
			exit(1);
		}

		//child process
		else if (pid == 0)
		{
			//execvp failed 
			if (execvp(args[0],args) < 0)
			{
				printf ("An error was found: the exec process failed\n");
				exit(1);
			}
		}

		else 
		{
			while(wait(&processStat) != pid);
		}

	}

	//Checks if ">" is an argument
	else if(strcmp(args[1], ">") == 0)
	{
		for (int j =0; args[j] != NULL; j++)
		{
			if (strcmp(args[j],">") == 0)
			{
				position = j;
			}
		}

		args[position] = NULL;

		//Open file
		file = freopen(args[position +1],"w",stdout);
		pid = fork();

		//failed forking condition
		if (pid < 0)
		{
			printf ("An error was found: the forking process has failed\n");
			exit(1);
		}

		//child process
		else if (pid == 0)
		{	
				//failed exec condition
				if (execvp(args[0],args) < 0)
				{
					printf ("An error was found: the exec process failed\n");
					exit(1);
				}
		}

		else 
		{
			while(wait(&processStat) != pid);
		}

		fclose(file);
	}

	else if(strcmp(args[1], "<") == 0)
	{
		//checks if there is a > in the commnad line
		for (int j =0; args[j] != NULL; j++)
		{
			if (strcmp(args[j],"<") == 0)
			{
				position = j;
			}
		}

		args[position] = NULL;

		//opens the file 
		file = freopen(args[position +1],"w",stdout);
		pid = fork();

		//checks if forking failed or not
		if (pid < 0)
		{
			printf ("An error was found: the forking process has failed\n");
			exit(1);
		}

		//child process
		else if (pid == 0)
		{	
				// checks if execvp is less than 0
				if (execvp(args[0],args) < 0)
				{
					printf ("An error was found: the exec process failed\n");
					exit(1);
				}
		}

		else 
		{
			while(wait(&processStat) != pid);
		}

		fclose(file);
	}

}


