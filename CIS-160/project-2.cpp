/*		Name: Dane Barnett
		Class: CIS 160 ME1
		Date: March 13, 2017
		Program: Customer's Bill
		Description: 	This program accepts as input, customer name, number of adults,
						number of children, cost of meal per adult, child and cost of
						desert to get the total including tax.
*/

// include iostream for input/output purposes and iomanip for manipulation of data
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const float LABOR_COST = 1.65;
const float TAX = .07;

float setdata(string &, int &, int &, float &, int &, float &, float &, float &);
void calculations(float, float, float &, float &, float &);
	float calcinstalled(float, float);
	float calcsubtotal(float, float);
	float calctotal(float, float);
void showresults(string, int, int, int, int, int, int, float, float, float, float, float);
	void heading(string, int);
	void measurement(int, int, int, int, int);
	void charges(int, float, float, float, float, float);

int main() {
	
	// variable declaration
	string customerName;
	int customerID;
	int lengthFeet;
	float lengthInch;
	int widthFeet;
	float widthInch;
	float area;
	float carpetPrice;
	float discount;
	float roomCharges;
	float installedPrice;
	float subTotal;
	float totalPrice;

	area = setdata(customerName, customerID, lengthFeet, lengthInch, widthFeet, widthInch, carpetPrice, discount);
	discount = discount / 100;
	calculations(carpetPrice, discount, installedPrice, subTotal, totalPrice);
	showresults(customerName, customerID, lengthFeet, lengthInch, widthFeet, widthInch, area, carpetPrice, discount, installedPrice, subTotal, totalPrice);
	cout << fixed << setprecision(2);
	cout << lengthInch << endl;
	cout << widthInch << endl;
	cout << area << endl;
	return 0;
}

	// input selection
float setdata(string & customerName, int & customerID, int & lengthFeet, float & lengthInch, int & widthFeet, float & widthInch, float & carpetPrice, float & discount) {

	cout << "Customers' Name\t\t : "; getline(cin, customerName);
	cout << "Customers' ID#\t\t : "; cin >> customerID;
	cout << "Length of Room\t\t : Feet\t  : "; cin >> lengthFeet;
	cout << "\t\t\t : Inches : "; cin >> lengthInch;
	cout << "Width of Room\t\t : Feet\t  : "; cin >> widthFeet;
	cout << "\t\t\t : Inches : "; cin >> widthInch;
	cout << "Cost / Square Foot\t : "; cin >> carpetPrice;
	cout << "Percentage if Discount\t : "; cin >> discount;


	float lengthconv = lengthInch / 12;
	float widthconv =  widthInch / 12;

	return (lengthFeet + lengthconv) * (widthFeet + widthconv);
}

void calculations(float carpetPrice, float discount, float & installedPrice, float & subTotal, float & totalPrice) {

	installedPrice = calcinstalled(carpetPrice, LABOR_COST);
	subTotal = calcsubtotal(installedPrice, discount);
	totalPrice = calctotal(subTotal, TAX);

}

float calcinstalled(float carpetPrice, float LABOR_COST) {
	return carpetPrice + LABOR_COST;
}

float calcsubtotal(float installedPrice, float discount) {
	discount = installedPrice * discount;
	return installedPrice - discount;
}

float calctotal(float subTotal, float TAX) {
	TAX = subTotal * TAX;
	return subTotal + TAX;
}

void showresults(string customerName, int customerID, int lengthFeet, int lengthInch, int widthFeet, int widthInch, int area, float carpetPrice, float discount, float installedPrice, float subTotal, float totalPrice) {
	heading(customerName, customerID);
	measurement(lengthFeet, lengthInch, widthFeet, widthInch, area);
	charges(area, carpetPrice, discount, installedPrice, subTotal, totalPrice);


}

void heading(string customerName, int customerID) {
	cout << "\n/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/" << endl;
	cout << "\t\t\t       Passaic County Community Carpet Center" << endl;
	cout << "\t\t\t\t\t   123 Main Street" << endl;
	cout << "\t\t\t\t\t  Paterson, NJ 07505" << endl;
	cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/" << endl;
	cout << "Customer Name:\t\t       Adnan I. Atshan" << endl;
	cout << "Customer Number:\t       12345\n" << endl;

}

void measurement(int lengthFeet, int lengthInch, int widthFeet, int widthInch, int area) {
	cout << "Room Measurement:" << endl;
	cout << "\t\t\t       Length :  " << lengthFeet << "\' " << lengthInch << "\"" << endl;
	cout << "\t\t\t       Width  :  " << widthFeet << "\' " << widthInch << "\"" << endl;
	cout << fixed << setprecision(2);
	cout << "\t\t\t       Area   :  " << area << " Sq/Ft\n" << endl;
}

void charges(int area, float carpetPrice, float discount, float installedPrice, float subTotal, float totalPrice) {
	float carpetTotal = carpetPrice * area;
	float laborTotal = LABOR_COST * area;
	float installTotal = carpetTotal + laborTotal;
	float discountTotal = installTotal * discount;
	float totalsubtotal = installTotal - discountTotal;
	float taxTotal = totalsubtotal * TAX;
	float totalTotal = totalsubtotal + taxTotal;

	cout << fixed << setprecision(2);
	cout << "_____________________________________________________________________________________________________\n" << endl;
	cout << "Charges:\n\n" << endl;
	cout << right << setw(17) << "Description" <<  setw(25) << "Cost/SQ Ft" << setw(25) << "Charges/Room" << endl;
	cout << right << setw(17) << "-----------" <<  setw(25) << "----------" << setw(25) << "------------" << endl;
	cout << right << setw(12) << "Carpet" << setw(25)  <<  "$" << setw(4) << carpetPrice << setw(17) << "$" << setw(6) << carpetTotal << endl;
	cout << right << setw(11) << "Labor" <<  setw(27) << "$" << LABOR_COST << setw(25) << "$" << laborTotal << endl;
	cout << right << setw(67) << "------------" << endl;
	cout << right << setw(21) << "Installed Price" << setw(46) << installTotal << endl;
	cout << right << setw(14) << "Discount" <<  setw(27) << discount * 100 << "%" << setw(25) << discountTotal << endl;
	cout << right << setw(67) << "------------" << endl;
	cout << right << setw(14) << "Subtotal" << setw(53) << totalsubtotal << endl;
	cout << right << setw(9) << "Tax" << setw(58) << taxTotal << endl;
	cout << right << setw(67) << "------------" << endl;
	cout << right << setw(11) << "Total" << setw(56) << totalTotal << endl;
	cout << "\n_____________________________________________________________________________________________________\n" << endl;
	cout << "\t\tThank you for using Passaic County Catering Services.\n" << endl;

}