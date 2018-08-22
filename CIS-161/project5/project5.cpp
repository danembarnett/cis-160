/**********************************************************
 * Name        : Dane Barnett                             *
 *             : Louis Taveras                            *
 * Class       : CIS 161 ME1                              *
 * Date        : November 25, 2017                         *
 * Program     : LAB 5- CIS 161 Class Statistics          *
 * Description : A program to keep records and print      *
 				 statistical analysis for a class of      *
				 students based on their ID numbers an    *
				 averages of each student. The methods    *
				 used in the program is search and sort   *
				 functions called binary search and       *
				 selection sorts.                         *
***********************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int size = 20; 

typedef struct Studinfo
{
	int ID, Quiz1, Quiz2, Quiz3;
	float qAverage;
} Student[size];

// Function Prototypes
void function1(Studinfo *);
void function2(const Studinfo *);
void function3(Studinfo *);
	void display(const Studinfo *, const int *);
	void sortArray(Studinfo *);
	int binarySearchAverage(const Studinfo *, float);
void function4(Studinfo *);
	int binarySearchID(const Studinfo *, int);
void function5(Studinfo *);


// main program
int main()
{	
	Student stud;
	
	function1(stud);
	function2(stud);
	function3(stud);
	function4(stud);
	function5(stud);
	


    return 0;
}

/* function1() reads a list of records from a file and calculates the average of each student*/
void function1(Studinfo *s)
{
	ifstream file("pr2data.txt");
	
	if (!file)
        cout << "Error! either file cannot open or does not exist! " << endl;
    else
        {
        for (int i = 0; i <size;i++)	
         {
			 file >> (*s).ID;
			 file >> (*s).Quiz1;
			 file >> (*s).Quiz2;
			 file >> (*s).Quiz3;
			
			 (*s).qAverage = ((*s).Quiz1 +(*s).Quiz2 +(*s).Quiz3) / 3.00;
			 cout<<showpoint<<fixed<<setprecision(2);
			
		/*this is just to show that its displaying the correct info*/	
		//cout<<(*s).ID<<" "<< (*s).Quiz1<<" "<<(*s).Quiz2<<" "<<(*s).Quiz3<<" "<<(*s).qAverage<<endl;
			s++;
		}
        }
}

/* function2() list the id and averages of all student with a score above 85.00*/
void function2(const Studinfo * a)
{
	cout << "\n---------------------------------------------------------\n";
	//for loop that prints the id and average og students if the average is above 85.
	for (int i = size; i>0; i--)
	{
		if((*a).qAverage >= 85.00)
		{
			cout << "\nID #: " << (*a).ID<< " average is " << (*a).qAverage;
		}
		a++;
	}
	cout << "\n---------------------------------------------------------";
}

/* function3() calls the sortArray() to sort the array of students in ascending order
 *  based on their average and uses the binarySearchAverage() function to list all to
 *  return the index of each student with averages equal to or above 85. */
void function3(Studinfo * a)
{


	// an array declaration to store the index position of students above 85.
	int *positionAbove85 = new int[size];

	//sortArray() is used in ascending order based on average.
	sortArray(a);

	// for loop is used to execute binarySearchAverage which returns the index of averages above 85.
	for (int i = 0, j = 0; i < size; i++)
	{
		if(((*(a + i)).qAverage) >= 85.00)
		{
			*(positionAbove85 + j) = binarySearchAverage(a, ((*(a + i)).qAverage));
			j++;
		}

	}

	display(a, positionAbove85);
}

/* display() is used to display the the results of function() */
void display(const Studinfo * a, const int * positionAbove85)
{
	//print the positions returned in the array.
	cout << "\nThe position returned for positions above 85 is ";
	cout << *(positionAbove85+0)<< ", "<< *(positionAbove85+1) << ", "<< *(positionAbove85+2) << ", "<< *(positionAbove85+3) << endl;
	cout << "---------------------------------------------------------\n";

	//print of the array sorted in ascending order based on the average of each student.
	cout << "\t  CIS Department-- Fall 2017 "<<endl;
	cout << "\t   CIS 161 Class Statistics"<<endl;
	cout <<"-----------------------------------------------\n";
	cout <<"-----------------------------------------------\n";
	cout << showpoint<<fixed<<setprecision(2);
	cout <<"\n\nSTUDENT\t\tQuiz1\tQuiz2\tQuiz3\tAverage\n";
	cout <<"-------\t\t -----\t-----\t-----\t------\n";
	for (int i= 0; i < size; i++)
	{

		cout << (*(a+i)).ID <<"\t\t"<< (*(a+i)).Quiz1 <<"\t"<< (*(a+i)).Quiz2 <<"\t"<< (*(a+i)).Quiz3 <<"\t "<<(*(a+i)).qAverage<<endl;

	}
	cout <<"-----------------------------------------------\n";
}
/* sortArray() is used to sort the averages of all student in ascending order */
void sortArray(Studinfo *s)
{
	int temp;
	float tempfloat;
	bool swap;

	do
	{
		swap = false;
		for (int i = 0; i < size-1;i++)
		{
			if (((*(s + i)).qAverage) > (*(s+(i + 1))).qAverage)
			{
				temp = (*(s + i)).ID;
				(*(s + i)).ID = (*(s+(i + 1))).ID;
				(*(s+(i + 1))).ID = temp;

				temp = (*(s + i)).Quiz1;
				(*(s + i)).Quiz1 = (*(s+(i + 1))).Quiz1;
				(*(s+(i + 1))).Quiz1 = temp;

				temp = (*(s + i)).Quiz2;
				(*(s + i)).Quiz2 = (*(s+(i + 1))).Quiz2;
				(*(s+(i + 1))).Quiz2 = temp;

				temp = (*(s + i)).Quiz3;
				(*(s + i)).Quiz3 = (*(s+(i + 1))).Quiz3;
				(*(s+(i + 1))).Quiz3 = temp;

				tempfloat = (*(s + i)).qAverage;
				(*(s + i)).qAverage = (*(s+(i + 1))).qAverage;
				(*(s+(i + 1))).qAverage = tempfloat;

				swap = true;
			}
		}
	} while(swap);
}

