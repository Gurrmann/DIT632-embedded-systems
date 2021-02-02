#include <limits.h>
#include <stdio.h>
#include <string.h>

char switchLetter(char, char[]); //function prototype

int main(int argc, char const *argv[])
{    

    //Variable declaration
    char input[100]; 
    char alphabet[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    char answer[100];
    char switchedLetter;

    //infinite loop
    while(1){
        scanf("%s", input); //get user input
        
        printf("%s \n", input); //print user input

        for(int i = 0; i < 100; i++) { //for loop 0-99
            char temp = input[i]; //charracter of index "i" stored in the temporary variable 

            //break if the loop reaches end of user input
            if (temp == NULL) { 
                break;
            }
            switchedLetter = switchLetter(temp, alphabet); //call the switchLetter function and assign the returned value to switchedLetter
            answer[i] = switchedLetter; //add the switched letter in to a new array
        } 
        
        printf("%s \n", answer); //print the sollution
        
        //setting value of all indexes of arrays input and answer to 0
        for(int i = 0; i < 100; i++) {
            input[i] = 0;
            answer[i] = 0;
        }
    }

    return 0;
}

char switchLetter(char c, char arr[]) {
    //for loop 0-25 size of array "alphabet"
    for (int i = 0; i < 26; i++) {
        if (!isupper(c))
        {
            if (c == arr[i] && i <= 12)
            { //if the letter found is in possition 0-12 returns char in position i+13
                printf("DEBUG: char is 12 or smaller \n");
                return arr[i + 13];
            }
            else if (c == arr[i] && i > 12)
            { //if the letter found is in possition 13-25 returns char in position i-13
                printf("DEBUG: char is 13 or greater \n");
                return arr[i - 13];
            }
        }
        else
        {
            if (c == arr[i] - 32 && i <= 12)
            { //if the letter found is in possition 0-12 returns char in position i+13
                printf("DEBUG: char is 12 or smaller \n");
                return arr[i + 13] - 32;
            }
            else if (c == arr[i] - 32 && i > 12)
            { //if the letter found is in possition 13-25 returns char in position i-13
                printf("DEBUG: char is 13 or greater \n");
                return arr[i - 13] - 32;
            }        
        }
    }
}
