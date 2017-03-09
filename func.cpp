/* 	Name: A. Atshan
	Class: CIS 160 ME1
	Date:
	program:
	description:
*/

#include <iostream>
#include <string>
using namespace std;

// prototype
string setname();
int setage();
float setGPA();

void print(string, int, float);

int main() {
	string name;
	int age;
	float gpa;
	
	name = setname();
	age = setage();
	gpa = setGPA();
	
	print(name, age, gpa);
	
	return 0;
	
}

string setname() {
	string n;
	cout << "What is your name : ";
	getline(cin, n);
	return n;
}

int setage() {
	int a;
	cout << "Enter your age : ";
	cin >> a;
	return a;
	
}

float setGPA() {
	float g;
	cout << "Enter your GPA : ";
	cin >> g;
	return g;
}

void print(string sname, int age, float gpa) {
	cout << sname << endl;
	cout << age << endl;
	cout << gpa << endl;
}
