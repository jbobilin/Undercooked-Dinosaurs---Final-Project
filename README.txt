Welcome the the README file for the Undercooked Dinosaurs's final project.

Along with this file, you should find:
  1 -	makefile
  2 -	main_module.c
  3 -	main_module.h
  4 -	starting_configuration_module.c
  5 -	starting_configuration_module.h
  6 -	gameplay_module.c
  7 -	gameplay_module.h
  8 -	move_module.c
  9 -	move_module.h
  10 -	plant_module.c
  11 -	plant_module.h
  12 -	check_adj_module.c
  13 -	check_adj_module.h
  14 -	endgame_module.c
  15 -	endgame_module.h
  16 -	display.h
  17 -	display.o
  18 -	miensfeldutil.h
  19 -	check_out_of_grid.c
  20 -	check_out_of_grid.h
  21 -	messages.h

Some quick notes for future developers:
This program stores all the information for the game in three two-dimensional arrays called the timmy_level, mine_level, and display_level. We have taken this approach because we found the need to store data about the game at different layers/levels; for example we need the program to know where all of the mines are within the game, but on a surface level display empty tiles.

The timmy_level array...
Keeps track of where timmy is on the board, where he has been, and where he has not been and each coordinate location may take a correspondig value of either:
1 - timmy has not been on this cell
2 - timmy is currently on this cell
3 - timmy has been on this cell
note that: Timmy's location (i.e. 2) in the timmy_level corresponds with the timmys_location array which is a simple 1D array giving the coordinates [row, column], we use the timmys_location array for a simple way keep track of timmy's actual location for computations

The mine_level array...
Keeps track of what is actually happening underneath the board. Coordinates in the mine_level can take on the values of: 
2 - SAFE
3 - EMPTY
4 - FLAG
5 - MINE
6 - FL_MINE

note that: EMPTY is used only to configure this level prior to gameplay, during gameplay coordinates on this level should never have a value of EMPTY.

The display_level array...
Keeps track of what the user sees during gameplay. This level is necessary because the Glifs printed to the play console are not stored in the computer's memory, at the same time the user needs to see empty cells even if there is a mine underneath so it is necessary to use this seperate level, rather than the mine_level. Coordinates in the display_level can take on the values of: 
1 - TIMMY
2 - SAFE
3 - EMPTY
4 - FLAG
5 - MINE
6 - FL_MINE
7 - EXPLODE
