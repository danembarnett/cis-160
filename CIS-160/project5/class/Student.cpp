//Student.cpp


#include <iostream>

#include "Student.h"

using namespace std;

// default constructor initialize member variable at the start of the object call.
Student::Student()
{
    name = "";
    id = 0;
    score1 = 0;
    score2 = 0;
    score3 = 0;
    avg = 0;
    grade = ' ';
}
// destructor is used to destruct the object at the end of the program .
Student::~Student() {}

// sets value for all private member variables.
void Student::setInput()
{
    cout << "Enter Name : "; getline(cin, name);
    cout << "Enter ID : "; cin >> id;
    cout << "Enter Test 1 Score : "; cin >> score1;
    cout << "Enter Test 2 Score : "; cin >> score2;
    cout << "Enter Test 3 Score : "; cin >> score3;
    avg = getAVG();
    grade = getGrade();
}

// return float for the average of member variable score1, score2 and score3.
float Student::getAVG() const

{
    return (score1 + score2 + score3) / 3;
}

// converts float avg and return char grade.
char Student::getGrade() const
{
    if (avg >= 90)
        return 'A';
    else if (avg >= 80 && avg < 90)
        return 'B';
    else if (avg >= 70 && avg < 80)
        return 'C';

    else if (avg >= 60 && avg < 70)
        return 'D';

    else {
        return 'F';
    }
}

// return string to determine if the student pass or fail.
string Student::passFail() const
{
    if (avg >= 70)
        return "You Passed.\n";
    else {
        return "You Failed.\n";
    }
}

// prints out all member variable and member function.
void Student::getOutput() const
{
    cout << "\nEmployee Name :\t" << name << endl;
    cout << "ID Number :\t\t" << id << endl;
    cout << "Test :\n\t1-    " << score1 << endl;
    cout << "\t2-    " << score2 << endl;
    cout << "\t3-    " << score3 << endl;
    printf("Average :\t%2.2f\n", getAVG());
    cout << "Grade :\t\t" << getGrade() << "    "<< passFail();
}