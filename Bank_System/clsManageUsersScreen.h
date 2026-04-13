#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsUser.h";
#include"clsInputValidate.h";
#include"clsAddNewUserScreen.h";
#include"clsUsersListScreen.h";
#include"clsDeleteUserScreen.h";
#include"clsUpdateUserScreen.h";
#include"clsFindUserSctreen.h";
#include<iomanip>
using namespace std;


class clsManageUsersScreen:protected clsScreen
{

private:

	enum enManageUserMenueOption {
		elistUser = 1, eAddUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};

	static void _GoBackToManageUserMenue() {
		cout << "\n\tpress any key to go back to main menue...\n";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowAllUsersScreen() {
		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen() {
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen() {
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen() {
		clsFindUserSctreen::ShowFindUserScreen();
	}

	static short _ReadManageUsersMenueOption() {
		short ch;
		cout << "  Choose What do you Want to do ?[1 to 6]: ";
		ch = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter number Between 1 to 6?");

		return ch;
	}

	static void _PerformManageUsersMenueOption(enManageUserMenueOption menueUsersoption) {
		switch (menueUsersoption) {
		case enManageUserMenueOption::elistUser:
		{
			system("cls");
			_ShowAllUsersScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case enManageUserMenueOption::eAddUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case enManageUserMenueOption::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case enManageUserMenueOption::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case enManageUserMenueOption::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case enManageUserMenueOption::eMainMenue:
		{
			
		}
		}
	}


public:
 
	static void ShowManageUsersMenue() {

		system("cls");
		if (!ChackAccessRight(clsUser::enpermision::pManageUser)) {
			return;
		}
		_DrawScreenHeader("\tManage Users Screen");

		cout << "===========================================\n";
		cout << "\t\tManage Users Menue\n";
		cout << "===========================================\n";
		cout << "  [1] List Users.\n";
		cout << "  [2] Add New User.\n";
		cout << "  [3] Delete User.\n";
		cout << "  [4] Update User.\n";
		cout << "  [5] Find User.\n";
		cout << "  [6] Main Menue.\n";
		cout << "============================================\n";

		_PerformManageUsersMenueOption((enManageUserMenueOption)_ReadManageUsersMenueOption());
	}

};

