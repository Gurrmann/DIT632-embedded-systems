#include<stdio.h>

#define MAX 80

int main() {

    char userInput[MAX];
    fgets(userInput, MAX, stdin);
    
    int words = 0;

    for (size_t i = 0; i < MAX; i++)
    {
        if (userInput[i] == ' ') {
            words++;
        }
    }
    
    printf("The number of words are %d!", words);

    return 0;
}