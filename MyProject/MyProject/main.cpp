#include <iostream>
#include <string>
#include "LocationClass.h"
#include "EventClass.h"
#include "PersonClass.h"
#include "TicketClass.h"



using namespace std;
void main() {

	cout << endl << "-------------------------------------------------------------------------";
	cout << endl<< "EVENT CLASS ";
	cout << endl << "-------------------------------------------------------------------------";

	Event event1;
	int data3[]{ 12, 23,33 };
	Event event2(1," Country tour Carla's ", 60, " December 23, 18:00", data3, 3 , EventType::Another, true);
	cout << endl << event2;
	cout << endl << " Copy constructor "; 
	Event event3(event2);
	cout << event3;
	cout << endl << "Operator = ";
	Event event4 = event2;
	cout << event4; // ostream operator
	cout << endl;
	cin >> event4; // istream operator
	cout << " Operator ++ ";
	++event4;
	cout << event4;
	cout << endl;
	cout << " Operator > ";
	cout << endl << endl;
	if (event3 > event4)
	{
		cout << endl <<"Price at the entrance for the event 3 are more expensive than event 3 ";
	}
	else cout << " Price at the entrance for the event 4 are more expensive than event 3";
	cout << endl << endl;


	cout << endl << "-------------------------------------------------------------------------";
	cout <<endl<< " TICKET CLASS ";
	cout << endl << "-------------------------------------------------------------------------";

	Ticket t1;
	cout << endl; 
	int data[]{ 10,20, 30, 40 };
	int data2[]{ 3, 4, 5 ,100 };
	Ticket DumitritaTicket(1, 30, " Mai pe buget", data, 4, Regular);
	cout << DumitritaTicket.applyDiscount(10);
	Ticket AdrianTicket(2, 50, " Mai cu bani", data2, 4, VIP);
	cout << DumitritaTicket; // operator ostream
	cin >> AdrianTicket; // operator istream
	cout << endl;
	Ticket Nutu(DumitritaTicket); // Copy constructor c
	cout << Nutu;
	cout << " Offering a ticket from Dumitrita for the best teacher Mr. Boja :" << endl;
	Ticket Maldive = DumitritaTicket;
	cout << Maldive;

	if (Maldive <= 4000) // <= operator
	{
		cout << "Mertitati mai mult!" << endl;
	}
	else
	{
		cout << "Schimbam zborul cu destinatia: CSIE";
	}
	cout << endl;
	if (DumitritaTicket == AdrianTicket)
	{
		cout << " Frateste " << endl;
	}
	else
	{
		cout << " Frate, frate, dar branza-i pe bani " << endl;
	}



	cout << endl << "-------------------------------------------------------------------------";
	cout << endl << "LOCATION CLASS";
	cout << endl << "-------------------------------------------------------------------------";

	Location location;
	Location Ferentari("Calea Victoriei", "Sector 46, Dubai");
	cout << Ferentari;
	cout << endl;
    Location Bucuresti("Liviu Rebreanu 23", "Titan", 200, 2000, true);
	cout << Bucuresti;
	cout << endl;  // ostream
	cout << endl << Bucuresti.getZone();
	
	Location Cluj("Strada Independentei 140", "Zona Noua", 150, 1500, true);
	cin >> Cluj; cout << endl;  // operator istream
	Cluj.getNoOfRows();
	
	cout << endl << Cluj.getNoOfRows();

	Location Iasi = Cluj; // op =
	cout << Iasi;

	Location Chisinau(Bucuresti);  // copy constr
	cout << Chisinau;

	if (Bucuresti >= 100) {
		cout << endl << "Bucharest location has enough seats for the participants";
	}
	else {
		cout << endl << "Find another location" << endl;

	}

	char secondAddressChar = Bucuresti[0]; // index operator
	Bucuresti[0] = 'P';
	cout << "\n " << Bucuresti;







	cout << endl << "-------------------------------------------------------------------------";
	cout << endl <<" PERSON CLASS";
	cout << endl << "-------------------------------------------------------------------------";
		cout << endl;
	Person John;

	int datas[] = { 2,1,3,5 };
	int nrMonths = 4;
	cout << endl;
	Person Dumitrita("Dumitrita", 22, true, datas, 4);
	cout << Dumitrita;
	cout << endl << "Amount of tickets sold in total : ";
	cout << Dumitrita.TotalAmountOfSales();
	cout << endl << " Month with the biggest income : " << Dumitrita.MostSoldTicketsInAMonth();
	cout << endl << "! Operator";
	cout << !Dumitrita; // ! operator
	Person p(Dumitrita); // copy constructor

	cout << "COPY " << endl << p;
	Dumitrita.getName();
	cout << endl;
	cout << endl << Dumitrita.getName();

	Person Adrian("Adrian", 23, true, datas, 4);
	Adrian.getName();
	cout << endl << Adrian.getName();
	John = Dumitrita;
	cout << John;  // << operator
	
	cout << endl;
	cout << "Operator +";
	cout << Dumitrita + 1;
	cin >> John;  // >> operator
	Person copy1 = Adrian;   // = operator
	Dumitrita = Adrian;
	
	
	cout << endl << "-------------------------------------------------------------------------";
	cout << endl << " ADULT CLASS";
	cout << endl << "-------------------------------------------------------------------------";
	cout << endl;

	int numbers[] = { 2,3 };
	int noNumbers = 2;

	Adult Mihai("Mihai", 2, 1, numbers, noNumbers, 501983400238, 40);
	cout << endl;
	cout << Mihai;

	cout << endl; 

	cout << "=============Virtual methods ====================="; 
	Person* person = new Adult(Mihai);
	person->addAnotherCNP(508787);
	cout << endl;
	person->checkHeight(34);

}
