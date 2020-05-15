#include "reservation.h";
#include <sstream>
Reservation::Reservation() {
	
	from = 0;
	to = 0;
	night = 0;
}
Reservation::Reservation(Customer name, string room, int from, int to , int night) {
	Fname = name.getFirstName();
	Lname = name.getLastName();
	custID = name.getCustomerID();
	this->room = room;
	this->from = from;
	this->to=to;
	this->night = night;
}
Reservation::~Reservation() {
}

string Reservation::getRoom() const {
	return room;
}
int Reservation::getFrom() const {
	return from;
}
int Reservation::getTo() const {
	return to;
}
int Reservation::getNights() const {
	return night;
}
int Reservation::getPrice() const{
	int sum = 0;
	return sum;
}
string Reservation::toString() const {
	ostringstream res;
	string customer = Fname + " " + Lname + " \n";
	res << "Room: " + room + "\nFrom: " << from << "     To: " << to << "\nNights: " << getNights();
	return customer + res.str();
}
string Reservation::overview() const {
	ostringstream res;
	res << Fname + ",  " + Lname + "  |  Room: " + room + "  |  From: " << from << "  |  To: " << to << "  |  Nights: " << getNights();
	return res.str();
}
string Reservation::toFile() const {
	ostringstream res;
	res << Fname + "|" + Lname + "|" + room + "|" << from << "|" << to << "|" << getNights();
	return res.str();
}
//string &Reservation::toStringR() const {
//	ostringstream res;
//	string customer = Fname + " " + Lname + " \n";
//	res << customer <<  "Room: " + room + "\nFrom: " << from << "     To: " << to << "\nNights: " << getNights();
//	return res.str();
//}