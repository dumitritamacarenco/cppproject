//#include <iostream>
//#include <string>
//using namespace std;
//
//class Location {
//	char* address = nullptr;
//	string zone = "";
//	int noOfRows = 0;
//	int noOfSeats = 0;
//	bool isAvailable = false;
//
//public:
//	static int MIN_NO_OF_SEATS;
//	static int ADDRESS_LENGHT;
//
//	bool IsAvailable() {
//		return this->isAvailable;
//	}
//
//	string getZone() {
//		return this->zone;
//	}
//
//	int getNoOfRows() {
//		return this->noOfRows;
//	}
//
//	int getNoOfSeats() {
//		return this->noOfSeats;
//	}
//
//	void setAddress(const char* newAddress) {
//		if (newAddress == nullptr && strlen(newAddress) < Location::ADDRESS_LENGHT) {
//			throw exception("Address is either to short or null");
//		}
//
//		if (this->address != nullptr) {
//			delete[] this->address;
//		}
//
//		this->address = new char[strlen(newAddress) + 1];
//		strcpy_s(this->address, strlen(newAddress) + 1, newAddress);
//	}
//
//	void setZone(string zone) {
//		if (zone.length() >= 1) { // the name for the zone can be "1" or "2" that's why i limited the lenght to 1.
//			this->zone = zone;
//		}
//		else {
//			throw exception("The name for the zone is too short");
//		}
//	}
//
//	void setNoOfRows(int newNoOfRows) {
//		if (newNoOfRows < 0) {
//			throw exception("It can't have  a negative number of rows");
//		}
//		this->noOfRows = newNoOfRows;
//		if (this->noOfRows == 0) {
//			this->isAvailable = false;
//		}
//		else {
//			this->isAvailable = true;
//		}
//	}
//
//	void setNoOfSeats(int newNoOfSeats) {
//		if (newNoOfSeats < 0) {
//			throw exception("The number of seats can't be a negative number");
//		}
//		this->noOfSeats = newNoOfSeats;
//		if (this->noOfSeats == 0) {
//			this->isAvailable = false;
//		}
//		else {
//			this->isAvailable = true;
//		}
//	}
//
//	Location():address(nullptr), zone("nothing"), noOfRows(0), noOfSeats(0), isAvailable(false) {
//		cout << endl << "Calling the default constructor";
//	}
//
//	Location(const char* address, string zone) {
//		this->setAddress(address);
//		this->setZone(zone);
//	}
//
//	Location(const char* address, string zone, int noOfRows, int noOfSeats) {
//		this->setAddress(address);
//		this->setZone(zone);
//		this->setNoOfRows(noOfRows);
//		this->setNoOfSeats(noOfSeats);
//	}
//
//	//Location class destructor
//	~Location() {
//		if (this->address != nullptr) {
//			delete[] this->address;
//		}
//	}
//
//	Location(const Location& copy) : isAvailable(copy.isAvailable) {
//		this->setAddress(copy.address);
//		this->setZone(copy.zone);
//		this->setNoOfRows(noOfRows);
//		this->setNoOfSeats(noOfSeats);
//	}
//
//	Location& operator = (const Location& location) {
//		cout << endl << "Calling the operator  = fot Location class";
//		this->setAddress(location.address);
//		this->setZone(location.zone);
//		this->setNoOfRows(location.noOfRows);
//		this->setNoOfSeats(location.noOfSeats);
//		this->isAvailable= location.isAvailable;
//		return *this;
//	}
//
//	/*char secondAddressChar = johnList[1];
//	johnList[1] = 'X';*/
//
//	char& operator[](int index) {
//		if (index < 0 || index >= strlen(this->address)) {
//			throw "Wrong index";
//		}
//		return this->address[index];
//	}
//
//	
//
//	//see if the location bucursti has more no of seats than location from cluj
//	/*if (bucuresti == cluj) {
//		cout << endl << "They have the same no of seats";
//	}*/
//	//pentru main
//	/*if (johnsticket <= 100) {
//		cout << enld << "Bucharest location has more  or equal seats than Cluj location";
//	}
//	else {
//		cout << endl << "Bucharest location has less seats than Cluj location";
//	}*/
//
//	bool operator>=(float value) {
//		return this->noOfSeats <= value;
//	}
//
//
//
//};
//int Location::MIN_NO_OF_SEATS = 50;
//int Location::ADDRESS_LENGHT = 3;