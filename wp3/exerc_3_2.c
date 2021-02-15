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
#define MAX 20

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
