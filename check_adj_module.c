/*
**************************
File Name:      check_adj_module.c
Created By:     Jonah Bobilin
Login:          jbobilin
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  30 November 2017
Description:	  This file contains the function adj.
**************************
*/

/*	***  Call Header Files  ***	*/
#include "miensfeldutil.h"
#include "display.h"

/*	***  Functions Workspace  ***	*/

/* Function Name:  adj
 * I/O:  int row, int column /  int
 * Purpose/Notes:  This function is given a cell on the playing field and calculates the mines in all adjacent tiles*/
int adj(int row, int column)
{
	//declare and initialize count variable
	int count = 0;    /* variable to count mines in a adjacent tiles */
    
	if (Glif MINE == mine_level[row - 1][column - 1])	//check up left cell for mine
		count++;
	if (Glif MINE == mine_level[row - 1]][column])		//check up cell for mine
		count++;
	if (Glif MINE == mine_level[row - 1][column + 1])	//check up right cell for mine
		count++;
	if (Glif MINE == mine_level[row][column - 1])		//check left cell for mine
		count++;
	if (Glif MINE == mine_level[row][column + 1])		//check right cell for mine
		count++;
	if (Glif MINE == mine_level[row + 1][column - 1])	//check down left cell for mine
		count++;
	if (Glif MINE == mine_level[row + 1][column])		//check down cell for mine
		count++;
	if (Glif MINE == mine_level[row + 1][column + 1])	//check down right cell for mine
		count++;
 
	//return total mines counted in adjacent cells
	return count;
}
