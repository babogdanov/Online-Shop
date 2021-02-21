#include "Product.h"

ostream& operator<<(ostream& out, const Category category)
{
	switch (category)
	{
	case Category::none: out << "None"; break;
	case Category::smartphones: out << "Smartphones"; break;
	case Category::shoes: out << "Shoes"; break;
	case Category::notebooks: out << "Notebooks"; break;
	}
	return out;
}

Product::Product()
{
	this->name = "";
	this->price = 0;
	this->category = Category::none;
	this->id = 0;
}
Product::Product(string name, double price, Category category, int id)
{
	this->name = name;
	this->price = price;
	this->category = category;
	this->id = id;
}


bool operator==(Product first, Product second)
{
	if (first.getName() == second.getName()  && first.getPrice() == second.getPrice()
		&& first.getCategory() == second.getCategory() && first.getId() == second.getId())
	{
		return true;
	}
	return false;
}

string Product::getName() const
{
	return this->name;
}
double Product::getPrice() const
{
	return this->price;
}
const Category& Product::getCategory() const
{
	return this->category;
}
int Product::getId() const
{
	return this->id;
}

void Product::print() const
{
	cout << "Name: " << this->name << endl;
	cout << "Category: " << this->category << endl;
	cout << "Price: " << this->price << endl;
	cout << "ID: " << this->id << endl << endl;
}
