
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
row.o: row.cpp 
winningrow.o: winningrow.cpp 
frog.o: frog.cpp 
board.o: board.cpp  
movingobject.o: movingobject.cpp 
car1.o: car1.cpp 
car2.o: car2.cpp 
movingobjectsfactory.o: movingobjectsfactory.cpp

GameObjects.a: board.o row.o winningrow.o frog.o movingobject.o car1.o car2.o movingobjectsfactory.o
	ar -rcs $@ $^


# Compile rules
.c.o:
	gcc -c $(CFLG) $<
.cpp.o:
	g++ -c $(CFLG) $<


#  Clean
clean:
	$(CLEAN)
