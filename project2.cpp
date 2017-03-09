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

const float CHILD_MEAL = .60;
const float DESSERT_COST = 3.00;
const float TAX = .07;
const float TIPS = .15;

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
	
	cout << "Enter customer's name : "; std::getline(std::cin, customerName);
	cout << "Enter number of adults : "; cin >> numOfAdults;
	cout << "Enter number of children : "; cin >> numOfChildren;
	cout << "Enter number of dessert : "; cin >> numOfDessert;
	cout << "Enter cost of adult's meal : "; cin >> adultMealCost;
	cout << "Enter room fee : "; cin >> roomFee;
	cout << "Enter deposit for reservation : "; cin >> depositFee;
	
	childMealCost = adultMealCost * CHILD_MEAL;
	totalAdultMeal = adultMealCost * numOfAdults;
	totalChildMeal = childMealCost * numOfChildren;
	totalDessert = DESSERT_COST * numOfDessert;
	totalFood = totalAdultMeal + totalChildMeal + totalDessert;
	withTax = totalFood * TAX;
	withTip = totalFood * TIPS;
	totalBill = totalFood + withTax + withTip + roomFee;
	balance = totalBill - depositFee;
	
	cout << "\n\n\tPassaic County Catering & Convention Services\n\n" << endl;
	cout << "Customer:\t\t\t\t" << customerName << endl;
	cout << "Number of Adults:\t\t\t" << numOfAdults << endl;
	cout << "Number of Children:\t\t\t" << numOfChildren << endl;
	printf("\nCost Of Meal Per Adult:\t\t\t$%.2f\n", adultMealCost);
	printf("Cost Of Meal Per Child:\t\t\t$%.2f\n", childMealCost);
	printf("Cost Per Dessert:\t\t\t$%.2f\n\n", DESSERT_COST);
	printf("Total Cost for Adult Meals:\t\t$%.2f\n", totalAdultMeal);
	printf("Total Cost for Child Meals:\t\t$%.2f\n", totalChildMeal);
	printf("Total Cost for Dessert:\t\t\t$%.2f\n", totalDessert);
	printf("Total Food Cost:\t\t\t$%.2f\n", totalFood);
	printf("\nPlus 7.00 % Taxes:\t\t\t$%.2f\n", withTax);
	printf("Plus 15.00 % Tips:\t\t\t$%.2f\n", withTip);
	printf("Plus Room Fee:\t\t\t\t$%.2f\n", roomFee);
	printf("\nTotal Bill:\t\t\t\t$%.2f\n", totalBill);
	printf("Less Deposit:\t\t\t\t$%.2f\n", depositFee);
	printf("\nBalance Due:\t\t\t\t$%.2f", balance);
	cout << "\n\n\n\tThank you for using Passaic County Catering Services." << endl;
	
	return 0;
}
