/*
**************************
File Name:      endgame_module.c
Created By:     Lian Huang
Login:          lian7
Team:           Undercooked Dinosaurs
Date Created:   8 December 2017
Last Modified:  8 December 2017
Description:	this file contains the functions used if the play wins or looses, and then runs a sequence to quit.
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main_global.h"
#include "display.h"
#include "check_adj_module.h"
#include "miensfeldutil_global.h"
#include "endgame_module.h"


/*	***  Functions Workspace  ***	*/

/* Function Name:  death
 * I/O:  void / void
 * Purpose/Notes:  This function runs the animation and message printing if Timmy dies*/
void death(void)
{
	#ifdef DISPLAY
		//declare variables
		int i, j;
	
		//clear write area
		write_message(12, "");
		write_message(13, "");
		write_message(14, "");
		write_message(15, "");
		write_message(16, "");

		//show mines
		for(i=0; i<8; i++)
		{
			for(j=0; j<10; j++)
			{
				if(mine_level[i][j] == MINE)
				{
					show_glif(MINE,i,j,0);
				}
			}
		}

		//show Timmy's death
		show_glif(EXPLODE,timmys_location[0],timmys_location[1],0);
	
		//print death message
		write_message(12, "We're gonna need");
		write_message(13, "another Timmy!");
	#endif

	#ifdef DEBUG
	printf("\nHe died, meh life is pointless and meaningless\nand you have to do projects like this so Timmy\nprobably got the better end of the deal anyway\n");
	#endif
	
	//run quit_sequence
	quit_sequence();
}


/* Function Name:  win
 * I/O:  void / void
 * Purpose/Notes:  This function runs the animation and message printing if the player wins*/
void win(void)
{
	#ifdef DISPLAY
		//declare variables
		int i, j, adjacent;

		//clear write area
		write_message(12, "");
		write_message(13, "");
		write_message(14, "");
		write_message(15, "");
		write_message(16, "");

		//show mines
		for(i=0; i<8; i++)
		{
			for(j=0; j<10; j++)
			{
				if(mine_level[i][j] == MINE)
				{
					show_glif(MINE,i,j,0);
				}
			}
		}

		//show Timmy is safe
		adjacent = adj(timmys_location[0],timmys_location[1]);
		show_glif(SAFE,timmys_location[0],timmys_location[1],adjacent);
	
		//write win message
		write_message(12, "Cognratuations!");
		write_message(13, "You won!");
	#endif
	
	#ifdef DEBUG
	printf("\nYou won, yay we are so fucking pleased\n");
	#endif

	//run quit_sequence
	quit_sequence();
}


/* Function Name:  quit_sequence
 * I/O:  void / void
 * Purpose/Notes:  This function asks the user if they want to play again and responds accordingly*/
void quit_sequence(void)
{
	//declare variables
	char ch;

	//clear write area
	write_message(12, "");
	write_message(13, "");
	write_message(14, "");
	write_message(15, "");
	write_message(16, "");

  	//ask if user wants to play again
	#ifdef DEBUG
	printf("\nPlay again bitch?\n");
	#endif
	
	#ifdef DISPLAY
	write_message(15, "Do you want to"); 
	write_message(16, "play again?");
	write_message(17, "(type Y for yes,");
	write_message(18, " and N for no)\n");
	#endif		

	//while user has not yet entered a valid answer
	while(TRUE)
	{
		//continuous run command line input
		system("/bin/stty raw");
		ch = getchar();
		system("/bin/stty cooked");

		//if yes restart game
		if(ch == 'y' || ch == 'Y')
		{
			quit_flag = RESTART;
			break;
		}
		
		//if no the quit
		if(ch == 'n' || ch == 'N')
		{
			quit_flag = TRUE;
			break;
		}
	}
}
