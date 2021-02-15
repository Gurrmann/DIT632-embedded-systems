/*====================================
File name: exerc_3_1.c
Date: 2020-02-16
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

all group members were present at the demo.
Demonstration code: 
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
typedef struct q{
int number;
struct q *next;
struct q *prev;
} REGTYPE;
// ##### Funcion declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{
  srand(time(0)); // Random seed
  
  int nr = 0;
  REGTYPE *akt_post, *head=NULL;
  
  head = random_list();
  akt_post=head;
  
  while(akt_post != NULL){
    printf("\n Post nr %d : %d" , nr++, akt_post->number);
    akt_post = akt_post->next;
  }
// .........
// .........

// --- Free of allocated memory ---
  while((akt_post=head) != NULL){
    head = akt_post->next;
    free(akt_post);
  }
//------------------
  return 0;
} // ==== End of main ======================================


REGTYPE* random_list(void){
  int nr, i = 0;
  REGTYPE *top, *old, *item;
  // ..........
  return(top);
}

//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
  // Adds a record first i list and set the field tal to data
}