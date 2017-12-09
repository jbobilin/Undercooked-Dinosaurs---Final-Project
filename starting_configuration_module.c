/*
**************************
File Name:      starting_configuration_module.c
Created By:	Thomas Yang     
Login:          thomasy4
Team:           Undercooked Dinosaurs
Date Created:   26 November 2017
Last Modified:  26 November 2017
Description:	Creates and intializes the board given a selected difficulty.  Returns a board with mines laid and a preset safe zone.  
**************************
*/

/*	***  Call Header Files  ***	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "check_adj_module.h"
#include "main_global.h"
#include "print_shit.h"
#include "miensfeldutil.h"

/*	***  Functions Workspace  ***	*/
void starting_configuration_module(int level)
{
	#ifdef DEBUG
	printf("DEBUG: ENTERING STARTING CONFIG\n\nlevel = %d\n\n", level);
	#endif

   int mine, tempR, tempC, adjacent, i, j;

#ifdef DISPLAY
 draw_board();
#endif


  if( level == 1 ) mine = 6;
  if( level == 2 ) mine = 11;
  if( level == 3 ) mine = 16;
  if( level == 4 ) mine = 20;
 
  //set score counter for mines and flags
   mines_count = mine;
   flags_count = mine;

variety = 0;


  //Resets mine level
  for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      mine_level[i][j] = EMPTY;
    }
  } 

#ifdef DEBUG
printf("make mine level empty\n");
print_shit();
#endif

  //Resets timmy level
   for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      timmy_level[i][j] = TIM_NOT_BEEN;
    }
  } 

#ifdef DEBUG
printf("set timmy level to TIM_NOT_BEEN\n");
print_shit();
#endif


   //Resets timmy location
   timmys_location[0] = 0;
   timmys_location[1] = 0;
   timmy_level[0][0] = TIM_ON;

#ifdef DEBUG
printf("set timmy location\n");
print_shit();
#endif

   //Resets dislay level
   for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      display_level[i][j] = EMPTY;
    }
  }

#ifdef DEBUG
printf("empty display level\n");
print_shit();
#endif

    //Set safe for mine level
  for(i=0; i<7; i++)
  {
    mine_level[i][0] = SAFE;
  }
    mine_level[0][1] = SAFE;
    mine_level[1][1] = SAFE;
    mine_level[3][1] = SAFE;
    mine_level[5][1] = SAFE;
    mine_level[6][1] = SAFE;
    mine_level[0][2] = SAFE;
    mine_level[3][2] = SAFE;
    mine_level[5][1] = SAFE;

#ifdef DEBUG
printf("set safe cells\n");
print_shit();
#endif

srand(time(NULL));    
  //Sets mines randomly
  while(mine > 0)
  {
    //srand(time(NULL));
    tempR = rand() % 8;
    tempC = rand() % 10;
    if(mine_level[tempR][tempC] == EMPTY)
    {
       mine_level[tempR][tempC] = MINE;
       mine--;
    }
  }

#ifdef DEBUG
printf("distribute mines\n");
print_shit();
#endif

  //Draws on display level for safe cells
  
  for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      if(mine_level[i][j] == SAFE)
      {
        adjacent = adj(i,j);
	#ifdef DISPLAY
        show_glif(SAFE,i,j,adjacent);
 	#endif
	timmy_level[i][j] = TIM_BEEN;
        display_level[i][j] = SAFE;
      }
      if(mine_level[i][j] == EMPTY || mine_level[i][j] == MINE)
	{
	#ifdef DISPLAY
        show_glif(EMPTY,i,j,0);
	#endif
        display_level[i][j] = EMPTY;
	}
    }
  } 

#ifdef DEBUG
printf("re-configure display level\n");
print_shit();
#endif 
  
  //Sets all other empty to safe
  for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      if(mine_level[i][j] == EMPTY)
      mine_level[i][j] = SAFE;
    }
  }

#ifdef DEBUG
printf("make all unset cells safe\n");
print_shit();
#endif

  //Initializes scoreboard
  score_count = 0;
#ifdef DISPLAY
  update_flags(flags_count);
  update_mines(mines_count);
  update_score(score_count);
#endif

  // Places Timmy onto board
adjacent = adj(0,0);
#ifdef DISPLAY
show_glif(TIMMY,0,0,adjacent);
#endif
display_level[0][0] = TIMMY;

#ifdef DEBUG
printf("initialize score and draw timmy on board\n");
print_shit();
#endif

}
