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

typedef struct node{
    studtype data;
    struct node *link;
}*studList;

studList readFile (FILE *file, studList *L);
void insertLast (studList *L, studtype data);

void displayList (studList L);
void displayStudent(studtype list);
void changeProg (FILE *file);
void displayHeader();


void main () {
	FILE *file;
	studList L = NULL;
	char filename[50];
	printf("Input the File Name to open: ");
	gets(filename);
	
	file = fopen(filename, "rb+");
	if (!file)
		printf("Error: Failed to open the file.");
	else {
		changeProg(file);
		readFile (file, &L);
		displayList (L);
		
		fclose(file);
	}
}

void changeProg (FILE *file) {
	studtype temp;
	
	while (fread(&temp, sizeof(studtype), 1, file) != 0) {
		if (strcmp(temp.currProg, "BSIS") == 0) {
			strcpy(temp.currProg, "Grad");
			fseek(file, (unsigned) - sizeof(studtype), SEEK_CUR);
			fwrite(&temp, sizeof(studtype), 1, file);
			fseek(file, 0, SEEK_CUR);
		}	
	}

}

studList readFile (FILE *file, studList *L) {
	studtype temp;
	
	while (fread(&temp, sizeof(studtype), 1, file) != 0) {
		insertLast (L, temp);	
	}

}

void insertLast (studList *L, studtype data) {
	studList *trav, temp;
	
	
	for (trav = L; *trav != NULL; trav = &(*trav)->link) {}
	temp = (studList)malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->data = data;
		temp->link = NULL;
		*trav = temp;
	}
}

void displayList (studList L) {
	studList trav;
	displayHeader();
	for (trav = L; trav != NULL; trav = trav->link) {
		displayStudent(trav->data);
	}
}

void displayHeader() {
    printf("%-10s", "ID#");
	printf("%-16s", "First Name");
	printf("%-20s", "Last Name");
	printf("%-6s", "Mi");
	printf("%-8s", "Prog");
	printf("%-5s", "yrLvl");
	printf("\n");
}

void displayStudent(studtype list){
	printf("%-10d", list.ID);
	printf("%-16s", list.name.FName);
	printf("%-20s", list.name.LName);
	printf("%-6c", list.name.Mi);
	printf("%-8s", list.currProg);
	printf("%-5d", list.yrLvl);
	printf("\n");
}

