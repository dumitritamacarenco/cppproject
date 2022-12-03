#include <iostream>
#include <string>
using namespace std;

class Location {
	char* address = nullptr;
	string zone = "";
	int noOfRows = 0;
	int noOfSeats = 0;
	bool isAvailable = false;
	// de adaugat 2 campuri care retin tara si orasul unde evenimentul are loc
public:
	static int MIN_NO_OF_SEATS;
	static int ADDRESS_LENGHT;

	bool IsAvailable() {
		return this->isAvailable;
	}

	string getZone() {
		return this->zone;
	}

	int getNoOfRows() {
		return this->noOfRows;
	}

	int getNoOfSeats() {
		return this->noOfSeats;
	}

	void setAddress(const char* newAddress) {
		if (newAddress == nullptr && strlen(newAddress) < Location::ADDRESS_LENGHT) {
			throw exception("Address is either to short or null");
		}

		if (this->address != nullptr) {
			delete[] this->address;
		}

		this->address = new char[strlen(newAddress) + 1];
		strcpy_s(this->address, strlen(newAddress) + 1, newAddress);
	}

	void setZone(string zone) {
		if (zone.length() >= 1) { // the name for the zone can be "1" or "2" that's why i limited the lenght to 1.
			this->zone = zone;
		}
		else {
			throw exception("The name for the zone is too short");
		}
	}

	void setNoOfRows(int newNoOfRows) {
		if (newNoOfRows < 0) {
			throw exception("It can't have  a negative number of rows");
		}
		this->noOfRows = newNoOfRows;
		if (this->noOfRows == 0) {
			this->isAvailable = false;
		}
		else {
			this->isAvailable = true;
		}
	}

	void setNoOfSeats(int newNoOfSeats) {
		if (newNoOfSeats < 0) {
			throw exception("The number of seats can't be a negative number");
		}
		this->noOfSeats = newNoOfSeats;
		if (this->noOfSeats == 0) {
			this->isAvailable = false;
		}
		else {
			this->isAvailable = true;
		}
	}

	Location() {

	}

	Location(const char* address, string zone) {
		this->setAddress(address);
		this->setZone(zone);
	}

	Location(const char* address, string zone, int noOfRows, int noOfSeats) {
		this->setAddress(address);
		this->setZone(zone);
		this->setNoOfRows(noOfRows);
		this->setNoOfSeats(noOfSeats);
	}

	//Location(const Location& copy) : isAvailable(copy.isAvailable) {
	//	this->setAddress(copy.address);
	//	this->setZone(copy.zone);
	//	this->setNoOfRows(noOfRows);
	//	this->setNoOfSeats(noOfSeats);
	//}

};
int Location::MIN_NO_OF_SEATS = 50;
int Location::ADDRESS_LENGHT = 3;