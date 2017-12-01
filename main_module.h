/*
**************************
File Name:      main_module.h
Created By:     Jonah Bobilin
Login:          jbobilin
Team:           Undercooked Dinosaurs
Date Created:   30 November 2017
Last Modified:  30 November 2017
Description:    This is the header file for the main module for the Miensfeld game.
**************************
*/

/*	***  Define Compiler Directives  ***	*/
//#define DEBUG

/*	***  Declare Global Variables  ***	*/
int quit_flag = FALSE;
int timmys_location[1];
int score_count;
int flags_count;
int mines_count;
enum TIM_LOC timmy_level[7][9];
enum Glif display_level[7][9];
enum Glif mine_level[7][9];
