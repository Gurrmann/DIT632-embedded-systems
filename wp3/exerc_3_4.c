#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

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
void write_new_file(PERSON*);
/* print all people in the file*/
void printfile(void);
/* search by first name and print out if in list*/
void search_by_firstname(char*);
/* search by last name and print out if in list*/
void search_by_lastname(char*);
/* append new person in file*/
void append_file(PERSON*);
/* converts a char array to lowercase letters*/
void conv_to_low(char*);


int main(int argc, char const *argv[])
{
    printf("Welcome to FIM!\n");
    struct PERSON dummy = {"Dummy", "File", "11111"};
    write_new_file(&dummy); //create file with dummy input

    while(1){
        printf("enter '1' to enter a new record, enter '2' to search for a person, enter '3' to print out the file, enter '0' to quit.\n");

        char choice[3]; // declare variable for user choice
        fgets(choice, sizeof(choice), stdin); // get user choice
        fflush(stdin); // empty stdin
        //for user input '1' prompt to add new file and add it to the file
        if(choice[0] == '1'){
            struct PERSON inRecord;
            inRecord = input_record();
            append_file(&inRecord);
        }
        // for user input '2' promt user to search for file
        else if(choice[0] == '2'){
            int search = 0; // declare variable for user choice
            char input[20]; // declare variable for user input

            printf("to search by firstname enter 1 to search by last name enter 2\n");

            scanf("%d", &search);
            if (search == 1){
                scanf("%s", &input); // get user input
                search_by_firstname(input); //search for user input by first name
            } else if(search == 2){
                scanf("%s", &input); //get user input
                search_by_lastname(input); //search for user input by last name
            }
            else{
                printf("invalid input");
            }
        }
        // for user choice '3' print all files
        else if(choice[0] == '3'){
            printfile();
        }
        //for user choice '0' exit application
        else if(choice[0] == '0'){
            break;
        }
    }
    return 0;
}

PERSON input_record(void){

    struct PERSON input;

    printf("enter first name:\n");
    fflush(stdin);
    ////promt user to enter first name
    fgets(input.firstname, sizeof(input.firstname), stdin);
    fflush(stdin);
    //remove new rows from string
    for(int i = 0; i < sizeof(input.firstname); i++){
        if( input.firstname[i] == '\n'){
            input.firstname[i] = '\0';
            break;
        }
    }

    printf("enter last name:\n");
    fflush(stdin);
    //promt user to enter last name
    fgets(input.lastname, sizeof(input.lastname), stdin);
    fflush(stdin);

    for(int i = 0; i < sizeof(input.lastname); i++){
        if( input.lastname[i] == '\n'){
            input.lastname[i] = '\0';
            break;
        }
    }

    printf("enter person number:\n");
    //promtuser to enter personal number
    fgets(input.pers_number, sizeof(input.pers_number), stdin);
    fflush(stdin);

    for(int i = 0; i < sizeof(input.pers_number); i++){
        if( input.pers_number[i] == '\n'){
            input.pers_number[i] = '\0';
            break;
        }
    }

    return input;
}

void write_new_file(PERSON *inrecord){
   FILE *outfile; //initialize object of type FILE

    // open file for writing
    outfile = fopen ("file", "w");
    //if file is missing or something went wrong exit with failure
    if (outfile == NULL)
    {
        fprintf(stderr, "Error opening file");
        exit (1);
    }

    // write struct to file
    fwrite (inrecord, sizeof(PERSON), 1, outfile);

    //check if the file has been written sucessfully
    if(fwrite != 0){
        printf("contents to file written successfully !\n");
    }
    else{
        printf("error writing file !");
    }
    // close file
    fclose (outfile);
}

void printfile(void){
    FILE *infile;
    struct PERSON input;


    // Open file for reading
    infile = fopen ("file", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Error opening file");
        exit (1);
    }

    // read file contents till end of file
    while(fread(&input, sizeof(PERSON), 1, infile)){
        printf ("First name:'%s' Last name:'%s' Person No.:'%s' \n", input.firstname, input.lastname, input.pers_number);
    }
    // close file
    fclose (infile);
}

void search_by_firstname(char *name){

    FILE *infile;
    struct PERSON input;
    //convert name to lowercase
    conv_to_low(name);
    //allocate memory in bytes of name to tempNameString
    char *tempNameString = (char *)malloc(strlen(name)+1);
    //coppy name to tempString
    strcpy(tempNameString, name);

    infile = fopen("file", "r");

    //if file is missing or something went wrong exit with failure
    if (infile == NULL)
    {
        fprintf(stderr, "Error opening file");
        exit (1);
    }
    //read file contents till end of file
    while(fread(&input, sizeof(PERSON), 1, infile)){
        char *storedNameString = (char *)malloc(strlen(input.firstname)+1); //same dark magic as before
        strcpy(storedNameString, input.firstname);

        conv_to_low(storedNameString);
        //print all files with matching first name
        if(strcmp(tempNameString,storedNameString) == 0){
            printf ("First name:'%s' Last name:'%s' Person No.:'%s' \n", input.firstname,input.lastname, input.pers_number);
        }
    }
    fclose(infile);
}

void conv_to_low(char *c){
    int i = 0;
    //for i of position of c[0] utill the end of the string replace it with a lowercase of the appropriate letter
    while (c[i] != '\0'){
        c[i] = tolower(c[i]);
        i++;
    }
}

void search_by_lastname(char *name){

    FILE *infile;
    struct PERSON input;
    conv_to_low(name);
    char *tempNameString = (char *)malloc(strlen(name)+1);
    strcpy(tempNameString, name);

    infile = fopen("file", "r");

    if (infile == NULL)
    {
        fprintf(stderr, "Error opening file");
        exit (1);
    }

    while(fread(&input, sizeof(PERSON), 1, infile)){
        char *storedNameString = (char *)malloc(strlen(input.firstname)+1);
        strcpy(storedNameString, input.lastname);

        conv_to_low(storedNameString);
        if(strcmp(tempNameString,storedNameString) == 0){
            printf ("First name:'%s' Last name:'%s' Person No.:'%s' \n", input.firstname,input.lastname, input.pers_number);
        }
    }
    fclose(infile);
}

void append_file(PERSON *inrecord){

    FILE *infile;
    //open file for appending
    infile = fopen("file", "a");

    fwrite (inrecord, sizeof(PERSON), 1, infile);

    fclose (infile);
}