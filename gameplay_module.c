/*
**************************
File Name:      gameplay_module.c
Created By:     Jonah Bobilin
Login:          jbobilin
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  26 November 2017
Description:	  
**************************
*/

/*	***  Call Header Files  ***	*/
#include "miensfeldutil.h"
#include "main_module.h"
#include "move_module.h"
#include "plant_module.h"
#include "endgame_module.h"

/*	***  Define Compiler Directives  ***	*/
//#define DEBUG


/*	***  Functions Workspace  ***	*/

/* Function Name:  gameplay_module
 * I/O:  void / void  
 * Purpose/Notes:  this module runs the game as it is played by the human*/
void gameplay_module(void)
{
	// while the player has quit or restarted the program
	while (quit_flag == FALSE)
	{
		// declare variable for user input and get input from user
		char user_input;
		user_input = getchar();
		
		//switch case for user input
		switch (user_input)
		{
			case 'y':			//move up left
				move(-1, -1);
				break;
			case 'u':			//move up
				move(-1, 0);
				break;
			case 'i':			//move up right
				move(-1, 1);
				break;
			case 'h':			//move left
				move(0, -1);
				break;
			case 'k':			//move right
				move(0, 1);
				break;
			case 'n':			//move down left
				move(1, -1);
				break;
			case 'm':			//move down
				move(1, 0);
				break;
			case ',':			//move down right
				move(1, 1);
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
				plant_flaf(0, -1);
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
				plant_flag(1, 1)
				break;
			case 'Q':			//run quit_sequence
			case 'q':
				quit_sequence();
			default:
		}
		
		//flush buffer
		while(getchar() != '\n');
	}
}
