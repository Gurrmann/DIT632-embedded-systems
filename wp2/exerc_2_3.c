#include <stdio.h>
#include <stdbool.h>

//macro to calculate the length of an array
#define ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))

int main() {

    char test1[] = "hej";
    char test2[] = "hej";

    //Takes the length of the two arrays to see if they are the same
    size_t arr1 = ARRAYSIZE(test1);
    size_t arr2 = ARRAYSIZE(test2);
    

    if (arr1 != arr2) printf("not identical");

    else {
        // if they are the same length it compares each element to see if there is a match
        // if there isn't it will break the loop and alert the user

        bool identical = true;

        for (size_t i = 0; i < arr1; i++)
        {
            if(test1[i] != (test2[i])) {
                identical = false;
                break;
            }
        }
        // Prints out the result depending on if they are identical or not 
        identical ? printf("The words are identical") : printf("the words are not identical");
        
    }


    return 0;
}
