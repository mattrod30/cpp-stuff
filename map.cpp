#include <iostream>
#include <map>
#include <string>
using namespace std;

class Person {
private:
	string firstName, lastName;
	bool gender;
	int age;
public:
	Person(string argF, string argL, bool argG, int argA);

	void setFName(string);
	void setLName(string);
	void setGender(bool);
	void setAge(int);

	string getFName();
	string getLName();
	bool getGender();
	int getAge();

	void Display();
};

class Student : public Person {
private:
	int cosID;

public:
	Student(int argID, string argFN, string argLN, bool argG, int argAge);

	void setID(int arg);
	int getID(void);

	void Display();
};

int main(void) {
	Student* temp;
	map<int, Student*> roster;
	map<int, Student*> ::iterator cur;
	int userInput;

	temp = new Student(939337, "Matthew", "Rodriguez", true, 19);
	roster[temp->getID()] = temp;
	temp = new Student(574833, "Bruce", "Wayne", true, 43);
	roster[temp->getID()] = temp;
	temp = new Student(676767, "LeBron", "James", true, 41);
	roster[temp->getID()] = temp;
	temp = new Student(947329, "Donald", "Trump", true, 78);
	roster[temp->getID()] = temp;
	temp = new Student(345280, "Minnie", "Mouse", false, 400);
	roster[temp->getID()] = temp;

	for (cur = roster.begin(); cur != roster.end(); cur++) {
		cout << "key: " << cur->first << endl;
		(cur->second)->Display();
	}

	cout << "\nEnter a student id: ";
	cin >> userInput;
	bool isInDatabase = false;

	for (cur = roster.begin(); cur != roster.end(); cur++) {
		if (cur->first == userInput) {
			cout << "Data for ID: " << userInput << endl;
			roster[userInput]->Display();

		}
		if(isInDatabase){
			cout << "Data for ID: " << userInput << endl;
			roster[userInput]->Display();
		}
		else {
			cout << "Not found in database!" << endl;
		}

	}

	return 0;
}

Person::Person(string argF, string argL, bool argG, int argA)
{
	setFName(argF);
	setLName(argL);
	setGender(argG);
	setAge(argA);
}

void Person::setFName(string arg)
{
	arg[0] = toupper(arg[0]);
	firstName = arg;
}
void Person::setLName(string arg)
{
	arg[0] = toupper(arg[0]);
	lastName = arg;
}
void Person::setGender(bool arg)
{
	gender = arg;
}
void Person::setAge(int arg)
{
	age = arg;
}

string Person::getFName()
{
	return firstName;
}
string Person::getLName()
{
	return lastName;
}
bool Person::getGender()
{
	return gender;
}
int Person::getAge()
{
	return age;
}

void Person::Display()
{
	cout << getFName() << " " << getLName() << " ";
	if (getGender())
	{
		cout << "Male";
	}
	else
		cout << "Female";
	cout << " Age : " << getAge() << endl << endl;
}
Student::Student(int argID, string argFN, string argLN, bool argG, int argAge):Person(argFN,  argLN,  argG,  argAge){
	setID(argID);
}

void Student::setID(int arg) {
	cosID = arg;
}
int Student::getID(void) {
	return cosID;
}

void Student::Display() {
	Person::Display();
	
}
