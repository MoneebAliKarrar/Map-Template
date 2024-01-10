#include "Employee.h"
#include "Map.h"

typedef unsigned int ID;
typedef string Title;

typedef Map<ID, Employee> Database1;
typedef Map<Title, Book> Database2;

using namespace std;

void addEmployees(Database1& database);
void addBooks(Database2& bookdatabase);
void modifyEmployees(Database1& database);
void modifyBooks(Database2& bookdatabase);
void test();
void testAddingAameKey();
void testSearchUnAvailableKey();

int main()
{
	Database1 employeedatabase;
	Database2 bookdatabase;

	addEmployees(employeedatabase);
	addBooks(bookdatabase);

	Database1 newDatabase = employeedatabase;
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));
	modifyEmployees(newDatabase);
	cout << "Employee Original database:" << endl << employeedatabase << endl;
	cout << "Employee Modified database:" << endl << newDatabase << endl;

	employeedatabase = newDatabase;

	cout << "Employee Database after the assignment:" << endl
		 << employeedatabase << endl;

	cout << "Books Original database:" << endl << bookdatabase << endl;
	modifyBooks(bookdatabase);
	cout << "Books Modified database:" << endl << bookdatabase << endl;
	test();
}
void addEmployees(Database1& employeedatabase)
{
	employeedatabase.add(761028073, Employee("Jan Kowalski", "salesman", 28));
	employeedatabase.add(510212881, Employee("Adam Nowak", "storekeeper", 54));
	employeedatabase.add(730505129, Employee("Anna Zaradna", "secretary", 32));
}

void modifyEmployees(Database1& employeedatabase)
{
	Employee* employeePtr;

	employeePtr = employeedatabase.find(510212881);
	employeePtr->position = "salesman";

	employeePtr = employeedatabase.find(761028073);
	employeePtr->age = 29;
}
void test()
{
	testAddingAameKey();
	testSearchUnAvailableKey();
}
void testAddingAameKey()
{
	cout << "---------------------------------------------------------------"
		 << endl;
	cout << "testing addition with the same key:" << endl;
	Database1 MyDatabase;
	MyDatabase.add(123, Employee("MONEEB", "BOSS", 22));
	MyDatabase.add(1234, Employee("ALI", "NOTBOSS", 52));
	cout << "Original database:" << endl << MyDatabase << endl;
	MyDatabase.add(123, Employee("Mohammed", "BOSS", 50));
	cout << "Modified database:" << endl << MyDatabase << endl;
}
void testSearchUnAvailableKey()
{
	cout << "---------------------------------------------------------------"
		 << endl;
	cout << "testing searching unavailable  key:" << endl;
	Database1 MyDatabase;
	MyDatabase.add(123, Employee("MONEEB", "BOSS", 22));
	MyDatabase.add(1234, Employee("ALI", "NOTBOSS", 52));
	cout << "Original database:" << endl << MyDatabase << endl;
	Employee* emp1;
	emp1 = MyDatabase.find(453);
	Employee* emp2;
	emp2 = MyDatabase.find(123);
	if (emp1 == nullptr) {
		cout << "Hey this is not available  in our database " << endl;
	}
	else {
		cout << "This guy is here :" << *emp1 << endl;
	}
	if (emp2 == nullptr) {
		cout << "Hey this is not unavailable  in our database " << endl;
	}
	else {
		cout << "This guy is here :" << *emp2 << endl;
	}
}
void addBooks(Database2& bookdatabase)
{
	bookdatabase.add("The black tulip",
					 Book("Jan Kowalski", "History", 28, "bookshelf"));
	bookdatabase.add("Endless road",
					 Book("Adam Nowak", "Kids", 54, "borrowed"));
	bookdatabase.add("Long distance",
					 Book("Anna Zaradna", "Art", 32, "borrowed"));
}
void modifyBooks(Database2& bookdatabase)
{
	Book* bookPtr;

	bookPtr = bookdatabase.find("The black tulip");
	bookPtr->status = "borrowed";

	bookPtr = bookdatabase.find("Endless road");
	bookPtr->pages = 29;
}
