#pragma once
#include <iostream>
#include <string>
using namespace std;

enum TicketType { Regular = 1, VIP = 2, Family = 3 }; // by family i'm trying to say that the person will have a special seat. Ex: near the stage, or on the stage :)

class Ticket {
	const int ticketID = 0;
	float price = 0;
	char* ticketDescription = nullptr;
	int* soldTicketsEachMonth = nullptr;
	int noMonths = 0;
	TicketType type;
public:
	static float MIN_PRICE;
	static int NO_TICKETS_BOUGHT;//bc a person can't buy 0 tickets



	Ticket() : ticketID(0), price(0), ticketDescription(nullptr), soldTicketsEachMonth(nullptr), noMonths(0), type(Regular) {
		cout << endl << "Calling the default constructor for Ticket class";
	}

	Ticket(int ticketID, float price, const char* ticketDescription, int* data, int noMonths, TicketType type) :ticketID(ticketID), type(type) {
		this->price = price;
		this->ticketDescription = new char[strlen(ticketDescription) + 1];
		strcpy_s(this->ticketDescription, strlen(ticketDescription) + 1, ticketDescription);

		this->soldTicketsEachMonth = new int[noMonths];
		for (int i = 0; i < noMonths; i++)
		{
			this->soldTicketsEachMonth[i] = data[i];
		}
		this->noMonths = noMonths;
	}
	Ticket(const Ticket& t): ticketID(t.ticketID)
	{
		this->type = t.type;
		this->price = t.price;
		this->ticketDescription = new char[strlen(t.ticketDescription) + 1];
		strcpy_s(this->ticketDescription, strlen(t.ticketDescription) + 1, t.ticketDescription);

		this->soldTicketsEachMonth = new int[t.noMonths];
		for (int i = 0; i < t.noMonths; i++)
		{
			this->soldTicketsEachMonth[i] = t.soldTicketsEachMonth[i];
		}
		this->noMonths = t.noMonths;
	}
	Ticket& operator= (Ticket& t)
	{
		this->type = t.type;
		this->price = t.price;
		this->ticketDescription = new char[strlen(t.ticketDescription) + 1];
		strcpy_s(this->ticketDescription, strlen(t.ticketDescription) + 1, t.ticketDescription);

		this->soldTicketsEachMonth = new int[t.noMonths];
		for (int i = 0; i < t.noMonths; i++)
		{
			this->soldTicketsEachMonth[i] = t.soldTicketsEachMonth[i];
		}
		this->noMonths = t.noMonths;
	}


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


	~Ticket() {
		if (this->ticketDescription != nullptr) {
			delete[] this->ticketDescription;
		}
		if (this->soldTicketsEachMonth != nullptr) {
			delete[] this->soldTicketsEachMonth;
		}
	}




	bool operator== (const Ticket& t)
	{
		return this->price == t.price;
	}
	bool operator<=(float value) {
		return this->price <= value;
	}

	float applyDiscount(float discount)
	{ 
		float finalPrice = 0;
		cout << "Final price with the applied discount for the ticket : "; 
	    finalPrice+= this->price - (this->price*discount / 100);
	  return finalPrice;

	}

	friend ostream& operator<<(ostream& out, Ticket& t);
	friend istream& operator>>(istream& in, Ticket& t);


};
float Ticket::MIN_PRICE = 50;
int Ticket::NO_TICKETS_BOUGHT = 1;

bool operator==(Ticket& ticket1, Ticket& ticket2) {
	return ticket1.getPrice() == ticket2.getPrice();
}

ostream& operator<<(ostream& out, Ticket& t)
{
	out << " Ticket ID: " << t.ticketID << endl;
	out << "Price: " << t.price << endl;
	out << "Ticket Description : " << t.ticketDescription << endl;
	out << " Ticket type :" << t.type << endl;
	out << " No Months: " << t.noMonths << endl;
	for (int i = 0; i < t.noMonths; i++)
	{
		out << "Amount " << t.soldTicketsEachMonth[i] << " " << endl;
	}
	return out;
}
istream& operator>>(istream& in, Ticket& t)
{
	cout << " Ticket Price: ";
	in >> t.price;
	char buffer[100];
	in.ignore();
	cout << " Ticket Description : " << endl;
	in.getline(buffer, 100);
	in.clear();

	delete[] t.ticketDescription;
	t.ticketDescription = new char[strlen(buffer) + 1];
	strcpy_s(t.ticketDescription, strlen(buffer) + 1, buffer);

	cout << " No months ";
	in >> t.noMonths;
	delete[] t.soldTicketsEachMonth;
	t.soldTicketsEachMonth = new int[t.noMonths];
	for (int i = 0; i < t.noMonths; i++)
	{
		cout << "\n Tickets sold in the : " << i + 1 << " month: "; in >> t.soldTicketsEachMonth[i];
	}
	return in;
}
