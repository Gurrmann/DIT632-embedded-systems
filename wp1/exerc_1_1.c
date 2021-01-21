#include <stdio.h>
#include <stdbool.h>

int main() {

    bool exit = false;

        while (!exit) {

            int userInput;
            scanf("%d", &userInput);

        
            switch(userInput) {

                case 1:
                printf("You Pressed 1\n");
                break;

                case 2:
                printf("You Pressed 2\n");
                break;

                case 3:
                printf("You pressed 3\n");
                break;

                case 4:
                printf("You pressed 4\n");
                break;

                case 5:
                printf("You pressed 5\n");
                break;

                case 0:
                printf("Bye Bye!");
                exit = true;
            
            }   

        }       
    
}