/*====================================
File name: exerc_2_1.c
Date: 2020-02-09
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

all group members were present at the demo.
Demonstration code: 363840
======================================*/


#include <stdio.h>

#define MAX_LENGHT 20

void copyString(char*, char*);

int main(int argc, char const *argv[])
{
    char input[MAX_LENGHT];
    char copiedString[MAX_LENGHT];
    char copiedString2[MAX_LENGHT];

    fgets(input, MAX_LENGHT, stdin);
    printf("Entered String is: %s \n", input);

    copyString(input, copiedString);
    printf("Copied string with copyString is: %s \n", copiedString);
    
    strcpy(copiedString2, input);
    printf("Copied string with strcpy is: %s \n", copiedString);

    return 0;
}


void copyString(char *userInput, char *copy) {
    // char *strBeginning = copy; //starting address from string at copy

    while(*userInput != '\0') {
        /*Copies value from address where *userInput points to address where *copy is pointing to.
        Note: they should both be pointing to same index of each respective array.*/
        *copy = *userInput; 
        userInput++; //Move to the next char of userInput char array
        copy++; //Move to the next char of the copy char array
    }
    /*Now copy is pointing to the index right after the last char of the array.
    Adds the end of string char '\0' to the end of thse char array 
    at the current index which *copy is pointing to. */
    *copy = '\0';
}
