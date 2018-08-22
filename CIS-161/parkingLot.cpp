/**********************************************************
 * Name        : Dane Barnett                             *
 *             : Louis Taveras                            *
 * Class       : CIS 161 ME1                              *
 * Date        : September 25, 2017                       *
 * Program     : Passaic County Parking Authority         *
 * Description : A program that keep a record of vehicles *
 *               that used the parking services and also  *
 *               generates the charges of the parking     *
 *               for parking per hour.                    *
 * ********************************************************/

#include <iostream>

using namespace std;

// function prototypes
void start();
string vehicleType();
void parkTime(int &, int &, int &, int &);
void printStatement(string, int, int, int, int);
string timeConverter(int);
string amPM(int);
string conDigit(int);
string totalTime(int, int, int, int, int &, int &);
string roundedTime(int &, int);
float totalDue(string, int);
bool newVehicle();
string towed(int, int);

const int SIXTY = 60;

/*************************************************************************
 * main() function used to call the start() function and end the program.*
 *************************************************************************/
int main()
{
    start();
    return 0;
}

/*************************************************************************
 * start() function is used to declare a boolean variable called again.  *
 * The program keeps running if 'again' remains true and stops whenever  *
 * 'again' is false. Also, the function contains a do while loop that    *
 * declares 5 variable and calls 4 function repeatedly until the boolean *
 * 'again' is false.                                                     *
 *************************************************************************/
void start()
{
    bool again;

    do
    {
        string vehicle;
        int hourIn;
        int minIn;
        int hourOut;
        int minOut;

        vehicle = vehicleType();
        parkTime(hourIn, minIn, hourOut, minOut);
        printStatement(vehicle, hourIn, minIn, hourOut, minOut);
        again = newVehicle();
    }
    while(again);
}

/*************************************************************************
 * vehicleType() function is called to accept user input and returns a   *
 * string with the results vary depending on the char input              *
 *************************************************************************/
string vehicleType()
{

    char type;
    bool truck = true;

    cout << "============================" << endl;
    cout << "== C = or = c ==========Car=" << endl;
    cout << "== V = or = v ==========Van=" << endl;
    cout << "== S = or = s ==========SUV=" << endl;
    cout << "== B = or = b ==========Bus=" << endl;
    cout << "== T = or = t ========Truck=" << endl;
    cout << "============================" << endl;

    cout << "\nPlease enter a letter for vehicle type : " << endl;
    cin >> type;

    if (type == 'C' || type == 'c')
        return "Car";
    else if (type == 'V' || type == 'v')
        return "Van";
    else if (type == 'S' || type == 's')
        return "SUV";
    else if (type == 'B' || type == 'b')
        return "Bus";
    else if (type == 'T' || type == 't' )
        while(truck)
        {
            cout << "Truck size needed, please enter s for small or l for large" << endl;
            cin >> type;
            if (type == 'S' || type == 's')
            {
                truck = false;
                return "Small Truck";
            }

            else if(type == 'L' || type == 'l')
            {
                truck = false;
                return "Large Truck";
            }
            else
                truck = true;
        }
    else
        cout << "INVALID INPUT !!!!!\n\n";
        vehicleType();

    return std::string();
}
/****************************************************************************
 * newVehicle() function is called at the end of the do while loop in the   *
 * start() function to accept user choice to input another vehicle data     *
 ****************************************************************************/
bool newVehicle()
{
    char choice;

    cout << "Do you have another vehicle? (Y/N)" << endl;
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        return true;
    else if(choice == 'N' || choice == 'n')
        return false;
    else
    {
        cout << "invalid Input !!!" << endl << endl;
        newVehicle();
    }
    return bool(true);
}

/*************************************************************************
 * parkTime() function accepts user input when the vehicle entered and   *
 * exited the parking lot. All parameters are pass by reference          *
 *************************************************************************/
void parkTime(int & h_in, int & m_in, int & h_out, int & m_out)
{
    cout << "\nPlease enter hour the vehicle entered the parking lot : " << endl;
    cin >> h_in;
    while (h_in < 0 && h_in > 23)
    {
        cout << "INVALID INPUT !!!\n\n";
        cout << "\nPlease enter hours between between 6 and 23 the vehicle entered the parking lot : " << endl;
        cin >> h_in;
    }

    cout << "\nPlease enter minute the vehicle entered the parking lot : " << endl;
    cin >> m_in;
    while (m_in < 0 && m_in > 59)
    {
        cout << "INVALID INPUT !!!\n\n";
        cout << "\nPlease enter minute the vehicle entered the parking lot : \"" << endl;
        cin >> m_in;
    }
    cout << "\nPlease enter hour the vehicle exited the parking lot : " << endl;
    cin >> h_out;
    while (h_out < 0 && h_out > 23)
    {
        cout << "INVALID INPUT !!!\n\n";
        cout << "\nPlease enter hour the vehicle exited the parking lot : " << endl;
        cin >> h_out;
    }

    cout << "\nPlease enter minute the vehicle existed the parking lot : " << endl;
    cin >> m_out;
    while (m_out < 0 && m_out > 59)
    {
        cout << "INVALID INPUT !!!\n\n";
        cout << "\\nPlease enter minute the vehicle exited the parking lot : \"" << endl;
        cin >> m_out;
    }
    if (h_in >= 0 && h_in <= 6)
    {
        h_in = 0;
        m_in = 0;
        h_out = 0;
        m_out = 0;

    }
    else if(h_out >= 0 && h_out <= 6)
    {
        h_out = 11;
        m_out = 59;
    }

}
/*************************************************************************
 * timeConverter() function converts 24 hour to 12 hour time format      *
 *************************************************************************/
