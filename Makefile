



all: planride testperson

planride : main.o
	clang++ main.o -std=c++14 -o planride
	
testperson : testPerson.o person.o driver.o plist.o node.o
	clang++ testPerson.o person.o driver.o plist.o node.o -std=c++14 -o testperson

main.o: main.cpp
	clang++ -std=c++14 -c -g main.cpp

testPerson.o: testPerson.cpp Model/person.h Model/driver.h Model/plist.h Model/node.h
	clang++ -std=c++14 -c -g testPerson.cpp

person.o: Model/person.h Model/person.cpp 
	clang++ -std=c++14 -c -g Model/person.cpp

driver.o: Model/person.h Model/driver.h Model/driver.cpp Model/plist.h
	clang++ -std=c++14 -c -g Model/driver.cpp

plist.o: Model/node.h Model/driver.h Model/plist.h Model/plist.cpp
	clang++ -std=c++14 -c -g Model/plist.cpp

node.o: Model/node.h Model/node.cpp Model/person.h 
	clang++ -std=c++14 -c -g Model/node.cpp

clean:
	rm *.o planride testperson
