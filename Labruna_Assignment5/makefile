CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Driver.exe

theImp.o: Makefile theImp.cpp
	$(CC) $(BUILD_FLAGS) -c theImp.cpp -o theImp.o

Menu.o: Makefile Menu.cpp
	$(CC) $(BUILD_FLAGS) -c Menu.cpp -o Menu.o

Student.o: Makefile Student.cpp
	$(CC) $(BUILD_FLAGS) -c Student.cpp -o Student.o

StudentTree.o: Makefile StudentTree.cpp
	$(CC) $(BUILD_FLAGS) -c StudentTree.cpp -o StudentTree.o

Faculty.o: Makefile Faculty.cpp
	$(CC) $(BUILD_FLAGS) -c Faculty.cpp -o Faculty.o

FacultyTree.o: Makefile FacultyTree.cpp
	$(CC) $(BUILD_FLAGS) -c FacultyTree.cpp -o FacultyTree.o

IDGenerator.o: Makefile IDGenerator.cpp
	$(CC) $(BUILD_FLAGS) -c IDGenerator.cpp -o IDGenerator.o

Driver.exe: Makefile theImp.o Menu.o Student.o StudentTree.o Faculty.o FacultyTree.o IDGenerator.o  themain.cpp
	$(CC) $(BUILD_FLAGS) theImp.o Menu.o Student.o StudentTree.o Faculty.o FacultyTree.o IDGenerator.o  themain.cpp -o Driver.exe

clean:
	$(RM) $(EXES) $(OBJECTS)
