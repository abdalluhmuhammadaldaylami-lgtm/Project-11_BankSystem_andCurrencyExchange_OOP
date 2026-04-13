#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsInputValidate.h";
#include"clsListCurrenciesScreen.h";
#include"clsFindCurrencyScreen.h";
#include"clsUpdateCurrencyScreen.h";
#include"clsCurrencyCalculitorScreen.h";
using namespace std;

class clsCurrencyExchangemainScreen:protected clsScreen
{
	enum enCurrencyMenue {
		eListCurrency = 1, eCurrencyFind = 2, eUpdateRate = 3, eCalcultorCurrency = 4, mainMenue = 5
	};

	static void _ShowListCurrencyScreen() {

		clsListCurrenciesScreen::ShowListCurenciesScreen();

	}

	static void _ShowFindCurrencyScreen() {

		clsFindCurrencyScreen::ShowFindCurrencyScreen();

	}

	static void _ShowUpdateCurrencyRateScreen() {

		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculitorScreen() {

		clsCurrencyCalculitorScreen::ShowCurrencyCalcoltorScreen();
	}

	static short _ReadMainMenueOption() {
		short ch;
		cout << "  Choose What do you Want to do ?[1 to 5]: ";
		ch = clsInputValidate::ReadShortNumberBetween(1, 5, "\n Enter number Between 1 to 5?");

		return ch;
	}

	static void _GoBackToCurrenciesMenue() {
		cout << "\n\tpress any key to go back to main menue...\n";
		system("pause>0");
		ShowCurrenciesMenue();
	}


	static void _PerformCurrencyMainMenueOption(enCurrencyMenue CurrencyMenue) {

		switch (CurrencyMenue) {
		case enCurrencyMenue::eListCurrency:
		{
			system("cls");
			_ShowListCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case enCurrencyMenue::eCurrencyFind:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case enCurrencyMenue::eUpdateRate:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case enCurrencyMenue::eCalcultorCurrency:
		{
			system("cls");
			_ShowCurrencyCalculitorScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case enCurrencyMenue::mainMenue:
		{

		}
		}
	}

public:

	static void ShowCurrenciesMenue() {
		system("cls");
		if (!ChackAccessRight(clsUser::enpermision::pCurrenciesExchange)) {
			return;
		}
		_DrawScreenHeader("\tCurrency Exhange Main Screen");

		cout << "=============================================\n";
		cout << "\t\tCurrency Exhange Menue\n";
		cout << "=============================================\n";
		cout << "  [1] List Currency.\n";
		cout << "  [2] Find Currency.\n";
		cout << "  [3] Update Rate.\n";
		cout << "  [4] Currency Calcultor.\n";
		cout << "  [5] Main Menue.\n";
		cout << "==============================================\n";

		_PerformCurrencyMainMenueOption((enCurrencyMenue)_ReadMainMenueOption());
	}
};

