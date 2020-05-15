// Function Declarations
#pragma once
#include <string>
#include <iostream>

using namespace std;

#ifndef customer_h
#define customer_h

class Customer {
//private: //can not be access in any other file, don't want to be changed
	//Member Variables


protected: 
	string Lname;
	string Fname;

	int custID;


public: // usually functions
	// Default constructor makes Member Variables into a null
	Customer();
	// Overload Constructor
	Customer(string, string, int);

	// Destructor once you are done using a Object it destroys the memory
	~Customer();

	// Accessor Functions
	string getLastName() const;
		//returns last name
	string getFirstName() const; 
		// returns first name
	int getCustomerID() const;
	// return Customer ID
	// Mutator/Updates Functions
	void setLastName(string);
		// sets the last name
		// @param string name of customer
	void setFirstName(string);
		// sets the first name
		// @param string name of customer


};

#endif