string timeConverter(int h)
{
    if (h > 12)
        return to_string(h-12);
    else
        return to_string(h);
}
/********************************************************************
 * amPM() returns am or pm as a string depending on the time of day.*
 ********************************************************************/
string amPM(int h)
{
    if (h > 12)
        return " PM";
    else
        return " AM";
}
/**********************************************************
 * conDigit() returns minutes as a string in double digits*
 * if the minutes are in single digits.                   *
 **********************************************************/
string conDigit(int min)
{
    if (min < 10)
        return "0" + to_string(min);
    else
        return to_string(min);
}
/********************************************************************
 * totalTime() accepts all integers as arguments, calculates the    *
 * time of the parking services and returns the results as a string *
 ********************************************************************/
string totalTime(int h_in, int m_in, int h_out, int m_out, int & calcHours, int & calcMinutes)
{
    if (h_in == h_out)
    {
        calcHours = 0;
        calcMinutes = m_out - m_in;
    }
    else
    {
        calcHours = h_out - h_in;
        calcMinutes = (SIXTY - m_in) + (m_out);
    }

    if (h_in == 0)
        return "         N/A";

    else if (calcMinutes < SIXTY && calcHours > 0)
        calcHours -= 1;
    else if (calcMinutes == SIXTY)
    {
        calcMinutes = 0;
    }
    return to_string(calcHours) + " Hrs:" + conDigit(calcMinutes) + "mins";

}
/******************************************************************************
 * roundedTime() rounds the parking to an extra hour if one minutes has passed*
 ******************************************************************************/
string roundedTime(int & Hours, int Minutes)
{
    if (Minutes > 1)
    {
        Hours += 1;
        return to_string(Hours) + " hours";
    }
    else
        return to_string(Hours) + " hours";
}
/********************************************************
 * totalDue() accepts the Hours and vehicle type as     *
 * arguments, calculates the time and cost depending on *
 * the vehicle type and returns the results as a string *
 ********************************************************/
float totalDue(string v, int Hours)
{

    if (v == "Car" || v == "Van" || v == "SUV")
    {
        if (Hours <= 3)
            return 0;
        else
            return (Hours - 3) * 1.50;
    }
    else if(v == "Small Truck" || v == "Bus")
    {
        if (Hours <= 2)
            return Hours * 2;
        else
            return ((Hours - 2) * 2.50) + 2.00;
    }
    else
    {
        if (Hours <= 1)
            return Hours * 2.00;
        else
            return (Hours - 1) * 3.50 + (2.00);
    }
}
/****************************************************
 * towed() accepts time of when the vehicle entered *
 * and existed the parking returned either Parking  *
 * Not Allowed or Towed depending on the conditions.*
 ****************************************************/
string towed(int h_in, int h_out)
{
    if (h_in >= 0 && h_in <= 6)
        return "(Parking Not Allowed)";
    else if(h_out >= 0 && h_out <= 6)
        return "(Towed)";
    else
        return "";
}
/*******************************************************************
 * printStatement() print the statment of the parking services for *
 * the vehicle such as parking time and cost of the services       *
 *******************************************************************/
void printStatement(string v, int h_in, int m_in, int h_out, int m_out)
{
    int calcHours, calcMinutes;

    cout << "\n\t\t\tPassaic County Parking Authority" << endl;
    cout << "\n\t\t\t   Parking Lot Charges" << endl;
    cout << "\nType of Vehicle: " << v << towed(h_in, h_out) << "\n" << endl;
    cout << "Time-In\t\t\t\t\t\t       " << timeConverter(h_in) << ":" << conDigit(m_in) << amPM(h_in) << endl;
    cout << "Time-Out\t\t\t\t\t       " << timeConverter(h_out) << ":" << conDigit(m_out) << amPM(h_out) << endl;
    cout << "\t\t\t\t\t\t _____________" << endl;
    cout << "Parking-Time\t\t\t\t\t  " << totalTime(h_in, m_in, h_out, m_out, calcHours, calcMinutes) << endl;
    cout << "\nRounded Parking Time\t\t\t\t       " << roundedTime(calcHours, calcMinutes) << endl;
    cout << "\t\t\t\t\t\t _____________" << endl;
    printf("\nTOTAL DUE\t\t\t\t\t         $%0.2f", totalDue(v, calcHours));
    cout << "\n\n\t\t\tThank you for using Passaic County Parking Authority\n" << endl;
}
