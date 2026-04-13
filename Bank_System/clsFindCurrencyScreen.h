#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include<iomanip>
using namespace std;


class clsFindCurrencyScreen:protected clsScreen
{
private:

	static void PrintCurrenciesRecordLine(clsCurrency C) {
		cout << " Currency Card\n";
		cout << "_________________________________\n\n";
		cout << " Country   :" << C.Country()<<endl;
		cout << " Code      : " << C.CurrencyCode() << endl;
		cout << " Name      : " << C.CurrencyName()<<endl;
		cout << " Rate/(1$) : "  << C.Rate()<<endl;
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

	static int _ReadTypeFindCurrency() {
		int ch;
		cout << "Find by: [1] Code or [2] Country.?";
		ch=clsInputValidate::ReadShortNumberBetween(1, 2, "\n Enter number Between 1 to 2?");
		return ch;
	}
	 
public:

	static void ShowFindCurrencyScreen() {

		vector<clsCurrency>Vcurrency = clsCurrency::GetCurrenciesList();

		_DrawScreenHeader("Find Currency Screen\n");

		int TypeFind = _ReadTypeFindCurrency();

		if (TypeFind == 1) {
			cout << "\n\nPlease Enter CurrencyCode :";
			string CurrencyCode = clsInputValidate::ReadString();
			
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}
		if (TypeFind == 2) {

			cout << "\n\nPlease Enter Country Name :";
			string CountryName = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
			_ShowResult(Currency);
		}
	}
};

