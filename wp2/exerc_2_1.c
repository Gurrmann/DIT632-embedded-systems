#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h> // so that we can assign NULL to pointer values

#define MAX 20 //max number of chars in input

void copyString(char *userInput2, char *copyStr2); //function prototype

int main() {
    char userInput[MAX]; //local string variable with user input
    char anotherStr[MAX];

    printf("Please enter string to be copied:\n");
    fgets(userInput, MAX, stdin); //read user input, saves it in userInput local var
    
    // a) copying variable with lib function strcpy()
    strcpy(anotherStr, userInput); //copies userInput to anotherStr
    printf("The first copied string is:\n %s", anotherStr);

    //b) Your own function void copyString(...) not using any library function.
    printf("Please enter second string to be copied:\n");
    char userInput2[MAX]; //local string variable with user input
    char anotherStr2[MAX]; //copy string
    fgets(userInput2, MAX, stdin); //read user input, saves it in userInput2 local var
    copyString(userInput2, anotherStr2);    //copies userInput2 into anotherStr2
                                            //you don't have to pass pointers because you are passing arrays!
                                            //if you were dealing with simple chars, you would have to pass a pointer.
    printf("the value of anotherStr2 is\n%s\n", anotherStr2);

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





