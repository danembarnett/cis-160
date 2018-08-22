//Student.h

//Header file used to declare member variable and member function.
#ifndef PROJECTC_STUDENT_H  // Guards
#define PROJECTC_STUDENT_H  // Guards

using namespace std;
class Student
{
// private cannot be accessed from outside programs
private:
    // member variables.
    string name;
    int id;
    short score1, score2, score3;
    float avg;
    char grade;

    // member function
    float getAVG() const;         // return float for the average of member variable score1, score2 and score3.
    char getGrade() const;        // converts float avg and return char grade.
    string passFail() const;      // return string to determine if the student pass or fail.

//public can be access by other programs such as main.
public:
    Student();              // default constructor.
    ~Student();             // destructor.
    void setInput();   // sets value for all private member variables.
    void getOutput() const; // prints out all member variable and member function.

};

#endif                      // Guards