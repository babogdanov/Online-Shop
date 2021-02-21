#include "Address.h"

int SafelyInputInteger() {
	long num;
	while (true) {
		cin >> num;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	return num;
}

const int MAX_STRING_SIZE = 100;
Address::Address()
{
	this->street = "";
	this->streetNumber = 0;
	this->zipcode = 0;
	this->city = "";
	this->phone = "";
}

Address::Address(string street, int streetNumber, int zipcode, string city, string phone)
{
	this->setStreet(street);
	this->setStreetNumber(streetNumber);
	this->setZipcode(zipcode);
	this->setCity(city);
	this->setPhone(phone);
}

Address::~Address()
{

}

void Address::setStreet(string street)
{
	this->street = street;
}
void Address::setStreetNumber(int streetNumber)
{
	this->streetNumber = streetNumber;
}
void Address::setZipcode(int zipcode)
{
	this->zipcode = zipcode;
}
void Address::setCity(string city)
{
	this->city = city;
}
void Address::setPhone(string phone)
{
	this->phone = phone;
}

void Address::inputAddress()
{
	string newStrings; 
	int newNumbers;

	cin.ignore();
	cout << "Enter your Street Name: ";
	getline(cin,newStrings);
	this->setStreet(newStrings);
	
	cout << "Enter your Street Number: ";
	newNumbers = SafelyInputInteger();
	this->setStreetNumber(newNumbers);

	cin.ignore();
	cout << "Enter your City: ";
	getline(cin, newStrings);
	this->setCity(newStrings);

	cout << "Enter your zipcode: ";
	newNumbers = SafelyInputInteger();
	this->setZipcode(newNumbers);
	
	cin.ignore();
	cout << "Enter your phone: ";
	getline(cin, newStrings);
	this->setPhone(newStrings);
	
	this->print();
}
void Address::print() const
{
	cout << "Delivery address is currently set as: " << this->street << " " << this->streetNumber 
		<< " , " << this->city << " , " << this->zipcode << endl << "Phone: " << this->phone << endl;
}
