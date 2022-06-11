/****************************************************************
 * An ADT list can be implemented/represented in memory using:  *
 *    a) array Implementation        --> Exer 06                *
 *    b) linked list Implementation  --> Exer 07                *
 *    c) Cursor-based Implementation --> CIS 2101               *
 *                                                              *   
 * This program will implement ADT list represented in memory   *
 * using a linked list implementation.                          *
 *                                                              *
 * There are 5 problems and each problem requires creation of   *
 * function definition, and a series of function calls.         *
 *                                                              *   
 * Problem 1: Populates the list with student records from the  *
 *            given file  and displays the contents of the list.*
 *     5 Functions to be implemented:                           *
 *     initList(), insertFirst(), populateListFromFile(),       *
 *     displayStud(), displayList()                             *
 *                                                              * 
 * Problem 2: Sorts collection of records using selection sort  *
 *            technique() via function selectionSort().         *
 *                                                              *
 * Problem 3: Implements function insertLast() using different  *
 *            lists (with elements and initially empty).        *
 *                                                              *
 * Problem 4: Illustrates deletion operation via deleteID().    *
 *                                                              *
 * Problem 5: Illustrates insertion operations in an UNSORTED   *
 *            and SORTED Collections via functions insertPos()  *
 *            insertSorted() respectively.                      *    
 ****************************************************************/

#include <stdio.h>
#include "CESAHA-LinkList-v3.h" 


/***************************************************************
 * The main() function will call the functions listed in the   *
 * function prototypes in the header file Exer07-LinkList.h    *
 ***************************************************************/
int main()
{
   linkList L, B;
   char filename[20];
 
   
   /*** 1) Problem 1: 
	        Populate the linklist L by calling populateListFromFile(), 
	        then call displayList(). Name of the file is inputted
			  from the keyboard and passed to the function    ***/
  	printf("\n\nProblem 1:: ");
  	
  	printf("\nEnter filename: ");
  	scanf(" %[^\n]s", filename);
  	
	initList(&L);
	L = populateListFromFile(filename);
	displayList(L);
	

   /*** 2) Problem 2: Call selectionSort(), then displayList() ***/
  	printf("\n\nProblem 2:: ");
 	selectionSort(L);
	displayList(L);
   
   /*** 3) Problem 3: 
	        A) Call insertLast() passing linkList L of problem 1
			     and S01, then call displayList().  
			  B) i) Declare and Initialize a linkList variable B.
			    ii) Call insertLast 3 times passing S01, S02, and S03.
				iii) Call displayList()              		  ***/
  
   	studtype S01 = {{"Ana Marie", "Zozobrano", 'Z'}, 18201111, "BSIT", 2 };
   	studtype S02 = {{"Ben Joseph", "Abrea", 'D'}, 19202222, "BSCS", 1 };
   	studtype S03 = {{"Carla", "Medina", 'A'}, 19103333, "BSIS", 1 };
 	printf("\n\nProblem 3A:: ");
 	
 	insertLast(&L, S01);
 	displayList(L);
 
	printf("\n\nProblem 3B:: ");
	initList(&B);
	insertLast(&B, S01);
	insertLast(&B, S02);
	insertLast(&B, S03);
	displayList(B);


	/*** 4) Problem 4: Use linked list L in Problem 1
	 		  a) Call deleteID() 4 times passing the following ID:
	 		      19101111, 17208888, 17101111 and 18201111
			  b) call displayList()  */ 
	printf("\n\nProblem 4:: ");
	
	deleteID(&L, 19101111);
	deleteID(&L, 17208888);
	deleteID(&L, 17101111);
	deleteID(&L, 18201111);
	displayList(L);
	
	
   /*** 5) Problem 5: 
	        A) Using linked list B in problem 3B (with 3 elements)
			     i) Call insertPos() 4x passing:
				         stud01 @ position 1
							stud02 @ position 6
							stud03 @ position 5
							stud04 @ position 3
               ii) call displayList().  
			  B) Using the sorted list L in problem in problem 2  
			      i) Call insertSorted() 2 times passing stud01 and stud02.
				  ii) Call displayList()              		  ***/
	studtype stud01 = {{"Marian Cole", "Go", 'A'}, 19101111, "BSIT", 1 };
	studtype stud02 = {{"Zenia", "Zuniga", 'Z'}, 19106666, "BSCS", 1 };
	studtype stud03 = {{"Ana Grace", "Lim", 'Z'}, 19106666, "BSIS", 1 };
	studtype stud04 = {{"Alvin", "Uy", 'Z'}, 19105555, "BSMath", 1 };

	printf("\n\nProblem 5A:: ");
	
	insertPos(&B, stud01, 1);
	insertPos(&B, stud02, 6);
	insertPos(&B, stud03, 5);
	insertPos(&B, stud04, 3);
	displayList(B);
 
	printf("\n\nProblem 5B:: ");
 	insertSorted(&L, stud01);
 	insertSorted(&L, stud02);
 	displayList(L);
 
 
  return 0;
}
