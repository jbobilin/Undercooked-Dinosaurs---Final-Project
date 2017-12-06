/*
**************************
File Name:      starting_configuration_module.c
Created By:     
Login:          
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  26 November 2017
Description:	  
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include "miensfeldutil.h"

/*	***  Define Compiler Directives  ***	*/
//#define DEBUG


/*	***  Functions Workspace  ***	*/
int starting_configuration_module(int level)
{
   int mine, tempR, tempC, adjacent;
  draw_board();
  if( level = 1 ) mine = 6;
  if( level = 2 ) mine = 11;
  if( level = 3 ) mine = 16;
  if( level = 4 ) mine = 20;
  
  //set score counter for mines and flags
   mines_count = mine;
   flags_count = mine;
  
  //Resets mine level
  for(i=0, i<7, i++)
  {
    for(j=0, j<9, j++)
    {
      mine_level[i,j] = EMPTY;
    }
  } 
  
  //Set safe for mine level
  for(i=0, i<7, i++)
  {
    mine_level[i,0] = SAFE;
  }
    mine_level[0,1] = SAFE;
    mine_level[1,1] = SAFE;
    mine_level[3,1] = SAFE;
    mine_level[5,1] = SAFE;
    mine_level[6,1] = SAFE;
    mine_level[0,2] = SAFE;
    mine_level[3,2] = SAFE;
    mine_level[5,2] = SAFE;
    
  //Sets mines randomly
  while( mine > 0)
  {
    tempR = rand() % 7;
    tempC = rand() % 9;
    if(mine_level[tempR, tempC] == EMPTY)
    {
       mine_level[tempR, tempC] = MINE;
       mine--;
    }
  }
  
  //Draws on display level for safe cells
  
  for(i=0, i<7, i++)
  {
    for(j=0, j<9, j++)
    {
      if(mine_level[i,j] == SAFE)
      {
        adjacent = adj(i,j);
        show_glif(SAFE,i,j,adjacent);
      }
      if(mine_level[i,j] == EMPTY || mine_level[i,j] == MINE)
        show_glif(EMPTY,i,j,0);
    }
  } 
  
  
  //Sets all other empty to safe
  for(i=0, i<7, i++)
  {
    for(j=0, j<9, j++)
    {
      if(mine_level[i,j] == EMPTY)
      mine_level[i,j] = SAFE;
    }
  } 
  //Initializes scoreboard
  score_count = 0;
  update_flags(flags_count);
  update_mines(mines_count);
  update_score(score_count);
}
  
      
   
/* Function Name:  
 * I/O:  /  
 * Purpose/Notes:  */

