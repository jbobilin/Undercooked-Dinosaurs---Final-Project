/*
**************************
File Name:      plant_module.c
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

        if (check_out_of_grid(temp_row, temp_col) == OUT_OF_BOUNDS || check_out_of_grid(temp_row, temp_col) == WIN_ZONE)
                write_message(15, "You can’t plant there!");
       
        else if (check_out_of_grid(temp_row, temp_col) == IN_FIELD)
        {
                switch ( mine_level[temp_row][temp_col])
                {
                        case MINE:
                                score_count += 2;
                                update_score(score_count);
                                flags_count--;
                                update_flags(flags_count);
                                mines_count--;
                                update_mines(mines_count);
                                display_level[temp_row][temp_col] == FL_MINE;
                                mine_level[temp_row][temp_col] == FL_MINE;
                                show_glif(FL_MINE,temp_row,temp_col,0);
                                break;
                        case FL_MINE:
                                write_message(15, "You can’t plant there!");
                                break;
                        case SAFE:
                                score_count--;
                                update_score(score_count);
                                flags_count--;
                                update_flags(flags_count);
                                display_level[temp_row][temp_col] == FLAG;
                                mine_level[temp_row][temp_col] == FLAG;
                                show_glif(FLAG,temp_row,temp_col,0);
                                break;
                  
                        case FLAG:
                                write_message(15, "You can’t plant there!");
                                break;
                }
        }
}
