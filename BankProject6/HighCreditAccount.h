#ifndef HIGH_CREDIT_ACCOUNT_H
#define HIGH_CREDIT_ACCOUNT_H
#include "NormalAccount.h"


class HighCreditAccount : public NormalAccount{
	int specialRate;
	
	public:
		HighCreditAccount(int account, const char* _name, int _balance, int rate, int special) : NormalAccount(account, _name, _balance, rate){
			specialRate = special;
		}
		
		virtual void deposit(int money){
			NormalAccount::deposit(money);
			Customer::deposit(money*((double)specialRate / 100));
		}
		
};

#endif
