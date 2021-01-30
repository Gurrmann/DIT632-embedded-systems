#include <stdio.h>
#include <stdbool.h>

#define ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))

//initialising functions
int stringSplicer();
int stringComparer(char *string1, char *string2);

int main() {

    char test1[] = "hej";
    char test2[] = "hea";

    size_t arr1 = ARRAYSIZE(test1);
    size_t arr2 = ARRAYSIZE(test2);
    

    if (arr1 != arr2) printf("not identical");

    else {
        
        for (size_t i = 0; i < arr1; i++)
        {
            if(test1[i] != (test2[i])) {
                printf("not identical");
                break;
            }
        }
        
    }


    return 0;
}
