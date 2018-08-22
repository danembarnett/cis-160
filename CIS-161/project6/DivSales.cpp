#include <string>
#include <iostream>
#include "DivSales.h"

using namespace std;

//deconstructor
DivSales::~DivSales() {}

//constructor
DivSales::DivSales()
{
    name = "";
    for (int i = 0; i < 4; i++)
        fourQuarterSales[i] = 0;
}

//return region name
string DivSales::getRegionName()
{
    return this->name;
}

//input quarter sales
void DivSales::getQuarter()
{

    for (int i = 0; i < 4; i++)
    {
        cout << "\tQuarter " << (i + 1) << " : ";
        cin >> fourQuarterSales[i];
        //float DivSales::annualCorporateSales += fourQuarterSales[i];
        regionSales += fourQuarterSales[i];
    }

}

// input region name
void DivSales::inputData()
{
    bool validRegion = true;
    string name;

    while(validRegion)
    {
        cout << "Enter Region : ";
        getline(cin, name);
        if (name != regionName[0] && name != regionName[1] && name != regionName[2] && name != regionName[3])
            {
                cout << "Invalid Region!";
                validRegion = true;
            }
        else
            {
                getQuarter();
                validRegion = false;
            }
    }
}

//return total region sales
float DivSales::totalRegionSales()
{
    float total = 0.00;

    for (int i = 0; i < 4; i++)
        total += fourQuarterSales[i];
        
		annualCorporateSales+= total; 
		 
    return total;
}

//return corporate sales
float DivSales::allRegionSales()
{
    return annualCorporateSales;
}

//output region quarter and total
void DivSales::outPut()
{
    cout << getRegionName() << endl;
    for (int i = 0; i < 4;i++)
        cout << "\tQuarter " << (i+1) << " : " << fourQuarterSales[i] << endl;
    cout << "Region's total : " << totalRegionSales() << endl << endl;
}
