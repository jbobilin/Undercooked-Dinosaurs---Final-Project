/*
**************************
File Name:      main_global.h
Created By:     Thomas Yang
Login:          thomasy4
Team:           Undercooked Dinosaurs
Date Created:   30 November 2017
Last Modified:  30 November 2017
Description:    This is the header file for the main module for the Miensfeld game.
**************************
*/

/*	***  Define Compiler Directives  ***	*/
//#define DEBUG

/*	***  Declare Global Variables  ***	*/
extern int quit_flag;
extern int timmys_location[2];
extern int score_count;
extern int flags_count;
extern int mines_count;
extern enum TIM_LOC timmy_level[8][10];
extern int display_level[8][10];
extern int mine_level[8][10];
