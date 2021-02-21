#include "Account.h"


Account::Account()
{
	this->setUsername("Guest");
	this->setPassword("");
}

Account::Account(string username, string password)
{
	this->setUsername(username);
	this->setPassword(password);
}


bool operator==(Account first, Account second)
{
	if (first.username == second.username && first.password == second.password)
	{
		return true;
	}
	return false;
}


void Account::setUsername(string u)
{
	this->username = u;
}
void Account::setPassword(string p)
{
	this->password = p;
}

string Account::getUsername() const
{
	return this->username;
}
string Account::getPassword() const
{
	return this->password;
}

const Cart& Account::getCart() const
{
	return this->cart;
}

const Order& Account::getOrder() const
{
	return this->currentOrder;
}
void Account::setAddress(const Address& address)
{
	this->address = address;
}
Address Account::getAddress() const
{
	return this->address;
}
void Account::addProductToCart(Product product)
{
	this->cart.addProduct(product);
}

void Account::checkOut()
{
	double total = 0;
	cout << "You have ordered: ";
	for (int i = 0; i < this->getCart().getProductsCount(); i++)
	{
		cout << this->getCart().getArray()[i].getName() << ", ";
		total += this->getCart().getArray()[i].getPrice();
	}
	cout << endl;
	cout << "For a total of " << total << endl;
	
	this->address.print();
	while (true)
	{
		int toDo;
		cout << "To confirm the order press 1. Press 2 to empty your cart. Press 3 to change your address" << endl;
		cin >> toDo;

		if (toDo == 1)
		{
			
			this->currentOrder.setSum(total);
			this->currentOrder.generateId();
			this->currentOrder.writeOrderToLog();
			break;
		}
		if (toDo == 2)
		{
			this->cart.emptyArr();
			total = 0;
			/*this->cart.printContents();*/
		}
		if (toDo == 3)
		{
			this->address.inputAddress();
		}
	}
	
}
