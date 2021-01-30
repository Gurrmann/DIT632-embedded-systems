#include <stdio.h>
#include <stdbool.h>

#define ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))

//initialising functions
int stringSplicer();
int stringComparer(char *string1, char *string2);

int main() {

    char test1[] = "hej";
    char test2[] = "hejsan";

    size_t arr1 = ARRAYSIZE(test1);
    size_t arr2 = ARRAYSIZE(test2);
    

    if (arr1 == arr2) printf("not identical");


    return 0;
}
