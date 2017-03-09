/*		Name: Dane Barnett
		Class: CIS 160 ME1
		Date: Feb 12, 2017
		Program: Customer's Bill
		Description: 	This program accepts as input, customer name, number of adults,
						number of children, cost of meal per adult, child and cost of
						desert to get the total including tax.
*/

// include iostream for input/output purposes and iomanip for manipulation of data
#include <iostream>
#include <iomanip>

using namespace std;


const float CHILD_MEAL = .60;
const float DESSERT_COST = 3.00;
const float TAX = .07;
const float TIPS = .15;

int main() {
	
	// variable declaration
	string customerName;
	int numOfAdults; 
	int numOfChildren;
	int numOfDessert;
	float adultMealCost;
	float roomFee;
	float depositFee; 
	float childMealCost; 
	float totalAdultMeal;
	float totalChildMeal; 
	float totalDessert; 
	float totalFood;
	float withTax;
	float withTip;
	float totalBill;
	float balance;
	
	// input selection
	
	cout << "Enter customer's name : "; std::getline(std::cin, customerName);
	cout << "Enter number of adults : "; cin >> numOfAdults;
	cout << "Enter number of children : "; cin >> numOfChildren;
	cout << "Enter number of dessert : "; cin >> numOfDessert;
	cout << "Enter cost of adult's meal : "; cin >> adultMealCost;
	cout << "Enter room fee : "; cin >> roomFee;
	cout << "Enter deposit for reservation : "; cin >> depositFee;
	
	// processing of the data
	childMealCost = adultMealCost * CHILD_MEAL;
	totalAdultMeal = adultMealCost * numOfAdults;
	totalChildMeal = childMealCost * numOfChildren;
	totalDessert = DESSERT_COST * numOfDessert;
	totalFood = totalAdultMeal + totalChildMeal + totalDessert;
	withTax = totalFood * TAX;
	withTip = totalFood * TIPS;
	totalBill = totalFood + withTax + withTip + roomFee;
	balance = totalBill - depositFee;
	
	cout << fixed; 				// show with a fixed decimal point - not scientific notation.
	cout << setprecision(2);	// show only two digits beyond the decimal point.
	
	// Printout of the Bill's header
	cout << "\n\n\tPassaic County Catering & Convention Services\tFinal Bill\n\n" << endl;
	
	// output of the results
	cout << left << setw(25) << "Customer:";
	cout << right << setw(25) << customerName << endl;
	cout << left << setw(25) << "Number of Adults:";
	cout << right << setw(25) << numOfAdults << endl;
	cout << left << setw(25) << "Number of Children:";
	cout << right << setw(25) << numOfChildren << endl;
	
	cout << left << setw(26) << "\nCost Of Meal Per Adult:";
	cout << right << setw(25) << adultMealCost << endl;
	cout << left << setw(25) << "Cost Of Meal Per Child:";
	cout << right << setw(25) << childMealCost << endl;
	cout << left << setw(25) << "Cost Per Dessert:";
	cout << right << setw(25) << DESSERT_COST << endl;
	
	cout << left << setw(21) << "\nTotal Cost for Adult Meals:";
	cout << right << setw(23) << totalAdultMeal << endl;
	cout << left << setw(21) << "Total Cost for Child Meals:";
	cout << right << setw(23) << totalChildMeal << endl;
	cout << left << setw(25) << "Total Cost for Dessert:";
	cout << right << setw(25) << totalDessert << endl;
	cout << left << setw(25) << "Total Food Cost:";
	cout << right << setw(25) << totalFood << endl;
	
	cout << left << setw(26) << "\nPlus 7.00 % Taxes:";
	cout << right << setw(25) << withTax << endl;
	cout << left << setw(26) << "Plus 15.00 % Tips:";
	cout << right << setw(24) << withTip << endl;
	cout << left << setw(25) << "Plus Room Fee:";
	cout << right << setw(25) << roomFee << endl;
	
	cout << left << setw(26) << "\nTotal Bill:";
	cout << right << setw(25) << totalBill << endl;
	cout << left << setw(25) << "Less Deposit:";
	cout << right << setw(25) << depositFee << endl;
	
	cout << left << setw(26) << "\nBalance Due:";
	
	cout << right << setw(25) << balance << endl;
	
	// Printout of the Bill's footer
	cout << "\n\n\n\tThank you for using Passaic County Catering Services." << endl;
	
	return 0;
}
