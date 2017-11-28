# Undercooked Dinosaurs's makefile for the final project
# Created: 26 November 2017

# directory path for links
FPROJ = /inst/ee/ee160/ee160/Code.lect/Miensfeld

# target for making executables
all: miensfeld

# target for miensfeld
miensfeld: miensfeld.o mainmodule.o starting_configuration_module.o gameplay_module.o move_module.o plant_module.o check_adj_module.o endgame_module.o
	cc mainmodule.o starting_configuration_module.o gameplay_module.o move_module.o plant_module.o check_adj_module.o endgame_module.o -o miensfeld.o

#source file dependencies
mainmodule.o: mainmodule.h display.h miensfeldutil.h
starting_configuration_module.o: 
gameplay_module.o:
move_module.o
plant_module.o
check_adj_module.o
endgame_module.o
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
