/*====================================
File name: exerc_3_1.c
Date: 2020-02-16
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

Group members present at the demo:
Aleksandar Isakovski
Thiago Oliva

->Since the demo was done on a spontaneous manner without being schedule beforehand,
Gustav Skallberg could not join in time to participate on this Demo.

Demonstration code: AB005
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    printf(" argv: %d %x %x\n", *argv[1], *argv[1], strtol(argv[1], NULL, 16));
    if(argc == 2){
        if (strlen(argv[1]) > 2)
        {
            printf("argument too long, only accept '2' characters\n");
            exit(1);
        }

        // convert argv string to HEX
        const unsigned char car = strtol(argv[1], NULL, 16);

        unsigned char engine_on = car >> 7;
        unsigned char gear_pos = car & 127;
        gear_pos = gear_pos >> 4;
        unsigned char key_positon = car & 15;
        key_positon = key_positon >> 2;
        unsigned char brake1 = car & 2;
        brake1 = brake1 >> 1;
        unsigned char brake2 = car & 1;

        if (engine_on < 0 || engine_on > 1)
        {
            printf("engine value out of range\n");
            exit(1);
        }
        else if (gear_pos < 0 || gear_pos > 4)
        {
            printf("gear value out of range\n");
            exit(1);
        }
        else if (key_positon < 0 || key_positon > 2)
        {
            printf("key possition out of range\n");
            exit(1);
        }
        else if (brake1 < 0 || brake1 > 1)
        {
            printf("brake1 value out of range\n");
            exit(1);
        }
        else if (brake2 < 0 || brake2 > 1)
        {
            printf("brake2 value out of range\n");
            exit(1);
        }
        else
        {
            printf(" car: %d %x\n", car, car);
            printf(" engine_on: %d \n gear_pos: %d \n key_positon: %d \n brake1: %d \n brake2: %d \n", engine_on, gear_pos, key_positon, brake1, brake2);
        }
    }

    else if(argc > 2){
        printf("too many arguments");
    }else{
        printf("too few arguments");
    }

    return 0;
}
