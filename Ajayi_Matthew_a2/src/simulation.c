#include "simulation.h"

void parseFile(FILE * file)
{
	// printf("Inside parser!\n");
	// int numProcess;
	// int threadSwitch;
	// int processSwitch;
	// int processNumber;
	// int numThread;
	// int threadNum;
	// int arrival;
	// int numCPU;
	// int cpuTime;
	// int ioTime;

    char * line;
    line = (char *)malloc(sizeof(char*));
    int lineLen;
    lineLen = 0;	
    char * val11 = malloc(sizeof(char*));
        char * val12 = malloc(sizeof(char*));
        char * val13 = malloc(sizeof(char*));
        char * val1 = malloc(sizeof(char));
        char * val2 = malloc(sizeof(char));
        char * val3 = malloc(sizeof(char));
        char * comment = malloc(sizeof(char));
        char * val4 = malloc(sizeof(char));

    while(fgets(line,350, file) != NULL)
    { 
    	
        lineLen++;
        
        //get rid of new lines
        // if(line[strlen(line) - 1] == '\n')
        // {
        //     line[strlen(line) -1] = '\0';

        // }

        

        val1 = zstring_strtok(line, " ");
        val2 = zstring_strtok(NULL, " ");
        val3 = zstring_strtok(NULL, " ");
        comment = zstring_strtok("//", "\n");
        val4 = zstring_strtok("\n", " ");

        val11 = malloc(sizeof(char)* (strlen(val1)) + 1);
        val12 = malloc(sizeof(char)* (strlen(val2)) + 1);
        val13 = malloc(sizeof(char)* (strlen(val3)) + 1);

        strcpy(val11, val1);
        strcpy(val12, val2);
        strcpy(val13, val3);


        printf("Num process = %s, threadSwitch = %s, processSwitch = %s, processNumber = %s, numberofThreads = %s\n", val11, val12, val13, comment, val4);

        //Data * carInfo = (Data *) malloc(sizeof(Data));


        // carInfo->travelDirection = line[0];
        // carInfo-> actualDirection = line[2];

        // carInfo -> timeQueue = atoi(&line[4]);

        // carInfo -> numberofCars = lineLen;

        //insertSorted(queue, carInfo);
        

    }

    //free(val1);
    
    //simulateProgram(queue,output);
    
    fclose(file);



}

//Manually Parse string
char *zstring_strtok(char *str, const char *delim) 
{
    static char *static_str=0;      /* var to store last address */
    int index=0, strlength=0;       /* integers for indexes */
    int found = 0;                  /* check if delim is found */

    /* delimiter cannot be NULL
    * if no more char left, return NULL as well
    */
    if (delim==0 || (str == 0 && static_str == 0))
        return 0;

    if (str == 0)
        str = static_str;

    /* get length of string */
    while(str[strlength])
        strlength++;

    /* find the first occurance of delim */
    for (index=0;index<strlength;index++)
        if (str[index]==delim[0]) {
            found=1;
            break;
        }

    /* if delim is not contained in str, return str */
    if (!found) {
        static_str = 0;
        return str;
    }

    /* check for consecutive delimiters
    *if first char is delim, return delim
    */
    if (str[0]==delim[0]) {
        static_str = (str + 1);
        return (char *)delim;
    }

    /* terminate the string
    * this assignmetn requires char[], so str has to
    * be char[] rather than *char
    */
    str[index] = '\0';

    /* save the rest of the string */
    if ((str + index + 1)!=0)
        static_str = (str + index + 1);
    else
        static_str = 0;

        return str;
}

