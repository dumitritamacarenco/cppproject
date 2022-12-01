#include <iostream>
#include <string>
using namespace std;

class Location {
	char* address = nullptr;
	string zone = "";
	int noOfRows = 0;
	int noOfSeats = 0;
	bool isAvailable = false;
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


};
int Location::MIN_NO_OF_SEATS = 50;
int Location::ADDRESS_LENGHT = 3;

enum EventType { Football = 1, Movie = 2, Theater = 3, Concert = 4, ComedyClub = 5, Another = 6 };

class Event {
	int eventId = 0;
	char* eventName = nullptr;
	float price = 0;
	char time[150] = "";
	char dateAndTime[150] = ""; // that is telling when the event takes place (date and time)
	int* soldItemsEachEvent = nullptr;
	int noEvents;
	bool hasSponsor = false;
	EventType type;
public:
	static int MIN_EVENT_LENGHT;
	static int MAX_NO_TICKETS;

	bool doesHaveSponsor() {
		return this->hasSponsor;
	}

	int getEventID() {
		return this->eventId;
	}

	float getPrice() {
		return this->price;
	}

	int* getNoSoldItemsEachMonth() {
		if (this->noEvents == 0) {
			return nullptr;
		}
		int* copy = new int[this->noEvents];
		for (int i = 0; i < this->noEvents; i++) {
			copy[i] = this->soldItemsEachEvent[i];
		}
		return copy;
	}

};
int Event::MIN_EVENT_LENGHT = 3;
int Event::MAX_NO_TICKETS = 10000;


class Person { // is the person that is buying a ticket for an event
	string name = "";
	int personID = 0;
	bool has18 = false;
	int* noTicketsBought = nullptr;
	int noTickets = 0;
public:
	static int MIN_NAME_LENGHT;
};
int Person::MIN_NAME_LENGHT = 3;

enum TicketType{Regular = 1, VIP = 2, Family =3}; // by family i'm trying to say that the person will have a special seat. Ex: near the stage, or on the stage :)

class Ticket {
	const int ticketID = 0;
	float price = 0;
	char* ticketDescription;
	//const int codeBarNumber; not sure yet.
	int* soldTicketsEachMonth = nullptr;
	int noMonths = 0;
	TicketType type;
public:
	static float MIN_PRICE;
	static int NO_TICKETS_BOUGHT;//bc a person can't buy 0 tickets
};
float Ticket::MIN_PRICE = 50;
int Ticket::NO_TICKETS_BOUGHT = 1;


int main() {
	std::cout << std::endl << "Hello Dumitrita";
	cout << endl << "Trying to update";
}