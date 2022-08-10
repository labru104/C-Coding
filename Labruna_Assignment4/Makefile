LD_FLAGS = -W -Wall -pedantic
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Assignment4Driver.exe

Registrar.o: Makefile Registrar.cpp
	$(CC) $(BUILD_FLAGS) -c Registrar.cpp -o Registrar.o

Student.o: Makefile Student.cpp
	$(CC) $(BUILD_FLAGS) -c Student.cpp -o Student.o

Window.o: Makefile Window.cpp
	$(CC) $(BUILD_FLAGS) -c Window.cpp -o Window.o

Assignment4Driver.exe: Makefile Registrar.o Student.o Window.o Assignment4Main.cpp
	$(CC) $(BUILD_FLAGS) Registrar.o Student.o Window.o Assignment4Main.cpp -o Assignment4Driver.exe

clean:
	$(RM) $(EXES) $(OBJECTS)
