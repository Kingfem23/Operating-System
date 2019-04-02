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

//Parse the given file
void parseFile(FILE * file, Queue * q)
{
	char * line;
    line = (char *)malloc(sizeof(char*));
    float lineLen;
    lineLen = 0;

    while(fgets(line,150, file) != NULL)
    { 

        lineLen++;
        
        //get rid of new lines
        if(line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) -1] = '\0';

        }

        //Store values into linked list data
        Data * qInfo = (Data *) malloc(sizeof(Data));
        qInfo->name = line[0];
        qInfo-> size = atoi(&line[2]);	
		enqueue(q, qInfo);
		q -> printData(qInfo);

    }


}

//Initialize Linked list
Queue *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{

    Queue * myList = (Queue*) malloc(sizeof(Queue));

    if(myList == NULL)
    {
    	return NULL;
    	
    }

    else
    {
        myList -> head = NULL;
		myList -> tail = NULL;
        myList -> printData =  printFunction;
        myList -> deleteData =  deleteFunction;
        myList -> compare = compareFunction;	
    }
	

    return myList;

}

//Create node for linked list
Node *initializeNode(void * data)
{
    Node * ptr = (Node *) malloc(sizeof(Node));
    ptr -> data = data;
    ptr -> next = NULL;
    return ptr;

}

//insert node in the front
void enqueue(Queue *list, void *toBeAdded)
{

    if (list == NULL || toBeAdded == NULL)
    {
        return;
    }
    
    Node * temp = initializeNode(toBeAdded);
    if(list -> head != NULL)
    {
		temp -> next = list -> head;
		list -> head = temp;
    }

    else
    {
		list -> head = temp;
		list -> tail = temp;
    }
	
}

//First Fit algorithm
void firstFit(Queue * q)
{
	int memMax = 128;
	if(q == NULL)
    {
        return;
    }

    // Node * tempPtr; 
    // tempPtr = q -> head;
	char memory[memMax];

	for (int i = 0; i < memMax; i++)
	{
		memory[i] = '-';
	}

	calculateAlgo(memory, q);

}

//Next Fit algorithm
void nextFit(Queue * q)
{
	int memMax = 128;
	if(q == NULL)
    {
        return;
    }

    // Node * tempPtr; 
    // tempPtr = q -> head;
	char memory[memMax];

	for (int i = 0; i < memMax; i++)
	{
		memory[i] = '-';
	}

	calculateAlgo(memory, q);

}

//Worst Fit algorithm
void worstFit(Queue * q)
{
	int memMax = 128;
	if(q == NULL)
    {
        return;
    }

    // Node * tempPtr; 
    // tempPtr = q -> head;
	char memory[memMax];

	for (int i = 0; i < memMax; i++)
	{
		memory[i] = '-';
	}

	calculateAlgo(memory, q);

}

//Best Fit algorithm
void bestFit(Queue * q)
{
	int memMax = 128;
	if(q == NULL)
    {
        return;
    }

    // Node * tempPtr; 
    // tempPtr = q -> head;
	char memory[memMax];

	for (int i = 0; i < memMax; i++)
	{
		memory[i] = '-';
	}

	calculateAlgo(memory, q);

}

//Comparing nodes to see if less than equal to 128 and also delete from list
void calculateAlgo (char mem[], Queue *q)
{
	int hole;
	hole = 1;
	int end;
	end = 0;
	int memMax = 128;

	for (int i = 0 ; i < memMax; i++)
	{
		if (mem[i] == '-')
		{
			for (int j = i; j < memMax; j++)
			{
				if (mem[j] != '-' && mem[j+1] != '-')
				{
					end++;
				}
			}
			if (end == 1)
			{
				hole++;
			}
		}
	}

	if (hole > 6)
	{
		hole = 3;
	}

	Node * node = (Node*) (q -> tail);
	Data * qInfo = (Data*) (q -> head -> data);

	int num = 0;

	while (node != NULL)
	{
		for (int i = 0; i < memMax; i++)
		{
			if (qInfo->name == mem[i] && mem[i] != mem[i+1])
			{
				num++;
			}
		}

		node = node->next;
	}

	int memusage = 0;

	for (int i = 0; i < memMax; i++)
	{
		if (mem[i]!='-')
		{
			memusage++;
		}
	}

	printf ("Pid Loaded: Process Number = %d, Hole Number = %d, %%Memory Usage = %d, Total %%Memory = %.1f\n",num,hole, memusage,0.0);
}

//Queue void function
void printData(void * stringPtr)
{
    Data * d = (Data* )(stringPtr);
    printf("Name is: %c Size is: %d\n", d -> name, d -> size);

}

int compare(const void *first, const void *second)
{
    // Data * firstD = (Data * )(first);
    // Data * secondD = (Data * )(second);

    // if(firstD -> timeQueue > secondD -> timeQueue)
    // {
    //     return 1;
    // }

    // else
    // {
    //     return 0;
    // }
	return 0;

}

