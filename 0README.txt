Welcome the the README file for the Undercooked Dinosaurs's final project.

In addition to this file, you should find:
0 - Initial_Algorithms.pdf			//our team's original planning/algorithms document
1 - check_adj_module.c				//checks for mines in adjacent cells
2 - check_adj_module.h
3 - check_out_of_grid_module.c			//checks if cell is in gameplay area
4 - check_out_of_grid_module.h
5 - display.h					//tep's display
6 - display.o
7 - endgame_module.c				//runs when the game ends
8 - endgame_module.h
9 - gameplay_module.c				//runs the game
10 - gameplay_module.h
11 - main_global.h				//global for main_module.h
12 - main_module.c				//the master driver, also has menu
13 - main_module.h				//contains anything globally declared
14 - makefile					//our makefile
15 - miensfeldutil.h				//our utility file
16 - miensfeldutil_global.h			//global for our utility file
17 - move_module.c				//moves timmy
18 - move_module.h
19 - plant_module.c				//plants flags
20 - plant_module.h
21 - print_shit.c				//a function desgined for debugging
22 - print_shit.h
23 - starting_configuration_module.c		//configures the field prior to gameplay
24 - starting_configuration_module.h



Some notes for future developers:

In Tep's included file for display.h, he incorrectly labeled the row and column for the function, show_glif. We've reversed the input such that it makes sense now.

If you are trying to debug then go into the the main_global.h file and in the compiler directives you will see DISPLAY and DEBUG. To run in debugging mode: uncomment DEBUG and comment out DISPLAY. To run normally: uncomment DISPLAY and comment out DEBUG. Also in the print_shit.c file, uncomment line #27 for a more dynamic game debugging feedback (it is commented out right now so the configuration module debugs are not cleared when the gameplay module runs).

This program stores all the information for the game in three two-dimensional arrays called the timmy_level, mine_level, and display_level. We have taken this approach because we found the need to store data about the game at different layers/levels; for example we need the program to know where all of the mines are within the game, but on a surface level display empty tiles.

The timmy_level array keeps track of where timmy is on the board, where he has been, and where he has not yet been. Each coordinate location may take a value of:
0 - TIM_NOT_BEEN
1 - TIM_ON
2 - TIM_BEEN
note that: Timmy's location (i.e. 2) in the timmy_level corresponds with a 1D array called timmys_location, which contains the coordinates for the cell Timmy is currently on in the form timmys_location[0] = row and timmys_location[1] = column, we use this array as a simple way keep track of timmy's actual location for computations.

The mine_level array keeps track of what is actually "underneath the ground." Each coordinate location may take a value of:
1 - SAFE
2 - EMPTY
3 - FLAG
4 - MINE
5 - FL_MINE
note that: EMPTY is used only to configure this level prior to gameplay, during gameplay coordinates on this level should never have a value of EMPTY.

The display_level array keeps track of what the user sees during gameplay. Each coordinate location may take a value of:
0 - TIMMY
1 - SAFE
2 - EMPTY
3 - FLAG
4 - MINE

This program has been designed in four main steps:
1st - the menu runs
2nd - the game field is configured
3rd - the game runs
4th - the game ends

For more details on our code design process, see our initial algorithms document; however please note that although the overall sturcture for this program has remained constant, many of the details changed during the implementation and debugging processes.

Thank you,
The Undercooked Dinosaurs
