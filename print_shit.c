/*
**************************
File Name:      print_shit.c
Created By:     Jonah Bobilin
Login:          jbobilin
Team:           Undercooked Dinosaurs
Date Created:   7 December 2017
Last Modified:  7 December 2017
Description:	This is a file designed to debug to meinsfeld game.
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include "main_global.h"

/*	***  Functions Workspace  ***	*/

/* Function Name:  print_shit
 * I/O:  void / void  
 * Purpose/Notes:  this function prints all the global arrays to test if the game is correct*/
void print_shit(void)
{
	//print map of field for reference
        int row, col;
        printf("Coordinate Map\n");
        for (row = 0; row < 8; row++)
        {
		for (col = 0; col < 10; col++)
                {
			printf("%d , %d", row,col);
			printf("\t");
                }
		printf("\n");
        }

	//print the timmy level array
        printf("Timmy Level\n");
	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 10; col++)
		{
			printf("%d", timmy_level[row][col]);
			printf("\t");
		}
		printf("\n");
	}

	//print the display level
	printf("Display Level\n");
	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 10; col++)
		{
			printf("%d", display_level[row][col]);
			printf("\t");
		}
		printf("\n");
	}

	//print the mine level
	printf("Mine Level\n");
	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 10; col++)
		{
			printf("%d", mine_level[row][col]);
			printf("\t");
		}
		printf("\n");
	}

	//print timmy's location
	printf("Timmy's Location:\t");
	printf("(%d, %d)\n", timmys_location[0], timmys_location[1]);
	
	//print scores
	printf("Mines:\t%d", mines_count);
	printf("Flags:\t%d", flags_count);
	printf("Score:\t%d", score_count);
}
