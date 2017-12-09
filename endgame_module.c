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
#include <stdlib.h>
#include <unistd.h>
#include "main_global.h"
#include "display.h"
#include "check_adj_module.h"
#include "miensfeldutil_global.h"
#include "endgame_module.h"


/*	***  Functions Workspace  ***	*/
void death(void)
{
#ifdef DISPLAY
  int i, j;
write_message(12, "");
write_message(13, "");
write_message(14, "");
write_message(15, "");
write_message(16, "");

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
  write_message(12, "We're gonna need");
  write_message(13, "another Timmy!");
#endif
#ifdef DEBUG
printf("\nHe died, meh life is pointless and meaningless\nand you have to do projects like this so Timmy\nprobably got the better end of the deal anyway\n");
#endif

  quit_sequence();
 }


void win(void)
{
#ifdef DISPLAY
  int i, j, adjacent;

write_message(12, "");
write_message(13, "");
write_message(14, "");
write_message(15, "");
write_message(16, "");

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
  write_message(12, "Cognratuations!");
  write_message(13, "You won!");
#endif
#ifdef DEBUG
printf("\nYou won, yay we are so fucking pleased\n");
#endif
  quit_sequence();

}
    
void quit_sequence(void)
{
 	char ch;
write_message(12, "");
write_message(13, "");
write_message(14, "");
write_message(15, "");
write_message(16, "");

  
	#ifdef DEBUG
	printf("\nPlay again bitch?\n");
	#endif
	#ifdef DISPLAY
	write_message(15, "Do you want to"); 
	write_message(16, "play again?");
	write_message(17, "(type Y for yes,");
	write_message(18, " and N for no)\n");
	#endif		

	while(TRUE)
	{
		system("/bin/stty raw");
		ch = getchar();
		system("/bin/stty cooked");

		if(ch == 'y' || ch == 'Y')
		{
			quit_flag = RESTART;
			break;
		}
		if(ch == 'n' || ch == 'N')
		{
			quit_flag = TRUE;
			system("clear");
			break;
		}
	}
}
