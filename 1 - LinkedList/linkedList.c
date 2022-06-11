#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
	int jersNum;
	char name[50];
}playerType;

typedef struct node {
	playerType player;
	struct node * link;
}*List, cellType;

typedef enum {
	TRUE, FALSE
}boolean;

void populateList (List *L, playerType player[]);

void displayList (List L);
void displayListOnly (List L, int jersNum);
void displayListReverse (List L);
void header();

void insertFirst (List *L, playerType player);
void insertLast (List *L, playerType player);
void insertPos (List *L, playerType player, int pos);
void insertSorted (List *L, playerType player, int mode);

void deletePlayer (List *L, int jersNum);
void deleteFirst (List *L);
void deletePos (List *L, int pos);
void deleteLast (List *L);
void makeEmpty (List *L);

int find (List L, int jersNum);
boolean check (List L, int jersNum);

void bubbleSort (List *L, int mode);
void selectionSort (List *L, int mode);
void insertionSort (List *L, int mode);

void reverseList (List *L);

int countList (List L);

List createEvenList (List A);

void main () 
{
	List L = NULL;
	playerType player[SIZE] = 	{
									{30, "Stephen Curry"}, 
									{07, "Kevin Durant"},
									{23, "Lebron James"},  
									{24, "Kobe Bryant"},
									{11, "Klay Thompson"} 
								};
	playerType player01 = {13, "Paul George"};
	playerType player02 = {3, "Dwayne Wayde"};						
	populateList (&L, player);
	

/***********Sorting Functions***********/
//	bubbleSort (&L, 1);
//	selectionSort (&L, 2);
	insertionSort (&L, 1);
	
	
/***********Insert Functions***********/
//	insertFirst (&L, player01);
//	insertLast (&L, player01);
//	insertPos (&L, player01,6);
//	insertSorted (&L, player02, 1);


/***********Delete Functions***********/
//	deletePlayer(&L, 30);
//	deleteFirst (&L);
//	deleteLast (&L);
//	deletePos (&L, 2);
//	makeEmpty (&L);


/*********Return List Function********/
	List evenList = createEvenList (L);
//	int count = countList(L);
	// printf("%d", count);


/*********Reverse List Function********/
//	reverseList (&L);


/**********Display Functions**********/
	// displayList (L);
	displayList (evenList);
//	displayListOnly (L, 23);
	// displayListReverse (L);


/**********Find Function**********/
//	int pos = find (L, 7);
//	printf("\n\n\tPosition: %d", pos);	


/***********Boolean Function***********/
//	boolean b = check (L, 30);
//	if (b == TRUE)
//		printf("\n\tPlayer does exist.");
//	else 
//		printf("\n\tPlayer does not exist.");

}

void populateList (List *L, playerType player[]) {
	int i;
	
	for (i = 0; i < SIZE; i++) {
		insertLast (L, player[i]);
	}
}

void insertFirst (List *L, playerType player) {
	List temp;
	
	temp = (List)malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->player = player;
		temp->link = *L;
		*L = temp;
	}
	
}

void insertLast (List *L, playerType player) {
	List *trav, temp;
	
	for (trav = L; *trav != NULL; trav = &(*trav)->link) {}
	temp = (struct node*)malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->player = player;
		temp->link = *trav;
		*trav = temp;
	}

}

void insertPos (List *L, playerType player, int pos) {
	int i;
	List *trav, temp;
	
	for (trav = L, i = 1; *trav != NULL && i < pos; trav = &(*trav)->link, i++) {}
	
	if (pos == i) {
		temp = (List)malloc(sizeof(cellType));
		temp->player = player;
		temp->link = *trav;
		*trav = temp; 
	}
	else {
		printf("Error: Invalid Postion\n\n");
	}
}

void insertSorted (List *L, playerType player, int mode) {
	List *trav, temp;
	
	if (mode == 1) {
		for (trav = L; *trav != NULL && (*trav)->player.jersNum < player.jersNum; trav = &(*trav)->link) {}
	}
	else if (mode == 2 ) {
		for (trav = L; *trav != NULL && (*trav)->player.jersNum > player.jersNum; trav = &(*trav)->link) {}	
	}
	
	temp = (List)malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->player = player;
		temp->link = *trav;
		*trav = temp;
	}	

}

void deletePlayer (List *L, int jersNum) {
	List *trav, temp;
	
	for (trav = L; *trav != NULL && (*trav)->player.jersNum != jersNum; trav = &(*trav)->link) {}
	if (*trav != NULL) {
		temp = *trav;
		*trav = temp->link;
		free(temp);
	}
}

void deleteFirst (List *L) {
	if (*L == NULL)
		return;
		
	List temp = *L;
	*L = temp->link;
	free(temp);
}

void deleteLast (List *L) {
	if (*L == NULL)
		return;
		
	List *trav, temp;
	
	for (trav = L; (*trav)->link != NULL; trav = &(*trav)->link){}

	temp = *trav;
	*trav = NULL;
	free(temp); 

}

void deletePos (List *L, int pos) {
	List *trav, temp;
	int i;
	
	for (trav = L, i = 1; *trav != NULL && i < pos; trav = &(*trav)->link, i++) {}
	if (*trav != NULL) {
		temp = *trav;
		*trav = temp->link;
		free(temp);
	} else {
		printf("Error: Invalid Position\n\n");
	}
}

