/*
**************************
File Name:      main_module.c
Created By:     Jonah Bobilin
Login:          jbobilin
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  9 December 2017
Description:	This is the main module for the Miensfeld game. It contains all the menus used to set up the game as well as the main function which runs the game.
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "display.h"
#include "main_module.h"
#include "starting_configuration_module.h"
#include "gameplay_module.h"
#include "print_shit.h"
#include "miensfeldutil_global.h"


/*	***  Declare Prototypes  ***	*/
void intro(void);		/* prints intro screen */
void print_title1(void);	/* prints program title block */
void main_menu(void);		/* runs main menu */
void print_menu_choices(void);	/* prints main menu options */
void print_move(void);		/* prints move directions */
void print_flags(void);		/* prints flag planting directions */
void print_points(void);	/* prints earning points directions */
void print_level_choices(void);	/* prints level selection menu options */
int choose_level(void);		/* runs level selection menu */


/*	***  Main Code  ***	*/
int main(void)
{	
	//declare and initialize variables
	int level;
	quit_flag = FALSE;

	//print intro screen		
	intro();

	//while loop to restart game until player wants to quit
	while(quit_flag == FALSE || quit_flag == RESTART)
	{
		//run main_menu and check if player wants to quit
		main_menu();
			if (quit_flag == TRUE)
				break;
		
		//run choose_level and check if player wants to quit, assign to level variable
		level = choose_level();
			if (quit_flag == TRUE)
				break;
		
		//run starting configuration module with level selected by user
		starting_configuration_module(level);
	
		//run gameplay module until user wins, looses, or chooses to quit
		gameplay_module();
		
		//clear tep's display
		clear_screen();
	}

	//clear the console screen
	system("clear");
}


/*	***  Functions Workspace  ***	*/

/* Function Name: intro
 * I/O:  void / void  
 * Purpose/Notes:  this function runs the intro screen for the program. */
void intro(void)
{	
	//clear the console screen
	system("clear");
	
	//animated chase sequence for title and credit sub-title
	printf("\n\n\n");
	usleep(400000);
	printf("\t     ███╗   ███╗██╗███████╗███╗   ██╗███████╗███████╗███████╗██╗     ██████╗\n");
	usleep(400000);
	printf("\t     ████╗ ████║██║██╔════╝████╗  ██║██╔════╝██╔════╝██╔════╝██║     ██╔══██╗\n");
        usleep(400000);
	printf("\t     ██╔████╔██║██║█████╗  ██╔██╗ ██║███████╗█████╗  █████╗  ██║     ██║  ██║\n");
        usleep(400000);
	printf("\t     ██║╚██╔╝██║██║██╔══╝  ██║╚██╗██║╚════██║██╔══╝  ██╔══╝  ██║     ██║  ██║\n");
        usleep(400000);
	printf("\t     ██║ ╚═╝ ██║██║███████╗██║ ╚████║███████║██║     ███████╗███████╗██████╔╝\n");
        usleep(400000);
	printf("\t     ╚═╝     ╚═╝╚═╝╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝     ╚══════╝╚══════╝╚═════╝\n");

	printf("\n\n\n\n");
        usleep(400000);
	printf("\t             __  ___    ___     __  __  ___ __     __       ___    ___\n");
        usleep(400000);
	printf("\t            |  \\|__\\  /|__ |   /  \\|__)|__ |  \\   |__)\\ /    ||__||__\n");
        usleep(400000);
	printf("\t            |__/|___\\/ |___|___\\__/|   |___|__/   |__) |     ||  ||___\n");
        usleep(400000);
	printf("\n\n");
	printf("\t          __  ___ __  __  __  __      ___ __     __       __  __          __  __\n");
        usleep(400000);
	printf("\t |  ||\\ ||  \\|__ |__)/  `/  \\/  \\|__/|__ |  \\   |  \\||\\ |/  \\/__` /\\ |  ||__)/__` \n");
        usleep(400000);
	printf("\t \\__/| \\||__/|___|  \\\\__,\\__/\\__/|  \\|___|__/   |__/|| \\|\\__/.__//~~\\\\__/|  \\.__/\n"); 
	printf("\n\n\n\n\n");
	usleep(2500000);
}

/* Function Name:  main_menu
 * I/O:  void / void  
 * Purpose/Notes:  this function runs the main menu for the program. */
