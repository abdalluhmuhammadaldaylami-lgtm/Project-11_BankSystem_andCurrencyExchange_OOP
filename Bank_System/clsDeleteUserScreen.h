#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsUser.h";
#include"clsInputValidate.h";
#include<iomanip>
using namespace std;

class clsDeleteUserScreen:protected clsScreen
{
private:


	static void _PrintUser(clsUser User) {
		cout << "\n\tClaint Card:";
		cout << "\n_______________________________";
		cout << "\n Frist Name   :" << User.FristName;
		cout << "\n FullName     :" << User.FullName();
		cout << "\n Email        :" << User.Email;
		cout << "\n Phon Number  :" << User.Phon;
		cout << "\n UserName     :" << User.UserName;
		cout << "\n Password     :" << User.Password;
		cout << "\n Permissios   :" << User.Permissions;
		cout << "\n_______________________________\n";
	}

public:

	static void ShowDeleteUserScreen() {

		_DrawScreenHeader("\tDelete User Screen");

		string UserName = "";
		cout << "please Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nUserName Is Already Used, Choose another one :";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		char ch = 'n';
		cout << "\nAre you sure you want to delete this clint Y/N :";
		cin >> ch;

		if (ch == 'Y' || ch == 'y') {
			if (User.Delete()) {
				cout << "\n User Delete Successfully :-)";
				_PrintUser(User);
			}
			else {
				cout << "\nError User Was not Deleted\n";
			}
		}

	}

};

