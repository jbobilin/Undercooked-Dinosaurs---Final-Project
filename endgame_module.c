/*
**************************
File Name:      endgame_module.c
Created By:     Thomas Yang
Login:          thomasy4
Team:           Undercooked Dinosaurs
Date Created:   7 December 2017
Last Modified:  7 December 2017
Description:	  This module contains the sequences for a win, loss, and a prompt to play again.
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include "main_global.h"
#include "display.h"
#include "miensfeldutil.h"
#include "check_adj_module.h"

/*	***  Define Compiler Directives  ***	*/
//#define DEBUG

/*	***  Functions Workspace  ***	*/

/* Function Name:  death
 * I/O:  void / void
 * Purpose/Notes:  runs the death sequence*/
void death(void)
{
  int i, j;
  for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      if(mine_level[i][j] == MINE)
      {
        show_glif(MINE,i,j,0);
      }
    }
 }
  show_glif(EXPLODE,timmys_location[0],timmys_location[1],0);
  write_message(15, "We're gonna need another Timmy!");
  quit_sequence();
 }

/* Function Name:  win
 * I/O:  void / void
 * Purpose/Notes:  runs the win sequence*/
void win(void)
{
  int i, j, adjacent;
  for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      if(mine_level[i][j] == MINE)
      {
        show_glif(MINE,i,j,0);
      }
    }
  }
  adjacent = adj(timmys_location[0],timmys_location[1]);
  show_glif(SAFE,timmys_location[0],timmys_location[1],adjacent);
  write_message(15, "Cognratuations! You won!");
  quit_sequence;
}

  
/* Function Name:  quit_sequence
 * I/O:  void / void
 * Purpose/Notes:  prompts user to quit or play again*/
 void quit_sequence(void)
 {
   int char;
   char = getchar();
   if(char == 'y' || char == 'Y') quit_flag = RESTART;
   if(char == 'n' || char == 'N') quit_flag = TRUE;
   
   while(char != 'y' && char != 'Y' && char != 'N' && char != 'n')
   {
   char = getchar();
   if(char == 'y' || char == 'Y') quit_flag = RESTART;
   if(char == 'n' || char == 'N') quit_flag = TRUE;
   }
 }
