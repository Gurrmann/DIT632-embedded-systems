#include <limits.h>
#include <stdio.h>
#include <string.h>

char switchLetter(char, char[]);

int main(int argc, char const *argv[])
{    
    char input[100];
    char alphabet[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    char answer[100];
    char switchedLetter;

    while(1){
        scanf("%s", input);
        
        printf("%s \n", input);

        for(int i = 0; i < 100; i++) {
            char temp = input[i];

            if (temp == NULL) {
                break;
            }
            switchedLetter = switchLetter(temp, alphabet);
            answer[i] = switchedLetter;
        } 
        
        printf("%s \n", answer);
        for(int i = 0; i < 100; i++) {
            input[i] = 0;
            answer[i] = 0;
        }
    }

    return 0;
}

char switchLetter(char c, char arr[]) {
    for (int i = 0; i < 26; i++) {
        if (c == arr[i] && i <= 12) {
            printf("DEBUG: char is 12 or smaller \n");
            return arr[i+13];
        } else if (c == arr[i] && i > 12) {
            printf("DEBUG: char is 13 or greater \n");
            return arr[i-13];
        }
    }
}
