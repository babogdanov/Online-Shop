#pragma once

#include <vector>
#include <algorithm>
#include "Product.h"
using namespace std;
class Cart
{
protected:
	vector<Product> arr;
public:
	vector<Product> getArray() const;
	int getProductsCount() const;
	void addProduct(Product);
	void removeProduct(Product);
	void emptyArr();
	void print() const;
};

