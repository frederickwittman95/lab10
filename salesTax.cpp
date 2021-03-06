// Frederick Wittman
// Dr. Hill
// COSC 2030
// Lab 10
// 06 May 2019

#include "stdafx.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Declare exception classes
class percentageError : public exception {
public:
	string errorMessage() {
		return "The exceptable values for sales tax are 0 - 0.99 in this jurisdiction!";
	}
};
class negativeValueError : public exception {
};

// Function that calculates the total cost of an item when sales tax is included
void calcTotalCost() {
	try {

		// Declare objects of the exception handling classes that were defined above
		percentageError pError;
		negativeValueError nvError;

		float itemCost;
		float salesTax;
		cout << "This application calculates the cost of an item when sales tax is included.  Please enter the cost of the item now.";
		cin >> itemCost;
		if (itemCost < 0) {
			throw nvError;
		}
		cout << "Please enter the sales tax as a figure between 0 - 0.99, inclusive.";
		cin >> salesTax;
		if (salesTax > 0.99 || salesTax < 0) {
			throw pError;
		}
		cout << "The cost of the item with sales tax is: " << itemCost * (1 + salesTax);
	}
	
	// The negativeValueError class does not have a member function for printing the appropriate output; therefore, I manually wrote the output in the catch block
	catch (negativeValueError& e) {
		cout << "The cost of the item cannot be negative.";
		return;
	}
	// The percentageError class does have a function for printing the appropriate response; call this function when needed
	catch (percentageError& e) {
		cout << e.errorMessage();
		return;
	}
}

int main()
{
	calcTotalCost();

    return 0;
}