//FCFS implementation
void firstComeFirstServe(int detailMode, int verboseMode)
{
	int numProcess;
	int threadSwitch;
	int processSwitch;
	int processNum;
	int numThreads;
	int threadTime;
	int arrivalTime;
	int numberCPU;
	int cpuTime;
	int ioTime;
	int cpuNum;
	char data[255];
	int totalCPU[255];
	int totalIO[255];
	int tempFinalCPU;
	int tempFinalIO;
	int finalCPUTime;
	int finalIOTime;
	int totalTime;
	int k;
	int threadCounter;
	threadCounter = 0;
	int serviceT;
	serviceT = 0;
	int tempFinal;
	tempFinal = 0;
	int taTime; 
	taTime = 0;
	int tempTotalReq;
	tempTotalReq = 0;
	double cpuPercent, totalAverageTurnA;
	cpuPercent = totalAverageTurnA = 0.0;
	int avgTime; 
	avgTime = 0;
	int fTime = 0;

	tempFinalIO = tempFinalCPU = totalTime = finalCPUTime = finalIOTime = cpuNum = numProcess = threadSwitch = processSwitch = processNum = numThreads = threadTime = arrivalTime = 
	numberCPU = cpuTime = ioTime = 0;

	fgets (data,255,stdin);
	numProcess = atoi(zstring_strtok(data, " "));
	threadSwitch = atoi (zstring_strtok(NULL, " "));
	processSwitch = atoi(zstring_strtok(NULL,"\n"));
	//printf("number of process's = %d thread switch = %d, process switch = %d\n", numProcess, threadSwitch, processSwitch);

	//Check line by line and save values
	for (int i = 0; i < numProcess; i++)
	{

		fgets (data,255,stdin);
		processNum = atoi(zstring_strtok(data, " "));
		numThreads = atoi (zstring_strtok(NULL, " "));
		threadCounter += numThreads;
		//printf("process Number = %d number of threads = %d\n", processNum, numThreads);

		for(int j = 0; j < numThreads; j++)
		{
			fgets (data,255,stdin);
			threadTime = atoi(zstring_strtok(data, " "));
			arrivalTime = atoi (zstring_strtok(NULL, " "));
			numberCPU = atoi (zstring_strtok(NULL, " "));
			//printf("thread Time = %d arrival Time = %d, number of CPU = %d\n", threadTime, arrivalTime, numberCPU);
	
			for(k = 0; k < (numberCPU - 1); k++)
			{
				fgets (data,255,stdin);
				cpuNum = atoi(zstring_strtok(data, " "));
				cpuTime = atoi (zstring_strtok(NULL, " "));
				ioTime = atoi (zstring_strtok(NULL, " "));
				totalCPU[k] = cpuTime;
				totalIO[k] = ioTime;
				//printf("CPU Number = %d cpu Time = %d, i/o Time = %d\n", cpuNum, cpuTime, ioTime);

			}

			fgets (data,255,stdin);
			cpuNum = atoi(zstring_strtok(data, " "));
			cpuTime = atoi (zstring_strtok(NULL, " "));
			totalCPU[k] = cpuTime;
			//printf("CPU Number = %d cpu Time = %d\n", cpuNum, cpuTime);
			
			tempFinalCPU = 0;
			for(k = 0; k < numberCPU; k++)
			{
				finalCPUTime = totalCPU[k] + finalCPUTime; 
				tempFinalCPU += totalCPU[k];
			}

			tempFinalIO = 0;
			for(k = 0; k < numberCPU - 1; k++)
			{
				finalIOTime = totalIO[k] + finalIOTime; 
				tempFinalIO += totalIO[k];
			}

			if (threadTime == 1)
			{
				totalTime = totalTime + processSwitch;
				fTime = fTime + processSwitch;
			}

			//Service and turnaround time calculation
			tempFinal = tempFinalIO + tempFinalCPU;
    		taTime = taTime + tempFinal + threadSwitch;
			serviceT = tempFinal - tempFinalIO;
			avgTime = avgTime + (taTime - arrivalTime);
			fTime += finalIOTime + finalCPUTime + threadSwitch;
			fTime = fTime - arrivalTime;

			//Go into detail mode
			if(detailMode == 1)
			{
				//printf("-------------------------------Detail Mode-------------------------------\n");
				printf("\nThe thread is: %d The process is: %d\n",threadTime,processNum);  
			    printf("The arrival time is: %d\n",arrivalTime); 
			    printf("The service time is: %d\n",serviceT); 
			    printf("I/O time: %d\n",tempFinalIO); 
			    printf("Turnaround time: %d units \n",(taTime-arrivalTime));
			    printf("Finish time: %d units \n",taTime);
			}

			//Go into verbose mode
			if (verboseMode == 1)
			{ 
				//printf("-------------------------------Verbose Mode-------------------------------\n");
				printf ("\nAt arrival time: %d Thread: %d Process: %d transitions from %s to %s\n",0,threadTime,processNum,"new", "ready");
				printf ("At arrival time: %d Thread: %d Process: %d transitions from %s to %s\n",arrivalTime,threadTime,processNum, "ready", "running");
				printf ("At arrival time: %d Thread: %d Process: %d transitions from %s to %s\n",(fTime - threadSwitch), threadTime, processNum, "running", "terminate");
				printf("\n");
			}

		}

		totalTime = totalTime + (threadSwitch * numThreads);

	}

	//more calculations
	totalTime = totalTime + (processSwitch * numProcess);
	totalTime = totalTime + finalIOTime + finalCPUTime;
	tempTotalReq = totalTime - (processNum * processSwitch) - (threadSwitch * numThreads) - finalIOTime; 
	cpuPercent = tempTotalReq; 
	cpuPercent /= totalTime;
	totalAverageTurnA = avgTime / threadCounter;

	printf ("\nThe average turnaround time is: %0.2f\n",totalAverageTurnA);
	printf ("The CPU utilization is: %0.2f\n", cpuPercent*100);
	printf("The total simulation time is: %d\n", totalTime);

}