void makeEmpty (List *L) {
	List *current, next;
	
	for (current = L; *current != NULL; *current = next) {
		next = (*current)->link;
		free(*current);
	}
	*current = NULL;
}

int find (List L, int jersNum) {
	List trav;
	int i, ret;
	
	for (trav = L, i = 1; trav != NULL && trav->player.jersNum != jersNum; trav = trav->link, i++){}
	return ret = (trav != NULL) ? i:-1;
} 

boolean check (List L, int jersNum) {
	List trav;
	
	for (trav = L; trav != NULL && trav->player.jersNum != jersNum; trav = trav->link) {}
	return (trav != NULL) ? TRUE:FALSE;
}

void displayListOnly (List L, int jersNum) {
	List trav;
	
	header();
	for (trav = L; trav != NULL; trav = trav->link) {
		if (jersNum == trav->player.jersNum) {
			printf("\t%-10d", 1);
			printf("\t%-20d", trav->player.jersNum);
			printf("%-20s\n", trav->player.name);
		}
	}
}

void displayList (List L) {
	List trav;
	int i;
	header();
	for (trav = L, i = 0; trav != NULL; trav = trav->link, i++) {
		printf("\t%-10d", i+1);
		printf("\t%-20d", trav->player.jersNum);
		printf("%-20s\n", trav->player.name);
	}
}

void header() {
	printf("\t%-10s", "Player no.");
	printf("\t%-20s", "Jersey Number");
	printf("%-20s\n\n", "Player Name");
}

List createEvenList (List L) {
	List trav;
	List evenList = NULL, temp, *move;
	
	for (trav = L; trav != NULL; trav = trav->link) {
		if (trav->player.jersNum % 2 == 0) {
			// insertLast (&evenList, trav->player);
			for (move = &evenList; *move != NULL; move = &(*move)->link) {}
			temp = (List)malloc(sizeof(struct node));
			if (temp != NULL) {
				temp->player = trav->player;
				temp->link = *move;
				*move = temp;
			}
		}
	}
	
	return evenList;
}

void bubbleSort (List *L, int mode) {
	List *trav;
	playerType temp;
	int i, j, size;
	
	size = countList(*L);
	
	if (mode == 1) {
		for (i = 0; i < size - 1; i++) {
			for (j = 0, trav = L; j < size - i - 1; j++, trav = &(*trav)->link) {
				if ((*trav)->player.jersNum  > (*trav)->link->player.jersNum) {
					temp = (*trav)->player;
					(*trav)->player = (*trav)->link->player;
					(*trav)->link->player = temp;
				}
			}
		}
	}
	else if (mode == 2) {
		for (i = 0; i < size - 1; i++) {
			for (j = 0, trav = L; j < size - i - 1; j++, trav = &(*trav)->link) {
				if ((*trav)->player.jersNum < (*trav)->link->player.jersNum) {
					temp = (*trav)->player;
					(*trav)->player = (*trav)->link->player;
					(*trav)->link->player = temp;
				}
			}
		}
	}		
}

void selectionSort (List *L, int mode) {
	List *trav, *min_Idx, *max_Idx, *idx;
	playerType temp;
	int i, j, size;
	
	size = countList (*L);

	if (mode == 1) {
		for (i = 0, trav = L; i < size - 1; i++, trav = &(*trav)->link) {
			min_Idx = trav;
			for (j = i + 1, idx = &(*trav)->link; j < size; j++, idx = &(*trav)->link) {
				if ((*min_Idx)->player.jersNum > (*idx)->player.jersNum) {
					min_Idx = idx;
				}
			}
			temp = (*min_Idx)->player;
			(*min_Idx)->player = (*trav)->player;
			(*trav)->player = temp;
		}
	} 
	else if (mode == 2) {
		for (i = 0, trav = L; i < size - 1; i++, trav = &(*trav)->link) {
			max_Idx = trav;
			for (j = i + 1, idx = &(*trav)->link; j < size; j++, idx = &(*trav)->link) {
				if ((*max_Idx)->player.jersNum < (*idx)->player.jersNum) {
					max_Idx = idx;
				}
			}
			temp = (*max_Idx)->player;
			(*max_Idx)->player = (*trav)->player;
			(*trav)->player = temp;
		}
	}
	
}

void insertionSort (List *L, int mode) {
	List *trav, sorted = NULL;
	
	for (trav = L; *trav != NULL; trav = &(*trav)->link) {
		insertSorted(&sorted, (*trav)->player, mode);
	}
	*L = sorted;
	
}


void reverseList (List *L) {
	List *current, next = NULL, prev = NULL;
	
	for (current = L; *current != NULL; *current = next) {
		next = (*current)->link;
		(*current)->link = prev;
		prev = *current;
	}
	*L = prev;
}

int countList (List L) {
	List trav;
	int ctr;
	
	for (trav = L, ctr = 0; trav != NULL; trav = trav->link, ctr++) {}
	return ctr;
}

void displayListReverse (List L) {
	List end = NULL, trav;
	int i = 0;
	
	header();
	for (trav = L; L != end ; end = trav, trav = L) {
		for ( ;trav->link != end; trav = trav->link) {}
		printf("\t%-10d", i++);
		printf("\t%-20d", trav->player.jersNum);
		printf("%-20s\n", trav->player.name);
	}
}



