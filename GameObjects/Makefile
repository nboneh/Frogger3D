
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
frog.o: frog.cpp ../drawshapes.c
board.o: board.cpp  
movingobject.o: movingobject.cpp 
car1.o: car1.cpp 
car2.o: car2.cpp 
car3.o: car3.cpp
car4.o: car4.cpp
truck.o: truck.cpp
waterobject.o: waterobject.cpp
movingobjectsfactory.o: movingobjectsfactory.cpp
log.o: log.cpp
turtles.o: turtles.cpp
car.o: car.cpp

GameObjects.a: board.o row.o winningrow.o frog.o movingobject.o car1.o car2.o car3.o car4.o truck.o movingobjectsfactory.o waterobject.o log.o turtles.o car.o 
	ar -rcs $@ $^


# Compile rules
.c.o:
	gcc -c $(CFLG) $<
.cpp.o:
	g++ -c $(CFLG) $<


#  Clean
clean:
	$(CLEAN)
