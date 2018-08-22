/**********************************************************
 * Name        : Dane Barnett                             *
 *             : Louis Taveras                            *
 * Class       : CIS 161 ME1                              *
 * Date        : October 25, 2017                         *
 * Program     : LAB 3- CIS 161 Class Statistics          *
 * Description : A program to keep records and print      *
 				 statistical analysis for a class of      *
				 students. There are three quizzes for    *
				 each student during the term. The program* 
				 calculates the statistics for each       *
				 student and for each quiz. After         *
				 gathering the data, we then output it to * 
				 a file.                                  *              
***********************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;


typedef vector<int> iVec;
typedef vector<float> fVec;

// Function Prototypes
void printAll(int ,iVec, iVec, iVec, iVec, iVec, iVec, fVec, fVec);
float findQZAVG(int, float, float);
int findLow(int, iVec);
int findHigh(int, iVec);
void findSTAVG(int, iVec, iVec, iVec, fVec &);
void getData(int &, iVec &, iVec &, iVec &, iVec &);


int main()
{	
	//Declarations
    iVec  ID, Quiz1, Quiz2, Quiz3, highScore, lowScore;
    fVec  sAVG, qAverage;
    int     numOfElements;
	
	//Function Calls
    getData(numOfElements, ID, Quiz1, Quiz2, Quiz3);
    cout<< ID[1];
    findSTAVG(numOfElements, Quiz1, Quiz2, Quiz3, sAVG);
    highScore[0] = findHigh(numOfElements, Quiz1);
    highScore[1]=findHigh(numOfElements, Quiz2);
    highScore[2] = findHigh(numOfElements, Quiz3);
    lowScore[0] = findLow(numOfElements, Quiz1);
    lowScore[1] = findLow(numOfElements, Quiz2);
    lowScore[2] = findLow(numOfElements, Quiz3);
    qAverage[0] = findQZAVG(numOfElements, highScore[0], lowScore[0]);
    qAverage[1] = findQZAVG(numOfElements, highScore[1], lowScore[1]);
    qAverage[2] = findQZAVG(numOfElements, highScore[2], lowScore[2]);
    printAll(numOfElements, ID, Quiz1, Quiz2, Quiz3, highScore, lowScore, sAVG, qAverage);

    return 0;
}
/* In this function we take the input data from a file called pr2data.txt.
   We also get the number of elements read from the counter.  */
void getData(int & elm, iVec & ID, iVec & Q1, iVec & Q2, iVec & Q3)
{
    ifstream file("pr2data.txt");
	
	// This if statement is used to check if the file exists
    if (!file)
        cout << "Error! either file cannot open or does not exist! " << endl;
    else
        {
            int id, q1, q2, q3;
            while (file>> id)
            {
				ID.push_back(id);
                file>> q1;
				Q1.push_back(q1);
				file >> q2;
				Q2.push_back(q2);
                file>> q3;
                Q3.push_back(q3);
            }
            elm = ID.size() - 1;
        }
        
        /*	while (fin >> idnum)
	{
			ids.push_back(idnum);
			fin >> salary;
			sals.push_back(salary);
	}*/
}

//This function finds the float average for each student.
void findSTAVG(int elm, iVec Q1, iVec Q2, iVec Q3, fVec & sAVG)
{
    for (int i = 0; i < elm; i++)
        sAVG[i] = (Q1[i] + Q2[i] + Q3[i]) / 3.00;
}

//This function returns the highest quiz.
int findHigh(int elm, iVec Quiz)
{
    int high = Quiz[0];
    for (int i = 1; i < elm; i++)
    {
        if (Quiz[i] > high)
            high = Quiz[i];
    }
    return high;
}

//This function returns the lowest quiz.
int findLow(int elm, iVec Quiz)
{
    int low = Quiz[0];
    for (int i = 1; i < elm; i++)
    {
        if (Quiz[i] < low)
            low = Quiz[i];
    }
    return low;
}

// This function returns the quiz average.
float findQZAVG(int elm, float highScore, float lowScore)
{
    return (highScore + lowScore) / 2.00;
}

//This function opens an ouput file and outputs the data gathered to that file.
void printAll(int elm, iVec ID, iVec Q1, iVec Q2, iVec Q3, iVec hScore, iVec lScore, fVec sAVG, fVec qAverage)
{
	ofstream outputFile;
	
	outputFile.open("outputdata.txt");
	outputFile << "\t  CIS Department-- Fall 2017 "<<endl;
	outputFile << "\t   CIS 161 Class Statistics"<<endl;
	outputFile <<"-----------------------------------------------\n";
	outputFile <<"-----------------------------------------------\n";
	outputFile << showpoint<<fixed<<setprecision(2);
	outputFile <<"\n\nSTUDENT\t\tQuiz1\tQuiz2\tQuiz3\tAverage\n"; 
	outputFile <<"-------\t\t -----\t-----\t-----\t------\n";
	for (int i= 0; i < elm; i++)
		{
			 
        outputFile << ID[i] <<"\t\t"<< Q1[i] <<"\t"<< Q2[i] <<"\t"<< Q3[i] <<"\t "<<sAVG[i]<<endl;
             
            }
            
    outputFile <<"-----------------------------------------------\n";      
    outputFile <<"High Score\t"<<hScore[0]<<"\t"<< hScore[1]<<"\t"<<hScore[2]<<endl;
    outputFile <<"----------\n";
	outputFile <<"Low Score\t" <<lScore[0] <<"\t"<<lScore[1]<<"\t"<<lScore[2]<<endl;
	outputFile <<"---------\n";
	outputFile <<"Quiz Average\t"<<qAverage[0]<<"\t"<<qAverage[1]<<"\t"<<qAverage[2]<<endl;
	outputFile <<"------------\n";
	
	
	outputFile.close();
}

