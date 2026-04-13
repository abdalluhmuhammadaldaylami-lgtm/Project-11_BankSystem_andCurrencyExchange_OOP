#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include<iomanip>
using namespace std;


class clsUpdateCurrencyScreen:protected clsScreen
{
private:

	static void PrintCurrenciesRecordLine(clsCurrency C) {
		cout << " Currency Card\n";
		cout << "_________________________________\n\n";
		cout << " Country   :" << C.Country() << endl;
		cout << " Code      : " << C.CurrencyCode() << endl;
		cout << " Name      : " << C.CurrencyName() << endl;
		cout << " Rate/(1$) : " << C.Rate() << endl;
		cout << "_________________________________\n\n";
	}

	static void _ShowResult(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\n\nCurrency Found :-)\n\n";
			PrintCurrenciesRecordLine(Currency);
		}
		else
		{
			cout << "\n\n Currency Was Not Found :-(\n\n";
		}
	}

public:

	static void ShowUpdateCurrencyScreen() {

		_DrawScreenHeader("Update Currency Screen\n");

		cout << "\n\nPlease Enter CurrencyCode :";
		string CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_ShowResult(Currency);

		char ch;
		cout << "Are you sure you want to update tje rate of this currency Y/N:";
		cin >> ch;

		if (ch == 'Y'  || ch == 'y') {
			cout << "\nUpdate Currency Rate:\n";
			cout << "______________________\n";
			cout << "Enter New Rate :";
		    float RateNew=clsInputValidate::ReadFloatNumber();

			Currency.UpdateRate(RateNew);
			PrintCurrenciesRecordLine(Currency);
		}
	}
};

