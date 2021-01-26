#include <stdio.h>

int main(int argc, char const *argv[])
{
    oneToFive(); //calling void function
    return 0;
}

void oneToFive(void){

    int number; //declaring variable
    while (1){ // infinite loop
        
        printf("enter an integer between 1 and 5: \n"); //printing string to console
        scanf("%d", &number); //setting input prompt, assigning value to variable "number"

        if(number < 1 || number > 5){ //if statement to check if the number is smaller than 1 and larger than 5
            printf("invalid integer! \n"); //only accessable if the input is larger than 5 or smaller than 1
        }else{
            printf("you entered: %d" , number , "\n"); //printing the number if it is withing the given range
            break; //exiting the loop
        }    
    }

}