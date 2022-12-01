#include <iostream>
#include <string>
using namespace std;

class Location {
	char* address = nullptr;
	int noOfRows = 0;
	string zone = "";
	int noOfSeat = 0;
public:
	static int MIN_NO_OF_SEATS;
};
int Location::MIN_NO_OF_SEATS = 50;

enum EventType { Football = 1, Movie = 2, Theater = 3, Concert = 4, ComedyClub = 5, Another = 6 };

class Event {
	int eventId = 0;
	char* eventName = nullptr;
	float price = 0;
	float time = 0;
	float durationTime = 0;
	int* soldItemsEachEvent = nullptr;
	int noEvents;
	EventType type;
public:
	static int MIN_EVENT_LENGHT;
	static int MAX_NO_TICKETS;
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