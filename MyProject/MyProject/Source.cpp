#include <iostream>
#include <string>
using namespace std;

class Location {
	char* address = nullptr;
	int noOfRows = 0;
	string zone = "";
	int noOfSeat = 0;
};

class Event {
	int eventId = 0;
	char* eventName = nullptr;
	float price = 0;
	float time = 0;
	float durationTime = 0;
	int* soldItemsEachEvent = nullptr;
	int noEvents;
};

class Person { // is the person that is buying a ticket for an event
	string name = "";
	int personID = 0;
	bool has18 = false;
	int* noTicketsBought = nullptr;
	int noTickets = 0;
};

class Ticket {
	const int ticketID = 0;
	float price = 0;
	char* ticketDescription;
	//const int codeBarNumber; not sure yet.

};


int main() {
	std::cout << std::endl << "Hello Dumitrita";
	cout << endl << "Trying to update";
}