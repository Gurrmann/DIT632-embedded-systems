//include sections
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{

    //save 5 different strings in variables
    int choice;

    char firstString[]="This is the first string!";
    char secondString[]="This is the second string!";
    char thirdString[]="This is the third string!";
    char fourthString[]="This is the fourth string!";
    char fifthString[]="This is the fifth string!";

    printf("\nEnter a number between 1 and 5:\n\n");

    //read input 1 to 5
    scanf("%d", &choice);  
    
    while (choice >= 1 && choice <= 5)
        {
            switch(choice) {
            case 1 :
                printf("\n%s\n\n", firstString);
                break;
            case 2 :
                printf("\n%s\n\n", secondString);
                break;
            case 3 :
                printf("\n%s\n\n", thirdString);
                break;
            case 4 :
                printf("\n%s\n\n", fourthString);
                break;
            case 5 :
                printf("\n%s\n\n", fifthString);
                break;
            default:
                break;
        }
        scanf("%d", &choice);
    }
    
    
    
    //add input validations so the program does not crash
    return 0;
}

