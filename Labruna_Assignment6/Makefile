LD_FLAGS = -W -Wall -pedantic
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Program.exe

TestAlgorithms.o: Makefile TestAlgorithms.cpp
	$(CC) $(BUILD_FLAGS) -c TestAlgorithms.cpp -o TestAlgorithms.o

Program.exe: Makefile TestAlgorithms.o Main.cpp
	$(CC) $(BUILD_FLAGS) TestAlgorithms.o Main.cpp -o Program.exe

clean:
	$(RM) $(EXES) $(OBJECTS)

