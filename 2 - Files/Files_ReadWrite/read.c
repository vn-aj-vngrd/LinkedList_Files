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

typedef struct node {
	studtype data;
	struct node * link;
}*List;

 	studtype list[] =	{   
                    {20102314, {"AAA", "AAAAA", 'A'}, "BSIT", 1},
                    {20101234, {"BBB", "BBBBB", 'B'}, "BSIS", 2},
                    {20103142, {"CCC", "CCCCC", 'C'},"BSICT", 3},
                    {20104321, {"DDD", "DDDDD", 'D'}, "BSCS", 4},
                    {20101324, {"EEE", "EEEEE", 'E'}, "BSIT", 1},
                }; 
                
void append(FILE *file);
void readFile(FILE *file, List *L);
void insertLast (List *	L, studtype data);
void displayList (List L);
void changeLastName (FILE *file);

void main () {
	FILE * file;
	List L = NULL;
	char filename[50];
	printf("Enter file name: ");
	gets(filename);
	
	file = fopen(filename, "rb+"); 
	if (!file) {
		printf("Error: Cannot create the file");
	}
	else {
//		append(file);
//		changeLastName (file);
		readFile(file, &L);
		displayList(L);
		
		
		fclose(file);
	}
		
}

void readFile(FILE *file, List *L) {
	studtype temp;
	
	while (fread(&temp, sizeof(studtype), 1, file) != 0) {
		insertLast(L, temp);
	}
}

void insertLast (List *	L, studtype data) {
	List *trav, temp;
	
	for (trav = L; *trav != NULL; trav = &(*trav)->link){}
	temp = (List)malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->data = data;
		temp->link = *trav;
		*trav = temp;
	}
}

void displayList (List L) {
	List trav;
	
	for (trav = L; trav != NULL; trav = trav->link) {
		printf("%s\n", trav->data.name.LName);
	}
}

void append(FILE *file) {
	fwrite(list, sizeof(studtype), SIZE, file);
}

void changeLastName (FILE *file) {
	studtype temp;
	
	while (fread(&temp, sizeof(studtype), 1, file) != 0) {
		if (strcmp(temp.name.LName, "Rosario") == 0) {
			strcpy(temp.name.LName, "Raven");
			fseek(file, (unsigned) - sizeof(studtype), SEEK_CUR); 
			fwrite(&temp, sizeof(studtype), 1, file);
			fseek(file, 0, SEEK_CUR);
		}
	}
}
