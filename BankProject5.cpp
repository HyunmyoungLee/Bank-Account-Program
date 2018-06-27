//Hyunmyoung Lee
//hyunmyoung266@gmail.com 
//BANK PROGRAM - Version 5
#include <iostream>
#include <cstring>
#define NAME_LEN 50
#define NUMBER_OF_ACCOUNT 100
using namespace std;
enum {A = 7, B = 4, C = 2};

class Customer{
	int AccountNumber;
	char* name;
	int Balance;
	
	public:
		Customer(int account, const char* _name, int balance){
			AccountNumber = account;
			name = new char[NAME_LEN + 1];
			strcpy(name, _name);
			Balance = balance;
		}
		
		~Customer(){
			delete[] name;
		}
		
		Customer(const Customer& ref){
			*this = ref;
		}
		int getAccountNumber() const{
			return AccountNumber;
		}
		
		virtual void deposit(int money){
			Balance += money;
		}
		
		void withdraw(int money){
			if(Balance < money){
				cout << "Your balance is: $" << Balance << ". Withdrawing the amount of money of your balance" << endl; 
				Balance = 0;
			}else{
				Balance -= money;
			}
		}
		
		void Display() const{
			cout << "Account Number : " << AccountNumber << endl;
			cout << "Customer Name  : " << name << endl;
			cout << "Account Balance: " << Balance << endl << endl;
		}
		
		
};

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

class AccountHandler{
	
	Customer* customer[NUMBER_OF_ACCOUNT];
    int COUNT = 0;
	
	public: 
	
	AccountHandler(){
		COUNT = 0;
	}
	
	~AccountHandler(){
		for(int i = 0 ; i < COUNT ; i++){
			delete customer[i];
		}
	}
	
	void display() const{
		cout << "------Menu------" << endl;
		cout << "1.CreateAccout" << endl;
		cout << "2.Deposit     " << endl;
		cout << "3.Withdraw    " << endl;
		cout << "4.Check Balance"<< endl;
		cout << "5.Show all Account" << endl;
		cout << "6.Exit        " << endl;
	}

	void CreateAccount(){
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
	void Deposit(){
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
		
	void Withdraw(){
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
		
	void CheckBalance() const{
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
	
	void ShowAllAccount() const{
		for(int i = 0 ; i < COUNT; i++){
			cout << i+1 << ". Account" << endl;
			
			customer[i]->Display();
		}
	}
};




int main(){
	AccountHandler Manager;
	
	int option;
	do{
		Manager.display();
		cout << "Choose Option: ";
		cin >> option;

		cout << endl;

		switch(option){

			case 1 :
				Manager.CreateAccount();
				break;
			case 2 :
				Manager.Deposit();
				break;
			case 3 :
				Manager.Withdraw();
				break;
			case 4 :
				Manager.CheckBalance();
				break;
			case 5 :
				Manager.ShowAllAccount();
				break;
			case 6 : 
				cout << "End Program." << endl;
				break;

			default :
				cout << "Invalid Number" << endl;
				break;	
		}
	}while(option != 6);

	return 0;
}
