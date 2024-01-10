testEmployee: testEmployee.o Employee.o
	g++ -g $^ -o $@

Employee.o: Employee.cpp Employee.h Map.h
	g++ -g -c -Wall -pedantic $< -o $@

testEmployee.o: testEmployee.cpp Employee.h Map.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm Employee.o testEmployee.o testEmployee