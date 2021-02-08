#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 10

//prototypes
void create_random(int*);
void count_frequency(int*, int*);
void draw_histogram(int*);


int main(int argc, char const *argv[])
{
    //declaring variables
    int table[MAX];
    int frequency[MAX];


    create_random(&table[0]); //filling table with random numbers

    count_frequency(&table[0], &frequency[0]); //call count frequency, fill freqency array

    // print out table in order to see if solution is correct
    for(int i=0; i < MAX; i++)
    {
        printf("table[%d] = %d \n", i, table[i]);
    }

    //print frequency table to see if solution is correct
    for(int i=0; i < MAX; i++)
    {
        printf("frequency[%d] = %d \n", i, frequency[i]);
    }

    //draw the histogram
    draw_histogram(frequency);
    return 0;
}

void create_random(int *tab)
{
    int *secondElemLoc = tab + 1; //address + 1 (table[i+1])
    printf("first elem %d, second elem %d \n", *tab, *secondElemLoc);

    time_t timeSeed; // set variable to use for seeding random number generator
    srand((unsigned) time(&timeSeed)); //set seed for rand()

    for(int i = 0; i < MAX; i++)
    {
        *tab = rand() % MAX; //create random number
        printf("generated value: %d\n", *tab); // printout the generated value
        tab++; //go to the next index of table
    }
}

void count_frequency(int *tab, int *freq)
{
    for (int i=0; i < MAX; i++)
    {
        int count = 0; //cout the appearance of the numbers in the array tab
        for (int j = 0; j < MAX; j++)
        {
            if (*(tab+j) == i) // table[j]==i
            {
                count++; //increase count
            }
        }
        *(freq+i) = count; // frequency[i] = count
    }
}

// 111 2222 3333

void draw_histogram(int *freq)
{
    for(int i=0; i < MAX; i++)
    {
        if(*freq != 0){ // if frequency[i] not eqal to 0 print out the appearance of the number
            printf("%d ", i);
            for (int i = 0; i < *freq; i++){ // add x for each appearance of number of pos *freq
                printf("x");
            }
            printf(" \n");
        }
        freq++; //frequency[i+1]
    }
}