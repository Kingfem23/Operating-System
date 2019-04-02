#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseFile(FILE * file);

//Parse file 
char *zstring_strtok(char *str, const char *delim);

//First come first serve algorithm implementation
void firstComeFirstServe(int detailMode, int verboseMode);

//Round robin implementation
void roundRobin(int detailMode, int verboseMode, int value);


