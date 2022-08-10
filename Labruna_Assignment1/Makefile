LD_FLAGS = -W -Wall -pedantic
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Assignment1Driver.exe 

Assignment1imp.o: Makefile Assignment1imp.cpp
	$(CC) $(BUILD_FLAGS) -c Assignment1imp.cpp -o Assignment1imp.o

Assignment1Driver.exe: Makefile Assignment1imp.o Assignment1main.cpp
	$(CC) $(BUILD_FLAGS) Assignment1imp.o Assignment1main.cpp -o Assignment1Driver.exe

clean:
	$(RM) $(EXES) $(OBJECTS)
