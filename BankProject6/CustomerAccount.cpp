#include <iostream>
#include <cstring>
#include "CustomerAccount.h"
using namespace std;

		Customer::Customer(int account, const char* _name, int balance){
			AccountNumber = account;
			name = new char[NAME_LEN + 1];
			strcpy(name, _name);
			Balance = balance;
		}
		
		Customer::~Customer(){
			delete[] name;
		}
		
		Customer::Customer(const Customer& ref){
			*this = ref;
		}
		int Customer::getAccountNumber() const{
			return AccountNumber;
		}
		
		void Customer::deposit(int money){
			Balance += money;
		}
		
		void Customer::withdraw(int money){
			if(Balance < money){
				cout << "Your balance is: $" << Balance << ". Withdrawing the amount of money of your balance" << endl; 
				Balance = 0;
			}else{
				Balance -= money;
			}
		}
		
		void Customer::Display() const{
			cout << "Account Number : " << AccountNumber << endl;
			cout << "Customer Name  : " << name << endl;
			cout << "Account Balance: " << Balance << endl << endl;
		}
