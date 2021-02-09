/*====================================
File name: exerc_2_2.c
Date: 2020-02-09
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

all group members were present at the demo.
Demonstration code: 363840
======================================*/

#include <stdlib.h> //Without this lib, Srand() and rand() result in annoying warning.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h> // so that we can assign NULL to pointer values
#include <time.h> //so that we can use srand

#define MAX 20 //max number of chars in input

int main() {

    int intArray[MAX]; //Max 20 elements
    int lower = 1; //lower limit of the random int generation.
    int upper = 99; //upper limit of the random int generation.
    int randNumber; //variable containing the random int generated.
    srand(time(NULL)); //reinitialize the seed for number generation in every execution of the code.
    for (int i = 0; i < MAX; i++) {
        randNumber = (rand() % (upper - lower + 1)) + lower;    //random number generated.
                                                                //This formula for delimiting range in
                                                                //generation of random numbers.
        intArray[i] = randNumber; //assign intArray[i] to point to int number generated.
        printf("array element %d is: %d\n", i, intArray[i]);
    }

    printf("The value of the label array (address) is: %p\n", &intArray); //ampersand to get address.
    printf("First integer in the array is (array[0]): %d\n", intArray[0]); //intArray[0] as the first element.
    printf("The size of an integer (number of bytes) is: %d \n", sizeof(intArray[0])); //size of int, as first index is an int.
    printf("The size of the whole array is: %d\n", sizeof(intArray)); //size of whole array.

    printf("\nPrinting each element of an array as a double, through a pointer\n");
    
    int *ptr = intArray; //assigns pointer to first element of intArray
    int counter = 0; //*ptr does not stop after 20 iterations, so it was necessary counter to ensure loop would stop at index 19.
    while (*ptr != NULL && counter < MAX) { 
        // printf("array index %d is: %d\n", counter, *ptr);
        printf("%lf\n", (double) *ptr); //format specifier for double, and casts *ptr value to double.
        counter++; //Keeps track of iterations count.
        ptr++; //Move to next element of array
    }
    
    
    return 0; //return 0 if program is executed with no issues.
}







