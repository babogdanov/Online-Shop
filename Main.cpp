#include "Shop.h"

//Max size for username and password.
const int MAX_SIZE = 20;
using namespace std;

int SafelyInputInteger(int lowerBound, int upperBound) {
	long num;
	while (true) {
		cin >> num;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if ((num >= lowerBound) && (num <= upperBound)) break;
	}
	return num;
}

int main()
{
	Shop shop;
	AccountFile accounts;
	Address test("bul. Vasil Levski",12,9000,"Varna","089898989");
	
	accounts.printAccount();

	Account byDefault;
	Account currentAccount;

	Account first("qnko", "1234");
	
	first.setAddress(test);
	Account second("joro", "4321");
	second.setAddress(test);
	
	
	accounts.addAccount(first);
	accounts.addAccount(second);
	/*accounts.printAllAccounts();*/
	
	
	while (true)
	{
		cout << "Press 1 to continue as guest, 2 to log in or 3 to create a new account: ";
		int toDo;
		toDo = SafelyInputInteger(1, 3);
		if (toDo == 1)
		{
			currentAccount = byDefault;
			break;
		}
		if (toDo == 2 || toDo == 3)
		{
			char username[MAX_SIZE + 1];
			char password[MAX_SIZE + 1];

			cout << "Choose a username of up to " << MAX_SIZE << " characters: ";
			cin >> username;
			cout << "Choose a password of up to " << MAX_SIZE << " characters: ";
			cin >> password;

			currentAccount.setUsername(username);
			currentAccount.setPassword(password);

			currentAccount.setAddress(test);
			if (toDo == 2)
			{
				if (!accounts.logIn(currentAccount))
				{
					
					int toDo2;
					cout << "Enter 1 to try again, or any number to continue as guest: ";
					toDo2 = SafelyInputInteger(1,2147483646);
					if (toDo2 == 1)
					{
						continue;
					}
					
						currentAccount = byDefault;
					
				}
			}
			if (toDo == 3)
			{
				if (!accounts.addAccount(currentAccount) || !accounts.logIn(currentAccount))
				{
					int toDo2;
					cout << "Enter 1 to try again, or 2 to continue as guest: ";
					cin >> toDo2;
					if (toDo2 == 1)
					{
						continue;
					}
					if (toDo2 == 2)
					{
						currentAccount = byDefault;
					}
				}
			}
			

			accounts.printAccount();
			break;
		}
	}
	
	
	

	Product a("nokia", 15, Category::smartphones, 1);
	Product b("motorola", 33, Category::smartphones, 2);
	Product c("nike", 150, Category::shoes, 3);
	Product d("adidas", 100, Category::shoes, 4);
	Product e("reebok", 111, Category::shoes, 5);
	Product f("sony", 1300, Category::notebooks, 6);

	shop.addProduct(a);
	shop.addProduct(b);
	shop.addProduct(c);
	shop.addProduct(d);
	shop.addProduct(e);
	shop.addProduct(f);

	while (true)
	{
		cout << endl;
		cout << "Press 1 to sort the products alphabetically, 2 to sort them by price, or 3 to sort them by category";
		int toDo = SafelyInputInteger(1, 3);
		if (toDo == 1)
		{
			shop.printProductsAlphabetically();
			break;
		}
		else if (toDo == 2)
		{
			cout << "Press 1 to sort from lowest prices, or 2 to sort from highest prices: ";
			int toDo2 = SafelyInputInteger(1, 2);
			if (toDo2 == 1)
			{
				shop.printProductsByPrice("from lower");
			}
			else
			{
				shop.printProductsByPrice("from higher");
			}
			break;

		}
		else
		{
			cout << "Enter 1 for smartphones, 2 for shoes and 3 for notebooks : ";
			int toDo2 = SafelyInputInteger(0, 3);
			shop.printProductsByCategory(static_cast<Category>(toDo2));
			break;
		}

	}
	while (true)
	{
		cout << endl;
		int toDo;
		cout << "Which product do you want to add to your cart (Enter its ID, enter 0 to stop adding products): ";
		cin >> toDo;
		if (toDo == 0)
		{
			break;
		}
		for (int i = 0; i < shop.getArray().size(); i++)
		{
			if (toDo == shop.getArray()[i].getId())
			{
				currentAccount.addProductToCart(shop.getArray()[i]);
			}
		}
		
	}
	
	
	currentAccount.getCart().print();
	currentAccount.checkOut();

	
	
	return 0;
}