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
#include <string>
#include <iomanip>

using namespace std;

//Prototype
void setData(string &, int &);
float setRoom(int, string &);
float setPhone(int, string &);
float setTV(int, string &);
void print(string, int, float, float, float, string, string, string, float);

// Start of program
int main() {
    
    // variable declaration
    string name, roomType, phoneType, tvType;
    int days;
    float roomCharges, phoneCharges, tvCharges, totalCharges;

    setData(name, days);
    roomCharges = setRoom(days, roomType);
    phoneCharges = setPhone(days, phoneType);
    tvCharges = setTV(days, tvType);
    print(name, days, roomCharges, phoneCharges, tvCharges, roomType, phoneType, tvType, totalCharges);

    return 0;

}

// process for the name of the pateint and the day count in hospital
void setData(string & name, int & days) {

    cout << "Patient Name : "; getline(cin, name);
    cout << "\nNumber of Days in the Hospital : "; cin >> days;
}

// function to process for the roomtype.
float setRoom(int days, string & roomType) {

    char choice;
    const float singleRoom = 1325.00;
    const float doubleRoom = 1525.00;
    const float ward = 1650.00;

    cout << "\n\n\t\tRoom Used" << endl << endl;
    cout << "\t1-  Single Room-One Bed" << endl;
    cout << "\t2-  Double Room-Two Beds" << endl;
    cout << "\t3-  Ward" << endl << endl;
    cout << "\t\tEnter Choice: "; cin >> choice;

    // unlimited loop until the condition is met.
    while (true) {

        if (choice == '1' || choice == 'S' || choice == 's') {
            roomType = "Single Room";
            return days * singleRoom;

        }
        else if (choice == '2' || choice == 'D' || choice == 'd') {
            roomType = "Double Room";
            return days * doubleRoom;
            
        }
        else if (choice == '3' || choice == 'W' || choice == 'w') {
            roomType = "Ward";
            return days * ward;
        }

        else {
            cout << "\n\t\tYou may enter 1, S, s or 2, D, d or 3, W, w\b\b\b\b\b\b" << endl;
            cout << "\t\tEnter Choice: "; cin >> choice;
        }
    }
}

// function to process the phone type.
float setPhone(int days, string & phoneType) {

    char choice1;
    char choice2;
    const float sharedPhone = 5.95;
    const float dedicatedPhone = 9.95;

    cout << "Phone usage(Y/N): "; cin >> choice1;

    // unlimited loop until condition is met.
    while(true) {

        if (choice1 == 'Y' || choice1 == 'y') {
            cout << "\n\n\t\tPhone Access" << endl << endl;
            cout << "\t1-  Shared Line" << endl;
            cout << "\t2-  Dedicated Line" << endl << endl;
            cout << "\t\tEnter Choice: "; cin >> choice2;

            while(true) {
                if (choice2 == '1' || choice2 == 'S' || choice2 == 's') {
                    phoneType = "Shared";
                    return days * sharedPhone;
                }
                else if (choice2 == '2' || choice2 == 'D' || choice2 == 'd') {
                    phoneType = "Dedicated";
                    return days * dedicatedPhone;
                }
                else {
                    cout << "\t\tYou may enter 1, S, s or 2, D, d" << endl;
                    cout << "\t\tEnter Choice: "; cin >> choice2;
                }
            }
        }
        else if (choice1 == 'N' || choice1 == 'n') {
            return 0.00;
        }

        else {
            cout << "Phone usage(Y/N): "; cin >> choice1;
        }
    }
}

// function to process the tv type.
float setTV(int days, string & tvType) {

    char choice1;
    char choice2;
    const float basic = 5.95;
    const float cable = 9.95;

    cout << "TV usage(Y/N): "; cin >> choice1;

    // unlimited loop until condition is met
    while(true) {

        if (choice1 == 'Y' || choice1 == 'y') {
            cout << "\n\n\t\tTV Usage" << endl << endl;
            cout << "\t1-  Basic Channels" << endl;
            cout << "\t2-  Cable Channels" << endl << endl;
            cout << "\t\tEnter Choice: "; cin >> choice2;
            
            while(true) {

                if (choice2 == '1' || choice2 == 'B' || choice2 == 'b') {
                    tvType = "Basic";
                    return days * basic;
                }
                else if (choice2 == '2' || choice2 == 'C' || choice2 == 'c') {
                    tvType = "Cable";
                    return days * cable;
                }
                else {
                    cout << "\t\tYou may enter 1, B, b or 2, C, c" << endl;
                    cout << "\t\tEnter Choice: "; cin >> choice2;
                }
            }
        }
        else if (choice1 == 'N' || choice1 == 'n') {
            return 0.00;
        }
        else {
            
            cout << "Phone usage(Y/N): "; cin >> choice1;
        }
    }
}

// function that prints the statement.
void print(string name, int days, float roomCharges, float phoneCharges, float tvCharges, string roomType, string phoneType, string tvType, float totalCharges) {

    totalCharges = roomCharges + phoneCharges + tvCharges;

    cout << setprecision(2) << fixed;

    cout << "\t\t\t\t\tSt. Joseph's Hospital\n\n" << endl;
    cout << " " << name << "\'s Billing Statement\n" << endl;
    cout << "\tNumber of days in the hospital: " << days << "\t\t" << "(In a " << roomType << ")" << endl;
    cout << "\n\tRoom Charges\t\t\t\t\t  $" << roomCharges << endl;
    cout << "\n\tPhone Charges\t\t" << "(" << phoneType << ")" << "\t\t    $" << phoneCharges << endl;
    cout << "\n\tTelevision Charges\t" << "(" << tvType << ")" << "\t\t\t    $" << tvCharges << endl;
    cout << "\n\tTotal Charges\t\t\t\t\t  $" << totalCharges << endl;
    cout << "\n\n\tHope you are satisfied with St. Joseph's Hospital services, Stay well." << endl << endl;

}