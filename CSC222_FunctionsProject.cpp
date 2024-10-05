// CSC222_FunctionsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// A program that outputs the inflation rates for two successive years and whether the inflation trend is 
// increasing or decreasing.
//
//Programmer: Aslihan Celik
//

#include <iostream>
using namespace std;

void getInput(double &, double &, double &);

void calculateResult(double, double, double, double &, double &);

void printResult(double, double);

int main()
{
    double currentPrice, priceLastYear, priceTwoYearsAgo, inflation1, inflation2;
    
    getInput(currentPrice, priceLastYear, priceTwoYearsAgo);
    calculateResult(currentPrice, priceLastYear, priceTwoYearsAgo, inflation1, inflation2);
    printResult(inflation1, inflation2);
     
    return 0;
}

void getInput(double &currentPrice, double &priceLastYear, double &priceTwoYearsAgo) {

    cout << "Please enter the current price of an item and its price from one year and two years ago as " << endl;
    cout << "currentprice pricelasyear pricetwoyearsago e.g. 10 5 3" << endl;
    cin >> currentPrice >> priceLastYear >> priceTwoYearsAgo;
    
    if (currentPrice < 0 || priceLastYear < 0 || priceTwoYearsAgo < 0) {
        do {
            cout << " You can not enter any negative values. Please enter again." << endl;
            cin >> currentPrice >> priceLastYear >> priceTwoYearsAgo;
        } while (currentPrice < 0 || priceLastYear < 0 || priceTwoYearsAgo < 0);
    }
    cout << "You entered " << currentPrice << " " << priceLastYear << " " << priceTwoYearsAgo << endl;
}

void calculateResult(double currentPrice, double priceLastYear, double priceTwoYearsAgo, 
                     double &inflation1, double &inflation2) {

    inflation1 = (currentPrice - priceLastYear) / priceLastYear;
    inflation2 = (priceLastYear - priceTwoYearsAgo) / priceTwoYearsAgo;
}

void printResult(double inflation1, double inflation2) {
    cout << "The inflation rate for the current year is " << inflation1*100 << "%" << endl;
    cout << "The inflation rate for the last year is " << inflation2*100 << "%" << endl;
    if (inflation2 > inflation1) {
        cout << "Inflation trend is increasing.";
    }
    else if (inflation1 = inflation2) {
        cout << "Inflation trend is stable.";
    }
    else {
        cout << "Inflation trend is decreasing.";
    }
}
