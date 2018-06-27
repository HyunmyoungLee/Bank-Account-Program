#ifndef CUSTOMER_ACCOUNT_H
#define CUSTOMER_ACCOUNT_H
#define NAME_LEN 50
class Customer{
	int AccountNumber;
	char* name;
	int Balance;
	
	public:
		Customer(int account, const char* _name, int balance);
		~Customer();
		Customer(const Customer& ref);
		int getAccountNumber() const;
		virtual void deposit(int money);
		void withdraw(int money);
		void Display() const;
};

#endif
