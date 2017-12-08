/*
**************************
File Name:      move_module.c
Created By:     Thomas Yang
Login:          thomasy4
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  3 December 2017
Description:	  
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include "main_global.h"
#include "miensfeldutil.h"
 
/*	***  Define Compiler Directives  ***	*/
//#define DEBUG


/*	***  Functions Workspace  ***	*/
    
void move(int a, int b)
{

        int temp_row, temp_col, adjacent;
        temp_row = timmys_location[0] + a;
        temp_col = timmys_location[1] + b;

        if (check_out_of_grid(temp_row, temp_col) == OUT_OF_BOUNDS)
                write_message(15, "You can’t move there!");
        else if (check_out_of_grid(temp_row, temp_col) == WIN_ZONE)
                win();
        else if (check_out_of_grid(temp_row, temp_col) == IN_FIELD)
        {
                switch ( mine_level[temp_row][temp_col])
                {
                        case MINE:
                        case FL_MINE:
                                death();
                                break;
                        case SAFE:
                        case FLAG:
                                if(timmy_level[temp_row][temp_col] == TIM_NOT_BEEN)
                                {
                                score_count++; 
                                update_score(score_count);
                                }
                                timmy_level[timmys_location[0], timmys_location[1]] = TIM_BEEN;
                                timmy_level[temp_row][temp_col] = TIM_ON;
                                adjacent = adj(temp_row, temp_col);
                                if (mine_level[timmys_location[0]][timmys_location[1]] == FLAG)
                                {
                                        show_glif(Glif FLAG, temp_row, temp_col, 0);
                                        display_level[timmys_location[0]][timmys_location[1]] = FLAG;
                                }
                                if (mine_level[timmys_location[0]][timmys_location[1]] == SAFE)
                                {
                                        show_glif(Glif SAFE, temp_row, temp_col, adj);
                                        display_level[timmys_location[0]][timmys_location[1]] = SAFE;
                                }
                                show_glif(Glif TIMMY, temp_row, temp_col, adj);
                                display_level[temp_row][temp_col] = TIMMY;

                                timmys_location[0] += a;
                                timmys_location[1] += b;
                                break;
                        default:
                                write_message("15, Error! The program messed up\n");
                                break;
                }
        }
}


/* Function Name:  
 * I/O:  /  
 * Purpose/Notes:  */

