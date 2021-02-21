#pragma once
#include "Address.h"
#include "Cart.h"
#include "Order.h"
#include <string>
class Account
{
private:
	string password;
	string username;
	Address address;
	Cart cart;
	Order currentOrder;
	
public:
	Account();
	Account(string, string);
	
	friend bool operator==(Account, Account);

	void setUsername(string);
	void setPassword(string);
	string getUsername() const;
	string getPassword() const;
	const Cart& getCart() const;
	const Order& getOrder() const;
	void setAddress(const Address&);
	Address getAddress() const;


	void addProductToCart(Product);
	void checkOut();
	
};

