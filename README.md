# DIT632-embedded-systems


<details>
<summary>Work Package 1 exercises</summary>
<br>
Exerc_1_ 1 : (Filename   exerc_1_1.c)
<br><br>
Write a program that reads in an integer number between 1 and 5 from the keyboard and prints outone of existing five sentences on the console depending on what number was entered.The program continues to ask for a new number and exits if number isn ́t in the interval 1 to 5.
<br><br>
Exerc_1_ 2 : (Filename   exerc_1_2.c)
<br><br>
Write a program that reads in a sentence of MAX characters and counts the number of words in it. The number of words should then be printed out on the console window.
<br><br>
Exerc_1_3 : (Filename   exerc_1_3.c)
<br><br>
Create a very simple encryption program. The program is based on the principal of “shifts of characters”   in the ASCII-code table. In the example below, A has shifted to N, B to O, etc., that will mean 13 steps in the table. Only capital letters are viewed in the figure but the same ideas applies to lower case letters. The word HELLO becomes URYYB after encryption. The user enters a text and the program prints out the encrypted text. Let the program read character by character, and encrypt it as above. The program is repeated until EOF indicated the program ends. (EOF, the user enters Ctrl +z for Windows and Ctrl + d for Linux system).
<br><br>
Example of a test run
<br>
:HELLO (+enter)
<br>
URYYB
<br>
Banana (+enter)
<br>
Onanan( +Ctrl-z)
<br>
(Program ends)
<br><br>
Exerc_1_ 4 : (Filname   exerc_1_4.c)
<br><br>
You should develop a very simple game in which the computer creates a random integer numberbetween 1..100.  The user then tries to guess the number. The program should work as specified below:
<br> 
-The computer creates a random number-The user guess the number
<br>
-The computer respond by printing one of: You have guessed xx times and your guess is correct. Or Your guess is to low or to high.
<br>
-If wrong the user is asked for a new guess, this will continue until the guess is right or the number of guesses exceeds the value MAX_NUMBER.
<br>
-After end of one round the user is asked for a new round or to finish. The program should only except guessed numbers in the range of  1 ...100.  An option, but not a demand, is to secure that the program don't fail (crashes)
if a user by accident put in any character other than a number.
</details>

