/*====================================
File name: exerc_3_1.c
Date: 2020-02-16
Group nr: 21
Members that contributed to the solutions:
Aleksandar Isakovski
Gustav Skallberg
Thiago Oliva

all group members were present at the demo.
Demonstration code: 
======================================*/

#include <stdio.h>
#define MAX 20

enum DIRECTION {N,E,S,W}; //North, East, South, West

typedef struct { //typedef so you don't have to type struc every time you create a new ROBOT
  int xpos; //position on X axis
  int ypos; //position on Y axis
  enum DIRECTION dir; //direction N E S W equivalent to 0, 1, 2, 3
} ROBOT;

void initializeRobot(ROBOT*, int, int, enum DIRECTION);
void move(ROBOT*);
void turn(ROBOT*);
void executeInstructions(ROBOT*, char[]);

int main()
{
  ROBOT robot, *ptr; //initializes Robot and pointer of type ROBOT.
  ptr = &robot; //points ptr to robot address. 
  
  int x;
  int y;
  char userInput[MAX];

  while(1) { //infinite loop

  printf("\n------------------------------------------------------------------\n");
  printf("\nReinitializing...\n");
  printf("\n------------------------------------------------------------------\n");
  printf("\nPlease inform starting position on the X AXIS\n");
  scanf("%d", &x); //get robot's starting position on the X axis

  printf("\nPlease inform starting position on the Y AXIS\n");
  scanf("%d", &y); //get robot's starting position on the Y axis
  
  initializeRobot(ptr, x, y, N); //initialized Robot with x, y and North direction.

  printf("\nPlease inform strings containing\nchar m for movements\nchar t for turning 90 degrees clockwise\n");
  scanf("%s", userInput); //get string containing 'm' and 't'

  executeInstructions(ptr, userInput);

  printf("\n****Final Robot position****\n");
  printf("->the y is %d\n", robot.ypos);
  printf("->the x is %d\n", robot.xpos);
  printf("->the Robot direction is %d\n\n", ptr->dir);

  }
  return 0;
}

void executeInstructions(ROBOT *ptr, char instructions[]) {
  int i = 0;
  while (instructions[i] != '\0') { //while not the end of the string
    if (instructions[i] != 'm' && instructions[i] != 't') {
      printf("\n*********************************************************\n");
      printf("\n------------>WARNING!! Invalid input detected<------------\n");
      printf("\n*********************************************************\n");
      break;
    } else {
      //if instruction is an m, call function move. Else, call function turn.
      instructions[i] == 'm' ? move(ptr) : turn(ptr);
    }
    i++;
  }
}

//set the robot with the informed x, y and direction.
void initializeRobot(ROBOT *ptr, int x, int y, enum DIRECTION dir) {
  ptr->xpos = x; //set robot's xpos to x.
  ptr->ypos = y; //same as (*ptr).ypos = y
  ptr->dir = dir; //set robot's dir (always north here).
}

//move the robot by 1 unit in its current direction.
void move (ROBOT *ptr) {
  /*depending on which direction the robot is pointed to, 
  increases or decreases the xpos or ypos */
  if (ptr->dir == 0) {//North -> moves by 1 in the y axis
    ptr->ypos++;
  }
  if (ptr->dir == 1) {//East -> moves by 1 in the x axis
    ptr->xpos++;
  }
  if (ptr->dir == 2) {//South -> moves by -1 in the y axis
    ptr->ypos--;
  }
  if (ptr->dir == 3) {//West -> moves by -1 in the x axis
    ptr->xpos--;
  }
}

void turn (ROBOT *ptr) {
    ptr->dir++; //increases dir by 1. {N, E, S, W} is equivalent to {0, 1, 2, 3}.
    ptr->dir = ptr->dir % 4; //so that when you turn 4 times it goes back to 0 (NORTH)
}