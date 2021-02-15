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

int main() {

// a) Write a function that given an integer n, an array of integers and the size of the array determines
// if n is in the array. If so the function should return the index for the first position of the number (in
// case of several) otherwise returns -1.
// For testing the function, write a main program that tests the function with help of an array initiated
// in the main program as below and with a function declaration:


  int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
  printf("{1, 2, 34, 5, 67, 3, 23, 12, 13, 10}\n");
  printf("Select a number to be searched in the array:\n");
  int userInput;
  scanf("%d", &userInput);
  printf("\nthe index of the number is: %d\n\n\n", search_number(userInput, test, 10));

// b) There are a lot of ways to sort an array. For example, bubble sort which not is the fastest, but it is
// easy to understand and implement. Write a sorting routine that use the following algorithm to sort
// an array of integers.
// • Find the minimum value in the list.
// • Swap the minimum with the first in list.
// • Repeat this but exclude the previous minimum on top of the list and search only in the rest of the
// list.

//loop through the list.
//for each element, start a new loop
//find index of min
//replace it with the first.
  int minIndex;
  int temp;
  for (int i = 0; i < MAX; i++){
  minIndex = i;
    for (int j = i + 1; j < MAX; j++) {
      if (test[minIndex] > test[j]) {
        minIndex = j;
      }
    }
    //swap
    if (i == minIndex) {
      //do nothing. element already in the right place.
    } else {
       temp = test[i];
       test[i] = test[minIndex];
       test[minIndex] = temp; 
    }
  }

  printf("The sorted array is:\n");
  for (int i = 0; i < MAX; i++) {
    printf ("%d ", test[i]);
  }

  printf("\n\n");


  return 0;
}

int search_number( int number, int tab[], int size) {
  for (int i = 0; i < size; i++) {
    if (tab[i] == number)
    {
      return i;
    }
  }
  return -1;
}
