//#include <iostream>
//#include <string>
//using namespace std;
//
// 
//enum EventType { Football = 1, Movie = 2, Theater = 3, Concert = 4, ComedyClub = 5, Another = 6 };
//
//class Event {
//	int eventId = 0;
//	char* eventName = nullptr;
//	float price = 0;
//	char time[150] = "";
//	char dateAndTime[150] = ""; // that is telling when the event takes place (date and time)
//	int* soldItemsEachEvent = nullptr;
//	int noEvents;
//	bool hasSponsor = false;
//	EventType type;
//public:
//	static int MIN_EVENT_LENGHT;
//	static int MAX_NO_TICKETS;
//
//	EventType getEventType() {
//		return this->type;
//	}
//
//	bool doesHaveSponsor() {
//		return this->hasSponsor;
//	}
//
//	int getEventID() {
//		return this->eventId;
//	}
//
//	float getPrice() {
//		return this->price;
//	}
//
//	int* getNoSoldItemsEachMonth() {
//		if (this->noEvents == 0) {
//			return nullptr;
//		}
//		int* copy = new int[this->noEvents];
//		for (int i = 0; i < this->noEvents; i++) {
//			copy[i] = this->soldItemsEachEvent[i];
//		}
//		return copy;
//	}
//
//	void setEventID(int newEventID) {
//		if (newEventID < 0) {
//			throw exception("No negative event id possible");
//		}
//		this->eventId = newEventID;
//		if (this->eventId == 0) {
//			cout << endl << "It's not possible to have an event with ID 0";
//		}
//		else {
//			cout << endl << "Your event is is: " << newEventID;
//		}
//	}
//
//	void setEventName(const char* newEventName) {
//		if (strlen(newEventName) < Event::MIN_EVENT_LENGHT) {
//			throw exception("The event name has to have to at least 3 letters");
//		}
//		this->eventName = new char[strlen(newEventName) + 1];
//		strcpy_s(eventName, strlen(newEventName) + 1, newEventName);
//	}
//
//	void setPrice(float newPrice) {
//		if (newPrice <= 0) {
//			throw exception("The price can't be negative or 0");
//		}
//		this->price = newPrice;
//	}
//
//	void setTime(const char* newTime) {
//		int availableSpace = sizeof(this->time);
//		if (strlen(newTime) + 1 > availableSpace) {
//			throw exception("Time is too long");
//		}
//		strcpy_s(this->time, strlen(newTime) + 1, newTime);
//	}
//
//	void setDateAndTime(const char* newDateAndTime) {
//		int anotherAvailableSpace = sizeof(this->dateAndTime);
//		if (strlen(newDateAndTime) + 1 > anotherAvailableSpace) {
//			throw exception("Date and time are too long!");
//		}
//		strcpy_s(dateAndTime, strlen(newDateAndTime) + 1, newDateAndTime);
//	}
//
//	void setData(const int* data, int noEvents) {
//		if (data == 0 || noEvents == 0) {
//			throw exception("No data found");
//		}
//		if (this->soldItemsEachEvent != nullptr) {
//			delete[] this->soldItemsEachEvent;
//		}
//
//		this->soldItemsEachEvent = new int[noEvents];
//		for (int i = 0; i < noEvents; i++) {
//			this->soldItemsEachEvent[i] = data[i];
//		}
//		this->noEvents = noEvents;
//	}
//
//	void setEventType(EventType type) {
//		this->type = type;
//	}
//
//	Event():eventId(0), eventName(nullptr), price(0), time("0"), dateAndTime("0"), soldItemsEachEvent(nullptr), noEvents(0), hasSponsor(false), type(Another) {
//		cout << endl << "calling the default constructor for event class";
//	}
//
//	Event(int eventID, const char* eventName, float price) {
//		this->eventId = 0;
//		this->setEventName(eventName);
//		this->price = 0;
//
//	}
//
//	Event(int eventID, const char* eventName, float price, const char* time, const char* dateAndTime, int* data, int noEvents, EventType type) {
//		this->setEventID(eventID);
//		this->setEventName(eventName);
//		this->setPrice(price);
//		this->setTime(time);
//		this->setDateAndTime(dateAndTime);
//		this->setData(data, noEvents);
//		this->setEventType(type);
//	}
//
//	//Event class destructor
//	~Event() {
//		if (this->eventName != nullptr) {
//			delete[] this->eventName;
//		}
//		if (this->soldItemsEachEvent != nullptr) {
//			delete[] this->soldItemsEachEvent;
//		}
//	}
//
//	Event(const Event& copy) : eventName(copy.eventName), hasSponsor(hasSponsor){
//		this->setEventID(copy.eventId);
//		this->setPrice(copy.price);
//		this->setTime(copy.time);
//		this->setDateAndTime(copy.dateAndTime);
//		this->soldItemsEachEvent = new int[copy.noEvents];
//		for (int i = 0; i < copy.noEvents; i++) {
//			this->soldItemsEachEvent[i] = copy.soldItemsEachEvent[i];
//		}
//		this->noEvents = copy.noEvents;
//	}
//
//	Event& operator=(const Event& event) {
//		cout << endl << "Calling the = operator for Event class";
//		if (this == &event) {
//			cout << endl << "Is the same object";
//		}
//		this->setEventID(event.eventId);
//		this->setEventName(event.eventName);
//		this->setPrice(event.price);
//		this->setTime(event.time);
//		this->setDateAndTime(event.dateAndTime);
//		this->setData(event.soldItemsEachEvent, event.noEvents);
//		this->hasSponsor = event.hasSponsor;
//		this->type = event.type;
//		return *this;
//	}
//
//	//try to see if the id is bigger of an event
//	bool operator>(Event e) {
//		return this->eventId > e.eventId;
//	}
//
//    //preincrementare
//	Event operator++() {
//		for (int i = 0; i < this->noEvents; i++) {
//			this->soldItemsEachEvent[i]++;
//		}
//		return *this;
//	}
//
//};
//int Event::MIN_EVENT_LENGHT = 3;
//int Event::MAX_NO_TICKETS = 10000;