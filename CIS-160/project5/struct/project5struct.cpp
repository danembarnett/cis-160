/*      Name: Dane Barnett
        Class: CIS 160 ME1
        Date: March 29, 2017
        Program: Project 5(Part 1 of 2)
        Description: A program that output Student average test grade
                     and determine if the student has passed or failed.
*/

#include <iostream>

using namespace std;

struct Student {

    string name;
    int id;
    short score1, score2, score3;
    float avg;
    char grade;
};

void start(Student &);
void input(Student &);
void average(Student &);
void convert(Student &);
void passFail();
void print(Student);

// Start of program
int main() {

    Student s1;

    start(s1);

    return 0;
}
void start(Student & s1) 
{
    input(s1);
    average(s1);
    convert(s1);
    print(s1);
}
void input(Student & s1) {

    cout << "Enter Name : "; getline(cin, s1.name);
    cout << "Enter ID : "; cin >> s1.id;
    cout << "Enter Test 1 Score : "; cin >> s1.score1;
    cout << "Enter Test 2 Score : "; cin >> s1.score2;
    cout << "Enter Test 3 Score : "; cin >> s1.score3;


}

void average(Student & s1) {

    s1.avg = (s1.score1 + s1.score2 + s1.score3) / 3;
}

void convert(Student & s1) {

    if (s1.avg >= 90)
        s1.grade = 'A';
    else if (s1.avg >= 80 && s1.avg < 90)
        s1.grade = 'B';
    else if (s1.avg >= 70 && s1.avg < 80)
        s1.grade = 'C';
    else if (s1.avg >= 60 && s1.avg < 70)
        s1.grade = 'D';
    else {
        s1.grade = 'F';
    }
}

void passFail(Student s1) {

    if (s1.avg >= 70)
        cout << "You Passed.\n";
    else {
        cout << "You Failed.\n";
    }
}

void print(Student s1) {

    cout << "\nEmployee Name :\t" << s1.name << endl;
    cout << "ID Number :\t" << s1.id << endl;
    cout << "Test :\n\t1-    " << s1.score1 << endl;
    cout << "\t2-    " << s1.score2 << endl;
    cout << "\t3-    " << s1.score3 << endl;
    printf("Average :\t%2.2f\n", s1.avg);
    cout << "Grade :\t\t" << s1.grade << "    ";
    passFail();
}