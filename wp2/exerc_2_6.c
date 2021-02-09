/*====================================
File name: exerc_2_6.c
Date: 2020-02-09
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

Demonstration code: 363840
======================================*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 5

//prototypes
int input(int[], int, int);
int output(int[], int);
void initQue(int[], int);

int main(int argc, char const *argv[])
{
    int que[MAX];

    //fill the array with -1 meaning is "empty"
    initQue(que, MAX);

    //check if the array is filled correctly
    for (int i = 0; i < MAX; i++){
        printf("initQue result %d \n", que[i]);
    }

    //fill in the array with predictable values expected 5 ones and 1 zero
    int gen = 20;
    for (int i = 0; i < MAX+1; i++){
        int inRes = input(que, gen, MAX);
        printf("input result %d \n", inRes);
        gen--;
    }

    //test output where result is current removed number and
    for (int i = 0; i < MAX*2; i++){
        int outRes = output(que, MAX);
        printf("Number removed from queue %d, next number in queue %d \n", outRes, que[0]);
    }

    return 0;
}


void initQue(int list[], int max){
    for(int i = 0; i < max; i++){ //loop through all postions in the array
        list[i] = -1; //set array of pos i to -1
    }
}

int input(int list[], int number, int max){
    for (int i = 0; i < max; i++)
    {
        if (list[i] == -1) // checks if there is an empty spot in the array
        {
            list[i] = number; //add the number to the queue if there is empty space
            return 1; //return 1 for successfull input
        }
    }
    return 0; // return 0 if thre are no empty spots
}

int output(int list[], int max){
    if(list[0] == -1){ // if first pos is empty the quque is empty
        return 0; //return 0 if queue is emty
    }else{
        int frontVal = list[0]; //save the front pos in queue

        for(int i = 0; i < max-1; i++)
        {
            list[i] = list[i+1]; //move index value to the left
        }
        list[max-1] = -1;//set last value to be -1

        return frontVal;
    }

}