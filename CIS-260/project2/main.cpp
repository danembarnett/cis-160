#include <iostream>
#include <iomanip>
#include <string>
#include "proj2.cpp"

using namespace std;

int main(){

    Department <string>  dept1("CIS");   // a department

    char choice, answer;    // handles input from menu and controls loop
    bool success;
    do{
        system("CLS");          // clears the screen
        cout <<setw(30)<< " Main Menu\n\n\n";   // menu of options to add/remove or clear
        cout << setw(15)<< " "<< "(1)- (A)dd\n\n"; // data is enterd from within Add
        cout << setw(15)<< " "<< "(2)- (R)emove \n\n"; // the id to remove is entered in Remove.
        cout << setw(15)<< " "<< "(3)- (C)lear\n\n\n";
        cout << setw(35)<< "Enter Choice ";cin >> choice;
        choice = toupper(choice);
        switch (choice)
        {   case '1':
            case 'A':
                success = dept1.add();
                if (success)       // call to the add method
                    cout <<  "\n\nAdded\n\n";
                else
                    cout << "\n\nCould not add\n\n";
                break;
            case '2':
            case 'R':
                success = dept1.remove();
                if(success)    // call to the remove method
                    cout << "\n\nRemoved\n\n";
                else
                    cout <<"\n\nCould not Remove\n\n";
                break;
            case '3':
            case 'C':
                dept1.clear();              // call to the clear method
                break;
        }
        cout << "another Operation "; cin >> answer; answer = toupper(answer);
    }     while (answer == 'Y');
    return 0;
}