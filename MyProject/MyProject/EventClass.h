#pragma once
#include <iostream>
#include <string>
using namespace std;

enum EventType { Football = 1, Movie = 2, Theater = 3, Concert = 4, ComedyClub = 5, Another = 6 };

class Event {
	int eventId = 0;
	char* eventName = nullptr;
	float price = 0;
	char dateAndTime[150] = ""; // that is telling when the event takes place (date and time)
	int* soldItemsEachEvent = nullptr;
	int noEvents = 0;
	bool hasSponsor = false;
	EventType type;
public:
	static int MIN_EVENT_LENGHT;
	static int MAX_NO_TICKETS;

	Event() :eventId(0), eventName(nullptr), price(0), dateAndTime("-"), soldItemsEachEvent(nullptr), noEvents(0), hasSponsor(false), type(Another) {
		cout << endl << "calling the default constructor for event class";
	}

	/*Event(int eventID, const char* eventName, float price) {
		this->eventId = eventID;
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
		this->eventName = new char[strlen(eventName) + 1];
		strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		this->price = price;

	}*/
	/*Event(int eventID, const char* eventName, float price, const char* time, const char* dateAndTime, int* data, int noEvents, EventType type) {
	this->setEventID(eventID);
	this->setEventName(eventName);
	this->setPrice(price);
	this->setTime(time);
	this->setDateAndTime(dateAndTime);
	this->setData( data, noEvents);
	this->setEventType(type);

}*/
	Event(int eventID, const char* eventName, float price, const char* newDateAndTime, int* data, int noEvents, EventType type, bool has)
	{
		this->eventId = eventID;
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
		this->eventName = new char[strlen(eventName) + 1];
		strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		this->price = price;
		int anotherAvailableSpace = sizeof(this->dateAndTime);
		if (strlen(newDateAndTime) + 1 > anotherAvailableSpace) {
			throw exception("Date and time are too long!");
		}
		strcpy_s(dateAndTime, strlen(newDateAndTime) + 1, newDateAndTime);

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
		this->type = type;
		this->hasSponsor = has;
	}


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
	// setters
	void setEventID(int newEventID) {
		if (newEventID < 0) {
			throw exception("No negative event id possible");
		}
		this->eventId = newEventID;
		if (this->eventId == 0) {
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

	void setDateAndTime(const char* newDateAndTime) {
		int anotherAvailableSpace = sizeof(this->dateAndTime);
		if (strlen(newDateAndTime) + 1 > anotherAvailableSpace) {
			throw exception("Date and time are too long!");
		}
		strcpy_s(dateAndTime, strlen(newDateAndTime) + 1, newDateAndTime);
	}

	void setData(int* data, int noEvents) {
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




	Event(const Event& copy) {

		this->eventId = copy.eventId;
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
		this->eventName = new char[strlen(copy.eventName) + 1];
		strcpy_s(this->eventName, strlen(copy.eventName) + 1, copy.eventName);
		this->price = copy.price;
		int anotherAvailableSpace = sizeof(this->dateAndTime);
		if (strlen(copy.dateAndTime) + 1 > anotherAvailableSpace) {
			throw exception("Date and time are too long!");
		}
		strcpy_s(this->dateAndTime, strlen(copy.dateAndTime) + 1, copy.dateAndTime);

		if (copy.soldItemsEachEvent == 0 || copy.noEvents == 0) {
			throw exception("No data found");
		}
		if (this->soldItemsEachEvent != nullptr) {
			delete[] this->soldItemsEachEvent;
		}

		this->soldItemsEachEvent = new int[copy.noEvents];
		for (int i = 0; i < copy.noEvents; i++) {
			this->soldItemsEachEvent[i] = copy.soldItemsEachEvent[i];
		}
		this->noEvents = copy.noEvents;
		this->type = copy.type;
		this->hasSponsor = copy.hasSponsor;
	}

	Event& operator=(const Event& copy) {

		this->eventId = copy.eventId;
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
		this->eventName = new char[strlen(copy.eventName) + 1];
		strcpy_s(this->eventName, strlen(copy.eventName) + 1, copy.eventName);
		this->price = copy.price;
		int anotherAvailableSpace = sizeof(this->dateAndTime);
		if (strlen(copy.dateAndTime) + 1 > anotherAvailableSpace) {
			throw exception("Date and time are too long!");
		}
		strcpy_s(this->dateAndTime, strlen(copy.dateAndTime) + 1, copy.dateAndTime);

		if (copy.soldItemsEachEvent == 0 || copy.noEvents == 0) {
			throw exception("No data found");
		}
		if (this->soldItemsEachEvent != nullptr) {
			delete[] this->soldItemsEachEvent;
		}

		this->soldItemsEachEvent = new int[copy.noEvents];
		for (int i = 0; i < copy.noEvents; i++) {
			this->soldItemsEachEvent[i] = copy.soldItemsEachEvent[i];
		}
		this->noEvents = copy.noEvents;
		this->type = copy.type;
		this->hasSponsor = copy.hasSponsor;
		return *this;
	}

	//try to see if the id is bigger of an event
	bool operator>(Event e) {
		return this->price > e.price;
	}

	//preincrementare
	Event& operator++() {
		this->eventId++;
		return *this;
	}

	
	//Event class destructor
	
	~Event() {
		cout << "call destructor ";
		if (this->eventName != nullptr) {
			delete[] this->eventName;
		}
		if (this->soldItemsEachEvent != nullptr) {
			delete[] this->soldItemsEachEvent;
		}
	}


	friend ostream& operator<<(ostream& out, const Event event);
	friend istream& operator>>(istream& in, Event& event);

};
int Event::MIN_EVENT_LENGHT = 3;
int Event::MAX_NO_TICKETS = 10000;

ostream& operator<<(ostream& out, const Event event) {
	cout << endl;;
	out << "The id for the event is: " << event.eventId << endl;
	out << (event.eventName != nullptr ? "Event name : " + string(event.eventName) : "No name") << endl;
	//out << "The event name is: " << event.eventName << endl;
	out << "The price for event entrance is: " << event.price << endl;
	out << "The time and date that the event is: " << event.dateAndTime << endl;
	out << "Does the event has a sponsor? " << event.hasSponsor << endl;
	out << "The event is the type of: " << event.type << endl;
	out << "The number of events each months is: " << event.noEvents << endl;
	for (int i = 0; i < event.noEvents; i++)
	{
		out << " Sold items for " << i + 1 << " month: " << event.soldItemsEachEvent[i] << endl;
	}

	return out;
}

istream& operator>>(istream& in, Event& event) {
	cout << endl;
	cout << " Event ID: ";  in >> event.eventId;

	cout << "The event name is: " << endl;
	char buffer[100];
	in.ignore();
	in.getline(buffer, 100);
	in.clear();
	delete[] event.eventName;
	event.eventName = new char[strlen(buffer) + 1];
	strcpy_s(event.eventName, strlen(buffer) + 1, buffer);

	cout << "The price at the intrance is: " << endl;
	in >> event.price;
	cout << "Does it have a sponsor? 1 for YES, 0 for NO " << endl;
	cin >> event.hasSponsor;
	cout << "The time and date that the event starts is:" << endl;
	cin >> event.dateAndTime;
	cout << "Number of events: " << endl;
	cin >> event.noEvents;
	delete[] event.soldItemsEachEvent;
	event.soldItemsEachEvent = new int[event.noEvents];
	for (int i = 0; i < event.noEvents; i++) 
	{
		cout << "Sold items for the :  " << i + 1 << " month : ";
		in >> event.soldItemsEachEvent[i];
	}
	

	
	return in;
}