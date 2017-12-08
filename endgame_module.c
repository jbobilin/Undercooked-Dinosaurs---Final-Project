/*
**************************
File Name:      endgame_module.c
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
#include "main_global.h"
#include "display.h"
#include "miensfeldutil.h"

/*	***  Define Compiler Directives  ***	*/
//#define DEBUG

void quit_sequence(void);

/*	***  Functions Workspace  ***	*/
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
  show_glif(EXPLODE,timmys_location[0],timmys_location[1],0);
  write_message(15, "We're gonna need another Timmy!");
  quit_sequence();
  }
void win(void)
{
  
  
/* Function Name:  
 * I/O:  /  
 * Purpose/Notes:  */

