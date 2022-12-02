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

	EventType getEventType() {
		return this->type;
	}

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

	void setEventID(int newEventID) {
		if (newEventID < 0) {
			throw exception("No negative event id possible");
		}
		this->eventId = newEventID;
		if(this->eventId == 0) {
			cout << endl << "It's not possible to have an event with ID 0";
		}
		else {
			cout << endl << "Your event is is: " << newEventID;
		}
	}

	void setEventName(const char* newEventName) {
		if (strlen(newEventName) < Event::MIN_EVENT_LENGHT) {
			throw exception("The event name has to have to at least 3 letters");
		}
		this->eventName = new char[strlen(newEventName) + 1];
		strcpy_s(eventName, strlen(newEventName) + 1, newEventName);
	}

	void setPrice(float newPrice) {
		if (newPrice <= 0) {
			throw exception("The price can't be negative or 0");
		}
		this->price = newPrice;
	}

	void setTime(const char* newTime) {
		int availableSpace = sizeof(this->time);
		if (strlen(newTime) + 1 > availableSpace) {
			throw exception("Time is too long");
		}
		strcpy_s(this->time, strlen(newTime) + 1, newTime);
	}

	void setDateAndTime(const char* newDateAndTime) {
		int anotherAvailableSpace = sizeof(this->dateAndTime);
		if (strlen(newDateAndTime) + 1 > anotherAvailableSpace) {
			throw exception("Date and time are too long!");
		}
		strcpy_s(dateAndTime, strlen(newDateAndTime) + 1, newDateAndTime);
	}

	void setData(const int* data, int noEvents) {
		if (data == 0 || noEvents == 0) {
			throw exception("No data found");
		}
		if (this->soldItemsEachEvent != nullptr) {
			delete[] this->soldItemsEachEvent;
		}
		
		this->soldItemsEachEvent = new int[noEvents];
		for (int i = 0; i < noEvents; i++) {
			this->soldItemsEachEvent[i] = data[i];
		}
		this->noEvents = noEvents;
	}

	void setEventType(EventType type) {
		this->type = type;
	}

	Event() {
		this->eventId = 0;
	}

	Event(int eventID, const char* eventName, float price) {
		this->eventId = 0;
		this->setEventName(eventName);
		this->price = 0;

	}

	Event(int eventID, const char* eventName, float price, const char* time, const char* dateAndTime, int* data, int noEvents, EventType type) {
		this->setEventID(eventID);
		this->setEventName(eventName);
		this->setPrice(price);
		this->setTime(time);
		this->setDateAndTime(dateAndTime);
		this->setData(data, noEvents);
		this->setEventType(type);
	}

};
int Event::MIN_EVENT_LENGHT = 3;
int Event::MAX_NO_TICKETS = 10000;


class Person { // is the person that is buying a ticket for an event
	char* name = nullptr;
	int personID = 0;
	bool has18 = false;
	int* noTicketsBoughtEachMonth = nullptr;
	int noMonths = 0;
public:
	static int MIN_NAME_LENGHT;

	bool Has18() {
		return this->has18;
	}

	char* getName() {
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy_s(nameCopy, strlen(this->name) + 1, this->name);
		return nameCopy;
	}

	int getPersonID() {
		return this->personID;
	}

	void setName(const char* newName) {
		if (newName == nullptr && strlen(newName) < Person::MIN_NAME_LENGHT ) {
			throw exception("The name can't be that short or null");
		}
		if (this->name != nullptr) {
			delete[] this->name;
		}
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}

	void setPersonID(int newPersonID) {
		if (newPersonID < 0) {
			throw exception("The person can't have an id equal to 0 or a negative id!");
		}
		this->personID = newPersonID;
		if (this->personID == 0) {
			cout << endl << "It's not possible to have an ID equal to 0!";
		}
		else {
			cout << endl << "Your person ID is: " << newPersonID;
		}
	}

	void setDataForPerson(const int* data, int noMonths) {
		if (data == nullptr || noMonths == 0) {
			throw exception("No data available!");
		}
		if (this->noTicketsBoughtEachMonth != nullptr) {
			delete[] this->noTicketsBoughtEachMonth;
		}

		this->noTicketsBoughtEachMonth = new int[noMonths];
		for (int i = 0; i < noMonths; i++) {
			this->noTicketsBoughtEachMonth[i] = data[i];
		}
		this->noMonths = noMonths;
	}

	Person() {

	}


	Person(const char* name) {
		this->setName(name);
	}
};

int Person::MIN_NAME_LENGHT = 3;

enum TicketType{Regular = 1, VIP = 2, Family =3}; // by family i'm trying to say that the person will have a special seat. Ex: near the stage, or on the stage :)

class Ticket {
	const int ticketID = 0;
	float price = 0;
	char* ticketDescription = nullptr ;
	//const int codeBarNumber; not sure yet.
	int* soldTicketsEachMonth = nullptr;
	int noMonths = 0;
	TicketType type;
public:
	static float MIN_PRICE;
	static int NO_TICKETS_BOUGHT;//bc a person can't buy 0 tickets

	const int getTicketID() {
		return this->ticketID;
	}

	float getPrice() {
		return this->price;
	 }

	
	int* getMonthlySales() {
		if (this->noMonths == 0) {
			return nullptr;
		}
		int* copy = new int[this->noMonths];
		for (int i = 0; i < noMonths; i++) {
			copy[i] = this->soldTicketsEachMonth[i];
		}
		return copy;
	}

	int* getNoTicketsSoldItemsEachMonth() {
		if (this->noMonths == 0) {
			return nullptr;
		}
		int* copy = new int[this->noMonths];
		for (int i = 0; i < this->noMonths; i++) {
			copy[i] = this->soldTicketsEachMonth[i];
		}
		return copy;
	}

	void setPrice(float newPrice) {
		if (newPrice == 0 && newPrice < Ticket::MIN_PRICE) {
			throw exception("The price can't be negative or zero!");
		}
		this->price = newPrice;
	}

	void setTicketDescription(const char* newTicketDescription) {
		if (newTicketDescription == nullptr) {
			throw exception("The description can't be null!");
		}
		if (this->ticketDescription != nullptr) {
			delete[] this->ticketDescription;
		}
		this->ticketDescription = new char[strlen(newTicketDescription) + 1];
		strcpy_s(this->ticketDescription, strlen(newTicketDescription) + 1, newTicketDescription);
	}

	void setRecord(const int* data, int noMonths) {
		if (data == nullptr || noMonths == 0) {
			throw exception("No data available!");
		}
		if (this->soldTicketsEachMonth != nullptr) {
			delete[] this->soldTicketsEachMonth;
		}

		this->soldTicketsEachMonth = new int[noMonths];
		for (int i = 0; i < noMonths; i++) {
			this->soldTicketsEachMonth[i] = data[i];
		}
		this->noMonths = noMonths;
	}

	Ticket() {

	}


};
float Ticket::MIN_PRICE = 50;
int Ticket::NO_TICKETS_BOUGHT = 1;


int main() {
	std::cout << std::endl << "Hello Dumitrita";
	cout << endl << "Trying to update";

	Event casaMare(1, "Casa mare la Bucuresti", 200);
}