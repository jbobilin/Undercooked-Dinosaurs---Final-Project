/*
**************************
File Name:      move_module.c
Created By:     Thomas Yang
Login:          thomasy4
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  3 December 2017
Description:	this file contains the move_tim functions, which moves Timmy.
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include "main_global.h"
#include "display.h"
#include "check_out_of_grid_module.h" 
#include "endgame_module.h"
#include "check_adj_module.h"
#include "print_shit.h"
#include "miensfeldutil.h"

/*	***  Functions Workspace  ***	*/  

/* Function Name:  move_tim
 * I/O:  int a, int b / void
 * Purpose/Notes:  This function moves Timmy in the passed direction (a = row, b = column) if the move is valid, and updates the scores*/
void move_tim(int a, int b)
{
	//declare variables
        int temp_row, temp_col, adjacent, adjtim;
	
	//clear write area
	write_message(14,"");
	write_message(15,"");
	write_message(16,"");
	
	//assign to temp variables the coordinates of the cell the user wants to move to
        temp_row = timmys_location[0] + a;
        temp_col = timmys_location[1] + b;
	
	//check if cell is in the win zone
	if (check_out_of_grid(temp_row, temp_col) == WIN_ZONE)
	{
		//update score and run win sequence
		score_count += 10;
		update_score(score_count);
		win();
	}

	//check if cell is out of bounds
        else if (check_out_of_grid(temp_row, temp_col) == OUT_OF_BOUNDS)
	{
		#ifdef DISPLAY
                write_message(15, "You can't move there!");
		#else
		printf("Why are you trying to walk off the game field? Dafuk!\n");
		#endif
	}
	
	//if cell is inside of the gameplay area
        else if (check_out_of_grid(temp_row, temp_col) == IN_FIELD)
        {
		//check the mine_level array for the Glif stored at coordinate
                switch ( mine_level[temp_row][temp_col])
                {
			//if mine is there then run death sequence
                        case MINE:
                        case FL_MINE:
                                death();
                                break;
			//if a safe cell or a flagged cell
                        case SAFE:
                        case FLAG:
                                //if timmy has not yet been to this cell
				if(timmy_level[temp_row][temp_col] == TIM_NOT_BEEN)
                                {	
					//update score
					score_count++;
					#ifdef DISPLAY
                                	update_score(score_count);
					#endif
                                }
				
				//assign cells in timmy_level array their new values
                                timmy_level[timmys_location[0]][timmys_location[1]] = TIM_BEEN;
                                timmy_level[temp_row][temp_col] = TIM_ON;
				
				//check for mines in adjacent cells
                                adjacent = adj(temp_row, temp_col);
				
				//check for mines around the cell timmy used to be on
				adjtim = adj(timmys_location[0], timmys_location[1]);
				
				//if cell timmy used to be on was previously flagged the make it display a flag on display level
                                if (mine_level[timmys_location[0]][timmys_location[1]] == FLAG)
                                {
					#ifdef DISPLAY
                                        show_glif(FLAG, timmys_location[0], timmys_location[1], adjtim);
					#endif
                                        display_level[timmys_location[0]][timmys_location[1]] = FLAG;
                                }
				
				//if cell timmy used to be on was previously safe then make it display a safe tile with the correct number of adjacent mines
                                if (mine_level[timmys_location[0]][timmys_location[1]] == SAFE)
                                {
					#ifdef DISPLAY
                                        show_glif(SAFE, timmys_location[0], timmys_location[1], adjtim);
					#endif
                                        display_level[timmys_location[0]][timmys_location[1]] = SAFE;
                                }

			
				//move timmy on the display level
				#ifdef DISPLAY
                                show_glif(TIMMY, temp_row, temp_col,adjacent);
				#endif
				display_level[temp_row][temp_col] = TIMMY;

				//assign to timmys_location array the correct new coordinates
                                timmys_location[0] += a;
                                timmys_location[1] += b;
                                break;
                        default:
                                #ifdef DISPLAY
				write_message(15, "Error! The program messed up\n");
                                #else
				printf("Error The program fucked up\n");
				#endif
				break;
                }
        }
}
