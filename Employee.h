#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;
class Employee {

  public:
	string name;
	string position;
	int age;

	Employee(const string& name, const string& position, int age);
	friend ostream& operator<<(ostream& os, const Employee& employee);
};
class Book {
  public:
	string author;
	string category;
	int pages;
	string status;

	Book(const string& a, const string& c, int p, const string& s);
	friend ostream& operator<<(ostream& os, const Book& Book);
};
#endif // EMPLOYEE_H
