/*====================================
File name: exerc_2_7.c
Date: 2020-02-09
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

Demonstration code: 363840
======================================*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 10

//prototypes
// int readPersnr(char *person);
int controlDigit(char *persnr);
int breakDown(char *persnr, int start, int end);

int main(int argc, char const *argv[])
{
    int persnr[MAX];
    readPersnr(persnr);

    printf("\n the persnr is \n");
    printf("%s", persnr);


    int year = breakDown(persnr, 0, 1);
    int month = breakDown(persnr, 2, 3);
    int day = breakDown(persnr, 4, 5);
    int number = breakDown(persnr, 6, 8);
    int lastDigit = breakDown(persnr, 9, 9);

    
    if (month > 12) {
    printf("Invalid month \n");
  }
  // print error if day incorrect
  if (day > 31 || day < 1) {
    printf("Invalid day \n");
  }

    return 0;
}
void readPersnr(char *person) { 
}

//get a range from the char array persnr and return it as an int
int breakDown(char *persnr, int start, int end) {
    char tempArray[10]; //creates temp array
    for (int i = start; i <= end; i++) { //iterates through range
        tempArray[i] = persnr[i]; //extracts char
    }
    return atoi(tempArray); //concatenates tempArray and return it as an int
}
