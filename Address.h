#pragma once
#include <string>
#include <iostream>
using namespace std;
class Address
{
private:
	string street;
	int streetNumber;
	int zipcode;
	string city;
	string phone;

public:
	Address();
	Address(string, int, int, string, string);
	~Address();

	void setStreet(string);
	void setStreetNumber(int);
	void setZipcode(int);
	void setCity(string);
	void setPhone(string);

	void inputAddress();

	void print() const;
	
};

