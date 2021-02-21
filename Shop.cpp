#include "Shop.h"


void swap(Product* a, Product* b)
{
	Product temp = *a;
	*a = *b;
	*b = temp;
}


void Shop::printProductsByCategory(Category category) const
{
	if (category == Category::none)
	{
		this->print();
	}
	else
	{
		for (int i = 0; i < this->arr.size(); i++)
		{
			if (this->arr[i].getCategory() == category)
			{
				this->arr[i].print();
			}

		}
	}
}

void Shop::printProductsAlphabetically() const
{

	vector<Product> tempArr = this->arr;
	

	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (tempArr[j].getName().compare(tempArr[j + 1].getName()) > 0)
			{
				swap(&tempArr[j], &tempArr[j + 1]);
			}
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		tempArr[i].print();
	}

}

void Shop::printProductsByPrice(string order) const
{

	vector<Product> tempArr = this->arr;



	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (order == "from lower")
			{
				if (tempArr[j].getPrice() > tempArr[j + 1].getPrice())
				{
					swap(&tempArr[j], &tempArr[j + 1]);
				}
			}

			if (order == "from higher")
			{
				if (tempArr[j].getPrice() < tempArr[j + 1].getPrice())
				{
					swap(&tempArr[j], &tempArr[j + 1]);
				}
			}
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		tempArr[i].print();
	}
}

