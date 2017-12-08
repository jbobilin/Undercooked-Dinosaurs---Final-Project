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
extern int quit_flag = FALSE;
extern int timmys_location[1];
extern int score_count;
extern int flags_count;
extern int mines_count;
extern enum TIM_LOC timmy_level[7][9];
extern enum Glif display_level[7][9];
extern enum Glif mine_level[7][9];
