#ifndef PROJECT6_DIVSALES_H
#define PROJECT6_DIVSALES_H
#include <string>

using namespace std;

class DivSales
{
    private:
        string name;
        const string regionName[4] = {"East", "West", "North", "South"};
        int fourQuarterSales[4];
        static float annualCorporateSales;
        float regionSales; 

    public:
        DivSales();
        ~DivSales();
        string getRegionName();
        void getQuarter();
        void inputData();
        float totalRegionSales();
        float allRegionSales();
        void outPut();



};

float DivSales::annualCorporateSales;

#endif //PROJECT6_DIVSALES_H
