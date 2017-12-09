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
#include "check_adj_module.h"
#include "check_out_of_grid_module.h"
#include "display.h"
#include "print_shit.h"
#include "miensfeldutil_global.h"

/*	***  Functions Workspace  ***	*/
    
void plant_flag(int a, int b)
{

        int temp_row, temp_col, adjacent;
        temp_row = timmys_location[0] + a;
        temp_col = timmys_location[1] + b;
	write_message(14, "");
	write_message(15, "");
	write_message(16, "");	 // Clears previous message
	if(flags_count > 0)
	{
        	if (check_out_of_grid(temp_row, temp_col) == OUT_OF_BOUNDS || check_out_of_grid(temp_row, temp_col) == WIN_ZONE)
               {
			flags_count--;
			update_flags(flags_count);
		 	#ifdef DEBUG
			printf("Throwing away your flags? damn you dumb af\n");
			#else
			switch(variety)
			{
				case 0:
					variety++;
					write_message(15, "Throwing away your flags?");
					break;
				case 1:
					variety++;
					write_message(15, "You know there's nothing");
					write_message(16, "there?");
					break;
				case 2:
					variety++;
					write_message(15, "Alright dude, your");
					write_message(16, "problem");
					break;
				case 3:
					variety++;
					write_message(15, "Is your cat on the");
					write_message(16, "keyboard?");
					break;
				case 4:
					variety++;
					write_message(15, "Save some flags for the");
					write_message(16, "mines");
					break;
				case 5:
					variety++;
					write_message(15, "Still at it?");
					break;
				case 6:
					variety++;
					write_message(15, "????????????????????????");
					break;
				case 7:
					variety = 0;
					write_message(15, "You're gonna run of flags");
					write_message(16, "soon???");
					break;
			}
			
			#endif
      		}
        	else if (check_out_of_grid(temp_row, temp_col) == IN_FIELD)
        	{
                	switch ( mine_level[temp_row][temp_col])
                	{
                        	case MINE:
                                	score_count += 2;
                			#ifndef DEBUG
                                	update_score(score_count);
                                	#endif
					flags_count--;
					#ifndef DEBUG
                                	update_flags(flags_count);
					#endif
                               		mines_count--;
					#ifndef DEBUG
                                	update_mines(mines_count);
					#endif
                                	display_level[temp_row][temp_col] = FL_MINE;
                                	mine_level[temp_row][temp_col] = FL_MINE;
					#ifndef DEBUG
                                	show_glif(FL_MINE,temp_row,temp_col,0);
					#endif
                                	break;
                        	case FL_MINE:
					flags_count--;
					update_flags(flags_count);
                                	#ifdef DEBUG
                        		printf("Hun, you already put a flag there. Next time why don't you try and use your eyes.\n");
                	        	#else
        	                	write_message(14, "Cannot put a flag there,");
					write_message(15, "you lose it.");
	                        	#endif

					break;
                        	case SAFE:
					if(display_level[temp_row][temp_col] == EMPTY)
					{
						score_count--;
                                		//#ifndef DEBUG
                                		update_score(score_count);
                                		//#endif
                                		flags_count--;
                                		//#ifndef DEBUG
                                		update_flags(flags_count);
                                		//#endif
                                		display_level[temp_row][temp_col] = FLAG;
                                		mine_level[temp_row][temp_col] = FLAG;
                        	        	//#ifndef DEBUG
                	                	show_glif(FLAG,temp_row,temp_col,0);
        	                        	//#endif
					}
					else
					{
						flags_count--;
						update_flags(flags_count);
						#ifdef DEBUG
                        			printf("Cannot put a flag there, you lose it, duh!\n");
                	        		#else
        	                		write_message(14, "Cannot put a flag there,");
						write_message(15, "you lose it.");
	                        		#endif
					}
	                                break;

                        	case FLAG:
					flags_count--;
					update_flags(flags_count);
					#ifdef DEBUG
                        		printf("Why? You put a flag there already. Stop trying to flag the same spot\n");
                	        	#else
        	                	write_message(14, "Cannot put a flag there,");
					write_message(15, "you lose it.");
	                        	#endif

                        	        break;
               		}
        	}
	}
		else
		#ifdef DISPLAY
		write_message(15, "No more flags!");
		#else
		printf("bitch you broke\n");
		#endif
}
