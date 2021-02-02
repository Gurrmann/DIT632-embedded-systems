/*====================================
File name: exerc_1_1.c
Date: 2020-02-02
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

Demonstration code: 495357
======================================*/

#include <stdio.h>
#include <stdbool.h>

int main() {

   bool exit = false; // Program will run forever while this value is equal to false

        //Infinite loop until the user puts in a 0
        while (!exit) {

            printf("Please enter a number between 1-5, press 0 to exit!\n");
            int userInput;
            scanf("%d", &userInput);

            //prints out the number the user put in if it's in the range of 1-5
             if (userInput > 0 && userInput < 6) printf("You Pressed %d\n", userInput);
             
             //exits the program
             if (userInput == 0) {
                printf("Bye Bye");
                exit = true;
             }
             //prints if the user puts in a different number than asked for
             else {
                 printf("Please put in a valid number\n");
             }
    }
    return 0;
}