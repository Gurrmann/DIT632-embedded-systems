#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//macro to calculate the length of an array
#define ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))

int main() {

      
  
        //takes in the input and stores it in variables
        char input1[20];
        char input2[20]; 
        scanf("%s", input1);
        scanf("%s", input2);
     
        //bool to determine if they are true or not
        bool identical = true;

        for (size_t i = 0; i < 20; i++)
        {
            if(input1[0] != (input2[0])) {
                identical = false; // sets the boolean to false and breaks the loop if they are not identical
                break;
            }
        }
        // Prints out the result depending on if they are identical or not 
        identical ? printf("The words are identical") : printf("the words are not identical");
        
    


    return 0;
}
