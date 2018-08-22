/**********************************************************
 * Name        : Dane Barnett                             *
 * Class       : CIS 260 ME1                              *
 * Date        : February 21, 2018                        *
 * Program     : LAB 1- CIS 260 Class Statistics          *
 * Description : Write a program to calculate last        *
 *semesters GPA for all the students in your class. Data  *
 *for each student consists of the students' name, id     *
 *number, and the number of courses he/she completed. For *
 *each course the data is, the course number, number of   *
 *credits, and the grade they obtained for the course.    *
 *you must also calculate the students GPA.               *
***********************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//declaration of struct
const int size = 3;
typedef struct Course1
{
    string courseNum;
    int numOfCredit;
    char grade;
    Course1 *next;
}*courseInfo[size], *Course;

typedef struct studentInfo
{
    string name;
    int id;
    int numOfCourses;
    float GPA;

} Student[size];

// function prototype
int inputData(Student, courseInfo, int &);
void createCourseNode(Course1 *, float &, int &);
Course setNode(float &, int &);
void print(Student, courseInfo, int);
float calcGPA(int, char);
void header(ofstream &);
int printStudent(Student, courseInfo, ofstream &, int);
void printCourses(Course1 *, ofstream &);
void deleteData(courseInfo);

//main() program
int main()
{
    // main() variable declarations includes a static variable
    Student studentArray;
    courseInfo courseArray;
    static int totalCredit;

    //function in main()
    inputData(studentArray, courseArray, totalCredit);
    print(studentArray, courseArray, totalCredit);
    deleteData(courseArray);
}

/*inputData() takes an array of student and courses and creates a linked list
based on the number of courses. Also, totalGPA is calculated through the accumation
of semesterGPA() diveded by the number of courses that was taken*/
int inputData(Student studentArray, courseInfo courseArray, int & totalCredit)
{
    for (int i = 0; i < size; i++)
    {
        char choice;
        cout << "Do you want to enter a student? ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            float semesterGPA = 0.0;
            float totalGPA = 0.0;

            courseArray[i] = new Course1;
            cout << "Enter Name : ";
            cin.get();
            getline(cin, studentArray[i].name);
            cout << "Enter ID : ";
            cin >> studentArray[i].id;
            cout << "Enter number of courses : ";
            cin >> studentArray[i].numOfCourses;

            for (int j = 0; j < studentArray[i].numOfCourses; j++)
            {
                createCourseNode(courseArray[i], semesterGPA, totalCredit);
            }
            totalGPA += semesterGPA;
            studentArray[i].GPA = (totalGPA / studentArray[i].numOfCourses);
        }
        else
        {
            return 0;
        }
    }
}

/*createCourseNode() is used to create a new Course node each time it is called,
this function performs a linked list data structure*/
void createCourseNode(Course1 * head, float & semesterGPA, int & totalCredit)
{
    if (head == NULL) {

        head = setNode(semesterGPA, totalCredit);
    }

    else {
        while (head->next != NULL) {

            head = head->next;
        }

        head->next = setNode(semesterGPA, totalCredit);
    }
}

/* setNode() function is used to enter data in a newly created node and returns
the data to the createCourseNode() function*/
Course setNode(float & semesterGPA, int & totalCredit)
{
    Course  node = new Course1;

    cin.get();
    cout << "Course ID : "; getline(cin, (node->courseNum));
    cout << "Course Credit : "; cin >> node->numOfCredit;
    totalCredit += node->numOfCredit;
    cout << "Course Grade : "; cin >> node->grade;
    semesterGPA += calcGPA(node->numOfCredit, node->grade);

    node->next = NULL;
    return node;
}

/* calcGPA() function returns a float when grade and credit is entered
in the parameter*/
float calcGPA(int credit, char grade)
{
    const int   A=4, B=3, C=2, D=1, F=0;

    switch(grade)
    {
        case 'A':
            return (A * credit)/credit;
        case 'B':
            return (B * credit)/credit;
        case 'C':
            return (C * credit)/credit;
        case 'D':
            return (D * credit)/credit;
        case 'F':
            return (F * credit)/credit;
    }
}
/*the print() function takes all arguments and calls all print function
necessary to print the data, Also output.txt is created to output all data*/
void print(Student studentArray, courseInfo courseArray, int totalCredit)
{
    ofstream output("output.txt");
    header(output);
    printStudent(studentArray, courseArray, output, totalCredit);
    output.close();
}

//header() function input the header data to output.txt
void header(ofstream & output)
{
    output << "&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~" << endl
           << "\t             Passaic County Community College" << endl
           << "\t           CIS 161 Students expectation report" << endl
           << "\t\t               Fall - 2017 Semester" << endl
           << "&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~&~" << endl
           << left << setw(14) << "Name"
           << left << setw(8)  << "ID#"
           << left << setw(15) << "# of courses"
           << left << setw(9)  << "Course"
           << left << setw(8)  << "Grade"
           << left << setw(10)  << "Credits"
           << left << setw(9)  << "GPA" << endl;
}

//printStudent function is used to output all of student's data to output.txt
int printStudent(Student studentArray, courseInfo courseArray, ofstream & output, int totalCredit)
{
    for (int i = 0; i < size; i++)
    {
        output << left << setw(14) << studentArray[i].name
               << left << setw(13) << studentArray[i].id
               << left << setw(10) << studentArray[i].numOfCourses;
        printCourses(courseArray[i]->next, output);
        output << left << setw(6)  << studentArray[i].GPA << endl << endl;
    }
}

/*printCourses function is a recursive function used to output all of student's
data to output.txt*/
void printCourses(Course head, ofstream & output)
{
    if(head == NULL)
        return;

    output << left << setw(12)  << head->courseNum
           << left << setw(8)  << head->grade
           << left << setw(7)  << head->numOfCredit;
    if (head->next != NULL)
        output << endl << left << setw(37) << "";
    printCourses(head->next, output); //recursion
}

//deleteData() function deletes all data in the course linked list
void deleteData(courseInfo courseArray)
{
    for (int i = 0; i < size; i++)
    {
        Course temp;
        while (courseArray[i] != NULL)
        {
            temp = courseArray[i];
            courseArray[i] = courseArray[i]->next;
            delete temp;
        }
    }
}