/* binarySearchAverage is used to return the index of each student with an average above 85 */
int binarySearchAverage(const Studinfo * s, float value)
{
	int 	first = 0,
			last = size - 1,
			middle,
			position =-1;

	bool 	found = false;

	while(!found && first <= last)
	{
		middle = (first + last) / 2;
		if ((*(s+middle)).qAverage == value)
		{
			found = true;
			position = middle;
		}
		else if ((*(s+middle)).qAverage > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

/* function4() is used to sort the array based on the ID number and also used the
 * selectionsort method. The function also uses the selection sort method and prints the results */
void function4(Studinfo * a)
{
	int startScan, minIndex;
	int minValue[4];
	float minFloat;
	int comparisonCount = 0;

	for (startScan = 0; startScan < (size-1); startScan++)
	{
		minIndex = startScan;
		minValue[0] = ((*(a + startScan)).ID);
		for(int index = startScan + 1; index < size; index++)
		{
			// count included to count the amount of comparison
			comparisonCount++;
			if (((*(a + index)).ID) < minValue[0])
			{
				minValue[0] = ((*(a + index)).ID);
				minValue[1] = ((*(a + index)).Quiz1);
				minValue[2] = ((*(a + index)).Quiz2);
				minValue[3] = ((*(a + index)).Quiz3);
				minFloat = ((*(a + index)).qAverage);
				minIndex = index;
			}
		}
		(*(a + minIndex)).ID = (*(a + startScan)).ID;
		(*(a + startScan)).ID = minValue[0];
		(*(a + minIndex)).Quiz1 = (*(a + startScan)).Quiz1;
		(*(a + startScan)).Quiz1 = minValue[1];
		(*(a + minIndex)).Quiz2 = (*(a + startScan)).Quiz2;
		(*(a + startScan)).Quiz2 = minValue[2];
		(*(a + minIndex)).Quiz3 = (*(a + startScan)).Quiz3;
		(*(a + startScan)).Quiz3 = minValue[3];
		(*(a + minIndex)).qAverage = (*(a + startScan)).qAverage;
		(*(a + startScan)).qAverage = minFloat;
	}

	cout << "\t  CIS Department-- Fall 2017 "<<endl;
	cout << "\t   CIS 161 Class Statistics"<<endl;
	cout <<"-----------------------------------------------\n";
	cout <<"-----------------------------------------------\n";
	cout << showpoint<<fixed<<setprecision(2);
	cout <<"\n\nSTUDENT\t\tQuiz1\tQuiz2\tQuiz3\tAverage\n";
	cout <<"-------\t\t -----\t-----\t-----\t------\n";
	for (int i= 0; i < size; i++)
	{

		cout << (*(a+i)).ID <<"\t\t"<< (*(a+i)).Quiz1 <<"\t"<< (*(a+i)).Quiz2 <<"\t"<< (*(a+i)).Quiz3 <<"\t "<<(*(a+i)).qAverage<<endl;

	}

	cout <<"-----------------------------------------------\n";
	cout <<"\nComparison count is " << comparisonCount << endl;
}

/* function5() is used to perform a binary search that will display the student's ID, test and averages.
 * The function also contains a loop that repeats until the used inputs no. */
void function5(Studinfo * a)
{
	int input;
	int position;
	bool again = true;
	string inputS;
	cout << "Do you want to enter a student ID? ";
	cin >> inputS;

	while (again)
	{
		//everything went well, we'll get out of the loop and return the value

		if (inputS == "yes" || inputS == "y" || inputS == "Yes")
		{
			cout << "Please enter student ID: " << flush;
			cin >> input;
			position = binarySearchID(a, input);
			cout <<"\n\nSTUDENT\t\tQuiz1\tQuiz2\tQuiz3\tAverage\n";
			cout << (*(a+position)).ID <<"\t\t"<< (*(a+position)).Quiz1 <<"\t"<< (*(a+position)).Quiz2 <<"\t"<< (*(a+position)).Quiz3 <<"\t "<<(*(a+position)).qAverage<<endl;
			cout << "Do you want to enter another student : ";
			cin >> inputS;
			if (inputS == "yes" || inputS == "y" || inputS == "Yes")
				again = true;
		}
		else if (inputS == "no" || inputS == "n" || inputS == "No")
			again = false;
		else
		{
			cout << "Invalid input, please enter yes or no" << endl;
			again = true;
		}
	}


}

/* binSearchId() is used to return the position/index of the student's ID */
int binarySearchID(const Studinfo * s, int value) {
	int first = 0,
			last = size - 1,
			middle,
			position = -1;

	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if ((*(s + middle)).ID == value) {
			found = true;
			position = middle;
		} else if ((*(s + middle)).ID > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}
