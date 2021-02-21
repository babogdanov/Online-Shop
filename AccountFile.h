#pragma once
#include "Account.h"
#include <vector>
class AccountFile
{
private:
    vector<Account> arr;
    Account currentAccount;
public:
    bool addAccount(Account account);
    bool logIn(Account account);
    void logOut();
    void printAccount() const;
    void printAllAccounts() const;
};


