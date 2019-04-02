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

/**
*Data strcut for Node
**/
typedef struct listNode{
    void * data;
    struct listNode *next;
} Node;

/**
*Data strcut to store all of the processer information.
**/
typedef struct data{
   char name;
   int size; 
   int swapCount; 
} Data;

/**
 *Dummy head of the list. Contains no actual data on it beyond a pointer to the front and end of the list.
 **/
typedef struct listHead{
    Node *head;
    Node *tail;
    Node * done;
    void (*deleteData)(void *toBeDeleted);
    int (*compare)(const void *first,const void *second);
    void (*printData)(void *toBePrinted);
} Queue;

//Parse the given file
void parseFile(FILE * file, Queue * q);

//Initialize Linked list
Queue *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

//Create node for linked list
Node *initializeNode(void * data);

//Insert node infront
void enqueue(Queue *list, void *toBeAdded);

//FF Algorithm
void firstFit(Queue * q);

//NF Algorithm
void nextFit(Queue * q);

//WF Algorithm
void worstFit(Queue * q);

//BF Algorithm
void bestFit(Queue * q);

//Queue void function
void printData(void * stringPtr);

//Calculate positioning algorithm
void calculateAlgo(char mem[], Queue *q);
