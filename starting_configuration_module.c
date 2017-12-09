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

/*      ***  Call Header Files  ***     */
#include <stdio.h>
#include <stdlib.h>
//#include "miensfeldutil.h"
#include "display.h"
#include <time.h>
#include "check_adj_module.h"
#include "main_global.h"
#include "print_shit.h"
/*      ***  Define Compiler Directives  ***    */
//#define DEBUG
//#define DISPLAY

/*      ***  Functions Workspace  ***   */
void starting_configuration_module(int level)
{
        #ifdef DEBUG
        printf("DEBUG:\nI:\tlevel = %d", level);
        #endif

   int mine, tempR, tempC, adjacent, i, j;

#ifdef DISPLAY
      // Draws board
 draw_board();
#endif

  if( level == 1 ) mine = 6;
  if( level == 2 ) mine = 11;
  if( level == 3 ) mine = 16;
  if( level == 4 ) mine = 20;

  //set score counter for mines and flags
   mines_count = mine;
   flags_count = mine;

#ifdef DEBUG
      // Display array to make sure board is drawn
print_shit();
#endif
    
      //Resets mine level
  for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      mine_level[i][j] = EMPTY;
    }
  }


  //Resets timmy level
   for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      timmy_level[i][j] = TIM_NOT_BEEN;
    }
  }

#ifdef DEBUG
printf("test1\n");
print_shit();
#endif



   //Resets timmy location
   timmys_location[0] = 0;
   timmys_location[1] = 0;
   timmy_level[0][0] = TIM_ON;

#ifdef DEBUG
printf("test2\n");
print_shit();
#endif

   //Resets dislay level
   for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      display_level[i][j] = 8;//EMPTY;
    }
  }
#ifdef DEBUG
printf("test3\n");
print_shit();
#endif


  //Set safe for mine level
  for(i=0; i<8; i++)
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

      srand(time(NULL));
  //Sets mines randomly
  while(mine > 0)
  {
    tempR = rand() % 8;
    tempC = rand() % 10;
    if(mine_level[tempR][tempC] == EMPTY)
    {
       mine_level[tempR][tempC] = MINE;
       mine--;
    }
  }

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
          // Update level arrays
        timmy_level[i][j] = TIM_BEEN;
        display_level[i][j] = SAFE;
      }
      if(mine_level[i][j] == EMPTY || mine_level[i][j] == MINE)
        #ifdef DISPLAY
        show_glif(EMPTY,i,j,0);
        #endif
        display_level[i][j] = EMPTY;
    }
  }


  //Sets all other empty to safe
  for(i=0; i<8; i++)
  {
    for(j=0; j<10; j++)
    {
      if(mine_level[i][j] == EMPTY)
      mine_level[i][j] = SAFE;
    }
  }
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

}
