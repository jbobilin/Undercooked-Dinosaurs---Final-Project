# Undercooked Dinosaurs's makefile for the final project
# Created: 26 November 2017

# directory path for links
FPROJ = /inst/ee/ee160/ee160/Code.lect/Miensfeld

# target for making executables
all: miensfeld

# target for miensfeld
miensfeld: miensfeld.o main_module.o check_adj_module.o check_out_of_grid_module.o endgame_module.o gameplay_module.o move_module.o plant_module.o starting_configuration_module.o
	cc main_module.o check_adj_module.o check_out_of_grid_module.o endgame_module.o gameplay_module.o move_module.o plant_module.o starting_configuration_module.o -o miensfeld.o

#source file dependencies
mainmodule.o: display.h starting_configuration_module.h gameplay_module.h miensfeldutil.h
starting_configuration_module.o: miensfeldutil.h
gameplay_module.o: miensfeldutil.h main_module.h move_module.h endgame_module.h
move_module.o: miensfeldutil.h
plant_module.o: miensfeldutil.h
check_adj_module.o: display.h miensfeldutil.h
check_out_of_grid_module.o: miensfeldutil.h
endgame_module.o: miensfeldutil.h
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
