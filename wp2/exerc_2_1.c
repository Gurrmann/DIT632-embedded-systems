#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h> // so that we can assign NULL to pointer values

#define MAX 20 //max number of chars in input
#define SIZE 2048 //max str size read from file

void copyString(char *userInput2, char *copyStr2); //function prototype

int main() {

    char stringInput[MAX]; //local string variable with user input
    char anotherStr[MAX]; // copy string for a)
    char anotherStr2[MAX]; //copy string for b)

    printf("Please enter string to be copied:\n");
    fgets (stringInput, MAX, stdin);  //reads f, stores content in read_str

    // a) Copying variable with lib function strcpy()
    printf("\na) Copying variable with lib function strcpy().\n");
    strcpy(anotherStr, stringInput); //copies userInput to anotherStr
    printf("The value of the copy anotherStr is:\n%s", anotherStr);

    // b) Your own function void copyString(...) not using any library function.
    printf("\nb) Copying variable with our own function copyString() function.\n");
    copyString(stringInput, anotherStr2);    //copies userInput into anotherStr2
    printf("The value of the copy anotherStr2 is:\n%s\n", anotherStr2);

    return 0; //returns 0 if everything is run properly
}

void copyString(char *userInput, char *copy) {
    // char *strBeginning = copy; //starting address from string at copy

    while(*userInput != '\0') {
        *copy = *userInput; //Copies value from address where *userInput points
                            //to address where *copy is pointing to.
                            //Note: they should both be pointing to same index of each respective array.
        userInput++; //Move to the next char of userInput char array
        copy++; //Move to the next char of the copy char array
    }
    //now copy is pointing to the index right after the last char of the array
    *copy = '\0';   //Adds the end of string char '\0' 
                    //to the end of the char array at the current index 
                    //which *copy is pointing to
}