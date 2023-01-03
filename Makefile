



all: planride testperson testnode testplist testreader

planride : Main.o
	clang++ Main.o -std=c++11 -o planride
	
testperson : TestPerson.o Person.o Driver.o PList.o Node.o
	clang++ TestPerson.o Person.o Driver.o PList.o Node.o -std=c++11 -o testperson

testnode : TestNode.o Person.o Driver.o Node.o DNode.o
	clang++ TestNode.o Person.o Driver.o DNode.o Node.o -std=c++11 -o testnode

testplist : TestPList.o Person.o PList.o Node.o
	clang++ TestPList.o Person.o PList.o Node.o -std=c++11 -o testplist

testreader : TestReader.o Person.o Driver.o Node.o DNode.o Reader.o 
	clang++ TestReader.o Person.o Driver.o Node.o DNode.o Reader.o  -std=c++11 testreader

Main.o: Main.cpp
	clang++ -std=c++11 -c -g Main.cpp

TestPerson.o: TestPerson.cpp Model/Person.h Model/Driver.h Model/PList.h Model/Node.h
	clang++ -std=c++11 -c -g TestPerson.cpp

TestNode.o: TestNode.cpp Model/Person.h Model/Driver.h Model/DNode.h Model/Node.h
	clang++ -std=c++11 -c -g TestNode.cpp

TestPList.o: TestPList.cpp Model/Person.h Model/Node.h Model/PList.h
	clang++ -std=c++11 -c -g TestPList.cpp

TestReader.o: TestReader.cpp Model/Reader.h Model/Driver.h Model/DNode.h Model/Node.h json.hpp
	clang++ -std=c++11 -c -g TestReader.cpp

Person.o: Model/Person.h Model/Person.cpp 
	clang++ -std=c++11 -c -g Model/Person.cpp

Driver.o: Model/Person.h Model/Driver.h Model/Driver.cpp Model/PList.h
	clang++ -std=c++11 -c -g Model/Driver.cpp

PList.o: Model/Node.h Model/Driver.h Model/PList.h Model/PList.cpp
	clang++ -std=c++11 -c -g Model/PList.cpp

Node.o: Model/Node.h Model/Node.cpp Model/Person.h 
	clang++ -std=c++11 -c -g Model/Node.cpp

DNode.o: Model/Node.h Model/Driver.h Model/DNode.h Model/DNode.cpp
	clang++ -std=c++11 -c -g Model/DNode.cpp

Reader.o: Model/Reader.h Model/Reader.cpp Model/Person.h Model/Dnode.h Model/Node.h json.hpp
	clang++ -std=c++11 -c -g Model/Reader.cpp

json.o: json.hpp
	clang++ -std=c++11 -c -g Model/Reader.cpp json.hpp

clean:
	rm *.o planride testperson testnode testplist testreader