//Round Robin calculation
void roundRobin(int detailMode, int verboseMode, int value)
{
	int numProcess;
	int threadSwitch;
	int processSwitch;
	int processNum;
	int numThreads;
	int threadTime;
	int arrivalTime;
	int numberCPU;
	int cpuTime;
	int ioTime;
	int cpuNum;
	char data[255];
	int totalCPU[255];
	int totalIO[255];
	int tempFinalCPU;
	int tempFinalIO;
	int finalCPUTime;
	int finalIOTime;
	int totalTime;
	int k;
	int threadCounter;
	threadCounter = 0;
	int serviceT;
	serviceT = 0;
	int tempFinal;
	tempFinal = 0;
	int taTime; 
	taTime = 0;
	//int tempTotalReq;
	//tempTotalReq = 0;
	int usedTime = 0;
	double cpuPercent, totalAverageTurnA;
	cpuPercent = totalAverageTurnA = 0.0;
	int avgTime; 
	avgTime = 0;
	int fTime = 0;
	int quanCPU[255];
	int quanIO[255];

	k = tempFinalIO = tempFinalCPU = totalTime = finalCPUTime = finalIOTime = cpuNum = numProcess = threadSwitch = processSwitch = processNum = numThreads = threadTime = arrivalTime = 
	numberCPU = cpuTime = ioTime = 0;

	fgets (data,255,stdin);
	numProcess = atoi(zstring_strtok(data, " "));
	threadSwitch = atoi (zstring_strtok(NULL, " "));
	processSwitch = atoi(zstring_strtok(NULL,"\n"));
	usedTime = numProcess * processSwitch;
	//printf("number of process's = %d thread switch = %d, process switch = %d\n", numProcess, threadSwitch, processSwitch);

	for (int i = 0; i < numProcess; i++)
	{
		fgets (data,255,stdin);
		processNum = atoi(zstring_strtok(data, " "));
		numThreads = atoi (zstring_strtok(NULL, " "));
		threadCounter += numThreads;
		usedTime = usedTime + (threadSwitch * numThreads);
		//printf("process Number = %d number of threads = %d\n", processNum, numThreads);

		for(int j = 0; j < numThreads; j++)
		{
			fgets (data,255,stdin);
			threadTime = atoi(zstring_strtok(data, " "));
			arrivalTime = atoi (zstring_strtok(NULL, " "));
			numberCPU = atoi (zstring_strtok(NULL, " "));
			//printf("thread Time = %d arrival Time = %d, number of CPU = %d\n", threadTime, arrivalTime, numberCPU);
	
			for(k = 0; k < (numberCPU - 1); k++)
			{
				fgets (data,255,stdin);
				cpuNum = atoi(zstring_strtok(data, " "));
				cpuTime = atoi (zstring_strtok(NULL, " "));
				ioTime = atoi (zstring_strtok(NULL, " "));
				// totalCPU[k] = cpuTime;
				// totalIO[k] = ioTime;
				// printf("CPU Number = %d cpu Time = %d, i/o Time = %d\n", cpuNum, cpuTime, ioTime);

				for(int l = 0; l < (numberCPU - 1); l++)
				{
					quanIO[l] = ioTime;
			        quanCPU[l] = cpuTime;

			        if(quanIO[l] - (value) >= 0)
			        {
			          quanIO[l] = quanIO[l] - value;
			          quanCPU[l] = quanCPU[l] - value;
			        }

			        totalIO[k] = quanIO[l];
			        totalCPU[k] = quanCPU[l];  

				}



			}

			fgets (data,255,stdin);
			cpuNum = atoi(zstring_strtok(data, " "));
			cpuTime = atoi (zstring_strtok(NULL, " "));
			totalCPU[k] = cpuTime;
			//printf("CPU Number = %d cpu Time = %d\n", cpuNum, cpuTime);

			tempFinalCPU = 0;
			for(k = 0; k < numberCPU; k++)
			{
				finalCPUTime = totalCPU[k] + finalCPUTime; 
				tempFinalCPU += totalCPU[k];
			}

			tempFinalIO = 0;
			for(k = 0; k < numberCPU - 1; k++)
			{
				finalIOTime = totalIO[k] + finalIOTime; 
				tempFinalIO += totalIO[k];
			}

			if (threadTime == 1)
			{
				totalTime = totalTime + processSwitch;
				fTime = fTime + processSwitch;
			}

			tempFinal = tempFinalIO + tempFinalCPU;
    		taTime = taTime + tempFinal + threadSwitch;
			serviceT = tempFinal - tempFinalIO;
			avgTime = avgTime + (taTime - arrivalTime);
			fTime += finalIOTime + finalCPUTime + threadSwitch;
			fTime = fTime - arrivalTime;

			if(detailMode == 1)
			{
				//printf("-------------------------------Detail Mode-------------------------------\n");
				printf("\nThe thread is: %d The process is: %d\n",threadTime,processNum);  
			    printf("The arrival time is: %d\n",arrivalTime); 
			    printf("The service time is: %d\n",serviceT); 
			    printf("I/O time: %d\n",tempFinalIO); 
			    printf("Turnaround time: %d units \n",(taTime-arrivalTime));
			    printf("Finish time: %d units \n",taTime);
			}

			if (verboseMode == 1)
			{ 
				//printf("-------------------------------Verbose Mode-------------------------------\n");
				printf ("\nAt arrival time: %d Thread: %d Process: %d transitions from %s to %s\n",0,threadTime,processNum,"new", "ready");
				printf ("At arrival time: %d Thread: %d Process: %d transitions from %s to %s\n",arrivalTime,threadTime,processNum, "ready", "running");
				printf ("At arrival time: %d Thread: %d Process: %d transitions from %s to %s\n",(fTime - threadSwitch), threadTime, processNum, "running", "terminate");
				printf("\n");
			}

		}

		totalTime = totalTime + (threadSwitch * numThreads);

	}

	totalTime = totalTime + (processSwitch * numProcess);
	totalTime = totalTime + finalIOTime + finalCPUTime;
	cpuPercent = totalTime - usedTime; 
	cpuPercent /= (totalTime); 
	//cpuPercent /= totalTime;
	totalAverageTurnA = avgTime / threadCounter;

	printf ("\nThe average turnaround time is: %0.2f\n",totalAverageTurnA);
	printf ("The CPU utilization is: %0.2f\n", cpuPercent*100);
	printf("The total simulation time is: %d\n", totalTime);

}















