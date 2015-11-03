
all: GameObjects.a

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
CLEAN=rm -f $(archive) *.o *.a .DS_Store
endif

# Dependencies
row.o: row.cpp row.h ../Frogger3D.h
frog.o: frog.cpp frog.h ../Frogger3D.h
board.o: board.cpp  board.h row.h frog.h  ../Frogger3D.h

GameObjects.a: board.o row.o frog.o
	ar -rcs $@ $^


# Compile rules
.c.o:
	gcc -c $(CFLG) $<
.cpp.o:
	g++ -c $(CFLG) $<


#  Clean
clean:
	$(CLEAN)