void main_menu(void)
{
	//declare and initialize variables
	int invalid_sel_flag = TRUE;		/* flag to check if user selected a valid menu option */

	//while user has not selected an item on the menu correctly
	while (invalid_sel_flag == TRUE)
	{
		//delcare variable for user input
		char menu_sel;

		//print titles
		print_title1();
		print_menu_choices();
		
		//get user selection
		menu_sel = getchar();

		//switch statement for menu
		switch (menu_sel)	
		{
			//if user enters 1, display directions for moving until user hits enter
			case '1':
				print_move();
				getchar();
				while(getchar() != '\n');
				break;

			//if user enters 2, display directions for flag planting until user hits enter
			case '2':
				print_flags();
				getchar();
				while(getchar() != '\n');
				break;

			//if user enters 3, display directions for earning points until user hits enter
			case '3':
				print_points();
				getchar();
				while(getchar() != '\n');
				break;

			//if user enters 4, break out of menu
			case '4':
				invalid_sel_flag = FALSE;
				while(getchar() != '\n');
				break;

			//if user enter q or Q, break out of menu make program quit
			case 'q':				
			case 'Q':
				quit_flag = TRUE;
				invalid_sel_flag = FALSE;
				break;
			default:
				break;
		}
	}
}

/* Function Name:  print_title1
 * I/O:  void / void  
 * Purpose/Notes:  print the welcome/title for Miensfeld on new screen. */
void print_title1(void)
{
	//clear the console screen
	system("clear");
	
	//print title1
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
        printf("\tmore information, or to begin, choose from the menu below. You may\n");
        printf("\tpress \"q\" at any time to exit this program.\n");
}

/* Function Name:  print_menu_choices
 * I/O:  void / void  
 * Purpose/Notes:  print the main menu. */
void print_menu_choices(void)
{
	//print the main menu choices
	printf("\n\n");
	printf("\t1)\tto find how to move about\n");
	printf("\t2)\tto find how to plant flags\n");
	printf("\t3)\tto see how to earn points\n");
	printf("\t4)\tto start play\n");
	printf("\tq)\tto quit\n\n");
}

/* Function Name:  print_move
 * I/O:  void / void  
 * Purpose/Notes:  print directions for moving on new screen. */
void print_move(void)
{
	//clear the console screen
	system("clear");
	
	//print move directions
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
	printf("\n\n\tHit ENTER to return to the main menu.\n");
}

/* Function Name:  print_flags
 * I/O:  void / void  
 * Purpose/Notes:  print directions for planting flags on new screen. */
void print_flags(void)
{
	//clear the console screen
	system("clear");
	
	//print planting flags directions
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
	printf("\n\n\tHit ENTER to return to the main menu.\n");
}

/* Function Name:  print_points
 * I/O:  void / void  
 * Purpose/Notes:  print directions for earning points on new screen. */
void print_points(void)
{
	//clear the console screen
	system("clear");
	
	//print earning points directions
	printf("	       			Earning Points\n\n");
	printf("	You earn 1 point for each new \"SAFE\" grid you identify by stepping\n");
	printf("	through it.  You also get a bonus of 10 points for making it\n");
	printf("	through the miensfeld by stepping out on the far right.  You also\n");
	printf("	can earn points for flags. You get 2 points for correctly flagging\n");
	printf("	a mine, but you lose 1 point for incorrectly flagging a \"SAFE\" grid.\n\n");
	printf("	The game ends when you either blow up :-( or safely make it out of\n");
	printf("	the miensfeld on the far right :-) or when you successfully flag\n");
	printf("	all mines.\n");
	printf("\n\n\tHit ENTER to return to the main menu.\n");
}

/* Function Name:  choose_level
 * I/O:  void / int  
 * Purpose/Notes:  this function runs the sub menu which is used to select a level. */
int choose_level(void)
{
	//infinite while loop until user makes a valid selection on the menu
	while (TRUE)
	{
		//delcare variable for user input
		char menu_sel;
		
		//print levels
		print_level_choices();
		
		//get user selection
		menu_sel = getchar();
		
		//switch statement for menu
		switch (menu_sel)	
		{
			//if user selects 1, return 1
			case '1':
				return 1;
				
			//if user selects 2, return 2
			case '2':
				return 2;

			//if user selects 3, return 3
			case '3':
				return 3;
				
			//if user selects 4, return 4
			case '4':
				return 4;
			
			//if user enter q or Q, break out of function and make program quit
			case 'q':				
			case 'Q':
				quit_flag = TRUE;
				return 0;
			default:
				break;
		}
	}
}

/* Function Name:  print_level_choices
 * I/O:  void / void  
 * Purpose/Notes:  print the level selection menu. */
void print_level_choices(void)
{
	//clear the console screen
	system("clear");
	
	//print level selection menu
	printf("Please choose a level:\n");
	printf("\n\n");
	printf("\t1)\tEasy\n");
	printf("\t2)\tModerate\n");
	printf("\t3)\tHard\n");
	printf("\t4)\tImpossible\n");
	printf("\tq)\tto quit\n\n");
}
