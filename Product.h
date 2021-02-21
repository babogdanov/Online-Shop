#pragma once
#include <iostream>
#include <string>
using namespace std;
enum class Category {
	none,
	smartphones,
	shoes,
	notebooks
};
class Product
{
private:
	string name;
	double price;
	Category category;
	int id;
	
public:
	friend ostream& operator<<(ostream& out, const Category category);
	Product();
	Product(string, double, Category, int);
	friend bool operator==(Product, Product);

	string getName() const;
	double getPrice() const;
	const Category& getCategory() const;
	int getId() const;

	void print() const;
	
};

