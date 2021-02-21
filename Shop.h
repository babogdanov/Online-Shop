#pragma once

#include "AccountFile.h"
#include "ProductArray.h"
//A Shop object is like a Cart object, but with all the Products inside.
class Shop: public Cart
{
public:
	void printProductsByCategory(Category category) const;
	void printProductsAlphabetically() const;
	void printProductsByPrice(string order) const;
};

