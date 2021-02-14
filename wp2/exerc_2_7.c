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

#define MAX 10

//prototypes
void readPersnr(char *person);
int controlDigit(char *persnr);
int breakDown(char *persnr, int start, int end);

int main()
{
    // char persnr[MAX];
    char persnr[] = "9006133590";
    // readPersnr(persnr);

    // printf("the user personnumer is: %s \n", persnr);
    // 9006133590

    int year = breakDown(persnr, 0, 1);
    printf("\n\nyear: %d", year);
    int month = breakDown(persnr, 2, 3);
    printf("\nmonth: %d", month);
    int day = breakDown(persnr, 4, 5);
    printf("\nday: %d", day);
    int number = breakDown(persnr, 6, 8);
    printf("\n3 digits: %d", number);
    int lastDigit = breakDown(persnr, 9, 9);
    printf("\nlastDigit: %d\n\n", lastDigit);
    printf("\nlastDigit: %d\n\n", lastDigit);

    
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
      person++;
    }
}

//get a range from the char array persnr and return it as an int
int breakDown(char *persnr, int start, int end) {
  int size = end - start + 1;
  char tempArray[size];
  char *tempPtr = tempArray;
  //set the pointer to the start index
  for(int i = 0; i < start; i++) {
    // printf("\n\nindex is: %d\n", i);
    // printf("value is: %c\n\n", *persnr);
    persnr++;
  }

  //add from start to end the items to tempArray
  while (start <= end)
  {
    *tempPtr = *persnr;
    tempPtr++;
    persnr++;
    start++;
  }

  //atoi tempArray and return it.
  return atoi(tempArray);
}
