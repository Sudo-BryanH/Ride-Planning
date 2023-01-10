
all: planride testperson testnode testplist testinreader testplanner

planride : Main.o
	clang++ Main.o -std=c++14 -o planride
	
testperson : TestPerson.o Person.o Driver.o PList.o Node.o
	clang++ TestPerson.o Person.o Driver.o PList.o Node.o -std=c++14 -o testperson

testnode : TestNode.o Person.o Driver.o Node.o DNode.o
	clang++ TestNode.o Person.o Driver.o DNode.o Node.o -std=c++14 -o testnode

testplist : TestPList.o Person.o PList.o Node.o
	clang++ TestPList.o Person.o PList.o Node.o -std=c++14 -o testplist

testinreader : TestReader.o Person.o Node.o Driver.o DNode.o InputReader.o
	clang++ TestReader.o Person.o Node.o Driver.o DNode.o InputReader.o -std=c++14 -o testinreader

testplanner : TestPlanner.o Planner.o InputReader.o Person.o Node.o Driver.o DNode.o PList.o Publisher.o
	clang++  TestPlanner.o Planner.o InputReader.o Person.o Node.o Driver.o DNode.o PList.o Publisher.o -std=c++14 -o testplanner

Main.o: Main.cpp
	clang++ -std=c++14 -c -g Main.cpp

TestPerson.o: TestPerson.cpp model/Person.h model/Driver.h model/PList.h model/Node.h
	clang++ -std=c++14 -c -g TestPerson.cpp

TestNode.o: TestNode.cpp model/Person.h model/Driver.h model/DNode.h model/Node.h
	clang++ -std=c++14 -c -g TestNode.cpp

TestPList.o: TestPList.cpp model/Person.h model/Node.h model/PList.h
	clang++ -std=c++14 -c -g TestPList.cpp

TestReader.o: TestReader.cpp model/InputReader.h model/Node.h model/DNode.h model/Driver.h
	clang++ -std=c++14 -c -g TestReader.cpp

TestPlanner.o: TestPlanner.cpp model/Person.h model/Driver.h model/Node.h model/PList.h model/DNode.h model/InputReader.h model/Planner.h
	clang++ -std=c++14 -c -g TestPlanner.cpp

Person.o: model/Person.h model/Person.cpp 
	clang++ -std=c++14 -c -g model/Person.cpp

Driver.o: model/Person.h model/Driver.h model/Driver.cpp model/PList.h
	clang++ -std=c++14 -c -g model/Driver.cpp

PList.o: model/Node.h model/Driver.h model/PList.h model/PList.cpp
	clang++ -std=c++14 -c -g model/PList.cpp

Node.o: model/Node.h model/Node.cpp model/Person.h 
	clang++ -std=c++14 -c -g model/Node.cpp

DNode.o: model/Node.h model/Driver.h model/DNode.h model/DNode.cpp
	clang++ -std=c++14 -c -g model/DNode.cpp

InputReader.o: model/InputReader.h model/InputReader.cpp model/Person.h model/Driver.h model/Node.h model/DNode.h
	clang++ -std=c++14 -c -g model/InputReader.cpp

Planner.o: model/PList.h model/Publisher.h model/Planner.h model/Planner.cpp model/Node.h model/DNode.h model/Person.h model/Driver.h
	clang++ -std=c++14 -c -g model/Planner.cpp

Publisher.o : model/Publisher.h model/Publisher.cpp model/DNode.h model/Node.h model/PList.h model/Driver.h model/Person.h
	clang++ -std=c++14 -c -g model/Publisher.cpp

clean:
	rm *.o planride testperson testnode testplist testinreader testplanner
