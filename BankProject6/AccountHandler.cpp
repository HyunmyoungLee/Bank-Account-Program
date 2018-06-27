#include <iostream>
#include <cstring>
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

using namespace std;	

	AccountHandler::AccountHandler(){
		COUNT = 0;
	}
	
	AccountHandler::~AccountHandler(){
		for(int i = 0 ; i < COUNT ; i++){
			delete customer[i];
		}
	}
	
	void AccountHandler::display() const{
		cout << "------Menu------" << endl;
		cout << "1.CreateAccout" << endl;
		cout << "2.Deposit     " << endl;
		cout << "3.Withdraw    " << endl;
		cout << "4.Check Balance"<< endl;
		cout << "5.Show all Account" << endl;
		cout << "6.Exit        " << endl;
	}

	void AccountHandler::CreateAccount(){
		int accountNumber;
		char Name[NAME_LEN];
		int balance;
		int rate;
		int level;
		int option;
		cout << "[ Choose the type of Accounts ]" << endl;
		cout << "1. Normal Account 2. High Credit Account" << endl;
		cout << "Enter number( 1 or 2 ) : ";
		cin >> option;
		
		switch(option){
			case 1:
				if(COUNT < NUMBER_OF_ACCOUNT){
				cout << "[Create the Normal Account]" << endl;
				cout << "Account Number: ";
				cin >> accountNumber;
				cout << "Name: ";
				cin >> Name;
				cout << "Balance: ";
				cin >> balance;
				cout << "Interest rate: ";
				cin >> rate;
				cout << endl;
				}
				customer[COUNT++] =  new NormalAccount(accountNumber, Name, balance, rate);
				break;
				
			case 2:
				if(COUNT < NUMBER_OF_ACCOUNT){
				cout << "[Create the High Credit Account]" << endl;
				cout << "Account Number: ";
				cin >> accountNumber;
				cout << "Name: ";
				cin >> Name;
				cout << "Balance: ";
				cin >> balance;
				cout << "Interest rate: ";
				cin >> rate;
				cout << "Credit Rating (A class = 7, B class = 4, C class =2)" << endl;
				cout << "Enter number( 7 or 4 or 2): ";
				cin >> level;
				
				switch(level){
					case 7:
						customer[COUNT++] = new HighCreditAccount(accountNumber, Name, balance, rate, A);
						break;
					case 4:
						customer[COUNT++] = new HighCreditAccount(accountNumber, Name, balance, rate, B);
						break;
					case 2:
						customer[COUNT++] = new HighCreditAccount(accountNumber, Name, balance, rate, C);
						break;
					default:
						cout << "Invalid Number " << endl;
						break;
				}
				cout << endl;
				}
				break;
				
			default:
				cout << "Invalid Number" << endl;
				break;
		}
	}
	void AccountHandler::Deposit(){
		int id, money;
		cout << "Enter Valid Account Number: ";
		cin >> id;
		cout << endl;
	
		for(int i = 0 ; i < COUNT ; i++){
			if(customer[i]->getAccountNumber() == id){
				cout << "Enter amount for deposit: ";
				cin >> money;
				customer[i]->deposit(money);
			}
		}

		cout << endl;	
	}
		
	void AccountHandler::Withdraw(){
		int id,money;
		cout << "Enter Valid Account Number: ";
		cin >> id;
		cout << endl;

		for(int i = 0; i < COUNT ; i++){
			if(customer[i]->getAccountNumber() == id){
				cout << "Enter amount for withdraw: ";
				cin >> money;
				customer[i]->withdraw(money);
			}
		}

		cout << endl;
	}
		
	void AccountHandler::CheckBalance() const{
		int id;
		cout<< "Enter Valid Account Number: ";
		cin >> id;
		cout << endl;

		for(int i = 0 ; i < COUNT; i++){
			if(customer[i]->getAccountNumber() == id){
				customer[i]->Display();
			}
		}
	}
	
	void AccountHandler::ShowAllAccount() const{
		for(int i = 0 ; i < COUNT; i++){
			cout << i+1 << ". Account" << endl;
			
			customer[i]->Display();
		}
	}
