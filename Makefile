heapofstudents: StudentDatabase.o Student.o Address.o Date.o main.o
	g++ -g StudentDatabase.o Student.o Address.o Date.o main.o -o heapofstudents
StudentDatabase.o: StudentDatabase.cpp StudentDatabase.h
	g++ -c -g StudentDatabase.cpp
Student.o: Student.cpp Student.h
	g++ -c -g Student.cpp
Address.o: Address.cpp Address.h
	g++ -c -g Address.cpp
Date.o: Date.cpp Date.h
	g++ -c -g Date.cpp
main.o: main.cpp StudentDatabase.h
	g++ -c -g main.cpp
clean:
	rm -f *.o
	rm heapofstudents
run: heapofstudents
	./heapofstudents
valgrind:
	valgrind ./heapofstudents
