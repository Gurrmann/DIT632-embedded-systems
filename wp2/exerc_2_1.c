/*====================================
File name: exerc_2_1.c
Date: 2020-02-09
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

Demonstration code: 363840
======================================*/


#include <stdio.h>

#define MAX_LENGHT 20

void copyString(char*, char*);

int main(int argc, char const *argv[])
{
    char input[MAX_LENGHT];
    char copiedString[MAX_LENGHT];

    fgets(input, MAX_LENGHT, stdin);
    printf("Entered String is: %s \n", input);

    copyString(input, copiedString);
    printf("The coppied string is: %s \n", copiedString);

    return 0;
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
