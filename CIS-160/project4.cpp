/*      Name: Dane Barnett
        Class: CIS 160 ME1
        Date: March 29, 2017
        Program: St Joseph Hospital Billing
        Description: A program that computes and print a statement of charges
                     for patience being discharged from the hospital.
*/


#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

//Prototype
void setProject(int &);
void contractCalc(int, float &, float &, float &, float &, float &, float &, float &);
float internalEmployee(int);
void fileOut(int, float, float, float, float, float, float, float);
void totalFile(float, float, float, float, float, float, float);


ofstream myfile;

// Start of program
int main() {
    
    // variable declaration
    int projectNum;
    float contractCost, electrical, plumbing, roofing, landscaping, material, internal;

    myfile.open("contractor.txt");
    myfile << fixed << setprecision(2);

    setProject(projectNum);
    contractCalc(projectNum, contractCost, electrical, plumbing, roofing, material, landscaping, internal);
    totalFile(contractCost, electrical, plumbing, roofing, landscaping, material, internal);

    myfile.close();
    
    return 0;
}

// process for the name of the pateint and the day count in hospital
void setProject(int & projectNum) 
    {

    cout << "\nWelcome to Passaic County Contracting Company." << endl;
    cout << "\n*******Please enter the number of project(s): "; cin >> projectNum;
    
    while (projectNum > 5 || projectNum < 0) {
        cout << "Invalid amount! Please enter 1-5 project(s): "; cin >> projectNum;
    }


}

void contractCalc(int projectNum, float & contractCost, float & electrical, float & plumbing, float & roofing, float & landscaping, float & material, float & internal) {

    int employee;
    float totalContract[4], totalElectrical[4], totalPlumbing[4], totalRoofing[4], totalLandscaping[4], totalMaterial[4], totalInternal[4];

    for (int num=1; projectNum > 0; num++) {

        cout << "\n\nWelcome to Project #" << num << "\n\n\tPlease enter contract amount : "; cin >> totalContract[num-1];
        contractCost += totalContract[num-1];
        cout << "\n\tPlease enter cost of Electrical : "; cin >> totalElectrical[num-1];
        electrical += totalElectrical[num-1];
        cout << "\n\tPlease enter cost of Plumbing : "; cin >> totalPlumbing[num-1];
        plumbing += totalPlumbing[num-1];
        cout << "\n\tPlease enter cost of Roofing : "; cin >> totalRoofing[num-1];
        roofing += totalRoofing[num-1];
        cout << "\n\tPlease enter cost of Landscaping : "; cin >> totalLandscaping[num-1];
        landscaping += totalLandscaping[num-1];
        cout << "\n\tPlease enter cost of Material : "; cin >> totalMaterial[num-1];
        material += totalMaterial[num-1];
        cout << "\nPlease enter the number of employees for Project #" << num << " : "; cin >> employee;
        
        while(employee > 5 || employee < 0) {
            cout << "\n\tInvalid input! Please enter the number of employees for Project #" << num << " : "; cin >> employee;
        }
        totalInternal[num-1] = internalEmployee(employee);
        internal += totalInternal[num-1];
        fileOut(num, totalContract[num - 1], totalElectrical[num -1], totalPlumbing[num-1], totalRoofing[num-1], totalLandscaping[num-1], totalMaterial[num-1], totalInternal[num-1]);
        projectNum--;
    }

}

float internalEmployee(int employee) {

    float internalCost;
    float totalCost;

    for (int x = 1; employee > 0; x++) {

        cout << "\n\tWhat is the cost of salary for employee #" << x << " : "; cin >> internalCost;
        totalCost += internalCost;
        employee--;

    }
    return totalCost;
}

void fileOut(int num, float contractCost, float electrical, float plumbing, float roofing, float landscaping, float material, float internal) {
    
    float totalCost = electrical + plumbing + roofing + landscaping + material + internal;
    float profitLoss = contractCost - totalCost;


    myfile << "\n\t\t\t     Project " << num << "\n\n" << endl;
    myfile << "**********************************************************************" << endl;
    myfile << "\n\tServices\t\t\t\t   Cost" << endl;
    myfile << "\n*********************************************************************" << endl;
    myfile << "\n\tElectricity\t\t\t\t $" << electrical << endl;
    myfile << "\n\tPlumbing\t\t\t\t $" << plumbing << endl;
    myfile << "\n\tRoofing\t\t\t\t\t $" << roofing << endl;
    myfile << "\n\tLandscaping\t\t\t\t $" << landscaping << endl;
    myfile << "\n\tMaterial\t\t\t         $" << material << endl;
    myfile << "\n\tEmployee\t\t\t         $" << internal << endl;
    myfile << "\n*********************************************************************" << endl;
    myfile << "\n\tTotal\t\t\t\t\t$" << totalCost << endl;
    myfile << "\n\tContract\t\t\t\t$" << contractCost << endl;
    myfile << "\n\tProfit/Lost\t\t\t\t$" << profitLoss << endl;
    myfile << "\n*********************************************************************" << endl;

}

void totalFile(float contractCost, float electrical, float plumbing, float roofing, float landscaping, float material, float internal) {


    float totalCost = electrical + plumbing + roofing + landscaping + material + internal;
    float profitLoss = contractCost - totalCost;
    
    myfile << "\n\n\n\t\t\t Total Project Cost \n\n" << endl;
    myfile << "*********************************************************************" << endl;
    myfile << "\n\tServices\t\t\t\t   Cost" << endl;
    myfile << "\n*********************************************************************" << endl;
    myfile << "\n\tElectricity\t\t\t\t $" << electrical << endl;
    myfile << "\n\tPlumbing\t\t\t\t $" << plumbing << endl;
    myfile << "\n\tRoofing\t\t\t\t\t $" << roofing << endl;
    myfile << "\n\tLandscaping\t\t\t\t $" << landscaping << endl;
    myfile << "\n\tMaterial\t\t\t         $" << material << endl;
    myfile << "\n\tEmployee\t\t\t         $" << internal << endl;
    myfile << "\n*********************************************************************" << endl;
    myfile << "\n\tTotal\t\t\t\t\t$" << totalCost << endl;
    myfile << "\n\tContract\t\t\t\t$" << contractCost << endl;
    myfile << "\n\tProfit/Lost\t\t\t\t$" << profitLoss << endl;
    myfile << "\n*********************************************************************" << endl;


}
