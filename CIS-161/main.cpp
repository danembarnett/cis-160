/* Name: Dane Barnett
   Class: CIS 160 ME1
   Date: May 5, 2017
   Program: A client file(main.cpp) that creates an object of the
           Student class and use the object to print out results
           of Student's grade.
*/

#include <iostream>
#include "Student.h"

using namespace std;

void start(Student);

//main() creates an object s1 from the student class and
// execute the start() function with s1 as an argument.
int main()
{
    Student s1;

    start(s1);

    return 0;
}

/* the start() executes object s1 from the class Student
 * and call public member function setInput() and getOutput() */
void start(Student s1)
{
    s1.setInput();
    s1.getOutput();
}