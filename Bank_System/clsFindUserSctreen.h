#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsUser.h";
#include"clsInputValidate.h";
#include<iomanip>
using namespace std;

class clsFindUserSctreen:protected clsScreen
{
private:

	static void _PrintUser(clsUser User) {
		cout << "\n\tUser Card:";
		cout << "\n_______________________________";
		cout << "\n Frist Name    :" << User.FristName;
		cout << "\n Last Name     :" << User.LastName;
		cout << "\n Full Name     :" << User.FullName();
		cout << "\n Email         :" << User.Email;
		cout << "\n Phon Number   :" << User.Phon;
		cout << "\n UserName      :" << User.UserName;
		cout << "\n Password      :" << User.Password;
		cout << "\n Permissions   :" << User.Permissions;
		cout << "\n_______________________________\n";
	}

public:
	static void ShowFindUserScreen() {
		_DrawScreenHeader("\t Find User Screen");
		string UserName = "";

		cout << "\nplease Enter User Name :";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nClint With [" << UserName << "] dose not found..!\n";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

	}
};

