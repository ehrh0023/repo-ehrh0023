


# Makefile for Lab 04.

all: test_exe Program

############################## Program 

#Program target depends on compiled Rectange and Main files 
Program: main.o rectangle.o
	g++ -o rectangleProgram rectangle.o main.o
	
# This section includes rules to compile .cpp files into .o files
rectangle.o:
	g++ -c rectangle.cpp
main.o:
	g++ -c main.cpp
	


############################## Tests 

# This section sets up rules to work with cxxtest, there are a couple of steps:
# 1. Scripts distributed with cxxtest parse through your .cpp files looking for the tests you wrote.  The scripts automatically generate a new .cpp file to run your tests.
# 2. Just like any other .cpp file you need to compile the cxxtest generated file and link it to generate an executable file. 
# 3. Finally, you call the executable file from the command line to run your tests.
# The makefile includes rules for doing all this automatically, so that you can simply type "make run-tests" at the command line and it should prepare and then run your tests.


# This rule acts a command for running the tests (i.e. type "make run-tests" and it will run).
# It depends on test_exe, so it will automatically use the rules below to build the test_exe if it does not already exist.
run-tests: test_exe
	./test_exe


CXXDIR = ./cxxtest-4.3
CXXTEST = $(CXXDIR)/bin/cxxtestgen
CXXFLAGS = --error-printer --abort-on-fail --have-eh


# This rule calls the scripts distributed with the cxxtest framework to auto-generate .cpp file(s) to run the tests that you have defined.
test.cpp: rectangleTests.h
	$(CXXTEST) $(CXXFLAGS) -o test.cpp rectangleTests.h

# This rule will create an executable program to run the tests by linking the test-related object files together:
test_exe: test.cpp rectangle.o
	g++ -I$(CXXDIR) -o test_exe rectangle.o test.cpp

# A target to remove all generated files.
clean:
	rm -f *.o
	rm -f rectangleProgram
	rm -f test_exe
	rm -f test.cpp

