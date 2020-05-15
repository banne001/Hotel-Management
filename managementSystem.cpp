#include <string>
#include <iostream>
#include "customer.h"
#include "reservation.h"
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

void viewReservation(vector<Reservation> const&);
void book(vector<Reservation>&);
void save(vector<Reservation>);
void load(vector<Reservation>&);
void deleteReservation(vector<Reservation> res);


int main() {
	// Create a Queue For dates
	// Once created put in 3 reservations into the queue for one date
	// name reservations and dates after date Reservation number
	//create a ticket variable in reservation

	// once multiple dates and reservations are made 
	// Code how to delete and update

	// then create a way to display all reservations for a specified date.
	// should be a for loop that prints out the reservation

	/** 
		Tomorrow:
			Queue is okay... I think
			 

	*/
	vector<Reservation> dailyReservation;

	load(dailyReservation);
	int choice;

	do{
		cout << "Welcome to Hotel Management System\n";
		cout << "MENU\n";
		cout << "1. Book \n2. Update a Reservation \n";
		cout << "3. Cancel a Reservation \n4. View Reservation \n";
		cout << "5. Rom Availability \n6. Exit\n";
		cout << "Enter Number: ";

		do {
			cin >> choice;
		} while (choice > 6 && choice < 1);

		switch (choice) {
		case 1:
			book(dailyReservation);
			break;
		case 3: 
			deleteReservation(dailyReservation);
			break;
		case 4:
			viewReservation(dailyReservation);
			break;
		
		case 6:
			save(dailyReservation);
		}
	} while (choice != 6);

	viewReservation(dailyReservation);
	return 0;
}

void load(vector<Reservation>& res) {
	ifstream inputFile; // takes stuff out of the file 
	inputFile.open("reservations.txt");
	string reservation;
	if (inputFile) {
		while (getline(inputFile,reservation)) {
			{
				std::stringstream ss(reservation);
				std::string item;
				std::vector<std::string> splittedStrings;
				while (std::getline(ss, item, '|'))
				{
					splittedStrings.push_back(item);
				}
				
				Customer cust = Customer(splittedStrings[0], splittedStrings[1], 123456);
				Reservation newR = Reservation(cust, splittedStrings[2], stoi(splittedStrings[3]), stoi(splittedStrings[4]), stoi(splittedStrings[5]));
				res.push_back(newR);
			}
		}
		viewReservation(res);
	}
	else {
		cout << "Error, No File" << endl;
	}
}

// Views Reservation created
void viewReservation(vector<Reservation> const &res) {
	int size = res.size();
	for (int i = 0; i < size; i++) {
		Reservation printing = res.at(i);
		cout << printing.overview() << endl;
	}
}

void book(vector<Reservation>& res) {
	string roomTypes[] = { "King Suite", "King Standard",
							"Queen Suite", "Queen ",
							"Double Suite", "Double" };
	// Customer Information
	string fname, lname;
	int from, nights, room, to;
	cout << "First Name: ";
	cin >> fname;
	cout << "Last Name: ";
	cin >> lname;
	Customer cus1 = Customer(lname, fname, 123456);

	// Room Reservation
	cout << "What type of room would you like? Enter Number\n";
	for (int i = 0; i < 6; i++) {
		cout << (i + 1) << ". " << roomTypes[i] << endl;
	}
	cin >> room;
	cout << "From when?";
	cin >> from;
	cout << "How many Nights?";
	cin >> nights;
	to = from + nights;
	Reservation r1 = Reservation(cus1, roomTypes[room-1], from, to, nights);
	cout << r1.toString();

	// create a confirmation
	// add to queue
	int confirm;
	cout << "Confirm? \n1. Yes\n2. No \n";
	cin >> confirm;
	if (confirm == 1)
		res.push_back(r1);
	else
		cout << "Aww... Next Time";
}

void updateReservation(vector<Reservation> res) {

}

void deleteReservation(vector<Reservation> res) {
	string fname, lname;
	cout << "Delete Reservation" << endl;
	cout << "First Name:  ";
	cin >> fname;
	cout << "Last Name: ";
	cin >> lname;
	int size = res.size();
	int index = 0;
	while (res[index].getFirstName() != fname && res[index].getLastName() != lname) {
		index++;
	}
	cout << res[index].toString();
}

void save(vector<Reservation> res){
	//Save the reservation in a file
	ofstream outputFile; // prints to the file
	outputFile.open("reservations.txt");

	int size = res.size();

	for(int i = 0; i < size; ++i) {
		outputFile << res[i].toFile() << "\n";
	}
}