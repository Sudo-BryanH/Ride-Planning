
all: main testperson

planride : main.o
	clang++ main.o -o planride
	
testperson : testPerson.o person.o driver.o
	clang++ testPerson.o person.o driver.o -o testperson

main.o: main.cpp
	clang++ -c -g main.cpp

testPerson.o: testPerson.cpp Model/person.h Model/person.cpp Model/driver.cpp Model/driver.h
	clang++ -c -g testPerson.cpp

person.o: Model/person.h Model/person.cpp 
	clang++ -c -g person.cpp

driver.o: Model/person.h Model/person.cpp Model/driver.cpp Model/driver.h
	clang++ -c -g driver.cpp

clean:
	rm *.o planride testperson
