



all: planride testperson testnode testplist

planride : Main.o
	clang++ Main.o -std=c++14 -o planride
	
testperson : TestPerson.o Person.o Driver.o PList.o Node.o
	clang++ TestPerson.o Person.o Driver.o PList.o Node.o -std=c++14 -o testperson

testnode : TestNode.o Person.o Driver.o Node.o DNode.o
	clang++ TestNode.o Person.o Driver.o DNode.o Node.o -std=c++14 -o testnode

testplist : TestPList.o Person.o PList.o Node.o
	clang++ TestPList.o Person.o PList.o Node.o -std=c++14 -o testplist

Main.o: Main.cpp
	clang++ -std=c++14 -c -g Main.cpp

TestPerson.o: TestPerson.cpp Model/Person.h Model/Driver.h Model/PList.h Model/Node.h
	clang++ -std=c++14 -c -g TestPerson.cpp

TestNode.o: TestNode.cpp Model/Person.h Model/Driver.h Model/DNode.h Model/Node.h
	clang++ -std=c++14 -c -g TestNode.cpp

TestPList.o: TestPList.cpp Model/Person.h Model/Node.h Model/PList.h
	clang++ -std=c++14 -c -g TestPList.cpp

Person.o: Model/Person.h Model/Person.cpp 
	clang++ -std=c++14 -c -g Model/Person.cpp

Driver.o: Model/Person.h Model/Driver.h Model/Driver.cpp Model/PList.h
	clang++ -std=c++14 -c -g Model/Driver.cpp

PList.o: Model/Node.h Model/Driver.h Model/PList.h Model/PList.cpp
	clang++ -std=c++14 -c -g Model/PList.cpp

Node.o: Model/Node.h Model/Node.cpp Model/Person.h 
	clang++ -std=c++14 -c -g Model/Node.cpp

DNode.o: Model/Node.h Model/Driver.h Model/DNode.h Model/DNode.cpp
	clang++ -std=c++14 -c -g Model/DNode.cpp

clean:
	rm *.o planride testperson testnode testplist
