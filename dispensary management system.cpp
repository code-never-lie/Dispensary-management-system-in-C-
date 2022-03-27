
#include <iostream>
#include<process.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
void menu2();
double p, l, v;
class Dispensary
{

	char   drug_name[20];//character data type
	int    ID;//integer typr
	double sale_price;//double type for sale_price
	double purchase_price;//double type for purchase_price
	double profit;//double type profit
	double Total_ammount;//double type total ammount
	double ammount_of_sale;// double ammount of sale
	double ammount_left;//double type ammount left
	double   manufacture_Date;//double type manufacture date
	double   expiry_date;//double type expiry date
	double valdity;//validity for howmany time remaining for expire
public:
	void getdata();//Member function for get data
	void display();//Member function for a dispaly
	int getid()//This function return The id
	{

		return ID;
	}

}s;

void Dispensary::getdata()//define out side using a scope resolution
{
//here we input the a values
	cout << "Enter the Name of The Drug(Name) \n";
	cin >> drug_name;
	cin.ignore();
	cout << "Enter ID of Drug(Integer) \n";
	cin >> ID;
	cin.ignore();
	cout << " Enter Sale Price  ==  ";
	cin >> sale_price;
	cin.ignore();
	cout << "Enter Purchase Price == ";
	cin >> purchase_price;
	cin.ignore();
	profit = sale_price - purchase_price;
	cout << "Enter Total Number a of Drugs == ";
	cin >> Total_ammount;
	cin.ignore();
	cout << "Enter The a Sale amount == ";
	cin >> ammount_of_sale;
	cin.ignore();
	ammount_left = Total_ammount - ammount_of_sale;
	cout << "Enter of Manufacture Date in (year please!) Format == ";
	cin >> manufacture_Date;
	cin.ignore();
	cout << "Enter the Expiry Date in (year please!) Format == ";
	cin >> expiry_date;
	cin.ignore();
	valdity = expiry_date - manufacture_Date;
	menu2();

	char a;
	cin >> a;
	if (a == 'a' || a == 'A')  cout << "Profit ===   " << profit << endl;//if we press A it check a profit
	else if (a == 'b' || a == 'B') cout << "Amount Left ==  " << ammount_left << endl;//if we press B it check a Ammount left
	else if (a == 'c' || a == 'C') cout << "Validity is   " << valdity << " Years " << endl;//if we press C it check validity of expiry
}
void Dispensary::display()
{
	cout << "@@=================================================@@\n";
	cout << "Name : " << drug_name << "\n";
	cout << "ID    : " << ID << "\n";
	// cout<<"=================================================\n";
}

//Prototyping of functions for menu
void search();
void add();
void displayall();
void menu2();
void options();
int main()
{
	system("COLOR 3E");
	fstream fio("NOTE.TEXT", ios::in | ios::out | ios::binary);

	int ch;
	options();
	cin >> ch;
	while (ch)
	{
		switch (ch)//here we use a three case
		{
		case 1: add(); break;//for adding
		case 2: displayall(); break;
		case 3: search(); break;
		case 4: return 0; break;
		default: cout << "Wrong Input please enter the correct value....\n";
		}
		system("pause");
		options();
		cin >> ch;
	}
	return 0;
}


void options()
{
	cout << endl;
	cout << "\t@@*____________________________________________________________*@@";
	cout << endl;
	cout << endl;
	cout << "\t\t **LAHORE DISPENSERY MANAGEMENT SYSTEM LIMITED **" << endl;
	cout << endl;
	cout << "\t@@_______________________________________________________________@@";

	cout << endl;
	cout << "\n\t...MENU OF PROGRAM...\n";

	cout << "\t1. ***Add the record***...\n";
	cout << "\t2. ***Display all records***...\n";
	cout << "\t3. ***Search the record***...\n";
	cout << "\t4. ***EXIT***....\n";
	cout << "\n***Enter Your Choice(An Integer)***  : ";
}
void menu2()
{
	cout << "WHAT YOU WANT TO CHECK OUT!(Given Blow.)\n";
	cout << "a.Profit\n";
	cout << "b.Amount left \n";
	cout << "c.Expiry date\n";
	cout << "Press Your Choice And do not press any integer\n";
}
void displayall()
{
	ifstream fin("NOTE.TEXT", ios::in | ios::binary);
	while (fin.read((char*)& s, sizeof(s)))
	{
		s.display();
	}
	fin.close();

}

void add()
{
	char ch = 'y';
	ofstream fout("NOTE.TEXT", ios::out | ios::app | ios::binary);
	while (ch == 'y' || ch == 'Y')
	{
		s.getdata();
		fout.write((char*)& s, sizeof(s));
		cout << "\nDo You Want To Add More : Press Y or N (Y For Yess & N For No)";
		cin >> ch;
	}
	cout << "\nData Appended and Transferred to file...\n";
	fout.close();
}
void search()
{
	ifstream fin("NOTE.TEXT", ios::in | ios::binary);
	int idd, i = 0;
	char found = 'n';
	cout << "\nEnter Id. to be searched : ";
	cin >> idd;

	while (fin.read((char*)& s, sizeof(s)))
	{
		if (s.getid() == idd)
		{
			s.display();
			found = 'y';
		}
		i++;
	}
	if (found == 'n') cout << "\nThis ID. " << idd << " is not in the file...\n";
	fin.close();
}
