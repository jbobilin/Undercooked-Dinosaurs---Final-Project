/*
**************************
File Name:	check_out_of_grid_module.c
Created By:	Jonah Bobilin
Login:          jbobilin
Team:		Undercooked Dinosaurs
Date Created:	26 November 2017
Last Modified:	1 December 2017
Description:	This function is given a row and column and checks if the cell is within the playing area it returns
		OUT_OF_BOUNDS
		IN_FIELD
		WIN_ZONE
**************************
*/

/*	***  Call Header Files  ***	*/
#include "miensfeldutil_global.h"
#include "main_global.h"

/*	***  Functions Workspace  ***	*/
int check_out_of_grid(int row, int column)
{
	// if column is within farest right column, return WIN_ZONE
	if (column == 10)
		return WIN_ZONE;

	// check if row or column has an out of bounds value, if so return OUT_OF_BOUNDs
	if (row < 0 || column < 0 || row > 7 || column > 9)
		return OUT_OF_BOUNDS;
	
	
	//otherwise return that cell is IN-FIELD
	else
		return IN_FIELD;
}
