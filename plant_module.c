/*
**************************
File Name:      plant_module.c
Created By:     Lian Huang
Login:          lian7
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  3 December 2017
Description:	This function is given the coordinates of the cell that the user wants to plant a flag in,
		and determines if its a valid cell and updates the associated levels and updates score.
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
	//Initializes variables
        int temp_row, temp_col, adjacent;
        temp_row = timmys_location[0] + a;
        temp_col = timmys_location[1] + b;
	//Clears the message screen
	write_message(14, "");
	write_message(15, "");
	write_message(16, "");	 // Clears previous message
	if(flags_count > 0)  //While you still have flags
	{
        	if (check_out_of_grid(temp_row, temp_col) == OUT_OF_BOUNDS || check_out_of_grid(temp_row, temp_col) == WIN_ZONE) //Check if plant is out of bounds
               {
			flags_count--;
			update_flags(flags_count);
		 	#ifdef DEBUG
			printf("Throwing away your flags? damn you dumb af\n");
			#else
			//Gradually roasts the player
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
        	else if (check_out_of_grid(temp_row, temp_col) == IN_FIELD) //If the cell is in field, checks what kind of cell it is
        	{
                	switch ( mine_level[temp_row][temp_col])
                	{
                        	case MINE:  //If the user correctly flags a mine
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
						//Change cell to flagged mine
                                	display_level[temp_row][temp_col] = FL_MINE;
                                	mine_level[temp_row][temp_col] = FL_MINE;
					#ifndef DEBUG
                                	show_glif(FL_MINE,temp_row,temp_col,0);
					#endif
                                	break;
                        	case FL_MINE:  //If user tries to flag a flagged mine
					flags_count--;
					update_flags(flags_count);
                                	#ifdef DEBUG
                        		printf("Hun, you already put a flag there. Next time why don't you try and use your eyes.\n");
                	        	#else
        	                	write_message(14, "Cannot put a flag there,");
					write_message(15, "so you lose it.");
	                        	#endif

					break;
                        	case SAFE: //Safe cells can either have two display level vaues, EMPTY or SAFE
					if(display_level[temp_row][temp_col] == EMPTY)  //Attempted to flag a mine, but was incorrect
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
					else  //Display level - SAFE, can't plant flags on SAFE cells
					{
						flags_count--;
						update_flags(flags_count);
						#ifdef DEBUG
                        			printf("Cannot put a flag there, you lose it, duh!\n");
                	        		#else
        	                		write_message(14, "Cannot put a flag there,");
						write_message(15, "so you lose it.");
	                        		#endif
					}
	                                break;

                        	case FLAG:  // If user tries to flag a flagged cell
					flags_count--;
					update_flags(flags_count);
					#ifdef DEBUG
                        		printf("Why? You put a flag there already. Stop trying to flag the same spot\n");
                	        	#else
        	                	write_message(14, "Cannot put a flag there,");
					write_message(15, "so you lose it.");
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
