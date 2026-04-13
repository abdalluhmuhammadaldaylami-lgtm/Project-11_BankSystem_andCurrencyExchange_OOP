#pragma once
#include<iostream>
#include"clsMainScreen.h";
#include"clsScreen.h";
#include"Global.h";
#include"clsUser.h";
using namespace std;

class clsLoginScreen:protected clsScreen
{

private:

	static bool _Login() {

		bool LoginFaild = false;
		short faildLoginCount = 0;
	
		string UserName, Password;
		do {

			if (LoginFaild) {
				cout << "\nInvlaid UserName/Password!\n";
				cout << "you have " <<3-faildLoginCount << " to login.\n\n";
			}
			if (faildLoginCount == 3) {
				cout << "\nYou are Locked after 3 faild trails\n";
				return false;
			}
			cout << "Enter UserName:";
			cin >> UserName;
			cout << "Enter Password:";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmptyMode();
			faildLoginCount++;
			
		} while (LoginFaild);

		CurrentUser.LoginRegister();
		clsMainScreen::ShowMainMenue();
		return true; 
	}
	

public:

	static bool ShowLoginScreen() {

		system("cls");
		_DrawScreenHeader("\tLogin Screen");

		return _Login();
	}
};

