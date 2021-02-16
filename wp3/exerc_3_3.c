/*====================================
File name: exerc_3_3.c
Date: 2020-02-16
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

Group members present at the demo:
Aleksandar Isakovski
Thiago Oliva

->Since the demo was done on a spontaneous manner without being schedule beforehand, 
Gustav Skallberg could not join in time to participate on this Demo.

Demonstration code: 2782
======================================*/

/********************************************
DIT1165 Program file exerc_3_3.c
**
2018-01-04
**
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Konstanter ####
#define MAX 5

//#### Typedefs ####
typedef struct node{ //change to q later
int number;
struct node *next;
struct node *prev;
} REGTYPE; //don't need to write struct q every initialization, just REGTYPE

//##### Funcion declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{
  srand(time(0)); // Random seed
  
  int nr = 0;
  
  REGTYPE *akt_post, *head=NULL; //akt_post is current node;
  
  head = random_list();
  akt_post=head;
  
  while(akt_post != NULL){
    printf("\n Post nr %d : %d" , nr++, akt_post->number);
    akt_post = akt_post->next;
  }

// // --- Free of allocated memory ---
//   while((akt_post=head) != NULL){
//     head = akt_post->next;
    // free(akt_post);
    // akt_post = NULL;
//   }
//------------------
  return 0;
} // ==== End of main ======================================


REGTYPE* random_list(void){

  int nr, i = 0;
  REGTYPE *head, *prevPtr, *current, firstNode;

  int lower = 0; //lower limit of the random int generation.
  int upper = 100; //upper limit of the random int generation.

  head = &firstNode; //ptr to keep track of the top of the nodeList.
  
  //set first node
  current = &firstNode;
  current->prev = NULL; //head does not have a prev.
  current->number = (rand() % (upper - lower + 1)) + lower;
  current->next = NULL; //empty for now

  printf("\nNode 0:");
  printf("\nCurrent is: %d", current->number);
  printf("\nPrev is: %d", current->prev);
  printf("\nNext is: %d\n", current->prev);

  prevPtr = current; //saves current number to be assigned as prev in the next node

  for (int i = 1; i <= MAX; i++) {

    REGTYPE *newNode = (REGTYPE*)malloc(MAX*sizeof(REGTYPE)); //trying to dynamically allocate memory here.
    if (!newNode) { //if it is null, fault at memory allocation.
      printf("\nSomething terrible has happened.\n");
      printf("The program could not allocate memory.");
      break;
    }

    current = newNode;
    current->number = (rand() % (upper - lower + 1)) + lower;
    current->prev = prevPtr;
    current->prev->next = current; //Set the previous node's next to the current node.
    current->next = NULL; //empty for now.

    printf("\nNode %d Current is: %d", i, current->number);
    printf("\nNode %d Prev is: %d", i, current->prev->number);

    prevPtr = current; //saves current number to be assigned as prev in the next node
  }

  return(head);
}

//==========================================================
// REGTYPE* add_first(REGTYPE* temp, int data){
//   // Adds a record first i list and set the field tal to data
// }





