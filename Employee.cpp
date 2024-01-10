#include "Employee.h"
Employee::Employee(const string& name, const string& position, int age)
	: name(name), position(position), age(age)
{
}
ostream& operator<<(ostream& os, const Employee& employee)
{
	os << "Name: " << employee.name << ", Position: " << employee.position
	   << ", Age: " << employee.age;
	return os;
}
Book::Book(const string& a, const string& c, int p, const string& s)
	: author(a), category(c), pages(p), status(s)
{
}

ostream& operator<<(ostream& os, const Book& book)
{
	os << "Author: " << book.author << ", Category: " << book.category
	   << ", Pages: " << book.pages << ", Status: " << book.status;
	return os;
}
