/*
**************************
File Name:      gameplay_module.c
Created By:     Jonah Bobilin
Login:          jbobilin
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  9 December 2017
Description:	this file contains the gameplay module, which runs the game.
**************************
*/

/*	***  Call Header Files  ***	*/
#include "main_global.h"
#include "move_module.h"
#include "plant_module.h"
#include "endgame_module.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include "print_shit.h"


/*	***  Functions Workspace  ***	*/

/* Function Name:  gameplay_module
 * I/O:  void / void  
 * Purpose/Notes:  this module runs the game as it is played by the human*/
void gameplay_module(void)
{	
	//set quit_flag to FALSE to make sure the loop is entered
	quit_flag = FALSE;
	
	//while the player has not quit or restarted the program
	while (quit_flag == FALSE)
	{
		#ifdef DEBUG
		printf("\nIn gameplay loop\n");
		#endif

		//declare variables
		char user_input;
		
		//continuous run command line input
		system("/bin/stty raw");
		user_input = getchar();
		system("/bin/stty cooked");

		//switch case for user input
		switch (user_input)
		{
			case 'y':			//move up left
				move_tim(-1, -1);
				break;
			case 'u':			//move up
				move_tim(-1, 0);
				break;
			case 'i':			//move up right
				move_tim(-1, 1);
				break;
			case 'h':			//move left
				move_tim(0, -1);
				break;
			case 'k':			//move right
				move_tim(0, 1);
				break;
			case 'n':			//move down left
				move_tim(1, -1);
				break;
			case 'm':			//move down
				move_tim(1, 0);
				break;
			case ',':			//move down right
				move_tim(1, 1);
				break;
			case 'Y':			//plant up left
				plant_flag(-1, -1);
				break;
			case 'U':			//plant up
				plant_flag(-1, 0);
				break;
			case 'I':			//plant up right
				plant_flag(-1, 1);
				break;
			case 'H':			//plant left
				plant_flag(0, -1);
				break;
			case 'K':			//plant right
				plant_flag(0, 1);
				break;
			case 'N':			//plant down left
				plant_flag(1, -1);
				break;
			case 'M':			//plant down
				plant_flag(1, 0);
				break;
			case '<':			//plant down right
				plant_flag(1, 1);
				break;
			case 'Q':			//run quit_sequence
			case 'q':
				quit_sequence();
			default:
				#ifdef DEBUG
				printf("Invalid entry\n");
				#endif
				break;
		}
		
		#ifdef DEBUG
		print_shit();
		#endif
		
		//auto win if all mines are found
		if(mines_count == 0)
			win();
	}
}
