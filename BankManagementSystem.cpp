//Bank management system
#include <iostream>
#include <conio.h>
using namespace std;
class bank
{
	string surname;
	string name;
	string add;
	string num;
	char type;
	float balance;
	int chr;
	bool acc_created=false;
	public:
		void open_account();
		void deposite_money();
		void withdraw_money();
		void display_account();
};
void bank::open_account()
{
	cout<<"Enter Your full surname:";
	cin.ignore();
	getline(cin,surname);
	cout<<"Enter your name :";
	getline(cin,name);
	cout<<"Enter your address :";
	getline(cin,add);
	cout<<"Enter your mobile number:";
	getline(cin,num);
	if(num.length()>10||num.length()<10)
	{
		cout<<"Invalid number.Please enter again!\n";
		cout<<"Enter your mobile number:";
		getline(cin,num);
	}
	cout<<"What type of account you want to open? Saving (s) or Current (C):";
    cin>>type;
    cout<<"Enter amount for deposit: ";
    cin>>balance;
    cout<<"Your account is successfully created"<<"\n";
    acc_created=true;
}
void bank::deposite_money()
{
	int a;
	cout<<"Enter how much money you want to deposite:";
	cin>>a;
	balance+=a;
	cout<<"Your current total balance: "<<balance<<"\n";
}
void bank::display_account()
{
	if(acc_created==true)
	{
	cout<<"Your full name:"<<surname<<"."<<name<<"\n";
	cout<<"Your address:"<<add<<"\n";
	cout<<"Your mobile number:"<<num<<"\n";
	cout<<"Type of account:"<<type<<"\n";
	cout<<"Amount you deposited:"<<balance<<"\n";
   }
   else
   {
   	cout<<"Oops no account found! Create one!\n";
   	cout<<"Create an account? Press Y/N:\n";
   	chr=getch();
   	if(chr=='Y'||chr=='y')
   	{
	   open_account();
    }

   }
}
void bank::withdraw_money()
{
	float amount;
	cout<<"WITHDRAW\n";
	cout<<"Enter amount to withdraw:";
	cin>>amount;
	if(balance>=amount)
	{
	balance-=amount;
	cout<<"Now total amount left in your account:\t"<<balance<<"\n";
    }
    else
    {
	cout<<"Sorry! Insufficient balance\n";
    }
}
int main()
{
	int ch;
	char x;
	bank obj;
	do
	{
	cout<<"1.Open Account \n";
	cout<<"2.Deposit money \n";
	cout<<"3.withdraw money \n";
	cout<<"4.Diplay account \n";
	cout<<"5.Exit\n";
	cout<<"Select the option from the above:\n";
	cin>>ch;
	switch(ch)
	{
		case 1:cout<<"\n >> Open Account\n";
		obj.open_account();
		break;
		
		case 2:cout<<">> Deposit money\n";
		obj.deposite_money();
		break;
		
		case 3:cout<<">> Withdraw money\n";
		obj.withdraw_money();
		break;
		
		case 4:cout<<">> Display Account\n";
		obj.display_account();
		break;
		
		case 5:cout<<"Thankyou!!!\nHope you had a safe transaction :)";
		exit(1);
		
		default:
			cout<<"This doesn't exist. Please try again!\n";
	}
	cout<<"Do you want to select any other option? Press Y/N\n";
	cout<<"If you want to exit then press 'N' \n";
	x=getch();
	if(x=='n'||x=='N')
	{
		cout<<"Thankyou!!!\nHope you had a safe transaction :)";
		exit(0);
	}
	}while(x=='y'||x=='Y');
	getch();
	return 0;
}
