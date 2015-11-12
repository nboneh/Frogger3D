# Frogger3D
EXE=Frogger3D

# Main target
all:  
	cd GameObjects; make; 
	@$(MAKE) --no-print-directory $(EXE)


#  MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall 
LIBS=-lglut32cu -lglu32 -lopengl32
CLEAN=del *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -Wno-deprecated-declarations
LIBS=-framework GLUT -framework OpenGL
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall
LIBS=-lglut -lGLU -lGL -lm
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) *.o *.a .DS_Store; cd GameObjects; make clean
endif

# Dependencies
Frogger3D.o: Frogger3D.cpp 
fatal.o: fatal.c 
loadtexbmp.o: loadtexbmp.c 
print.o: print.c 
project.o: project.c 
errcheck.o: errcheck.c
drawshapes.o: drawshapes.c 

#  Create archive
Frogger3D.a: fatal.o loadtexbmp.o print.o project.o errcheck.o drawshapes.o
	ar -rcs $@ $^

# Compile rules
.c.o:
	gcc -c $(CFLG) $<
.cpp.o:
	g++ -c $(CFLG) $<

#  Link
Frogger3D: Frogger3D.o Frogger3D.a GameObjects/GameObjects.a
	g++ -O3 -o $@ $^   $(LIBS)

#  Clean
clean:
	$(CLEAN)
