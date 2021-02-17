#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    printf(" argv: %d %x %x\n", *argv[1], *argv[1], strtol(argv[1], NULL, 16));
    if(argc == 2){
        // convert argv string to HEX
        const unsigned char car = strtol(argv[1], NULL, 16);

        unsigned char engine_on = car >> 7;
        unsigned char gear_pos = car & 127;
        gear_pos = gear_pos >> 4;
        unsigned char key_positon = car & 15 ;
        key_positon = key_positon >> 2;
        unsigned char brake1 = car & 2;
        brake1 = brake1 >> 1;
        unsigned char brake2 = car & 1;

        printf(" car: %d %x\n", car, car);

        printf(" engine_on: %d \n gear_pos: %d \n key_positon: %d \n brake1: %d \n brake2: %d \n",engine_on, gear_pos, key_positon, brake1, brake2);


    }
    else if(argc > 2){
        printf("too many arguments");
    }else{
        printf("too few arguments");
    }

    return 0;
}
