/*====================================
File name: exerc_1_3.c
Date: 2020-02-02
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

Demonstration code: 495357
======================================*/

#include <limits.h>
#include <stdio.h>
#include <string.h>

char switchLetter(char, char[], char[]); //function prototype

int main(int argc, char const *argv[])
{    

    //Variable declaration
    char input[100]; 
    char lowerCaseAlphabet[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    char upperCaseAlphabet[27] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    char answer[100];
    char switchedLetter;

    //infinite loop
    while(1){
        scanf("%s", input); //get user input
        
        printf("%s \n", input); //print user input

        for(int i = 0; i < 100; i++) { //for loop 0-99
            char temp = input[i]; //charracter of index "i" stored in the temporary variable 

            //break if the loop reaches end of user input
            if (temp == NULL) { 
                break;
            }
            switchedLetter = switchLetter(temp, lowerCaseAlphabet, upperCaseAlphabet); //call the switchLetter function and assign the returned value to switchedLetter
            answer[i] = switchedLetter; //add the switched letter in to a new array
        } 
        
        printf("%s \n", answer); //print the sollution
        
        //setting value of all indexes of arrays input and answer to 0
        for(int i = 0; i < 100; i++) {
            input[i] = 0;
            answer[i] = 0;
        }
    }

    return 0;
}

char switchLetter(char c, char lowerCaseArr[], char upperCaseArr[]) {
    //for loop 0-25 size of array "alphabet"
    for (int i = 0; i < 26; i++) {
        if (c == lowerCaseArr[i] && i <= 12) { //if the letter found is in possition 0-12 returns char in position i+13
            // printf("DEBUG: char is 12 or smaller \n"); //for testing purposes
            return lowerCaseArr[i+13];
        } else if (c == upperCaseArr[i] && i <= 12) { //if the letter found is in possition 0-12 returns char in position i+13
            // printf("DEBUG: char is 12 or smaller \n"); //for testing purposes
            return upperCaseArr[i+13]; 
        }  else if (c == lowerCaseArr[i] && i > 12) { //if the letter found is in possition 13-25 returns char in position i-13
            // printf("DEBUG: char is 13 or greater \n"); //for testing purposes
            return lowerCaseArr[i-13];
        } else if (c == upperCaseArr[i] && i > 12) { //if the letter found is in possition 13-25 returns char in position i-13
            // printf("DEBUG: char is 13 or greater \n"); //for testing purposes
            return upperCaseArr[i-13];
        }
    }
}
