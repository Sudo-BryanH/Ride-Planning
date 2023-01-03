



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

TestPerson.o: TestPerson.cpp model/Person.h model/Driver.h model/PList.h model/Node.h
	clang++ -std=c++14 -c -g TestPerson.cpp

TestNode.o: TestNode.cpp model/Person.h model/Driver.h model/DNode.h model/Node.h
	clang++ -std=c++14 -c -g TestNode.cpp

TestPList.o: TestPList.cpp model/Person.h model/Node.h model/PList.h
	clang++ -std=c++14 -c -g TestPList.cpp

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

clean:
	rm *.o planride testperson testnode testplist
