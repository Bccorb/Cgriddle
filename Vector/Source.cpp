// Program:		Project 6
// Programmer:	Brandon Corbett
// Date:		Nov 23, 2014
// Description:	Program accepts usernames and passwords, stores them as vectors then when prompted
//				displays all entries. 
// IDE used:	Visual Studio 2013 w/update 3

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <vector>
#include <string>
using namespace std;

string checkPassword();
//Checks users password input for validity. 

int main()
{
	vector<string> login;
	string userName = "", password;

	cout << "\n\n\t\t USER SIGN-UP\n";
	cout << "\t---------------------------------\n\n";
	cout << "\tEnter your username\n"
		<< "\tEnter 0 when done.\n\t";
	getline(cin, userName);

	while (userName != "0")
	{
			password = checkPassword();
			login.push_back(userName + ", " + password + "\n");	//concatenates the username and password

			cout << "\tEnter your username\n"
				 << "\tEnter 0 when done.\n\t";
			getline(cin, userName);
	}

	cout << endl;
	cout << "\tThe logins for this terminal are:\n";
	for (unsigned int i = 0; i < login.size(); i++)
		cout << "\t" << login[i];
		cout << endl;

	system("pause");

	return 0;
}


string checkPassword()
{
	using namespace std;
	string  pass;
	bool space;
	int numberSize;
	char ch;

	do
	{
		cout << "\tValid passwords cannot be all numbers,\n\tless than 5 characters or contain spaces\n"; 
		cout << "\tEnter your password\n\t";

		pass = "";
		cin.clear();
		ch = _getch();

		while (ch != 13)
		{
			pass += ch;
			cout << '*';
			ch = _getch();
		}

		space = false;
		numberSize = 0;

		for (unsigned int i = 0; i < pass.length(); i++)
		{
			if (isspace(pass[i]))
				space = true;
			
			if (isdigit(pass[i]))
				numberSize++;
		}
		cout << endl;
	} while (pass.length() < 5 || space == true || numberSize == pass.length());

	cout << "\n\tThe password you entered was " << pass << endl;
	cin.clear();

	return pass;
}

