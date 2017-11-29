/*
**************************
File Name:	    miensfeldutil.h
Created By:	    Jonah Bobilin
Login:          jbobilin
Team:		        Undercooked Dinosaurs
Date Created:	  26 November 2017
Last Modified:	26 November 2017
Description:	  utility functions, macros, etc. for the Undercooked Dinosaurs's final project in ee160
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>


/*	***  Define Compiler Directives  ***	*/
//#define DEBUG
#define TRUE 1
#define FALSE 0
#define RESTART 3
# define FLUSH   while(getchar() != '\n');


/*	***  Declare Enummerated Types  ***	*/
enum TIM_LOC {TIM_NOT_BEEN, TIM_ON, TIM_BEEN};
typedef enum TIM_LOC TIM_LOC;



/*	***  Declare Prototypes  ***	*/
//note: rn there are no utility functions, if you add one, please write a finalproject.c file to put it in and modify the README.txt file associated with the project to reflect your changes.
