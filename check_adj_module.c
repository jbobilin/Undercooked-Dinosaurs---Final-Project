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

#include "display.h"
#include "main_global.h"
#include "miensfeldutil_global.h"
#include "check_out_of_grid_module.h"
/*	***  Functions Workspace  ***	*/

/* Function Name:  adj
 * I/O:  int row, int column /  int
 * Purpose/Notes:  This function is given a cell on the playing field and calculates the mines in all adjacent tiles*/
int adj(int row, int column)
{
	//declare and initialize count variable
	int count = 0;    /* variable to count mines in a adjacent tiles */
    	if (check_out_of_grid(row - 1, column - 1) != OUT_OF_BOUNDS && row > 1 && column > 0)
	{
		if (MINE == mine_level[row - 1][column - 1] || FL_MINE == mine_level[row - 1][column - 1])	//check up left cell for mine
			count++;
	}

	if (check_out_of_grid(row - 1, column) != OUT_OF_BOUNDS && row > 0)
	{
		if (MINE == mine_level[row - 1][column] || FL_MINE == mine_level[row - 1][column])		//check up cell for mine
			count++;
	}
	if (check_out_of_grid(row - 1, column + 1) != OUT_OF_BOUNDS && row > 0 && column < 9)
	{
		if (MINE == mine_level[row - 1][column + 1] || FL_MINE == mine_level[row - 1][column + 1])	//check up right cell for mine
			count++;
	}

	if (check_out_of_grid(row, column - 1) != OUT_OF_BOUNDS && column > 0)
	{
		if (MINE == mine_level[row][column - 1] || FL_MINE == mine_level[row][column - 1])		//check left cell for mine
			count++;
	}

	if (check_out_of_grid(row, column + 1) != OUT_OF_BOUNDS && column < 9)
	{
		if (MINE == mine_level[row][column + 1] || FL_MINE == mine_level[row][column + 1])		//check right cell for mine
			count++;
	}

	if (check_out_of_grid(row + 1, column - 1) != OUT_OF_BOUNDS && row < 7 && column > 0)
	{
		if (MINE == mine_level[row + 1][column - 1] || FL_MINE == mine_level[row + 1][column - 1])	//check down left cell for mine
			count++;
	}

	if (check_out_of_grid(row + 1, column) != OUT_OF_BOUNDS && row < 7)
	{
		if (MINE == mine_level[row + 1][column] || FL_MINE == mine_level[row + 1][column])		//check down cell for mine
			count++;
	}

	if (check_out_of_grid(row + 1, column + 1) != OUT_OF_BOUNDS && row < 7 && column < 9)
	{
		if (MINE == mine_level[row + 1][column + 1] || FL_MINE == mine_level[row + 1][column + 1])	//check down right cell for mine
			count++;
	}
 
	//return total mines counted in adjacent cells
	return count;
}
