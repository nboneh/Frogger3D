# Example 15
EXE=Frogger3D

# Main target
all: $(EXE)

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
CLEAN=rm -f $(EXE) *.o *.a
endif

# Dependencies
Frogger3D.o: Frogger3D.cpp Frogger3D.h
fatal.o: fatal.c Frogger3D.h
loadtexbmp.o: loadtexbmp.c Frogger3D.h
print.o: print.c Frogger3D.h
project.o: project.c Frogger3D.h
errcheck.o: errcheck.c Frogger3D.h
board.o: board.cpp Frogger3D.h

#  Create archive
Frogger3D.a:fatal.o loadtexbmp.o print.o project.o errcheck.o board.o
	ar -rcs $@ $^

# Compile rules
.c.o:
	gcc -c $(CFLG) $<
.cpp.o:
	g++ -c $(CFLG) $<

#  Link
Frogger3D:Frogger3D.o Frogger3D.a
	gcc -O3 -o $@ $^   $(LIBS)

#  Clean
clean:
	$(CLEAN)
