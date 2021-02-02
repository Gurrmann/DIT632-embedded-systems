/*====================================
File name: exerc_1_4.c
Date: 2020-02-02
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg

Demonstration code: 495357
======================================*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));              //sets the random number generator to use a seed of current time
    int randomN = rand() % 100 + 1; //create a random integer

    //printf("%d", randomN , "\n");

    int guessCount = 0; //outside the loop, so it is not reinitialize every iteration
    
    //infinite while loop
    while(1){

        //variable declaration
        int number = 0;

        printf("enter a number in the range of 1-100: \n"); //print instructions to user
        scanf("%d", &number);                               // get user input

        // checks if the number entered is in the correct range
        if(number >= 1 && number <= 100){
            //returns a message if the user guessed too low and increases guess counter by 1
            if(number < randomN){
                printf("your guess is too low \n");
                ++guessCount;
            }
            //returns a message if the user guessed too high and increases guess counter by 1
            else if (number > randomN)
            {
                printf("your guess is to high: \n");
                ++guessCount;
            }
            //increase the guess count by one and tells the user that he has guessed successfully
            else
            {
                ++guessCount;
                printf("You have guessed %d times and your guess is correct!", guessCount);
                break;
            }
        }
        //prints a message that informs the user that the enetered number is out of range
        else
        {
            printf("Numebr is out of range!! \n");
        }
    }

    return 0;
}
