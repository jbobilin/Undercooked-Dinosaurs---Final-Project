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
#include "display.h"
#include "check_out_of_grid_module.h" 
#include "endgame_module.h"
#include "check_adj_module.h"
#include "print_shit.h"
#include "miensfeldutil.h"

/*	***  Functions Workspace  ***	*/    
void move_tim(int a, int b)
{

        int temp_row, temp_col, adjacent, adjtim;
	write_message(14,"");
	write_message(15,"");
	write_message(16,"");
        temp_row = timmys_location[0] + a;
        temp_col = timmys_location[1] + b;
	if (check_out_of_grid(temp_row, temp_col) == WIN_ZONE)
	{
	score_count += 10;
	update_score(score_count);
	win();
	}
        else if (check_out_of_grid(temp_row, temp_col) == OUT_OF_BOUNDS)
	{
		#ifdef DISPLAY
                write_message(15, "You can't move there!");
		#else
		printf("Why are you trying to walk off the game field? Dafuk!\n");
		#endif
	}
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
				#ifdef DISPLAY
                                update_score(score_count);
				#endif
                                }
                                timmy_level[timmys_location[0]][timmys_location[1]] = TIM_BEEN;
                                timmy_level[temp_row][temp_col] = TIM_ON;
                                adjacent = adj(temp_row, temp_col);
				adjtim = adj(timmys_location[0], timmys_location[1]);
                                if (mine_level[timmys_location[0]][timmys_location[1]] == FLAG)
                                {
					#ifdef DISPLAY
                                        show_glif(FLAG, timmys_location[0], timmys_location[1], adjtim);
					#endif
                                        display_level[timmys_location[0]][timmys_location[1]] = FLAG;
                                }
                                if (mine_level[timmys_location[0]][timmys_location[1]] == SAFE)
                                {
					#ifdef DISPLAY
                                        show_glif(SAFE, timmys_location[0], timmys_location[1], adjtim);
					#endif
                                        display_level[timmys_location[0]][timmys_location[1]] = SAFE;
                                }

				#ifdef DISPLAY
                                show_glif(TIMMY, temp_row, temp_col,adjacent);
				#endif

                                display_level[temp_row][temp_col] = TIMMY;

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
