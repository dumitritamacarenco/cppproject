//#include <iostream>
//#include <string>
//using namespace std;
//
//enum TicketType { Regular = 1, VIP = 2, Family = 3 }; // by family i'm trying to say that the person will have a special seat. Ex: near the stage, or on the stage :)
//
//class Ticket {
//	const int ticketID = 0;
//	float price = 0;
//	char* ticketDescription = nullptr;
//	//const int codeBarNumber; not sure yet.
//	int* soldTicketsEachMonth = nullptr;
//	int noMonths = 0;
//	TicketType type;
//public:
//	static float MIN_PRICE;
//	static int NO_TICKETS_BOUGHT;//bc a person can't buy 0 tickets
//
//	const int getTicketID() {
//		return this->ticketID;
//	}
//
//	float getPrice() {
//		return this->price;
//	}
//
//
//	int* getMonthlySales() {
//		if (this->noMonths == 0) {
//			return nullptr;
//		}
//		int* copy = new int[this->noMonths];
//		for (int i = 0; i < noMonths; i++) {
//			copy[i] = this->soldTicketsEachMonth[i];
//		}
//		return copy;
//	}
//
//	int* getNoTicketsSoldItemsEachMonth() {
//		if (this->noMonths == 0) {
//			return nullptr;
//		}
//		int* copy = new int[this->noMonths];
//		for (int i = 0; i < this->noMonths; i++) {
//			copy[i] = this->soldTicketsEachMonth[i];
//		}
//		return copy;
//	}
//
//	void setPrice(float newPrice) {
//		if (newPrice == 0 && newPrice < Ticket::MIN_PRICE) {
//			throw exception("The price can't be negative or zero!");
//		}
//		this->price = newPrice;
//	}
//
//	void setTicketDescription(const char* newTicketDescription) {
//		if (newTicketDescription == nullptr) {
//			throw exception("The description can't be null!");
//		}
//		if (this->ticketDescription != nullptr) {
//			delete[] this->ticketDescription;
//		}
//		this->ticketDescription = new char[strlen(newTicketDescription) + 1];
//		strcpy_s(this->ticketDescription, strlen(newTicketDescription) + 1, newTicketDescription);
//	}
//
//	void setRecord(const int* data, int noMonths) {
//		if (data == nullptr || noMonths == 0) {
//			throw exception("No data available!");
//		}
//		if (this->soldTicketsEachMonth != nullptr) {
//			delete[] this->soldTicketsEachMonth;
//		}
//
//		this->soldTicketsEachMonth = new int[noMonths];
//		for (int i = 0; i < noMonths; i++) {
//			this->soldTicketsEachMonth[i] = data[i];
//		}
//		this->noMonths = noMonths;
//	}
//
//	/*Ticket() {
//		cout << endl << "Calling the default constructor for Ticket class";
//	}
//
//	Ticket(int ticketID) :ticketID(ticketID), price(0), ticketDescription(nullptr), soldTicketsEachMonth(0), noMonths(0) {
//		cout << endl << "Nothing to display :)";
//	}*/
//
//	Ticket(int ticketID, float price, const char* ticketDescription, int* data, int noMonths, TicketType type) :ticketID(ticketID), type(type) {
//		this->setPrice(price);
//		this->setRecord(data, noMonths);
//		this->setTicketDescription(ticketDescription);
//	}
//
//
//	/*Ticket(const Ticket& copy) : ticketID(ticketID), type(type) {
//		this->setPrice(copy.price);
//		this->setTicketDescription(copy.ticketDescription);
//		this->soldTicketsEachMonth = new int[copy.noMonths];
//		for (int i = 0; i < noMonths; i++) {
//			this->soldTicketsEachMonth[i] = copy.soldTicketsEachMonth[i];
//		}
//		this->noMonths = copy.noMonths;
//	}*/
//
//};
//float Ticket::MIN_PRICE = 50;
//int Ticket::NO_TICKETS_BOUGHT = 1;