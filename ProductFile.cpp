#include "ProductFile.h"
#include <iostream>
using namespace std; 


void swap(Product* a, Product* b)
{
	Product temp = *a;
	*a = *b;
	*b = temp;
}
void ProductFile::printByCategory(const char* category) const
{
	if (category == "")
	{
		for (int i = 0; i < this->productsCount; i++)
		{
			 this->products[i].print();
		}
	}
	else
	{
		for (int i = 0; i < this->productsCount; i++)
		{
			if (strcmp(this->products[i].getCategory(), category) == 0)
			{
				this->products[i].print();
			}
			
		}
	}
}

void ProductFile::printAlphabetically() const
{
	
	Product* tempArr = new Product[this->productsCount];
	for (int i = 0; i < productsCount; i++)
	{
		tempArr[i] = products[i];
	}

	for (int i = 0; i < productsCount - 1; i++)
	{
		for (int j = 0; j < productsCount - i - 1; j++)
		{
			if (strcmp(tempArr[j].getName(), tempArr[j + 1].getName()) > 0)
			{
				swap(&tempArr[j], &tempArr[j + 1]);
			}
		}
	}
	for (int i = 0; i < productsCount; i++)
	{
		tempArr[i].print();
	}
	
}

void ProductFile::printByPrice(const char* order) const
{
	
	Product* tempArr = new Product[this->productsCount];
	for (int i = 0; i < productsCount; i++)
	{
		tempArr[i] = products[i];
	}

	

	for (int i = 0; i < productsCount - 1 ; i++)
	{
		for (int j = 0; j < productsCount - i - 1; j++)
		{
			if (strcmp(order, "from lower") == 0)
			{
				if (tempArr[j].getPrice() > tempArr[j + 1].getPrice())
				{
					swap(&tempArr[j], &tempArr[j + 1]);
				}
			}
			
			if (strcmp(order, "from higher") == 0)
			{
				if (tempArr[j].getPrice() < tempArr[j + 1].getPrice())
				{
					swap(&tempArr[j], &tempArr[j + 1]);
				}
			}
		}
	}
	for (int i = 0; i < productsCount; i++)
	{
		tempArr[i].print();
	}



}
void ProductFile::addProduct(Product product) 
{
	Product* temp = new Product[productsCount];
	for (int i = 0; i < productsCount; i++)
	{
		temp[i] = this->products[i];
	}
	delete[] products;
	this->productsCount++;
	products = new Product[productsCount];
	for (int i = 0; i < productsCount - 1; i++)
	{
		this->products[i] = temp[i];
	}
	this->products[productsCount - 1] = product;
	delete[] temp;
}