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

#include <stdio.h>
#define MAX 10

int search_number(int, int[], int);
void swap (int *current, int *min);

int main() {

//Part A
  int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10}; //test array
  int userInput; //number to be searched in test array

  printf("{1, 2, 34, 5, 67, 3, 23, 12, 13, 10}\n");
  printf("Select a number to be searched in the array:\n");

  scanf("%d", &userInput); //get number to be searched in the array

  //get result from search_number and prints it
  printf("\nthe index of the number is: %d\n\n\n", search_number(userInput, test, 10));

//Part B

  /*Logic: 
  1) loop through array
  2) for each element, start a new for loop
  3) iterate through whole array. Find and save minimum value in minIndex
  4) Swap current element and the element at minIndex (minimum value) */
  
  int minIndex; //current index of minimum value found
  for (int i = 0; i < MAX; i++){
  minIndex = i; //set minIndex to current element at every new iteration.
    
    for (int j = i + 1; j < MAX; j++) {
      if (test[minIndex] > test[j]) { //compares current minIndex element with every other element.
        minIndex = j; //assign new minimum in case a smaller number is found.
      }
    }
    if (i == minIndex) {
      //Do nothing. Current element is already the smallest.
    } else {
      swap(&test[i], &test[minIndex]); //passing addresses to be used by pointers
    }
  }

  printf("The sorted array is:\n");
  for (int i = 0; i < MAX; i++) {
    printf ("%d ", test[i]); //print elements of array.
  }
  
  printf("\n\n");
  return 0;
}

void swap (int *current, int *min) {
  int temp; //variable to assist in the swap
  temp = *current; //assign value of pointer to temp;
  *current = *min; //change VALUE at current to value of *min
  *min = temp; //change VALUE of *min to value of temp
}

int search_number( int number, int tab[], int size) {
  for (int i = 0; i < size; i++) {
    //if number you're looking for is found, return 1. Else, returns -1.
    if (tab[i] == number) 
    {
      return i;
    }
  }
  return -1;
}
