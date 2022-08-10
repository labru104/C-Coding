LD_FLAGS = -W -Wall -pedantic
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Assignment3Driver.exe

BraceCheckerImp.o: Makefile BraceCheckerImp.cpp
	$(CC) $(BUILD_FLAGS) -c BraceCheckerImp.cpp -o BraceCheckerImp.o

Assignment3Driver.exe: Makefile BraceCheckerImp.o Assignment3Main.cpp
	$(CC) $(BUILD_FLAGS) BraceCheckerImp.o Assignment3Main.cpp -o Assignment3Driver.exe

clean:
	$(RM) $(EXES) $(OBJECTS)
