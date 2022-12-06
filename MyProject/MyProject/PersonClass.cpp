//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person { // is the person that is buying a ticket for an event
//	char* name = nullptr;
//	int personID = 0;
//	bool has18 = false;
//	int* noTicketsBoughtEachMonth = nullptr;
//	int noMonths = 0;
//public:
//	static int MIN_NAME_LENGHT;
//
//	bool Has18() {
//		return this->has18;
//	}
//
//	char* getName() {
//		char* nameCopy = new char[strlen(this->name) + 1];
//		strcpy_s(nameCopy, strlen(this->name) + 1, this->name);
//		return nameCopy;
//	}
//
//	int getPersonID() {
//		return this->personID;
//	}
//
//	void setName(const char* newName) {
//		if (newName == nullptr && strlen(newName) < Person::MIN_NAME_LENGHT) {
//			throw exception("The name can't be that short or null");
//		}
//		if (this->name != nullptr) {
//			delete[] this->name;
//		}
//		this->name = new char[strlen(newName) + 1];
//		strcpy_s(this->name, strlen(newName) + 1, newName);
//	}
//
//	void setPersonID(int newPersonID) {
//		if (newPersonID < 0) {
//			throw exception("The person can't have an id equal to 0 or a negative id!");
//		}
//		this->personID = newPersonID;
//		if (this->personID == 0) {
//			cout << endl << "It's not possible to have an ID equal to 0!";
//		}
//		else {
//			cout << endl << "Your person ID is: " << newPersonID;
//		}
//	}
//
//	void setDataForPerson(const int* data, int noMonths) {
//		if (data == nullptr || noMonths == 0) {
//			throw exception("No data available!");
//		}
//		if (this->noTicketsBoughtEachMonth != nullptr) {
//			delete[] this->noTicketsBoughtEachMonth;
//		}
//
//		this->noTicketsBoughtEachMonth = new int[noMonths];
//		for (int i = 0; i < noMonths; i++) {
//			this->noTicketsBoughtEachMonth[i] = data[i];
//		}
//		this->noMonths = noMonths;
//	}
//
//	Person():name(nullptr), personID(0), has18(false), noTicketsBoughtEachMonth(nullptr), noMonths(0) {
//		cout << endl << "Calling the default constructor for Person class";
//	}
//
//
//	Person(const char* name, int personID, bool has18, int* data, int noMonths) :has18(has18) {
//		this->setName(name);
//		this->setPersonID(personID);
//		this->setDataForPerson(data, noMonths);
//	}
//
//	Person(const char* name) {
//		this->setName(name);
//	}
//
//	//Person class destructor
//	~Person() {
//		if (this->name != nullptr) {
//			delete[] this->name;
//		}
//		if (this->noTicketsBoughtEachMonth != nullptr) {
//			delete[] this->noTicketsBoughtEachMonth;
//		}
//	}
//
//	Person(const Person& copy) : has18(has18) {
//		this->setName(copy.name);
//		this->setPersonID(copy.personID);
//		this->noTicketsBoughtEachMonth = new int[copy.noMonths];
//		for (int i = 0; i < copy.noMonths; i++) {
//			this->noTicketsBoughtEachMonth[i] = copy.noTicketsBoughtEachMonth[i];
//		}
//		this->noMonths = copy.noMonths;
//	}
//
//	Person& operator=(const Person& person) {
//		cout << endl << "Calling the = operator for Person class";
//		if (this == &person) {
//			cout << endl << "Is the same object";
//		}
//		this->setName(person.name);
//		this->setPersonID(person.personID);
//		this->has18 = person.has18;
//		this->setDataForPerson(person.noTicketsBoughtEachMonth, person.noMonths);
//		return *this;
//	}
//
//
//	Person operator+(int value) {
//		Person result = *this;
//
//		int* newArray = new int[result.noMonths + 1];
//		for (int i = 0; i < result.noMonths; i++) {
//			newArray[i] = result.noTicketsBoughtEachMonth[i];
//		}
//		newArray[this->noMonths] = value;
//		
//		delete[] result.noTicketsBoughtEachMonth;
//		result.noTicketsBoughtEachMonth = newArray;
//
//		result.noMonths += 1;
//		 
//		return result;
//	}
//
//	//postincrementare
//	Person operator++(int) {
//		Person temp = *this;
//		for (int i = 0; i < this->noMonths; i++) {
//			this->noTicketsBoughtEachMonth[i]++;
//		}
//		return temp;
//	}
//
//};
//
//int Person::MIN_NAME_LENGHT = 3;