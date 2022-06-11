#include <stdio.h>
#define SIZE 5

typedef struct
{
	char FName[24];
	char LName[16];
	char Mi;
} nametype;

typedef struct
{
	unsigned int ID;
	nametype name;
	char currProg[8];
	int yrLvl;
} studtype;

typedef struct node
{
	studtype data;
	struct node *link;
} * studList;

void writeToFileNtimes(FILE *file, studtype list[]);
void writeToFileOnce(FILE *file, studtype list[]);

void main()
{
	FILE *file;
	char filename[20];
	printf("Enter File Name: ");
	gets(filename);

	file = fopen(filename, "wb");
	if (!file)
		printf("Error: Failed to create a file.");
	else
	{
		printf("File created successfully.");

		studtype list[] = {
			{20102314, {"Angel", "Abosayap", 'A'}, "BSIT", 1},
			{20101234, {"Bob", "Manalili", 'B'}, "BSIS", 2},
			{20103142, {"Carl", "Aquas", 'C'}, "BSICT", 3},
			{20104321, {"Derrick", "Rosario", 'D'}, "BSCS", 4},
			{20101324, {"Eve", "Aries", 'E'}, "BSIT", 1},
		};
		int size = sizeof(list) / sizeof(studtype);

		//    writeToFileNtimes (file, list);
		writeToFileOnce(file, list);

		fclose(file);
	}
}

void writeToFileNtimes(FILE *file, studtype list[])
{
	int i;

	for (i = 0; i < SIZE; i++)
	{
		fwrite(&list[i], sizeof(studtype), 1, file);
	}
}

void writeToFileOnce(FILE *file, studtype list[])
{
	fwrite(list, sizeof(studtype), SIZE, file);
}
