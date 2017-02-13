/*		Name: Dane Barnett
		Class: CIS 160 ME1
		Date: Feb 12, 2017
		Program: Customer's Bill
		Description: 	This program accepts as input, customer name, number of adults,
						number of children, cost of meal per adult, child and cost of
						desert to get the total including tax.
*/

#include <iostream>

using namespace std;

const float CHILD_MEAL = 0.6;
const int DESSERT_COST = 3;
const float TAX = 0.07;
const float TIPS = 0.15;

int main() {
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
	
	cout << "Enter customer's name : "; cin >> customerName;
	cout << "Enter number of adults : "; cin >> numOfAdults;
	cout << "Enter number of children : "; cin >> numOfChildren;
	cout << "Enter number of dessert : "; cin >> numOfDessert;
	cout << "Enter cost of adult's meal : "; cin >> adultMealCost;
	cout << "Enter room fee : "; cin >> roomFee;
	cout << "Enter deposit for reservation : "; cin >> depositFee;
	
	childMealCost = adultMealCost * CHILD_MEAL;
	totalAdultMeal = adultMealCost * numOfAdults;
	totalChildMeal = childMealCost * numOfChildren;
	totalDessert = numOfDessert * DESSERT_COST;
	totalFood = totalAdultMeal + totalChildMeal + totalDessert;
	withTax = totalFood * TAX;
	withTip = totalFood * TIPS;
	totalBill = totalFood + withTax + withTip + roomFee;
	balance = totalBill - depositFee;
	
	cout << "Customer:\t\t\t" << customerName << endl;
	cout << "Number of Adults:\t\t\t" << numOfAdults << endl;
	cout << "Number of Children:\t\t\t" << numOfChildren << endl;
	cout << "Cost Of Meal Per Adult:\t\t\t$" << adultMealCost << endl;
	cout << "Cost Of Meal Per Child:\t\t\t$" << childMealCost << endl;
	cout << "Cost Per Dessert:\t\t\t$" << totalDessert << endl;
	cout << "Total Cost for Adult Meals:\t\t\t$" << totalAdultMeal << endl;
	cout << "Total Cost for Child Meals:\t\t\t$" << totalChildMeal << endl;
	cout << "Total Cost for Dessert:\t\t\t$" << totalDessert << endl;
	cout << "Total Food Cost:\t\t\t$" << totalFood << endl;
	cout << "Plus 7.00 % Taxes:\t\t\t$" << withTax << endl;
	cout << "Plus 15.00 % Tips:\t\t\t$" << withTip << endl;
	cout << "Plus Room Fee:\t\t\t$" << roomFree << endl;
	cout << "Total Bill:\t\t\t$" << totalBill << endl;
	cout << "Less Deposit:\t\t\t$" << depositFee << endl;
	cout << "Balance Due:\t\t\t$" << balance << endl;
	
	return 0;
}
