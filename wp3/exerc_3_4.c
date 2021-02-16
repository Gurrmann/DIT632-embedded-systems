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

Demonstration code: 2782
======================================*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//delcare new struct
typedef struct PERSON
{
    char firstname[20];
    char lastname[20];
    char pers_number[13];

} PERSON;

/* reads in person record*/
PERSON input_record(void);
/* creates a file and write first record*/
void write_new_file(PERSON *);
/* print all people in the file*/
void printfile(void);
/* search by first name and print out if in list*/
void search_by_firstname(char *);
/* search by last name and print out if in list*/
void search_by_lastname(char *);
/* append new person in file*/
void append_file(PERSON *);
/* converts a char array to lowercase letters*/
void conv_to_low(char *);

int main(int argc, char const *argv[])
{
    printf("Welcome to FIM!\n"); //print out a wellcoming message
    struct PERSON dummy = {"Dummy", "File", "11111"};
    write_new_file(&dummy); //create file with dummy input

    while (1)
    {
        printf("enter '1' to enter a new record, enter '2' to search for a person, enter '3' to print out the file, enter '0' to quit.\n");

        char choice[3];                       // declare variable for user choice
        fgets(choice, sizeof(choice), stdin); // get user choice
        fflush(stdin);                        // empty stdin
        //for user input '1' prompt to add new file and add it to the file
        if (choice[0] == '1')
        {
            //create a PERSON var inRecord used as temporary storage so it can be further added in the file
            struct PERSON inRecord;
            //give a value to inRecord using input_record();
            inRecord = input_record();
            //Append the information in the file with the user input (new file)
            append_file(&inRecord);
        }
        // for user input '2' promt user to search for file
        else if (choice[0] == '2')
        {
            int search = 0; // declare variable for user choice
            char input[20]; // declare variable for user input

            printf("to search by firstname enter 1 to search by last name enter 2\n");

            scanf("%d", &search);
            //search file by firstname if user chooses '1'
            if (search == 1)
            {
                scanf("%s", &input);        // get user input
                search_by_firstname(input); //search for user input by first name
            }
            //search file by lastname if user chooses '2'
            else if (search == 2)
            {
                scanf("%s", &input);       //get user input
                search_by_lastname(input); //search for user input by last name
            }
            else
            {
                printf("invalid input");
            }
        }
        // for user choice '3' print all files
        else if (choice[0] == '3')
        {
            printfile();
        }
        //for user choice '0' exit application
        else if (choice[0] == '0')
        {
            break;
        }
    }
    return 0;
}

PERSON input_record(void)
{
    //temp PERSON input
    struct PERSON input;

    printf("enter first name:\n");
    fflush(stdin); //clear stdin buffer
    //promt user to enter first name trough stdin
    fgets(input.firstname, sizeof(input.firstname), stdin);
    fflush(stdin); //clear stdin buffer
    //remove new rows from string
    for (int i = 0; i < sizeof(input.firstname); i++)
    {
        //if the char in pos i is newline, change it with null terminator to know the end of the string
        if (input.firstname[i] == '\n')
        {
            input.firstname[i] = '\0';
            break;
        }
    }

    printf("enter last name:\n");
    fflush(stdin);
    //promt user to enter last name
    fgets(input.lastname, sizeof(input.lastname), stdin);
    fflush(stdin);

    for (int i = 0; i < sizeof(input.lastname); i++)
    {
        if (input.lastname[i] == '\n')
        {
            input.lastname[i] = '\0';
            break;
        }
    }

    printf("enter person number:\n");
    //promtuser to enter personal number
    fgets(input.pers_number, sizeof(input.pers_number), stdin);
    fflush(stdin);

    for (int i = 0; i < sizeof(input.pers_number); i++)
    {
        if (input.pers_number[i] == '\n')
        {
            input.pers_number[i] = '\0';
            break;
        }
    }

    return input;
}

