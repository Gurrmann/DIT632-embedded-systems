/*====================================
File name: exerc_2_7.c
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
#include <stdlib.h>
#include <string.h>

#define MAX 12

//prototypes
void readPersnr(char *person);
int controlDigit(char *persnr);
int breakDown(char *persnr, int start, int end);

int main()
{
    char persnr[MAX];
    readPersnr(persnr);

    printf("the user personnumer is: %s \n", persnr);
    // 9006133590


    int year = breakDown(persnr, 0, 1);
    printf("\nyear: %d", year);
    // int month = breakDown(persnr, 2, 3);
    // printf("\nmonth: %d", month);
    // int day = breakDown(persnr, 4, 5);
    // printf("\nday: %d", day);
    // int number = breakDown(persnr, 6, 8);
    // printf("\n3 digits: %d", number);
    // int lastDigit = breakDown(persnr, 9, 9);
    // printf("\nlastDigit: %d", lastDigit);

    
  // if (month > 12 || month < 1) {
  //   printf("Invalid month \n");
  // }
  // // print error if day incorrect
  // if (day > 31 || day < 1) {
  //   printf("Invalid day \n");
  // }

    return 0;
}
void readPersnr(char *person) { 
    char userInput[MAX]; 
    scanf("%s", userInput);

    for (int i = 0; i < MAX; i++) {
      *person = userInput[i];
      *person++;
    }
}

//get a range from the char array persnr and return it as an int
int breakDown(char *persnr, int start, int end) {
    for (int i = 0; i < start; i++){ //sets pointer to desired start index
      *persnr++;
    }
    
    char tempArray[MAX]; //creates temp array
    for (int i = 0; i <= start - end + 1; i++) { //iterates through range
        tempArray[i] = *persnr; //extracts char
        *persnr++;
    }
    printf("temp array is: %s\n", tempArray);
    int result;
    result = atoi(tempArray);
    printf("result is: %d\n", result);

    return result; //concatenates tempArray and return it as an int
}
