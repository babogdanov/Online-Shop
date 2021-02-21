#include "Order.h"

Order::Order()
{
	this->id = 1;
	this->sum = 0;
}

Order::Order(const Order& other)
{
	this->id = other.id;
	this->sum = other.sum;
}

Order& Order::operator=(const Order& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->sum = other.sum;

	}
	return *this;
}
void Order::setSum(double sum)
{
	this->sum = sum;
}
void Order::generateId()
{
	this->id = 1;
	int fileId;
	this->idCounter.open("IDs.txt", ios::in);
	if (this->idCounter.is_open())
	{
		while (idCounter >> fileId)
		{
			this->id++;
		}
	}
	this->idCounter.close();
}

void Order::writeOrderToLog()
{
	this->idCounter.open("IDs.txt", ios::out | ios::app);
	if (this->idCounter.is_open())
	{
		idCounter << this->id << endl; 
	}
	this->orderHistory.close();

	this->orderHistory.open("orders.txt", ios::out | ios::app);
	if (this->orderHistory.is_open())
	{
		time_t ttime = time(0);
		char* dt = ctime(&ttime);
		orderHistory << "ID: " << this->id << ", " << "Date: " << dt << ", " << "Sum: " << this->sum << endl;
	}
	this->orderHistory.close();
}
