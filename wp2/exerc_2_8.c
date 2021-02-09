/*====================================
File name: exerc_2_8.c
Date: 2020-02-09
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

Demonstration code: 363840
======================================*/


/*
 *  File    : nim.c
 *  Program : Nim game
 *  Author  : ...
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in:
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
  int pile,			/* This is how many coins we have */
    player,			/* Who is playing? */
    n_coins;			/* Number of coins taken */

  srand( time(0) );		/* Setup random */

  printf("Welcome to NIM by ...\n");



  pile = MAX_COINS;		/* Set start values (= init) */
  player = HUMAN;
  bool playing = true;

  /*
   *  Program main loop
   */
    while (playing){

        while( true ) {
            // int compC = computer_choice(pile);
            // printf("computer choice = %d \n", compC);

            //write_winner(HUMAN);

            // int tog = toggle(COMPUTER);
            // printf("%d ", tog);

            // bool playAgain = play_again();
            // if(playAgain){
            //     printf("is true");
            // }else{
            //     printf("is false");
            // }


            printf("There are %d coins in the pile \n", pile );

            if( player == HUMAN ){
                n_coins = human_choice(pile);
            }
            else{
                n_coins = computer_choice(pile);
                printf("- I took %d\n", n_coins);
            }
            pile -= n_coins;
            player = toggle( player );

            if( pile <= 1 ){
                break;
            }

        }

        write_winner( player );
        pile = MAX_COINS;

        printf("Finished! Play again?\n");
        playing = play_again();
    }

    /*
    * end main loop
    */
    return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 *
 ******************************************************/


void clear_stdin()
{
    // while( getchar() != '\n' ){
    //     ;
    // }
    fflush(stdin);
}

int human_choice(int pile)
{
    int humanChoiceInt = 0;

    bool toggle = true;
    while(toggle){

        char humanChoice[100] = "";
        fgets(humanChoice, 100, stdin);
        clear_stdin();

        humanChoiceInt = humanChoice[0] - '0';
        int humanChoiceInt2 = humanChoice[1] - '0';
        if (humanChoiceInt <= pile && humanChoiceInt <= 3 && humanChoiceInt >= 1 && (humanChoiceInt2 < 0)){
            if (humanChoiceInt2 )
            // printf("2: value human choice of [0] %d, value human choice of [1] %d \n", humanChoice[0] - '0', humanChoice[1] - '0');
            toggle = false;
        } else {
            printf("\tNot a valid input!!!\n");
        }
    }

    return humanChoiceInt;
}

int computer_choice(int pile)
{
    if (pile == 1){
        return 1;
    }
    else if (pile <=4){
        return pile-1;
    }
    else
    {
        time_t timeSeed; // set variable to use for seeding random number generator
        srand((unsigned) time(&timeSeed));
        int randNum = rand() % 3;
        return randNum + 1;
    }
}

void write_winner(int player )
{
    if(player == 1){ // cumputer wins
        fputs("Computer wins!\n", stdout);
    }else{
        fputs("Human wins!\n", stdout);
    }
}

int play_again()
{
    fputs("Do you want to play another round? \n press N to quit", stdout);

    char humanChoice[2];
    fgets(humanChoice, 2, stdin);
    char usable = humanChoice[0];

    switch(usable){
        case 'n':
            return false;
        case 'N':
            return false;
        default:
            return true;
    }
}

int toggle( int player )
{
    if(player == HUMAN){
        return COMPUTER; //returns 1
    }
    return HUMAN; //returns 0
}
