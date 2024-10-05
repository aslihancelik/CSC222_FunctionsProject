// CSC222_FunctionsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// A program that provides the radius, circumference and area of a circle given the coordinates of its 
// center point and a point on its circumference.
//
// Programmer: Aslihan Celik
//

#include <iostream>
#include <cmath>
using namespace std;

// Precondition: Coordinates of two points on the cartesian plane as input
// Postcondition: Return the distance between these two points
double calcDistance(double, double, double, double);

// Precondition: It takes as input the coordinates for the center of a circle 
//              and the coordinates of a point on the circumference
// Postcondition: It returns the radius of the circle
// 
// calculates the radius using calcDistance function
double calcRadius(double, double, double, double);

//Calculates the circumference of the circle
double calcCircumference(double, double);

//Calculates the area of the circle
double calcArea(double, double);

int main()
{
    const double PI = 3.1416;
    int radius;
    double xCenter, yCenter, xCircum, yCircum;
    cout << "Please enter the x and y coordinates of the center point of a circle as x y e.g. 5.2 7" << endl;
    
    //Read the x and y coordinates for the center of the circle
    cin >> xCenter >> yCenter;
    cout << "You have entered: " << xCenter << " " << yCenter << endl;

    cout << "Please enter the x and y coordinates of the point on a circle as x y e.g. 5.2 7" << endl;

    //Read the x and y coordinates for a point on the circle
    cin >> xCircum >> yCircum;
    cout << "You have entered: " << xCircum << " " << yCircum << endl;

    //calculate the radius
    radius = calcRadius(xCenter, yCenter, xCircum, yCircum);
    
    cout << "The radius of this circle is " << radius << endl;
    cout << "The circumference of the circle is " << calcCircumference(radius , PI) << endl;
    cout << "The area of the circle is " << calcArea(radius, PI);
   
    return 0;
}

double calcDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double calcRadius(double xCenter, double yCenter, double xCircum, double yCircum) {
    return calcDistance(xCenter, yCenter, xCircum, yCircum);
}

double calcCircumference(double radius, double pi) {
    return 2 * pi * radius;
}
double calcArea(double radius, double pi) {
    return pi * pow(radius, 2);
}