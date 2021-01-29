#include<stdio.h>

#define MAX 80 // This value will decide how many characters that the user is allowed to input

int main() {

    char userInput[MAX];
    fgets(userInput, MAX, stdin); // Gets the input from the user
    
    int words = 0;

    //The loop counts how many spaces there are from the user and will then decide the amount of words that was put in
    for (size_t i = 0; i < MAX; i++)
    {
        if (userInput[i] == ' ') {
            words++;
        }
    }
    
    //prints the amount of words
    printf("The number of words are %d!", words);

    return 0;
}