#include "AccountFile.h"


using namespace std;


bool AccountFile::addAccount(Account account)
{
	
	for (int i = 0; i < this->arr.size(); i++)
	{
		if (this->arr[i].getUsername() == account.getUsername())
		{
			cout << "Username is already taken. Choose another username." << endl;
			return false;
		}
	}
	this->arr.push_back(account);
	
	return true;
		
}

bool AccountFile::logIn(Account account)
{
	for (int i = 0; i < this->arr.size(); i++) {
		if (this->arr[i] == account)
		{
			this->currentAccount = account;
			cout << "You have logged in successfully." << endl;
			return true;
		}
	}
	cout << "There is no account with this username and password. Try again or create a new account." << endl;
	return false;
}

void AccountFile::logOut()
{
	this->currentAccount.setUsername("Guest");
	this->currentAccount.setPassword("");
}
void AccountFile::printAccount() const {
	
	cout <<"You are currently logged in as: "<< this->currentAccount.getUsername() << endl;
	
}
void AccountFile::printAllAccounts() const
{
	for (int i = 0; i < this->arr.size(); i++)
	{
		cout << this->arr[i].getUsername() << ", " << this->arr[i].getPassword();
	}
}
