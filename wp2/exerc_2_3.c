/*====================================
File name: exerc_2_3.c
Date: 2020-02-09
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

Demonstration code: 363840
======================================*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//macro to calculate the length of an array
#define ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))

int main() {

      
  
        //takes in the input and stores it in variables
        char input1[20];
        char input2[20]; 
        scanf("%s", input1);
        scanf("%s", input2);
     
        //bool to determine if they are true or not
        bool identical = true;

        for (size_t i = 0; i < 20; i++)
        {
            if(input1[0] != (input2[0])) {
                identical = false; // sets the boolean to false and breaks the loop if they are not identical
                break;
            }
        }
        // Prints out the result depending on if they are identical or not 
        identical ? printf("The words are identical\n\n") : printf("the words are not identical\n\n");
        
    


    return 0;
}
