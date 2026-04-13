#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"clsClintListSccreen.h";
#include"clsAddNewClintScreen.h";
#include"clsDeleteClintScreen.h";
#include"clsUpdateClintScreen.h";
#include"clsFindClintSctreen.h";
#include"clsTransactionsMenue.h";
#include"clsManageUsersScreen.h";
#include"clsLoginRegistersScreen.h";
#include"Global.h";
#include"clsLoginScreen.h";
#include"clsCurrencyExchangemainScreen.h";
using namespace std;


class clsMainScreen:protected clsScreen
{
private:

	enum enMainMenueOption {
		eListClints = 1, eAddClint = 2, eDeleteClint = 3, eUpdateClint = 4, eFindClint = 5,
		eShowTransactionsMenue = 6, eManageUsers = 7,LoginRegister=8 ,eCurrencies=9,eExit = 10
	};

	static void _GoBackToMainMenue() {
		cout << "\n\tpress any key to go back to main menue...\n";
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClintsScreen() {
		clsClintListSccreen::ShowClintList();
	}

	static void _ShowAddNewClintScreen() {
		clsAddNewClintScreen::ShowAddNewClint();
	}

	static void _ShowDeleteClintScreen() {
		clsDeleteClintScreen::ShowDeleteClintScreen();
	}

	static void _ShowUpdateClintScreen() {
		clsUpdateClintScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClintScreen() {
		clsFindClintSctreen::ShowFindClintScreen();
	}

	static void _ShowTransactionMenue() {
		clsTransactionsMenue::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue() {
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisters() {
		clsLoginRegistersScreen::ShowUsersLoginRegister();
	}

	static void _ShowCurrencyExchangeMainScreen() {

		clsCurrencyExchangemainScreen::ShowCurrenciesMenue();
	}

	static void _Logout() {
		CurrentUser = clsUser::Find("", "");
	}

	static short _ReadMainMenueOption() {
		short ch;
		cout << "  Choose What do you Want to do ?[1 to 10]: ";
		ch = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter number Between 1 to 10?");

		return ch;
	}

	static void _PerformMainMenueOption(enMainMenueOption mainmenueoption) {
		switch (mainmenueoption) {
		case enMainMenueOption::eListClints:
		{
			system("cls");
			_ShowAllClintsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eAddClint:
		{
			system("cls");
			_ShowAddNewClintScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eDeleteClint:
		{
			system("cls");
			_ShowDeleteClintScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eUpdateClint:
		{
			system("cls");
			_ShowUpdateClintScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eFindClint:
		{
			system("cls");
			_ShowFindClintScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::LoginRegister:
		{
			system("cls");
			_ShowLoginRegisters();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eCurrencies:
		{
			system("cls");
			_ShowCurrencyExchangeMainScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eExit:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}

public:
	
 	static void ShowMainMenue() {
		system("cls");
		_DrawScreenHeader("\tMain Menu Screen");

		cout << "============================================================\n";
		cout << "\t\tMain Menu Screen\n";
		cout << "============================================================\n";
		cout << "  [1] Show Clint List.\n";
		cout << "  [2] Add New Clint.\n";
		cout << "  [3] Delete Clint.\n";
		cout << "  [4] Update Clint info.\n";
		cout << "  [5] Find Clint.\n";
		cout << "  [6] Transactions.\n";
		cout << "  [7] Manage Users.\n";
		cout << "  [8] Login Registers.\n";
		cout << "  [9] Currencies Exchange.\n";
		cout << "  [10] Logout.\n";
		cout << "============================================================\n";

		_PerformMainMenueOption((enMainMenueOption)_ReadMainMenueOption());
	}
};

