#include "Cart.h"


vector<Product> Cart::getArray() const
{
	return this->arr;
}
int Cart::getProductsCount() const
{
	return this->arr.size();
}
void Cart::addProduct(Product product)
{
	this->arr.push_back(product);
}
void Cart::removeProduct(Product product)
{
	this->arr.erase(remove(arr.begin(), arr.end(), product), arr.end());
}

void Cart::emptyArr()
{
	this->arr.clear();
}
void Cart::print() const
{
	for (int i = 0; i < this->arr.size(); i++)
	{
		this->arr[i].print();
	}
}