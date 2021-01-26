#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int randomN = rand() % 100 + 1;    
    printf("%d", randomN , "\n");
  
    while(1){
        int number;
        int guessCount = 0;
        
        printf("enter a number in the range of 1-100: \n");
        scanf("%d", &number);
        
        if(number >= 1 && number <= 100){
            if(number < randomN){
                printf("your guess is too low \n");
                ++guessCount;
            }else if (number > randomN){
                printf("your guess is to high: \n");
                ++guessCount;
            }else{
                ++guessCount;
                printf("You have guessed %d times and your guess is correct!", guessCount);
                break;
            }
        }
        else
            printf("Numebr is out of range!! \n");
    }

    return 0;
}
