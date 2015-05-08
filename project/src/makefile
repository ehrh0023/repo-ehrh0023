UNAME = $(shell uname)
CC = g++
CFLAGS 	= -Wall -c
LDFLAGS = -Wall -lglut -lGLU -lGL -lX11

##
# List of cpp files to be compiled
# Note, if you add any cpp files to your project, you must also add them here
##

CPPEXTFILES += main.cpp 
CPPEXTFILES += BaseGfxApp.cpp
CPPEXTFILES += Simulation.cpp
CPPEXTFILES += Drawing.cpp
CPPEXTFILES += Keyboard.cpp
CPPEXTFILES += Color.cpp
CPPEXTFILES += Clock.cpp
CPPEXTFILES += randf.cpp
CPPEXTFILES += Entity/EntityManager.cpp 
CPPEXTFILES += Entity/Entity.cpp
CPPEXTFILES += Entity/Ball.cpp
CPPEXTFILES += Entity/Paddle.cpp

##
# Lists all the cpp files in /src
# Note, this means you can make from /src, /lib, or /bin
##
SOURCES = $(addprefix ../src/,  $(CPPEXTFILES))

OBJECTS = $(addprefix ../bin/,  $(CPPEXTFILES:.cpp=.o)) 

GLUI = glui

##
# Linking the GLUI libraries
##
LINK_LIBS += -L../lib/$(GLUI)/lib/ -lglui
INCLUDE = -I../lib/$(GLUI)/include -I../src

##
# Linking GLUT and OpenGl for Mac
##
ifeq ($(UNAME), Darwin)
	LINK_LIBS += -framework glut -framework opengl
	EXECUTABLE = gorobot
##
# Linking GLUT and OpenGl for Linux
##
else
	ifeq ($(UNAME), Linux)
		LINK_LIBS += -lglut -lGL -lGLU
		EXECUTABLE = gorobot
##
# Linking GLUT and OpenGl for Windows
# Note, you must have freeGlut installed; see the Resource page for details
##
	else 
		GLUTINCLUDEPATH = C:\Dev-Cpp\mingw32\freeglut\include\
		GLUTLIBPATH = C:\Dev-Cpp\mingw32\freeglut\lib\
		LINK_LIBS += -L$(GLUTLIBPATH) -lfreeglut -lopengl32 -Wl,--subsystem,windows
		INCLUDE += -I$(GLUTPATH)
		EXECUTABLE = gorobot.exe

	endif
endif

##
# Sets up the /bin folder, checks for all cpp files, and compiles the executable
##
all: setup testEntity testRobotClass $(SOURCES) $(EXECUTABLE)

setup:
	mkdir -p ../bin
	mkdir -p ../bin/Entity
##
# Compiles gorobot executable to run robot simulation
##

gorobot: setup $(GLUI) $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LINK_LIBS) -o $(EXECUTABLE)

##
# This creates the object files in the /bin and /bin/Entity folders
##
../bin/%.o: ../src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

../bin/Entity/%.o: ../src/Entity/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
##
# Removes all generated .o, executable, and testing .cpp files
##
clean:
	\rm -rf $(OBJECTS) $(EXECUTABLE)
	 $(MAKE)  -C ../lib/$(GLUI) clean	
	rm -f testEntity
	rm -f testRobotClass
	rm -f ../bin/EntityTests.cpp
	rm -f ../bin/RobotClassTests.cpp

$(GLUI):
	$(MAKE) -C ../lib/$(GLUI) all

##
# This specifies the path for cxxtest output and compiles/runs the tests
##
tests: setup ../bin/EntityTests.cpp makeTestEntity ../bin/RobotClassTests.cpp makeTestRobotClass
	./testEntity
	./testRobotClass

testEntity: setup ../bin/EntityTests.cpp makeTestEntity

testRobotClass: setup ../bin/RobotClassTests.cpp makeTestRobotClass

CXXDIR = ../bin/cxxtest-4.3
CXXTEST = $(CXXDIR)/bin/cxxtestgen
CXXFLAGS = --error-printer --abort-on-fail --have-eh

../bin/EntityTests.cpp: $(GLUI) EntityTests.h
	$(CXXTEST) $(CXXFLAGS) -o ../bin/EntityTests.cpp EntityTests.h

../bin/RobotClassTests.cpp: $(GLUI) RobotClassTests.h
	$(CXXTEST) $(CXXFLAGS) -o ../bin/RobotClassTests.cpp RobotClassTests.h

makeTestEntity: $(GLUI) ../bin/Drawing.o ../bin/randf.o ../bin/Clock.o ../bin/Entity/Entity.o ../bin/Entity/RobotClass.o ../bin/Entity/Target.o ../bin/Entity/Obstacle.o ../bin/Entity/EntityManager.o
	g++ -I$(CXXDIR) -o testEntity ../bin/Drawing.o ../bin/randf.o ../bin/Clock.o ../bin/Entity/Entity.o ../bin/Entity/RobotClass.o ../bin/Entity/Target.o ../bin/Entity/Obstacle.o ../bin/Entity/EntityManager.o ../bin/EntityTests.cpp $(LINK_LIBS)

makeTestRobotClass: $(GLUI) ../bin/Drawing.o ../bin/randf.o ../bin/Clock.o ../bin/Entity/Entity.o ../bin/Entity/RobotClass.o ../bin/Entity/Target.o ../bin/Entity/Obstacle.o ../bin/Entity/EntityManager.o
	g++ -I$(CXXDIR) -o testRobotClass ../bin/Drawing.o ../bin/randf.o ../bin/Clock.o ../bin/Entity/Entity.o ../bin/Entity/RobotClass.o ../bin/Entity/Target.o ../bin/Entity/Obstacle.o ../bin/Entity/EntityManager.o ../bin/RobotClassTests.cpp $(LINK_LIBS)


 


