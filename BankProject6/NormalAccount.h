#ifndef NORMAL_ACCOUNT_H
#define NORMAL_ACCOUNT_H
#include "CustomerAccount.h"

class NormalAccount : public Customer{
	int interestRate;
	
	public:
		NormalAccount(int account, const char* _name, int _balance, int rate) : Customer(account, _name, _balance){
			interestRate = rate;
		}
		
		virtual void deposit(int money){
			Customer::deposit(money);
			Customer::deposit(money*((double)interestRate / 100));
		}
		
		
};

#endif
