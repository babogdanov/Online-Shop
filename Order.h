#pragma once
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;
class Order
{
private:
	long long int id;
	double sum;
	ofstream orderHistory;
	fstream idCounter;
	
public:
	Order();
	Order(const Order& other);
	Order& operator=(const Order& other);
	void setSum(double);
	void generateId();
	void writeOrderToLog();
};

