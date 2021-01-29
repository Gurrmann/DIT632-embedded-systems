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

