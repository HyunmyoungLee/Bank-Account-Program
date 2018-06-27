#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H
#include "CustomerAccount.h"
#define NUMBER_OF_ACCOUNT 100

enum {A = 7, B = 4, C = 2};
class AccountHandler{
	
	Customer* customer[NUMBER_OF_ACCOUNT];
    	int COUNT = 0;
	
	public: 
	
	AccountHandler();
	~AccountHandler();
	void display() const;
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void CheckBalance() const;
	void ShowAllAccount() const;
};

#endif
