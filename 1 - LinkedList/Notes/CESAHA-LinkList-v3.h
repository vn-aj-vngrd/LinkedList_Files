#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***** Data Structure Definition *****/
typedef struct {
	char fname[24];     /* firstname */
	char lname[16];     /* lastname  */ 
	char mi;            /* middle initial */ 
}nametype;

typedef struct {
	nametype name;
	unsigned int ID;
	char course[8];
	int yrLevel;
}studtype;

/** Definition of the List represented 
    in Memory using a linked list   **/

typedef struct node {
	studtype stud;
	struct node *link;
}nodetype, *linkList;


/***** Function Prototypes *****/

void initList(linkList *L);  
/* Initializes the given list to be empty, i.e. pointer is NULL */
    
void insertFirst(linkList *L, studtype S);  
/* Makes given data elem (student record) the first element of
   the given list,if there is still available space in the list */ 

linkList populateListFromFile(char filename[]);  
/* Reads the file, 1 student record at a time and calls insertFirst() 
   to put each record read from the file into the newly created list. 
	Locally created list will be returned to the calling function. */

void displayHeader();            /*  Given: Displays a header of student information */
void displayStud(studtype S);     /* Displays student info in ONE horizontal line using:
                                      %-Nd  for integer, ex: %-10d - allocates 10 columns
												  %-Ns  for string,  ex: %-15s - allocates 15 columns
												  %-Nc  for char,    ex: %-3c  - allocates 3 columns   */

void displayList(linkList L);
/* Calls displayHeader() and displayStud() in displaying all the
   data elements in the given list. In addition, it will display
	the total records in the given list. */

void selectionSort(linkList L);  
/* Sorts a given List according to last names. Note that only 
   the studtype field will be modified  */


/*********************************************************
 * The following functions are implemented using         *
 * "a pointer to pointer to a node" technique. This      *
 * technique makes code is shorter.                      *
 *********************************************************/ 
void insertLast(linkList *L, studtype S); 
/* Inserts a data item (student record) at the last position in the 
   given list. If the list is empty, the new element is the first 
	and last element of the list */

void deleteID(linkList *L, int ID);
/* Deletes data item uniquely identified by ID from the given list.
   Display appropriate error messages or deletion success message */

void insertPos(linkList *L, studtype S, int pos);
/* Inserts data item S at position pos in the list A
   and if position is valid. First position is 1.
	Valid Positions:
	    a) Empty list ==>  position 1
	    b) List is 3 elements ==> positions 1, 2, 3, and 4
	Display appropriate error messages or insertion success message */ 

void insertSorted(linkList *A, studtype S);
/* Inserts a given data item S in its proper position in the SORTED list */



/***************************************************************
 * Definitions of functions listed in the function prototypes  *
 ***************************************************************/
/*************************************************
 * Problem 1  Function Definition                *
 *************************************************/
void initList(linkList *L)
{
	*L = NULL;
}

linkList populateListFromFile(char filename[])
{
	linkList myList = NULL;
	FILE *file = fopen(filename, "rb");
	
	if(file != NULL) {
		studtype myStudent;
		while(fread(&myStudent, sizeof(myStudent), 1, file)) {
			insertFirst(&myList, myStudent);
		}
	}else {
		printf("\nCannot Open File! :(\n");
	}
	
	return myList;
}

void insertFirst(linkList *L, studtype S)
{
	linkList temp;
	
	temp = (linkList)malloc(sizeof(nodetype));
	if(temp != NULL) {
		temp->link = *L;
		temp->stud = S;
		*L = temp;
	}
}

void displayHeader()
{
	printf("\n\n%-10s", "ID");
	printf("%16s", "Last Name");
	printf("%20s", "First Name");
	printf("%5s", "Mi");
	printf("%8s", "Course");
	printf("%10s", "YrLvl");
}

void displayList(linkList L)
{
	displayHeader();
	int i;
	
	for(i = 0; L != NULL ; L = L->link, i++) {
		displayStud(L->stud);
	}
	printf("\n\nTotal students: %d\n", i);
}

void displayStud(studtype S)
{
	printf("\n%-10d", S.ID);
	printf("%16s", S.name.lname);
	printf("%20s", S.name.fname);
	printf("%5c", S.name.mi);
	printf("%8s", S.course);
	printf("%10d", S.yrLevel);
}

/*************************************************
 * Problem 2  Function Definition                *
 *************************************************/
void selectionSort(linkList L)
{
	linkList traverse, tempPointer;
	tempPointer = traverse = NULL;
	studtype tempData;
	char x;

	for(; L != NULL; L = L->link) {
		tempPointer = L;
		for(traverse = L->link; traverse != NULL; traverse = traverse->link) {
			if(strcmp(tempPointer->stud.name.lname, traverse->stud.name.lname) > 0) {
				tempPointer = traverse;
			}else if(!strcmp(tempPointer->stud.name.lname, traverse->stud.name.lname)) {
				if(strcmp(tempPointer->stud.name.fname, traverse->stud.name.fname) > 0) {
					tempPointer = traverse;
				}
			}
		}
		if(L != tempPointer) {
			tempData = tempPointer->stud;
			tempPointer->stud = L->stud;
			L->stud = tempData;
		}
	}
}

/*************************************************
 * Problem 3  Function Definition                *
 *************************************************/
void insertLast(linkList *L, studtype S)
{
	for(; *L != NULL; L = &(*L)->link) {}
	
	linkList temp;
	
	temp = (linkList)malloc(sizeof(nodetype));
	if(temp != NULL) {
		temp->stud = S;
		temp->link = NULL;
		*L = temp;
	}
}

/*************************************************
 * Problem 4  Function Definition                *
 *************************************************/
void deleteID(linkList *L, int ID)
{
	linkList temp = NULL;
	
	for(; *L != NULL && (*L)->stud.ID != ID; L = &(*L)->link) {}
	
	if(*L != NULL) {
		temp = *L;
		free(temp);
		*L = (*L)->link;
		printf("\nDeleted Successfully! :)");
	}else {
		printf("\nUnable to delete. :(");
	}
}


/*************************************************
 * Problem 5  Function Definition                *
 *************************************************/
void insertPos(linkList *L, studtype S, int pos)
{
	int i;
	
	for(i = 1; *L != NULL && i != pos; L = &(*L)->link, i++) {}
	
	if(i == pos) {
		linkList temp;		
		
		temp = (linkList)malloc(sizeof(nodetype));
		if(temp != NULL) {
			temp->stud = S;
			temp->link = *L;
			*L = temp;
			printf("\nInserted Successfully! :)");	
		}
	}else {
		printf("\nInvalid Position! :(");
	}
}

void insertSorted(linkList *A, studtype S)
{
	linkList temp, prev, current;
	current = prev = *A;
	
	for(; current != NULL && (strcmp(current->stud.name.lname, prev->stud.name.lname) >= 0)
	; prev = current, current = current->link) {}
	
	if(current == NULL) {	
		for(; *A != NULL && (strcmp((*A)->stud.name.lname, S.name.lname) <= 0); A = &(*A)->link) {}
		
		temp = (linkList)malloc(sizeof(nodetype));
		if(temp != NULL) {
			temp->stud = S;
			temp->link = *A;
			*A = temp;
		}
	}else {
		printf("\nNot Sorted");
	}
}
#endif
