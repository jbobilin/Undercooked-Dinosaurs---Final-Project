/*
**************************
File Name:	miensfeldutil.h
Created By:	Jonah Bobilin
Login:          jbobilin
Team:		Undercooked Dinosaurs
Date Created:	26 November 2017
Last Modified:	1 December 2017
Description:	utility functions, macros, etc. for the Undercooked Dinosaurs's final project in ee160
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include <string.h>

/*	***  Define Compiler Directives  ***	*/
#define	TRUE           1
#define FALSE          0
#define RESTART        3
#define OUT_OF_BOUNDS  4
#define IN_FIELD       5
#define WIN_ZONE       6

/*	***  Declare Enummerated Types  ***	*/
//user defined type for timmy_level array
enum TIM_LOC {TIM_NOT_BEEN, TIM_ON, TIM_BEEN};
typedef enum TIM_LOC TIM_LOC;
