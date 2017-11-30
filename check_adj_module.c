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
#include <stdio.h>

/*	***  Functions Workspace  ***	*/

/* Function Name:  adj
 * I/O:  int row, int column /  int
 * Purpose/Notes:  This function is given a cell on the playing field and calculates the mines in all adjacent tiles*/
int adj(int row, int column)
{
    int count=0;
    if (Glif MINE == mine_level[row - 1, column - 1])
        count++;
    if (Glif MINE == mine_level[row - 1, column])
        count++;
    if (Glif MINE == mine_level[row - 1, column + 1])
        count++;
    if (Glif MINE == mine_level[row, column - 1])
        count++;
    if (Glif MINE == mine_level[row, column + 1])
        count++;
    if (Glif MINE == mine_level[row + 1, column - 1])
        count++;
    if (Glif MINE == mine_level[row + 1, column])
        count++;
    if (Glif MINE == mine_level[row + 1, column + 1])
            count++;
 
    return count;
}
