
all: main testperson

planride : main.o
	clang++ main.o -std=c++14 -o planride
	
testperson : testPerson.o person.o driver.o
	clang++ testPerson.o person.o driver.o -std=c++14 -o testperson

main.o: main.cpp
	clang++ -std=c++14 -c -g main.cpp

testPerson.o: testPerson.cpp Model/person.h Model/person.cpp Model/driver.cpp Model/driver.h
	clang++ -std=c++14 -c -g testPerson.cpp

person.o: Model/person.h Model/person.cpp 
	clang++ -std=c++14 -c -g Model/person.cpp

driver.o: Model/person.h Model/person.cpp Model/driver.cpp Model/driver.h
	clang++ -std=c++14 -c -g Model/driver.cpp

clean:
	rm *.o planride testperson
