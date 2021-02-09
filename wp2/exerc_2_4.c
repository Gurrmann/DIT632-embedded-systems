#include <stdio.h>
#include <string.h>

#define MAX 20

//Method to reverse a string
char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    //determines the length of the string and decided how many iterations the loop will run 
    int i = strlen(str) - 1, j = 0;

    char ch;

    // Iterates until it has reached the middle of the string when everything has been reversed
    while (i > j)
    {
        // Puts the characther at the opposite end of the String
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        // incrementing and decrementing to meet at the middle  
        i--; 
        j++;
    }
    return str;
}

int main() {

    char input[MAX];
    char inputRev[MAX];
    

    scanf("%s", input); // Gets the input from the user

    //copying the input from the user to the inputRev variable
    strcpy(inputRev, input);
    //reverses the String
    strrev(inputRev);


    //Compares if the two strings are identical when reversed
    if (strcmp(inputRev, input) == 0) {
        printf("palindrome");
    }
    else {
        printf("not palindrome");
    }

}