<details>
<summary>Work Package 2 exercises</summary>
<br><br>
Exerc_2_ 1 : (Filename exerc_2_1.c) 
<br>
Write a program that reads in a string with a maximum of 20 characters from the keyboard and
stores the string in a local string variable.
Copy the string to another string by using:
<br>
<br>
a) The library function strcpy(..)
<br>
b) Your own function void copyString(...) not using any library function.
Main program ends by printing out the copied string in the console.
<br>
<br>
The program should be able to both read in from keyboard or from a text file ‘myfile.txt’ containing
one string of characters. You create this file with notepad or any other text editor. The reading from
the text file should be done by redirect the readings from command line when program execution
starts as follows: Exerc_2_1 < myfile.txt
<br>
<br>
Where Exerc_2_1 is the filename of the compiled program. You shall not use standard file managing
by opening the file and the read from it.
<br>
<br>
Exerc_2_ 2: (Filename exerc_2_2.c)
<br>
<br>
Write a program that creates an array of integers, array[MAX], and then fill it with MAX no of random
integers from 1 to 99. Let then the program prints out the following:
<br>
<br>
The value of the label array (address) is: xxxxxxxxxx
<br>
First integer in the array is (array[0]) : xxxxxxxxxx
<br>
The size of an integer (number of bytes) is : xxxxxxxxx
<br>
The size of the whole array is : xxxxxxxxx
<br>
<br>
The program shall then, by use of a pointer, print out each integer value and it ́s double value.
<br>
<br>
Exerc_2_3 : (Filename exerc_2_3.c)
<br>
Create a program that reads in a number of strings from the command line when it starts and then
checks if it is two strings and if exactly two check if they are identical or not. Do this with and without
use of library function strcmp(..). Let the program print out the result in some way.
<br>
<br>
Start from command line: exerc_2_3 string1 string2
<br>
<br>
Exerc_2_4 : (Filename exerc_2_4.c)
<br>
<br>
Create a program that reads in a string and determines if the string is a palindrome. A word is a
palindrome if it is the same word reading from left to right or right to left. We can assume that it is a
simple strings without any space character in it.
<br>
<br>
Example of palindrome : level, rotor and racecar.
<br>
<br>
Exerc_2_5: Pointer exercise
<br>
<br>
You should develop a program that calculates some statistical values for an array of integers. Among
other things, the program will plot a histogram for the frequency of different numbers in the array.
To test it you need to create an array of integers (table [MAX]) with MAX number of random
numbers between 0 and MAXNUMBER. Then you should write a function that for each possible
number between 0 – MAXNUMBER calculates how many times the number exists in the array. The
result is then stored in a new array (frequency []).
Finally, you write a function that given the array frequency [] draw a histogram as below figure:
You should use the function declaration as below.
<br>
<br>
Given an array table[]={ 1,2,12, 5,1,0,0,5,9,12, 0,2,3,0} the program will printout:
<br>
<br>
0 xxxx <br>
1 xx <br>
2 xx <br>
3 x <br>
5 xx <br>
9 x <br>
12 xx <br>
<br>
Note: Numbers with frequency 0 in the array frequency[] is not printed out.
```c
#include <stdio.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

// ------ Function declaration ----------
void create_random( int *tab );             // Use pointer to fill the table
void count_frequency(int *tab, int *freq ); // Use pointer
void draw_histogram(int *freq );            // Use pointer
int main ( void){
    int table[MAX], n ;
    int frequency[MAXNUMBER];
}
```
Exerc_2_ 6
<br>
<br>
We want to use an array for a queue of positive integers. The numbers must be entered in to the queue which is done by putting them into the first vacant location in the field. (In the figure below from left) . An integer is taken out from the queue by taking the first number in the array. When an integer is    taken out the other integers should be shifted one step up to left in the queue. A vacancy in the queue is represented by the integer -1. In a full queue there is no integer -1. When taking out an integer from a full queue , the integer -1 must be written in the last position.Examples below show a queue with five positions.
<br>
<br>
int que [ MAX ] ;  // MAX equal to 5 in this example
<br>
<br>
Queue from the start:-1 -1 -1 -1 -1 <br>
Queue after you first put in the numbers 3 and then 4 and 5. 3  4  5  -1 -1 <br>
Queue after additional put in of 8 : 3  4  5   8  -1 
<br>
And after taken out an integer  4  5  8  -1 -1
<br>
<br>
 a) Write a function void initQue (int list [], int max ) that initializes a list to initially containing max nr of vacant positions (-1).  
 <br>
 b) Write a function int input (int list [] , int number, int max) that adds a number in the queue according to the rules , and return 1 if the number could be entered and 0 if the queue is full.
 <br><br>
 c) Write a function int output( int list[], int max)  that returns the value if any to fetch or 0 if que is empty.
 <br><br>
 d) Finally write a main-program that sets up an empty queue with 5 positions and then call all functions for test of its function.
 <br><br>
 Exerc_2_ 7 
 <br><br>
 Create a program that checks an entered Swedish person number. The number is entered in the form of :   7107254786 (yymmddxxxc). The number should be read in as a string and converted to   integers for year, month , day and number.  The last digit (here 6) is a control digit and is calculated from the other digits by an algorithm that you can find on the internet.
<br>

 The user inputs the number, the program first checks that the number of month and day is in the right range and after that calculate and checks the control digit. The program then prints out the result and asks for a new person number. This is repeated until the user inputs a ‘q’.
 <br>

 The program should at least consist of the functions: 
 <br>
 <br>
 main() , readPersnr( char *person),  int controlDigit( const char * persnr ).

Exerc_2_ 8
<br><br>
a) The game Nim works as follows:  On the table is a stack of 13 coins. Two players take in turn between one and three coins from the stack. Whoever are forced to take the last coin have lost.
<br>
<br>
Your task is to develop the game Nim by using the code skeleton which is available on the course webpage in Documents / Work package nr 2.
<br><br>
 The program is also available in the form of an executable demo program at the same place.<br><br>
 • Download the code skeleton. Read the code and the comments, and try to understand how the program is structured.
 <br><br>
 • Compile and run it.
 <br><br>
 • In the function declarations you can read a description of what the function should do. All function definitions are empty (called stubs). Read through the comments and develop the functions so that the program works. NOT all at once, do ONE by ONE. Try to test each function in any way.  For example use the debugger function or print out a value.
 <br>
 <br> 
 TIPS: Create a test area at the beginning of main. Test there to call and print the result of a function at a time. You can write return (0 ) immediately after printing, so you do not run the entire program. Remove the test parts when the test is complete.
 <br><br>
 b)  When the game works well, you can only play one  round. Change the program so you can play several rounds.  After each round the program asks if you want to play again. Use function play again()
</details>
