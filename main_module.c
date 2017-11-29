/*
**************************
File Name:      main_module.c
Created By:     Jonah Bobilin
Login:          jbobilin
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  26 November 2017
Description:	  
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include "display.h"
#include "starting_configuration_module.h"
#include "gameplay_module.h"
#include "miensfeldutil.h"

/*	***  Define Compiler Directives  ***	*/
//#define DEBUG

/*	***  Declare Global Variables  ***	*/
int quit_flag = FALSE;
enum TIM_LOC timmy_level[8][10];
enum Glif display_level[8][10];
enum Glif mine_level[8][10];

/*	***  Declare Prototypes  ***	*/
void print_title1(void);
void main_menu(void);
void print_menu_choices(void);
void print_move(void);
void print_flags(void);
void print_points(void);
void print_level_choices(void);
int choose_level(void);


/*	***  Main Code  ***	*/
int main(void)
{	
	// declare initialize variables
	int level;

	while(quit_flag == FALSE || quit_flag == RESTART)
	{
		print_title1();
		main_menu();
			if (quit_flag == TRUE)
				break;
		
		level = choose_level();
			if (quit_flag == TRUE)
				break;

		starting_configuration_module(level);
		
		gameplay_module();
	}	
	
	void clear_screen(void);
}


/*	***  Functions Workspace  ***	*/
void main_menu()
{
	int invalid_sel_flag = TRUE;
	print_menu_choices();
	while (invalid_sel_flag == TRUE)
	{
		char menu_sel;
		print_menu_choices();
		menu_sel = getchar();
		switch (menu_sel)	
		{
			case ('1'):
				print_move();
				break;
			case ('2'):
				print_flags();
				break;
			case ('3'):
				print_points();
				break;
			case ('4'):
				invalid_sel_flag = FALSE;
				break;
			case ('q'):				
			case ('Q'):
				quit_flag = TRUE;
				break;
			default:
				printf("Error: invalid selection, please try again\n");
				break;
		}
	}
}

void print_title1(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("				 WELCOME\n");
	printf("				   to\n");
	printf("				Miensfeld\n\n");
	printf("\tYou are about to be placed in grave danger. You are being sent\n");
	printf("\tinto the Miensfeld, a field full of mines.  Your mission is to\n");
	printf("\tfind your way to the other side without blowing yourself up, and\n");
	printf("\tmap the field in the process. Your predecessors have already mapped\n");
	printf("\tpart of the field for you before meeting their untimely ends.  You\n");
	printf("\tdo have a few tools to help you.  Your proximity probe will \n");
	printf("\tdisplay how many mines are in your immediate area as you step into\n");
	printf("\teach grid on the field.  You also carry a set of flags you can \n");
	printf("\tplant to show grids where you suspect there might be a mine.  For\n");
	printf("\tmore information, or to begin, choose from the menu below:\n");
}

void print_menu_choices(void)
{
	printf("\n\n\n");
	printf("\t1)\tto find how to move about\n");
	printf("\t2)\tto find how to plant flags\n");
	printf("\t3)\tto see how to earn points\n");
	printf("\t4)\tto start play\n");
	printf("\tq)\tquit\n\n:");
}

void print_move(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("			       Moving About\n\n");
	printf("	You can move about the field in any of eight directions from\n");
	printf("	your current position by using the keys centered around the 'j'\n");
	printf("	key:\n\n");
	printf("				y | u | i\n");
	printf("				--|---|--\n");
	printf("				h |   | k\n");
	printf("				--|---|--\n");
	printf("				n | m | ,\n\n");
	printf("	However, you will not be allowed to leave the field except from\n");
	printf("	the far right edge.\n");
}

void print_flags(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("	       			Planting Flags\n\n");
	printf("	You can plant one of your flags in any of eight directions from\n");
	printf("	your current position by using the shifted keys centered around\n");
	printf("	the \'J\' key:\n\n");
	printf("				Y | U | I\n");
	printf("				--|---|--\n");
	printf("				H |   | K\n");
	printf("				--|---|--\n");
	printf("				N | M | <\n\n");
	printf("	You will receive 2 points if you plant a flag on a mine, but you\n");
	printf("	will lose 1 point (and the flag) if you plant it in an empty grid.\n");
}

void print_points(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("	       			Earning Points\n\n");
	printf("	You earn 1 point for each new \"SAFE\" grid you identify by stepping\n");
	printf("	through it.  You also get a bonus of 10 points for making it\n");
	printf("	through the miensfeld by stepping out on the far right.  You also\n");
	printf("	can earn points for flags. You get 2 points for correctly flagging\n");
	printf("	a mine, but you lose 1 point for incorrectly flagging a \"SAFE\" grid.\n\n");
	printf("	The game ends when you either blow up :-( or safely make it out of\n");
	printf("	the miensfeld on the far right :-) or when you successfully flag\n");
	printf("	all mines.\n");
}

int choose_level(void)
{
	print_level_choices();

	while (TRUE)
	{
		char menu_sel;
		menu_sel = getchar();
		switch (menu_sel)	
		{
			case ('1'):
				return 1;
			case ('2'):
				return 2;
			case ('3'):
				return 3;
			case ('4'):
				return 4;
			case ('q'):				
			case ('Q'):
				quit_flag = TRUE;
				return 0;
			default:
				printf("Error: invalid selection, please try again\n");
				break;
		}
	}
}
void print_level_choices(void)
{
	printf("\n\n\n");
	printf("\t1)\tEasy\n");
	printf("\t2)\tModerate\n");
	printf("\t3)\tHard\n");
	printf("\t4)\tImpossible\n");
	printf("\tq)\tquit\n\n:");
}
