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

enum DIRECTION {N,E,S,W};

typedef struct {
  int xpos;
  int ypos;
  enum DIRECTION dir;
} ROBOT;

void initializeRobot(ROBOT*, int, int, enum DIRECTION);
void move(ROBOT*);
void turn(ROBOT*);
void executeInstructions(ROBOT*, char[]);

int main()
{
  ROBOT robot, *ptr;
  ptr = &robot;
  
  int x;
  int y;
  char userInput[MAX];

  while(1) { //infinite loop

  printf("\nReinitializing...\n\n");
  printf("\nPlease inform starting position on the X AXIS\n");
  scanf("%d", &x);

  printf("\nPlease inform starting position on the Y AXIS\n");
  scanf("%d", &y);
  initializeRobot(ptr, x, y, N);

  printf("\nPlease inform strings containing\nchar m for movements\nchar t for turning 90 degrees clockwise\n");
  scanf("%s", userInput);

  executeInstructions(ptr, userInput);

  printf("the y is %d\n\n", robot.ypos);
  printf("the x is %d\n\n", robot.xpos);
  printf("the Robot direction is %d\n\n", ptr->dir);

  }
  return 0;
}

void executeInstructions(ROBOT *ptr, char instructions[]) {
  int i = 0;
  while (instructions[i] != "\0") {
    if (instructions[i] != 'm' && instructions[i] != 't') {
      // printf("\n\ninvalid input detected\n\n"); //this is bugged, I need to fix it
      break;
    } else {
      instructions[i] == 'm' ? move(ptr) : turn(ptr);
    }
    i++;
  }
}

void initializeRobot(ROBOT *ptr, int x, int y, enum DIRECTION dir) {
  ptr->xpos = x;
  ptr->ypos = y;
  ptr->dir = dir;
}

void move (ROBOT *ptr) {
  if (ptr->dir == 0) {//North
    ptr->ypos++;
  }
  if (ptr->dir == 1) {//East
    ptr->xpos++;
  }
  if (ptr->dir == 2) {//South
    ptr->ypos--;
  }
  if (ptr->dir == 3) {//West
    ptr->xpos--;
  }
}

void turn (ROBOT *ptr) {
    ptr->dir++;
    ptr->dir = ptr->dir % 4;
}