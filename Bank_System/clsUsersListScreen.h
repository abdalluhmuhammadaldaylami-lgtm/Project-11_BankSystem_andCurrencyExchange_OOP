#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsUser.h";
#include"clsInputValidate.h";
#include<iomanip>
using namespace std;

class clsUsersListScreen:protected clsScreen
{

private:
	
	static void _printUsers(clsUser User) {
		cout << "| " << left << setw(13) << User.UserName;
		//cout << "| " << left << setw(13) << User.FristName;
		cout << "| " << left << setw(20) << User.FullName();
		cout << "| " << left << setw(10) << User.Phon;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(8) << User.Password;
		cout << "| " << left << setw(13) << User.Permissions;
	}

public:

	static void ShowUsersList() {

		vector<clsUser>vUsers;
		vUsers = clsUser::GetUsersList();

		string SubTitle = "(" + to_string(vUsers.size()) + ") User (s)\n";
		_DrawScreenHeader("Add New User Screen", SubTitle);

		cout << "-----------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(13) << "UserName";
		//cout << "| " << left << setw(13) << "Frist Name";
		cout << "| " << left << setw(20) << "FullName";
		cout << "| " << left << setw(10) << "Phon";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(8) << "password";
		cout << "| " << left << setw(13) << "Permissions";
		cout << "\n-----------------------------------------------------------------------------------------------\n";

		if (vUsers.size() == 0) {
			cout << "\n\t\t\t\tNo Users Available In the System!";
		}
		else {
			for (clsUser U : vUsers) {
				_printUsers(U);
				cout << endl;
			}
		}
		cout << "-----------------------------------------------------------------------------------------------\n";
	}


};

