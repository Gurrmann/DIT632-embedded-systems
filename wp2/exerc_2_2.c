#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h> // so that we can assign NULL to pointer values
#include <time.h> //so that we can use srand

#define MAX 20 //max number of chars in input
#define RAND_MAX 99 //max number of chars in input


int main() {

    int intArray[MAX]; //Max 20 elements
    int lower = 1; //lower limit of the random int generation.
    int upper = 99; //upper limit of the random int generation.
    int randNumber; //variable containing the random int generated.
    srand(time(0)); //reinitialize the seed for number generation in every execution of the code.
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

    return 0; //return 0 if program is executed with no issues.
}







