#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

typedef struct {
    char FName[24];
    char LName[16];
    char Mi;
}nametype;

typedef struct {
    unsigned int ID;
    nametype name;
    char currProg[8];
    int yrLvl;
}studtype;

 	studtype list[] =	{   
                    {20102314, {"Angel", "Abosayap", 'A'}, "BSIT", 1},
                    {20101234, {"Bob", "Manalili", 'B'}, "BSIS", 2},
                    {20103142, {"Carl", "Aquas", 'C'},"BSICT", 3},
                    {20104321, {"Derrick", "Rosario", 'D'}, "BSCS", 4},
                    {20101324, {"Eve", "Aries", 'E'}, "BSIT", 1},
                }; 

void writeToFileOnce (FILE * file);
void writeToFileNthTimes (FILE * file);

void main () {
	FILE * file;
	char filename[50];
	printf("Enter file name: ");
	gets(filename);
	
	file = fopen(filename,"wb");
	if (!file) {
		printf("Error: Cannot create the file");
	}
	else {
//		writeToFileOnce (file);
		writeToFileNthTimes(file);
		
		fclose(file);
	}
	
	
}

void writeToFileOnce (FILE * file) {
	fwrite(list, sizeof(studtype), SIZE, file);
}

void writeToFileNthTimes (FILE * file) {
	int i;
	
	for (i = 0; i < SIZE; i++) {
		fwrite(&list[i], sizeof(studtype), 1, file);
	}
}

