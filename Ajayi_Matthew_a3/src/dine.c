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
#include <pthread.h>
#include <unistd.h>

//Global variables 
int eatTime = 0;
int philosopherToDine = 0;
pthread_mutex_t cutlery[1000];

//Diner algorithm
void * dinerSim (void * value);

int main(int argc, char *argv[])
{
	pthread_t simulationThread[1000];

	int threadID[1000];
	int val = 0;
	char *val1, *val2;
    

	//Get the number of philosophers and number of times they eat
	val1 = argv[1];
    val2 = argv[2];

    if(val1 != NULL && val2 != NULL)
    {
    	philosopherToDine = atoi(val1);
    	eatTime = atoi(val2);
    }

    else
    {
    	printf("Incorrect number of values entered please try again\n");
    	exit(1);
    }


    //Make mutex and execute the functions
    for (int i = 0; i < philosopherToDine; i++) 
    {
        threadID[i] = i;
    }

    for (int i = 0; i < philosopherToDine; i++)
    {
        val = pthread_create(&(simulationThread[i]),NULL,dinerSim,&(threadID[i]));
        if (val != 0)
        {
            printf ("There was an error creating the thread. Please run the program again\n");
            exit(1);
        }
    }

    //Make a result for threads 
     for (int i = 0; i< philosopherToDine; i++)
    {
        pthread_mutex_init(&cutlery[i],NULL);
    }

    for (int i =0; i < philosopherToDine; i++)
    {
        pthread_join(simulationThread[i],NULL);
    }

    return 0;

}

//Diner simulation algorithm after user enters all 2 values
void * dinerSim (void * value)
{
	int counter = 0;
	int id = *(int *) value;
    int tempid;
    tempid = (id +1);
    tempid = tempid % philosopherToDine;

    while (counter < eatTime)
    {
        printf ("Philsopher #%d is thinking\n", (id + 1));
        pthread_mutex_lock(&cutlery[id % philosopherToDine]);
        pthread_mutex_lock(&cutlery[tempid]);
        printf ("Philsopher #%d is eating\n", (id +1));
        sleep(1);
        pthread_mutex_unlock(&cutlery[id % philosopherToDine]);
        pthread_mutex_unlock(&cutlery[tempid]);
        printf ("Philsopher #%d has finished eating\n",(id +1));
        counter++;
    }

    pthread_exit(0);
}
