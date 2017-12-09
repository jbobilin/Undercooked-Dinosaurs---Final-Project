# Undercooked Dinosaurs's Makefile for Miensfeld
# Created:	26 November 2017
# Last Mod:	9 December 2017


# directory path for links
FPROJ = /inst/ee/ee160/ee160/Code.lect/Miensfeld


# target for making executables
all: miensfeld


# target for miensfeld
miensfeld: main_module.o endgame_module.o plant_module.o print_shit.o move_module.o starting_configuration_module.o check_out_of_grid_module.o check_adj_module.o display.o gameplay_module.o
	cc main_module.o print_shit.o endgame_module.o move_module.o plant_module.o check_out_of_grid_module.o gameplay_module.o starting_configuration_module.o check_adj_module.o display.o -o miensfeld -lcurses


#source file dependencies
check_adj_module.o: display.h main_global.h miensfeldutil_global.h check_out_of_grid_module.h

check_out_of_grid_module.o: check_out_of_grid_module.h

endgame_module.o: endgame_module.h check_adj_module.h main_global.h miensfeldutil_global.h display.h

gameplay_module.o: miensfeldutil.h main_global.h move_module.h plant_module.h endgame_module.h print_shit.h

main_module.o: display.h starting_configuration_module.h miensfeldutil_global.h gameplay_module.h print_shit.h

move_module.o: display.h miensfeldutil.h print_shit.h endgame_module.h main_global.h check_adj_module.h check_out_of_grid_module.h

plant_module.o: display.h miensfeldutil_global.h main_global.h check_adj_module.h check_out_of_grid_module.h print_shit.h

print_shit.o: main_global.h

starting_configuration_module.o: miensfeldutil.h check_adj_module.h main_global.h display.h print_shit.h

display.o: display.h


# copies targets
copies:
	cp  -i $(FPROJ)/display.h .
	cp  -i $(FPROJ)/display.o .


#utility targets
clean:
	mv display.o display.sav
	rm -f *.o
	mv display.sav display.o

real_clean: clean
	rm  -f miensfeld a.out core
