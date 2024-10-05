// CSC222_FunctionsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// A program that outputs the inflation rates for two successive years and whether the inflation trend is 
// increasing or decreasing.
//
//Programmer: Aslihan Celik
//

#include <iostream>
using namespace std;

//Gets the correct input from the user making sure the input consists of positive values
void getInput(double &, double &, double &);

//Calculates the inflation for current year and last year
void calculateResult(double, double, double, double &, double &);

//prints the calculated inflation amounts and the trend
void printResult(double, double);

int main()
{
    double currentPrice, priceLastYear, priceTwoYearsAgo, inflation1, inflation2;
    
    getInput(currentPrice, priceLastYear, priceTwoYearsAgo);
    calculateResult(currentPrice, priceLastYear, priceTwoYearsAgo, inflation1, inflation2);
    printResult(inflation1, inflation2);
     
    return 0;
}

//Gets the correct input from the user making sure the input consists of positive values
void getInput(double& currentPrice, double& priceLastYear, double& priceTwoYearsAgo) {

    cout << "Please enter the current price, price from one year ago, and price from two years ago.\n";
    cout << "For example: 10 5 3\n";
    cin >> currentPrice >> priceLastYear >> priceTwoYearsAgo;

    if (currentPrice <= 0 || priceLastYear <= 0 || priceTwoYearsAgo <= 0) {
        do {
            cout << "Prices must be greater than zero. Please enter the values again.\n";
            cin >> currentPrice >> priceLastYear >> priceTwoYearsAgo;
        } while (currentPrice < 0 || priceLastYear < 0 || priceTwoYearsAgo < 0);
    }
    cout << "You entered: Current Price = " << currentPrice
        << ", Last Year Price = " << priceLastYear
        << ", Two Years Ago Price = " << priceTwoYearsAgo << endl;
}

//Calculates the inflation for current year and last year
void calculateResult(double currentPrice, double priceLastYear, double priceTwoYearsAgo, 
                     double &inflation1, double &inflation2) {

    inflation1 = (currentPrice - priceLastYear) / priceLastYear;
    inflation2 = (priceLastYear - priceTwoYearsAgo) / priceTwoYearsAgo;
}

//prints the calculated inflation amounts and the trend
void printResult(double inflation1, double inflation2) {
    cout << "The inflation rate for the current year is " << inflation1*100 << "%" << endl;
    cout << "The inflation rate for the last year is " << inflation2*100 << "%" << endl;
    if (inflation1 > inflation2) {
        cout << "Inflation trend is increasing.";
    }
    else if (inflation1 == inflation2) {
        cout << "Inflation trend is stable.";
    }
    else {
        cout << "Inflation trend is decreasing.";
    }
}