void write_new_file(PERSON *inrecord)
{
    FILE *outfile; //initialize object of type FILE

    // open file for writing
    outfile = fopen("file", "w");
    //if file is missing or something went wrong exit with failure
    if (outfile == NULL)
    {
        fprintf(stderr, "Error opening file");
        exit(1);
    }

    // write struct to file
    fwrite(inrecord, sizeof(PERSON), 1, outfile);

    //check if the file has been written sucessfully
    if (fwrite != 0)
    {
        printf("contents to file written successfully !\n");
    }
    else
    {
        printf("error writing file !");
    }
    // close file
    fclose(outfile);
}

void printfile(void)
{
    FILE *infile;
    struct PERSON input;

    // Open file for reading
    infile = fopen("file", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Error opening file");
        exit(1);
    }

    // read file contents till end of file
    while (fread(&input, sizeof(PERSON), 1, infile))
    {
        printf("First name:'%s' Last name:'%s' Person No.:'%s' \n", input.firstname, input.lastname, input.pers_number);
    }
    // close file
    fclose(infile);
}

void search_by_firstname(char *name)
{

    FILE *infile; //initialize FILE object
    struct PERSON input;
    //convert name to lowercase
    conv_to_low(name);
    //allocate memory in bytes of name to tempNameString
    char *tempNameString = (char *)malloc(strlen(name) + 1);
    //coppy name to tempString
    strcpy(tempNameString, name);

    infile = fopen("file", "r");

    //if file is missing or something went wrong exit with failure
    if (infile == NULL)
    {
        fprintf(stderr, "Error opening file");
        exit(1);
    }
    //read file contents till end of file
    while (fread(&input, sizeof(PERSON), 1, infile))
    {
        char *storedNameString = (char *)malloc(strlen(input.firstname) + 1); //allocate memory in bytes of input.firstname to storedNameString
        //copy input.firstname to storedNameString
        strcpy(storedNameString, input.firstname);

        conv_to_low(storedNameString);
        //print all files with matching first name
        if (strcmp(tempNameString, storedNameString) == 0)
        {
            printf("First name:'%s' Last name:'%s' Person No.:'%s' \n", input.firstname, input.lastname, input.pers_number);
        }
    }
    //close the file
    fclose(infile);
}

void conv_to_low(char *c)
{
    int i = 0;
    //for i of position of c[0] utill the end of the string replace it with a lowercase of the appropriate letter
    while (c[i] != '\0')
    {
        c[i] = tolower(c[i]);
        i++;
    }
}

void search_by_lastname(char *name)
{

    FILE *infile; //initialize FILE object
    struct PERSON input;
    conv_to_low(name); // convert to lowercase
    //allocate memory in bytes of name to tempNameString
    char *tempNameString = (char *)malloc(strlen(name) + 1);
    strcpy(tempNameString, name); // oppy name to tempNmaeString

    //open file for reading
    infile = fopen("file", "r");

    //if file is missing or something went wrong exit with failure
    if (infile == NULL)
    {
        fprintf(stderr, "Error opening file");
        exit(1);
    }

    //read file contents till end of file
    while (fread(&input, sizeof(PERSON), 1, infile))
    {
        //allocate memory in bytes of input.lastname to storedNameString
        char *storedNameString = (char *)malloc(strlen(input.lastname) + 1);
        strcpy(storedNameString, input.lastname); //coppy content of input.lastname to storedNameString

        conv_to_low(storedNameString); //convert to lowercase
        if (strcmp(tempNameString, storedNameString) == 0)
        {
            printf("First name:'%s' Last name:'%s' Person No.:'%s' \n", input.firstname, input.lastname, input.pers_number);
        }
    }
    //close file
    fclose(infile);
}

void append_file(PERSON *inrecord)
{
    FILE *infile;
    //open file for appending
    infile = fopen("file", "a");
    //append contents of inrecord to file
    fwrite(inrecord, sizeof(PERSON), 1, infile);
    //close file
    fclose(infile);
}