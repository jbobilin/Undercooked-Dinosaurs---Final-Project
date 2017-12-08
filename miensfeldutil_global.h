/*
**************************
File Name:	miensfeldutil_global.h
Created By:	Jonah Bobilin
Login:          jbobilin
Team:		Undercooked Dinosaurs
Date Created:	26 November 2017
Last Modified:	26 November 2017
Description:	utility functions, macros, etc. for the Undercooked Dinosaurs's final project in ee160
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include <string.h>

/*	***  Define Compiler Directives  ***	*/
//#define DEBUG
#define TRUE           1
#define FALSE          0
#define RESTART        3
#define OUT_OF_BOUNDS  4
#define IN_FIELD       5
#define WIN_ZONE       6

/*	***  Declare Enummerated Types  ***	*/
extern enum TIM_LOC {TIM_NOT_BEEN, TIM_ON, TIM_BEEN};
extern typedef enum TIM_LOC;


/*	***  Messages Library  ***	*/
char error_move[25] = “
char error_flag[25] = “Cannot place a flag there\n you’ll lose it”;
Play_again[25] = “Play again? \nWe’re gonna need another Timmy!”;


/*	***  Declare Prototypes  ***	*/
//note: rn there are no utility functions, if you add one, please write a finalproject.c file to put it in and modify the README.txt file associated with the project to reflect your changes.
