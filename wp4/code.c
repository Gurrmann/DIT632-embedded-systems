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

int main(int argc, char const *argv[])
{

    if(argc == 6){

        if(atoi(argv[1]) < 0 || atoi(argv[1]) > 1){
            printf("invalid engine_on value\n");
            exit(1);
        }else if (atoi(argv[2]) < 0 || atoi(argv[2]) > 4){
            printf("invalid gear_pos value\n");
            exit(1);
        }else if (atoi(argv[3]) < 0 || atoi(argv[3]) > 2){
            printf("invalid key_positon value\n");
            exit(1);
        }else if (atoi(argv[4]) < 0 || atoi(argv[4]) > 1){
            printf("invalid brake1 value\n");
            exit(1);
        }else if (atoi(argv[5]) < 0 || atoi(argv[5]) > 1){
            printf("invalid brake2 value\n");
            exit(1);
        }else{
            //assignning integers from arguments
            int engine_on = atoi(argv[1]);
            int gear_pos = atoi(argv[2]);
            int key_positon = atoi(argv[3]);
            int brake1 = atoi(argv[4]);
            int brake2 = atoi(argv[5]);
            unsigned char car;
            car = car | brake2;
            car = car | (brake1 << 1);
            car = car | (key_positon << 2);
            car = car | (gear_pos << 4);
            car = car | (engine_on << 7);
            printf("%x", car&0xff);
            printf(" engine_on:%d \n gear_pos:%d \n key_positon:%d \n brake1:%d \n brake2:%d \n",engine_on, gear_pos, key_positon, brake1, brake2);

            printf("Wohooo!\n");
        }
    }else if (argc > 6){
        printf("too many arguments\n");
        exit(1);
    }else{
        printf("too few arguments\n");
        exit(1);
    }

    return 0;
}
